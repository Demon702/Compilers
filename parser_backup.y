%{
	#include <stdio.h>
	#include <string.h>
	extern "C" void yyerror(char *s);
	extern int yylex(void);
	extern int yylineno;
	extern Program program_object;
	extern int scope;

	Symbol_Table* local_table = new Symbol_Table();
	Symbol_Table* global_table = new Symbol_Table();
	Procedure * procedure ; // new Procedure(void_data_type, "main", yylineno);
	// Procedure * procedure = new Procedure(void_data_type, "main", yylineno);
	list<Ast *> * ast_list = new list<Ast*>();

	//int yydebug = 1;

%}

%token INTEGER FLOAT ASSIGN VOID INTEGER_NUMBER DOUBLE_NUMBER NAME DO WHILE IF ELSE PRINT ';'

%right ASSIGN
%right '?' ':'
%left OR	 
%left AND
%left EQUAL NOT_EQUAL
%left LESS_THAN LESS_THAN_EQUAL GREATER_THAN GREATER_THAN_EQUAL
%left '+' '-'
%left '*' '/'
%nonassoc "ter"
%right NOT
%left '(' ')'


%union {
	int integer_value;           
	double double_value;             
	string * string_value; 
	list<Ast *> * ast_list;
	Ast* ast;
	Symbol_Table * symbol_table;
	Symbol_Table_Entry * symbol_entry;
	Basic_Block * basic_block;
	Procedure * procedure;

};

//%type<integer_value> expression constant variable number
%type<string_value> NAME proc_name
%type<integer_value> INTEGER_NUMBER
%type<double_value> DOUBLE_NUMBER
%type<ast> variable declaration_list declaration_list_loop procedure_definition integer_variable_list float_variable_list constant value expression assignment_statement assign_expression if_statement conditional_statement else_statement while_statement do_while_statement ternary_operator program_statements print_statement procedure_definition_list argument_declaration



%%

program 	: optional_declaration_list 
				{
					global_table->set_table_scope(global);
					program_object.set_global_table(*global_table);
					// program_object.set_global_table(*global_table);

				}
	
	procedure_definition_list
	;

optional_declaration_list: declaration_list
	| ;

/*
declaration_list  :   procedure_declaration
	  | variable_declaration_list 
		procedure_declaration
	  | procedure_declaration 
		variable_declaration_list
	  ;
	  */

/*procedure_definition  : VOID NAME '(' ')'
	'{'
		declaration_list
	'}' 
	{
		local_table->set_table_scope(local);
		procedure->set_local_list(*local_table);
		program_object.set_procedure(procedure, yylineno);

		$$ = $6;
	}
	;*/


procedure_definition_list : procedure_definition_list  procedure_definition
		|	procedure_definition
		;


procedure_definition  : VOID proc_name '(' argument_declaration ')'
	'{'
		declaration_list
	'}' 
	{
		local_table->set_table_scope(local);
		procedure->set_local_list(*local_table);
		/*program_object.set_procedure(procedure, yylineno); */
		$$ = $7;
	}
	|	INTEGER proc_name '(' argument_declaration ')'
		'{'
			declaration_list
			
		'}' 
		{
			local_table->set_table_scope(local);
			procedure->set_local_list(*local_table);
			/*program_object.set_procedure(procedure, yylineno); */
			$$ = $7;
		}
	|	FLOAT proc_name '(' argument_declaration ')'
		'{'
			declaration_list
		'}' 
		{
			local_table->set_table_scope(local);
			procedure->set_local_list(*local_table);
			/*program_object.set_procedure(procedure, yylineno); */
			$$ = $7;
		}

	;



proc_name : NAME 
	{	
		string s = *yylval.string_value + "_";
		procedure = new Procedure(void_data_type, s, yylineno);
		$$ = &s;
	}
	;

argument_declaration : argument_declaration ',' INTEGER NAME
	|	argument_declaration ',' FLOAT NAME
	|	INTEGER NAME
	{	
		$$ = 
	}
	| 	FLOAT NAME
	{
		$$ = 
	}
	;



