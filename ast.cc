#include "ast.hh"
#include <stdlib.h>
template class Number_Ast<double>;
template class Number_Ast<int>;

int Ast::labelCounter;

Ast::Ast()
{
	ast_num_child = zero_arity;
	node_data_type = void_data_type;
}

Ast::~Ast() {}
Data_Type Ast::get_data_type()
{
	return node_data_type;
}

void Ast::set_data_type(Data_Type dt)
{
	node_data_type = dt;
}

bool Ast::is_value_zero() { return false;}

bool Ast::check_ast() {}

Symbol_Table_Entry & Ast::get_symbol_entry() {}

Assignment_Ast::Assignment_Ast(Ast * temp_lhs, Ast * temp_rhs, int line)
{	
	// cout<< "Asg: " << line << endl;

	lhs = temp_lhs;
	rhs = temp_rhs;
	lineno = line;
	ast_num_child = binary_arity;
	if (lhs->is_value_zero () == 1) rhs->is_value_zero() == 1;
	if (lhs->get_data_type()==rhs->get_data_type())
		node_data_type = lhs->get_data_type();
	// printf("Assignment Data Type %d\n", this->get_data_type());
}
Assignment_Ast::~Assignment_Ast()
{
	delete lhs;
	delete rhs;
}

bool Assignment_Ast::check_ast()
{
	if (lhs->get_data_type()!=rhs->get_data_type())
	{
		printf("CS316 error: Line: %d: Assignment statement data type not compatible\n",lineno);
		exit(-1);
	}
}

void Assignment_Ast::print(ostream & file_buffer)
{	
	//  ++;
	file_buffer << "\n"<< AST_SPACE<<"Asgn:\n" << AST_NODE_SPACE;

	// for (int i = 0; i< ; i++)
	// 	file_buffer << AST_SP               ACE;
	file_buffer<< "LHS (";
	lhs->print(file_buffer); 
	file_buffer<< ")\n" << AST_NODE_SPACE;
	// for (int i = 0; i< ; i++)
	// 	file_buffer << AST_SPACE;
	file_buffer<<"RHS (";
	rhs->print(file_buffer) ;
	file_buffer<<")";
	// file_buffer << "Asgn:\n LHS (" <<
	// --;
}


Name_Ast::Name_Ast(string & name, Symbol_Table_Entry & var_entry, int line)
{
	// cout<< "name: " << name << line << endl;
	node_data_type = var_entry.get_data_type();
	lineno = line;
	variable_symbol_entry = &var_entry;
	ast_num_child = unary_arity;
}

void Name_Ast::print(ostream & file_buffer){
	// char temp[100];
	// strcpy(temp, "Name : ")
	// strcat(temp, variable_symbol_entry->get_variable_name())
	// printf("%s", variable_symbol_entry->get_variable_name());
	// cout << variable_symbol_entry->get_variable_name();
	// cout<< "Reached Here\n";
	file_buffer << "Name : "<< variable_symbol_entry->get_variable_name();
	// fputs(variable_symbol_entry->get_variable_name(), file_buffer)
}



Name_Ast::~Name_Ast()
{
	delete variable_symbol_entry;
}

Data_Type Name_Ast::get_data_type()
{
	return node_data_type;
}

Symbol_Table_Entry & Name_Ast::get_symbol_entry()
{
	return *variable_symbol_entry;
}

void Name_Ast::set_data_type(Data_Type dt)
{
	node_data_type = dt;
}


// =============================================
// Number_ast
// =============================================

template<typename T>
Number_Ast<T>::Number_Ast(T number, Data_Type constant_data_type, int line)
{
	constant = number;
	node_data_type = constant_data_type;
	lineno = line;
	ast_num_child = unary_arity;

}
template <typename T>
Number_Ast<T>::~Number_Ast()
{

}

template <typename T>
Data_Type Number_Ast<T>::get_data_type()
{
	return node_data_type;
}
template <typename T>
void Number_Ast<T>::set_data_type(Data_Type dt)
{
	node_data_type = dt;
}

template <typename T>
bool Number_Ast<T>::is_value_zero()
{
	return (constant == 0)|| (constant == 0.0);
}

template <typename T>
void Number_Ast<T>::print(ostream & file_buffer){
	file_buffer << "Num : "<< constant;
}


// =============================================
// Arithmetic_Expr_Ast
// =============================================

// Arithmetic_Expr_Ast::Arithmetic_Expr_Ast() {}
// Arithmetic_Expr_Ast::~Arithmetic_Expr_Ast() 
// {
// 	delete lhs;
// 	delete rhs;
// }