declaration_list : declaration_list variable_declaration 
	|  declaration_list assignment_statement
	{	

		ast_list->push_back($2);
		procedure->set_ast_list(*ast_list);
		// printf("pushing ast in list \n");
		// cout <<"assign here\n";

		Sequence_Ast* seq_ast = (Sequence_Ast*)$1;
		seq_ast->ast_push_back($2);
		$$ = seq_ast;
		
	}

	|  declaration_list while_statement
	{
		ast_list->push_back($2);
		procedure->set_ast_list(*ast_list);
		Sequence_Ast* seq_ast = (Sequence_Ast*)$1;
		seq_ast->ast_push_back($2);
		$$ = seq_ast;
	}
	| declaration_list if_statement
	{
		ast_list->push_back($2);
		procedure->set_ast_list(*ast_list);
		Sequence_Ast* seq_ast = (Sequence_Ast*)$1;
		seq_ast->ast_push_back($2);
		$$ = seq_ast;
	}
	| declaration_list do_while_statement
	{
		ast_list->push_back($2);
		procedure->set_ast_list(*ast_list);
		Sequence_Ast* seq_ast = (Sequence_Ast*)$1;
		seq_ast->ast_push_back($2);
		$$ = seq_ast;
	}
	|
		declaration_list '{' declaration_list '}'
	{
		Sequence_Ast* seq_ast = (Sequence_Ast*)$1;
		// Return_Ast* return_Ast = new Return_Ast(yylineno);
		// seq_ast->ast_push_back(return_Ast);
		seq_ast->ast_push_back($3);
		// cout << "braces Here\n";
		$$ = seq_ast;
	}
	| declaration_list print_statement
	{
		ast_list->push_back($2);
		procedure->set_ast_list(*ast_list);
		
		Sequence_Ast* seq_ast = (Sequence_Ast*)$1;
		seq_ast->ast_push_back($2);
		$$ = seq_ast;
	}
	| 
	{
		Sequence_Ast* seq_ast = new Sequence_Ast(yylineno);
		$$ = seq_ast;
	}
	;


declaration_list_loop : declaration_list_loop variable_declaration 
	|  declaration_list_loop assignment_statement
	{	

		// ast_list->push_back($2);
		// procedure->set_ast_list(*ast_list);
		// printf("pushing ast in list \n");
		// cout <<"assign here\n";


		Sequence_Ast* seq_ast = (Sequence_Ast*)$1;
		seq_ast->ast_push_back($2);
		$$ = seq_ast;
		
	}

	|  declaration_list_loop while_statement
	{
		// ast_list->push_back($2);
		// procedure->set_ast_list(*ast_list);
		Sequence_Ast* seq_ast = (Sequence_Ast*)$1;
		seq_ast->ast_push_back($2);
		$$ = seq_ast;
	}
	| declaration_list_loop if_statement
	{
		// ast_list->push_back($2);
		// procedure->set_ast_list(*ast_list);
		Sequence_Ast* seq_ast = (Sequence_Ast*)$1;
		seq_ast->ast_push_back($2);
		// cout <<"if here\n";

		$$ = seq_ast;
	}
	| declaration_list_loop do_while_statement
	{
		// ast_list->push_back($2);
		// procedure->set_ast_list(*ast_list);
		Sequence_Ast* seq_ast = (Sequence_Ast*)$1;
		seq_ast->ast_push_back($2);
		$$ = seq_ast;
	}
	| declaration_list_loop '{' declaration_list_loop '}'
	{
		Sequence_Ast* seq_ast = (Sequence_Ast*)$1;
		// Return_Ast* return_Ast = new Return_Ast(yylineno);
		// seq_ast->ast_push_back(return_Ast);
		seq_ast->ast_push_back($3);
		// cout << "braces Here\n";
		$$ = seq_ast;
	}
	| declaration_list_loop print_statement
	{
		Sequence_Ast* seq_ast = (Sequence_Ast*)$1;
		seq_ast->ast_push_back($2);
		$$ = seq_ast;
	}
	| 
	{
		Sequence_Ast* seq_ast = new Sequence_Ast(yylineno);
		$$ = seq_ast;
	}
	;