Data_Type Arithmetic_Expr_Ast:: get_data_type()
{
	return node_data_type;
}

void Arithmetic_Expr_Ast::set_data_type(Data_Type dt)
{
	node_data_type = dt;	
}

bool Arithmetic_Expr_Ast::check_ast()
{
	if (rhs!=NULL)
	{
		if (lhs->get_data_type()!=rhs->get_data_type())
		{
			// printf("CS316 error: Both sides of the arithmetic operator are not same\n");
			if (lhs->get_data_type()==int_data_type && rhs->is_value_zero())
			{
				this->set_data_type(int_data_type);
				// printf("1\n");
			}
			else if (lhs->get_data_type() == double_data_type && rhs->is_value_zero())
			{
				this->set_data_type(double_data_type);
				// printf("2\n");
			}
			else if (lhs->is_value_zero() && !rhs->is_value_zero() && rhs->get_data_type()==double_data_type)
			{
				this->set_data_type(double_data_type);
				// printf("3\n");
			}
			else if (rhs->is_value_zero() && !lhs->is_value_zero() && lhs->get_data_type()==double_data_type)
			{
				this->set_data_type(double_data_type);
				// printf("4\n");
			}
			else
			{	
				printf("CS316 error: Line: %d: Arithmetic statement data type not compatible\n",lineno);
				exit(-1);
			}
		}
	}

}



// =============================================
// Plus_ast
// =============================================
Plus_Ast::Plus_Ast(Ast * l, Ast * r, int line)
{
 	lhs = l;
	rhs = r;
	lineno = line;
	ast_num_child = binary_arity;
	if (lhs->get_data_type()==rhs->get_data_type())
		node_data_type = lhs->get_data_type();
	// printf("Plus Daratype %d\n", this->get_data_type());
}
// typename
// Plus_Ast::~Plus_Ast() {}

void Plus_Ast::print(ostream & file_buffer){
	file_buffer << "\n"<< AST_NODE_SPACE;

	file_buffer << "Arith: PLUS\n" << AST_SUB_NODE_SPACE;
	file_buffer<<"LHS (";
	lhs->print(file_buffer); 
	file_buffer<< ")\n" << AST_SUB_NODE_SPACE;
	file_buffer<<"RHS (";
	rhs->print(file_buffer);
	file_buffer<<")";
	// --;
}

// =============================================
// Minus_ast
// =============================================
Minus_Ast::Minus_Ast(Ast * l, Ast * r, int line)
{
	lhs = l;
	rhs = r;
	lineno = line;
	ast_num_child = binary_arity;
	if (lhs->get_data_type()==rhs->get_data_type())
		node_data_type = lhs->get_data_type();
	// printf("Minus data type %d\n", this->get_data_type());
}

// Minus_Ast::~Minus_Ast() {}

void Minus_Ast::print(ostream & file_buffer){
	file_buffer << "\n"<< AST_NODE_SPACE;

	file_buffer << "Arith: MINUS\n";
	file_buffer << AST_SUB_NODE_SPACE<<"LHS (";
	lhs->print(file_buffer); 
	file_buffer<< ")\n" << AST_SUB_NODE_SPACE;
	file_buffer<<"RHS (";
	rhs->print(file_buffer) ;
	file_buffer<<")";
}

// =============================================
// Divide_Ast
// =============================================
Divide_Ast::Divide_Ast(Ast * l, Ast * r, int line)
{
	lhs = l;
	rhs = r;
	lineno = line;
	ast_num_child = binary_arity;
	if (lhs->get_data_type()==rhs->get_data_type())
		node_data_type = lhs->get_data_type();
	// printf("Divide Data Type %d\n", this->get_data_type());
}

// Divide_Ast::~Divide_Ast() {}

void Divide_Ast::print(ostream & file_buffer){

	file_buffer << "\n"<< AST_NODE_SPACE;

	file_buffer << "Arith: DIV\n" << AST_SUB_NODE_SPACE;
	file_buffer<<"LHS (";
	lhs->print(file_buffer); 
	file_buffer<< ")\n" << AST_SUB_NODE_SPACE;
	file_buffer<<"RHS (" ;
	rhs->print(file_buffer);
	file_buffer<<")";
}

// =============================================
// Mult_Ast
// =============================================