print_statement : PRINT variable ';'
	{
		// string b = *$2 + "_";
		Print_Ast * print_ast = new Print_Ast($2, yylineno);
		// cout << "print ast";
		$$ = print_ast;
	}
	;


variable_declaration  : integer_declaration ';'
	|     float_declaration ';'
	;

integer_declaration           : INTEGER integer_variable_list
	;

integer_variable_list   :       NAME 
	{
		string b = *$1 + "_";
		
		Symbol_Table_Entry* symbol = new Symbol_Table_Entry(b, int_data_type, yylineno);
		// printf("int: %d\n", scope);

		if (scope) 
		{
			symbol->set_symbol_scope(global);
			global_table->push_symbol(symbol);
			// program_object.set_global_table(*global_table);
		}
		else 
		{
			symbol->set_symbol_scope(local);
			local_table->push_symbol(symbol);
			// procedure->set_local_list(*local_table);
		}
		
	}
	|   integer_variable_list ',' NAME
	{
		string b = *$3 + "_";
		Symbol_Table_Entry* symbol = new Symbol_Table_Entry(b, int_data_type, yylineno);
		// printf("int: %d\n", scope);

		if (scope) 
		{
			symbol->set_symbol_scope(global);
			global_table->push_symbol(symbol);
			// program_object.set_global_table(*global_table);
		}
		else 
		{
			symbol->set_symbol_scope(local);
			local_table->push_symbol(symbol);
			// procedure->set_local_list(*local_table);
		}
	}
	;

float_declaration		:  FLOAT float_variable_list
	;

float_variable_list		:       NAME 
	{
		string b = *$1 + "_";
		Symbol_Table_Entry* symbol = new Symbol_Table_Entry(b, double_data_type, yylineno);
		// printf("float: %d\n", scope);
		if (scope) 
		{
			symbol->set_symbol_scope(global);
			global_table->push_symbol(symbol);
			// program_object.set_global_table(*global_table);
		}
		else 
		{
			symbol->set_symbol_scope(local);
			local_table->push_symbol(symbol);
			// procedure->set_local_list(*local_table);
		}
	}
	|     float_variable_list ',' NAME 
	{
		string b = *$3 + "_";
		Symbol_Table_Entry* symbol = new Symbol_Table_Entry(b, double_data_type, yylineno);
		// printf("float: %d\n", scope);

		if (scope) 
		{
			symbol->set_symbol_scope(global);
			global_table->push_symbol(symbol);
			// program_object.set_global_table(*global_table);
		}
		else 
		{
			symbol->set_symbol_scope(local);
			local_table->push_symbol(symbol);
			// procedure->set_local_list(*local_table);
		}
	}
	;

/*
statement_list          : 
		| statement_list
		  assignment_statement
		;

		*/

assignment_statement  : assign_expression ASSIGN expression ';'
	{		
		// printf("creating ASSIGN ast\n");
		Assignment_Ast* assignment_ast =  new Assignment_Ast($1, $3, yylineno);
		//assignment_ast->set_data_type($3->get_data_type());

		$$ = assignment_ast;
		$$->check_ast();

	}

	;


assign_expression 	: 
	variable
	;
	/*assign_expression ASSIGN variable
	{	
		// printf("creating ASSIGN ast\n");

		Assignment_Ast* assignment_ast =  new Assignment_Ast($1, $3, yylineno);
		//assignment_ast->set_data_type($3->get_data_type());

		$$ = assignment_ast;
		$$->check_ast();


	}

	| variable
	;*/