Mult_Ast::Mult_Ast(Ast * l, Ast * r, int line)
{	
	lhs = l;
	rhs = r;
	lineno = line;
	ast_num_child = binary_arity;
	if (lhs->get_data_type()==rhs->get_data_type())
		node_data_type = lhs->get_data_type();
	// printf("Mult_Ast %d\n", this->get_data_type());
}

// Mult_Ast::~Mult_Ast() {}

void Mult_Ast::print(ostream & file_buffer){

	file_buffer << "\n"<< AST_NODE_SPACE;

	file_buffer << "Arith: MULT\n" << AST_SUB_NODE_SPACE;
	file_buffer<<"LHS (";
	lhs->print(file_buffer);
	file_buffer << ")\n" << AST_SUB_NODE_SPACE;
	file_buffer<<"RHS (";
	rhs->print(file_buffer) ;
	file_buffer<<")";
}

// =============================================
// UMinus_Ast
// =============================================

UMinus_Ast::UMinus_Ast(Ast * l, Ast * r, int line)
{
	lhs = l;
	rhs = r;
	lineno = line;
	ast_num_child = unary_arity;
	node_data_type = lhs->get_data_type();
	// printf("UMinus Data Type %d\n", this->get_data_type());	
}

// UMinus_Ast::~UMinus_Ast() {}
	
void UMinus_Ast::print(ostream & file_buffer)
{
	file_buffer << "\n"<< AST_NODE_SPACE;

	file_buffer << "Arith: UMINUS\n" << AST_SUB_NODE_SPACE;
	file_buffer<<"LHS (";
	lhs->print(file_buffer);
	file_buffer<< ")";
}

// =============================================
// Conditional_Expression_Ast
// =============================================

Conditional_Expression_Ast::Conditional_Expression_Ast(Ast* cond, Ast* l, Ast* r, int line){
	this->cond = cond;
	lhs = l;
	rhs = r;
	lineno = line;
	ast_num_child = ternary_arity;
	if (l->get_data_type() == r->get_data_type())
	{
		node_data_type = l->get_data_type();
	}
	else node_data_type = void_data_type;
}


void Conditional_Expression_Ast::print(ostream & file_buffer){
	file_buffer << "\n"<< AST_SPACE;

	file_buffer << "Cond:\n" << AST_NODE_SPACE << "IF_ELSE";
	// file_buffer <<endl;
	cond->print(file_buffer);
	file_buffer<< endl<<AST_NODE_SPACE<<"LHS (";
	lhs->print(file_buffer);
	file_buffer << ")\n" << AST_NODE_SPACE;
	file_buffer<<"RHS (";
	rhs->print(file_buffer) ;
	file_buffer<<")";

}


// =============================================
// Relational_Expr_Ast
// =============================================


Relational_Expr_Ast::Relational_Expr_Ast(Ast * lhs, Relational_Op rop, Ast * rhs, int line){
	lhs_condition = lhs;
	rhs_condition = rhs;
	this->rel_op = rop;
	lineno = line;
	ast_num_child = ternary_arity;
	if (lhs_condition->get_data_type()==rhs_condition->get_data_type())
		node_data_type = lhs_condition->get_data_type();
}

Data_Type Relational_Expr_Ast::get_data_type(){
	return node_data_type;
}

void Relational_Expr_Ast::set_data_type(Data_Type dt){
	node_data_type = dt;
}

void Relational_Expr_Ast::print(ostream & file_buffer){

	file_buffer <<endl<< AST_NODE_SPACE;
	file_buffer << "Condition: ";

	// less_equalto,
	// less_than,
	// greater_than,
	// greater_equalto,
	// equalto,
	// not_equalto

	switch(rel_op) { 
	    case less_equalto: 
	        file_buffer << "LE" ;
	        break; 
	    case less_than: 
	        file_buffer << "LT" ;
	        break;
	    case greater_than: 
	        file_buffer << "GT" ;
	        break; 
	    case greater_equalto: 
	        file_buffer << "GE" ;
	        break;
	    case equalto: 
	        file_buffer << "EQ" ;
	        break; 
	    case not_equalto: 
	        file_buffer << "NE" ;
	        break; 
	}

	// file_buffer << "\n";

	file_buffer<< endl<<AST_SUB_NODE_SPACE <<"LHS (";
	lhs_condition->print(file_buffer);
	file_buffer << ")\n" << AST_SUB_NODE_SPACE;
	file_buffer<<"RHS (";
	rhs_condition->print(file_buffer) ;
	file_buffer<<")";

}


bool Relational_Expr_Ast::check_ast(){
	if (lhs_condition->get_data_type()!=rhs_condition->get_data_type()){	
		printf("CS316 error: Line: %d: Arithmetic statement data type not compatible\n",lineno);
		exit(-1);
	}
	else return true;
}