expression : '(' expression ')'
	{
		$$ = $2;
	}
	|
	expression  '/' expression
	{ //$$ = $1 / $3; 
		// printf("creating / ARITHOP ast\n");
		Divide_Ast* divide_ast = new Divide_Ast($1, $3, yylineno);
		// divide_ast->set_data_type($3->get_data_type());
		$$ = divide_ast;
		$$->check_ast();

	}
	|
    expression  '*' expression
	{ //$$ = $1 * $3;
		// printf("creating * ARITHOP ast\n");
		//Symbol_Table_Entry symbol = program_object.get_symbol_table_entry(*$3);
		Mult_Ast* mlus_ast = new Mult_Ast($1, $3, yylineno);
		// mlus_ast->set_data_type($3->get_data_type());
		$$ = mlus_ast;
		$$->check_ast();

	}
	|
	expression '+' expression
	{ //$$ = $1 + $3;
		// printf("creating + ARITHOP ast\n");
		//Symbol_Table_Entry symbol = program_object.get_symbol_table_entry(*$3);
		Plus_Ast* plus_ast = new Plus_Ast($1, $3, yylineno);
		$$ = plus_ast;
		$$->check_ast();

	}
	

	| expression  '-' expression
	{// $$ = $1 - $3;
		// printf("creating - ARITHOP ast\n");
		Minus_Ast* minus_ast = new Minus_Ast($1, $3, yylineno);
		$$ = minus_ast;
		$$->check_ast();

	}
	| '-' expression 	%prec '/'
	{
			UMinus_Ast* un_ast = new UMinus_Ast($2, NULL, yylineno);
			// un_ast->set_data_type($2->get_data_type());
			$$ = un_ast;
			$$->check_ast();


		}
	| ternary_operator %prec "ter"
	| value
	;
	  
value: variable
	| constant
	;

variable : NAME 
	{ 
		// printf("creating NAME ast\n");
		Name_Ast* name_ast;
		string b = *$1 + "_";
		Symbol_Table_Entry* symbol = new Symbol_Table_Entry();
		if(scope){
			name_ast = new Name_Ast(b, global_table->get_symbol_table_entry(b), yylineno);
		}
		else{
			if(local_table->variable_in_symbol_list_check(b))
			{
				// *symbol = local_table->get_symbol_table_entry(b);
				name_ast = new Name_Ast(b, local_table->get_symbol_table_entry(b), yylineno);
			}
			else if (global_table->variable_in_symbol_list_check(b))
			{
				// *symbol = global_table->get_symbol_table_entry(b);
				name_ast = new Name_Ast(b, global_table->get_symbol_table_entry(b), yylineno);
			}
			else
			{
				std::cerr << "cs316: Error in line: "<< yylineno<<", " << *yyval.string_value<<" Symbol not found in global_table-\n";
				exit(-1);
			} 

		}
		// Name_Ast* name_ast = new Name_Ast(*$1, *symbol, yylineno);
		// name_ast->set_data_type(void_data_type);	
		$$ = name_ast;
	}
	;

constant  : INTEGER_NUMBER
	{	
		// printf("creating INT ast\n");
		Number_Ast<int>* number_ast = new Number_Ast<int>($1, int_data_type, yylineno);
		number_ast->set_data_type(int_data_type);

		$$ = number_ast;
		// $$->check_ast();

	}
	| DOUBLE_NUMBER
	{	
		// printf("creating FLOAT ast\n");
		Number_Ast<double>* number_ast = new Number_Ast<double>($1, double_data_type, yylineno);
		number_ast->set_data_type(double_data_type);
		$$ = number_ast;
		// $$->check_ast();

	}
	;


	/*less_equalto,
	less_than,
	greater_than,
	greater_equalto,
	equalto,
	not_equalto*/