// =============================================
// Logical_Expr_Ast
// =============================================


Logical_Expr_Ast::Logical_Expr_Ast(Ast * lhs, Logical_Op bop, Ast * rhs, int line){
	lhs_op = lhs;
	rhs_op = rhs;
	bool_op = bop;
	lineno = line;
	ast_num_child = binary_arity;
	node_data_type = void_data_type;
}



Data_Type Logical_Expr_Ast::get_data_type(){
	return node_data_type;
}

void Logical_Expr_Ast::set_data_type(Data_Type dt){
	node_data_type = dt;
}

bool Logical_Expr_Ast::check_ast(){
	if (lhs_op->get_data_type() != rhs_op->get_data_type()){	
		printf("CS316 error: Line: %d: Logical statement data type not compatible\n",lineno);
		exit(-1);
	}
	else return true;
}


void Logical_Expr_Ast::print(ostream & file_buffer){

	file_buffer <<endl<< AST_NODE_SPACE;
	file_buffer << "Condition: ";

	// _logical_not,
	// _logical_or,
	// _logical_and

	switch(bool_op) { 
	    case _logical_not: 
	        file_buffer << "NOT" ;
	        break; 
	    case _logical_or: 
	        file_buffer << "OR" ;
	        break;
	    case _logical_and: 
	        file_buffer << "AND" ;
	        break; 
	}

	file_buffer << "\n";
	if (lhs_op!= NULL)
	{
		file_buffer<<AST_SUB_NODE_SPACE <<"LHS (";
		lhs_op->print(file_buffer);
		file_buffer << ")\n" ;
	}
	file_buffer<< AST_SUB_NODE_SPACE<<"RHS (";
	// file_buffer << "\n";
	rhs_op->print(file_buffer) ;
	file_buffer<<")";

}


// =============================================
// Selection_Statement_Ast
// =============================================


Selection_Statement_Ast::Selection_Statement_Ast(Ast * cond,Ast* then_part, Ast* else_part, int line){
	this->cond = cond;
	this->then_part = then_part;
	this->else_part = else_part;
	lineno = line;
	ast_num_child = ternary_arity;
	node_data_type = void_data_type;
}


Data_Type Selection_Statement_Ast::get_data_type(){
	return node_data_type;
}

void Selection_Statement_Ast::set_data_type(Data_Type dt){
	node_data_type = dt;
}

bool Selection_Statement_Ast::check_ast(){
	return true;
}

void Selection_Statement_Ast::print(ostream & file_buffer){
	file_buffer << endl<<AST_SPACE;
	file_buffer << "IF : \n"<<AST_SPACE<<"CONDITION (";

	cond->print(file_buffer);
	file_buffer << ")" ;
	file_buffer<< endl<<AST_SPACE<<"THEN (";
	// file_buffer << AST_NODE_SPACE;
	then_part->print(file_buffer);
	file_buffer << ")" ;
	if (else_part != NULL){
		file_buffer<<endl<<AST_SPACE;
		file_buffer<<"ELSE (";
		// file_buffer << AST_NODE_SPACE;
		else_part->print(file_buffer) ;
		file_buffer<<")";
		
	}
}



// =============================================
// Iteration_Statement_Ast
// =============================================


Iteration_Statement_Ast::Iteration_Statement_Ast(Ast * cond, Ast* body, int line, bool do_form){
	this->cond = cond;
	this->body = body;
	this->is_do_form = do_form;
	lineno = line;
	ast_num_child = binary_arity;
	node_data_type = void_data_type;
}


Data_Type Iteration_Statement_Ast::get_data_type(){
	return node_data_type;
}

void Iteration_Statement_Ast::set_data_type(Data_Type dt){
	node_data_type = dt;
}

bool Iteration_Statement_Ast::check_ast(){
	return true;
}


void Iteration_Statement_Ast::print(ostream & file_buffer){

	if(is_do_form){
		file_buffer <<endl<< AST_SPACE;
		file_buffer << "DO (";
		// file_buffer << AST_NODE_SPACE;
		body->print(file_buffer);
		file_buffer << ")\n" ;
		file_buffer<<AST_SPACE<<"WHILE CONDITION (";
		cond->print(file_buffer);
		file_buffer << ")" ;
	}
	else{
		file_buffer <<endl<< AST_SPACE;
		file_buffer << "WHILE : \n"<<AST_SPACE<<"CONDITION (";

		cond->print(file_buffer);
		file_buffer << ")\n" ;
		file_buffer<< AST_SPACE<<"BODY (";
		// file_buffer << AST_NODE_SPACE;
		body->print(file_buffer);
		file_buffer << ")" ;
	}

}