conditional_statement: 	expression LESS_THAN_EQUAL expression 
					{
						// printf("HERE LESS_THAN_EQUAL");

						Relational_Expr_Ast* relational_expr_ast = new Relational_Expr_Ast($1, less_equalto, $3,yylineno);
						$$ = relational_expr_ast;
					}
					|  	expression LESS_THAN expression
					{
						Relational_Expr_Ast* relational_expr_ast = new Relational_Expr_Ast($1, less_than, $3,yylineno);
						$$ = relational_expr_ast;
					}
					|  	expression GREATER_THAN expression 
					{
						Relational_Expr_Ast* relational_expr_ast = new Relational_Expr_Ast($1, greater_than, $3,yylineno);
						$$ = relational_expr_ast;
					}
					|	expression GREATER_THAN_EQUAL expression 
					{
						Relational_Expr_Ast* relational_expr_ast = new Relational_Expr_Ast($1, greater_equalto, $3,yylineno);
						$$ = relational_expr_ast;
					}
					|	expression EQUAL expression
					{
						Relational_Expr_Ast* relational_expr_ast = new Relational_Expr_Ast($1, equalto, $3,yylineno);
						$$ = relational_expr_ast;
					}
					|	expression NOT_EQUAL expression 
					{
						Relational_Expr_Ast* relational_expr_ast = new Relational_Expr_Ast($1, not_equalto, $3,yylineno);
						$$ = relational_expr_ast;
					}
					| 	conditional_statement OR conditional_statement 
					{
						Logical_Expr_Ast* logical_expr_ast = new Logical_Expr_Ast($1, _logical_or, $3, yylineno);
						logical_expr_ast->set_data_type(void_data_type);
						$$ = logical_expr_ast;
					}
					|	conditional_statement AND conditional_statement
					{
						Logical_Expr_Ast* logical_expr_ast = new Logical_Expr_Ast($1, _logical_and, $3, yylineno);
						logical_expr_ast->set_data_type(void_data_type);
						$$ = logical_expr_ast;
					}
					|	NOT conditional_statement 
					{
						Logical_Expr_Ast* logical_expr_ast = new Logical_Expr_Ast(NULL, _logical_not, $2, yylineno);
						logical_expr_ast->set_data_type(void_data_type);
						$$ = logical_expr_ast;
					}
					|	'(' conditional_statement ')'
					{
						$$ = $2;
					}


if_statement : IF '(' conditional_statement ')' 
			'{'
				declaration_list_loop
			'}'
			else_statement
			{
				Selection_Statement_Ast* if_statement_exp = new Selection_Statement_Ast($3, $6, $8, yylineno);
				$$ = if_statement_exp;
				/*{
					code
				} */

			}
			|
			IF '(' conditional_statement ')' 
			program_statements
			else_statement
			{
				Selection_Statement_Ast* if_statement_exp = new Selection_Statement_Ast($3, $5, $6, yylineno);
				$$ = if_statement_exp;
				/*{
					code
				} */

			}

			;

/* else_if_statements: ELSE IF conditional_statement
// 					'{'
// 						declaration_list
// 					'}'
// 					else_if_statements
// 					|
 					;
 					*/

else_statement 	:	ELSE if_statement
					{
						$$ = $2;
					}
					| 
					ELSE 
					'{'
						declaration_list_loop
					'}'
					{
						$$ = $3;
					}
					|
					ELSE 
					program_statements
					{
						$$ = $2;
					}
					|
					{
						$$ = NULL;
					}
					;



while_statement:	WHILE '(' conditional_statement ')'
					'{'
						declaration_list_loop
					'}'
					{
						Iteration_Statement_Ast *while_stat = new Iteration_Statement_Ast($3, $6, yylineno, false);
						$$ = while_stat;
					}
					|
					WHILE '(' conditional_statement ')'
					program_statements
					{
						Iteration_Statement_Ast *while_stat = new Iteration_Statement_Ast($3, $5, yylineno, false);
						$$ = while_stat;
					}

					;

do_while_statement:	DO 
					'{'
						declaration_list_loop
					'}'
					WHILE '(' conditional_statement ')' ';'
					{
						Iteration_Statement_Ast *while_stat = new Iteration_Statement_Ast($7, $3, yylineno, true);
						$$ = while_stat;
					}
					|
					DO 
					program_statements
					WHILE '(' conditional_statement ')' ';'
					{
						Iteration_Statement_Ast *while_stat = new Iteration_Statement_Ast($5, $2, yylineno, true);
						$$ = while_stat;
					}
					;

ternary_operator:	conditional_statement '?' expression ':' expression 
					{
						Conditional_Expression_Ast *cond_expr_ast = new Conditional_Expression_Ast($1, $3, $5, yylineno);
						$$ = cond_expr_ast;
					}

program_statements : if_statement
					{
						$$ = $1;
					}
					| while_statement
					{
						$$ = $1;
					}
					| do_while_statement
					{
						$$ = $1;
					}
					| ternary_operator
					{
						$$ = $1;
					}
					| assignment_statement
					{
						$$ = $1;
					}
					;

%%


void yyerror( char * s){
	fprintf(stderr,"cs316: Error in line: %d, %s\n", yylineno,s);
	exit(-1);
}