// =============================================
// Sequence_Ast
// =============================================

Sequence_Ast::Sequence_Ast(int line){
	lineno = line;
	// list<Ast *> statement_list = new list<Ast *>();
	// list<Icode_Stmt *> sa_icode_list = new list<I
}

void Sequence_Ast::ast_push_back(Ast * ast){
	statement_list.push_back(ast);
}

void Sequence_Ast::print(ostream & file_buffer){
	file_buffer << endl;	
	file_buffer << AST_NODE_SPACE;


	// file_buffer << statement_list.size();

	for(list<Ast *>::iterator it=statement_list.begin(); it != statement_list.end(); ++it){
		(*it)->print(file_buffer);
		// list<Ast *>::iterator z = it;
		if (++it != statement_list.end()){
			file_buffer << endl;	
			file_buffer << AST_NODE_SPACE;
		}
		it--;
	}
}



// =============================================
// Print_Ast
// =============================================

void  Print_Ast::print(ostream & file_buffer){
	file_buffer << endl;	
	file_buffer << AST_SPACE;

	file_buffer << "Print :\n" << AST_SUB_NODE_SPACE <<"(";

	var->print(file_buffer);
	file_buffer << ")";
}

Print_Ast::Print_Ast(Ast *v, int line){
	var = v;
	lineno = line;
}

Print_Ast::~Print_Ast(){}




///////////////////////////////////////////////////////////////////////////////////
///////////////////////////Call_Ast////////////////////////////////////////////////////////


Call_Ast::Call_Ast(string name, int line)
{
	lineno = line;
	procedure_name = name;
	actual_param_list.clear();
	node_data_type = program_object.get_procedure_prototype(name)->get_return_type();

}
Call_Ast::~Call_Ast(){}

Data_Type Call_Ast::get_data_type()
{
	return node_data_type;
}

void Call_Ast::set_register(Register_Descriptor * reg)
{
	return_value_reg = reg;
}

void Call_Ast::check_actual_formal_param(Symbol_Table & formal_param_list)
{
	list<Symbol_Table_Entry *>::iterator it2 = formal_param_list.get_table().begin();
	for(list<Ast *>::iterator it=actual_param_list.begin(); it != actual_param_list.end(); ++it)
	{
		if (it2== formal_param_list.get_table().end())
		{
			std::cerr << "cs316: Error in line: "<< lineno<<"Parameters incorrect " <<"\n";
			exit(-1);
		}
		if ((*it2)->get_data_type() != (*it)->get_data_type())
		{
			std::cerr << "cs316: Error in line: "<< lineno<<"Parameters incorrect " <<"\n";
			exit(-1);
		}
		it2++;
	}
	if (it2!= formal_param_list.get_table().end())
	{
		std::cerr << "cs316: Error in line: "<< lineno<<"Parameters incorrect " <<"\n";
		exit(-1);
	}
}

void Call_Ast::set_actual_param_list(list<Ast *> & param_list)
{
	actual_param_list.clear();
	for(list<Ast *>::iterator it=param_list.begin(); it != param_list.end(); ++it)
	{
		actual_param_list.push_back(*it);
	}
}

void Call_Ast::print(ostream & file_buffer)
{

	file_buffer << endl;	
	file_buffer << AST_SPACE;
	file_buffer<<"FN CALL: "<<procedure_name<<"(";
	for(list<Ast *>::iterator it=actual_param_list.begin(); it != actual_param_list.end(); ++it)
	{
		file_buffer<<endl;
		// cout<< "Reached in call_ast print\n";
		file_buffer<< AST_NODE_SPACE;
		(*it)->print(file_buffer);
	}
	file_buffer<<")";
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

Return_Ast::Return_Ast(Ast * ret_val, string name, int line)
{
	lineno = line;
	proc_name = name;
	return_value = ret_val;
}

Return_Ast::~Return_Ast(){}

Data_Type Return_Ast::get_data_type()
{
	return node_data_type;
}

void Return_Ast::print(ostream & file_buffer)
{
	file_buffer<<"\n";
	file_buffer<< AST_SPACE<<"RETURN ";
	if (return_value!= NULL)
		return_value->print(file_buffer);
	else
		file_buffer<<"<NOTHING>";
	file_buffer<<"\n";
	

}
