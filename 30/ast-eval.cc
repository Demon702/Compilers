#include "ast.hh"
#include <stdlib.h>
template class Number_Ast<double>;
template class Number_Ast<int>;

// =============================================
// Ast
// =============================================



Eval_Result & Ast::get_value_of_evaluation(Local_Environment & eval_env){
}

void Ast::set_value_of_evaluation(Local_Environment & eval_env, Eval_Result & result){
	return;
}
void Ast::print_value(Local_Environment & eval_env, ostream & file_buffer)
{
	// Eval_Result & eval = rhs->evaluate(eval_env , file_buffer);
	// lhs->set_value_of_evaluation(eval_env, eval);
}


Eval_Result & Assignment_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	// Eval_Result eval-result = new Eval_Result();
	// return eval-result;

	Eval_Result & eval = rhs->evaluate(eval_env , file_buffer);
	lhs->set_value_of_evaluation(eval_env, eval);

	this->print(file_buffer);
	file_buffer <<endl<< VAR_SPACE<< lhs->get_symbol_entry().get_variable_name() << " : ";
	if (eval.get_result_enum() ==int_result)
		file_buffer << eval.get_int_value();
	else if (eval.get_result_enum() ==double_result)
		file_buffer << eval.get_double_value();

	file_buffer << endl<<endl;
}

Eval_Result & Name_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	// Eval_Result eval-result = new Eval_Result();
	// return eval-result;	
	// variable_name = this->get_symbol_entry().get_variable_name();
	// if (eval_env.is_variable_defined(variable_name))
	// {
		
	// 	return eval_env.get_variable_value(variable_name);
		
	// }

	string variable_name = variable_symbol_entry->get_variable_name();
	// return *eval_env.get_variable_value(variable_name);
	if (eval_env.does_variable_exist(variable_name))
		return *eval_env.get_variable_value(variable_name);
	else return *(interpreter_global_table.get_variable_value(variable_name));

}

void Name_Ast:: print_value(Local_Environment & eval_env, ostream & file_buffer)
{
	// file_buffer << "Name_Ast";	
}

Eval_Result & Name_Ast:: get_value_of_evaluation(Local_Environment & eval_env)
{
	string variable_name = variable_symbol_entry->get_variable_name();
	if (eval_env.does_variable_exist(variable_name))
		return *eval_env.get_variable_value(variable_name);
	else return *(interpreter_global_table.get_variable_value(variable_name));
}

void Name_Ast::set_value_of_evaluation(Local_Environment & eval_env, Eval_Result & result)
{
	string variable_name = variable_symbol_entry->get_variable_name();
	// cout << variable_name<< endl;
	if (eval_env.does_variable_exist(variable_name))
		eval_env.put_variable_value(result, variable_name);
	else interpreter_global_table.put_variable_value(result, variable_name);
}



template <typename T>
Eval_Result & Number_Ast<T>::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	// Eval_Result eval-result = new Eval_Result();
	// return eval-result;	
	// Eval_Result & eval;

	if (this->node_data_type == int_data_type)
	{
		Eval_Result &eval = *new Eval_Result_Value_Int();
		eval.set_variable_status(true);
		eval.set_value(constant);
		// printf("Number_Ast = %d\n",eval.get_int_value());
		return eval;
	}
	else if (this->node_data_type == double_data_type)
	{
		Eval_Result &eval = *new Eval_Result_Value_Double();
		eval.set_variable_status(true);
		eval.set_value(constant);
		// printf("Number_Ast = %d\n",eval.get_double_value());
		return eval;
	}


}

Eval_Result & Plus_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	// Eval_Result eval-result = new Eval_Result();
	// return eval-result;	

	Eval_Result & eval1 = lhs->evaluate(eval_env , file_buffer);
	Eval_Result & eval2 = rhs->evaluate(eval_env , file_buffer);


	if (this->node_data_type == int_data_type)
	{
		Eval_Result & eval3 = *new Eval_Result_Value_Int();
		eval3.set_variable_status(true);
		eval3.set_value(eval1.get_int_value() + eval2.get_int_value());
		return eval3;
	}
	else if (this->node_data_type == double_data_type)
	{
		Eval_Result & eval3 = *new Eval_Result_Value_Double();
		eval3.set_variable_status(true);
		eval3.set_value(eval1.get_double_value() + eval2.get_double_value());
		return eval3;
	
	}


}
Eval_Result & Minus_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	// Eval_Result eval-result = new Eval_Result();
	// return eval-result;	
	Eval_Result & eval1 = lhs->evaluate(eval_env , file_buffer);
	Eval_Result & eval2 = rhs->evaluate(eval_env , file_buffer);

	if (this->node_data_type == int_data_type)
	{
		Eval_Result & eval3 = *new Eval_Result_Value_Int();
		eval3.set_variable_status(true);
		eval3.set_value(eval1.get_int_value() - eval2.get_int_value());
		return eval3;
	}
	else if (this->node_data_type == double_data_type)
	{
		Eval_Result & eval3 = *new Eval_Result_Value_Double();
		eval3.set_variable_status(true);
		eval3.set_value(eval1.get_double_value() - eval2.get_double_value());
		return eval3;
	
	}
}
Eval_Result & Divide_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	Eval_Result & eval1 = lhs->evaluate(eval_env , file_buffer);
	Eval_Result & eval2 = rhs->evaluate(eval_env , file_buffer);


	if (this->node_data_type == int_data_type)
	{
		Eval_Result & eval3 = *new Eval_Result_Value_Int();
		eval3.set_variable_status(true);
		if (eval2.get_int_value() == 0)
		{
			printf("CS316: error: Divide by zero error\n");
			exit(-1);
		}
		eval3.set_value(eval1.get_int_value() / eval2.get_int_value());
		return eval3;
	}
	else if (this->node_data_type == double_data_type)
	{
		Eval_Result & eval3 = *new Eval_Result_Value_Double();
		eval3.set_variable_status(true);
		if (eval2.get_double_value() == 0.0)
		{
			printf("CS316: error: Divide by zero error\n");
			exit(-1);
		}
		eval3.set_value(eval1.get_double_value() / eval2.get_double_value());
		return eval3;	
	}

}
Eval_Result & Mult_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	Eval_Result & eval1 = lhs->evaluate(eval_env , file_buffer);
	Eval_Result & eval2 = rhs->evaluate(eval_env , file_buffer);

	if (this->node_data_type == int_data_type)
	{
		Eval_Result & eval3 = *new Eval_Result_Value_Int();
		eval3.set_variable_status(true);
		eval3.set_value(eval1.get_int_value() * eval2.get_int_value());
		return eval3;
	}
	else if (this->node_data_type == double_data_type)
	{
		Eval_Result & eval3 = *new Eval_Result_Value_Double();
		eval3.set_variable_status(true);
		eval3.set_value(eval1.get_double_value() * eval2.get_double_value());
		return eval3;
	
	}
}
Eval_Result & UMinus_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	Eval_Result & eval1 = lhs->evaluate(eval_env , file_buffer);
	// Eval_Result & eval3;

	if (this->node_data_type == int_data_type)
	{
		Eval_Result & eval3 = *new Eval_Result_Value_Int();
		eval3.set_variable_status(true);
		eval3.set_value(- eval1.get_int_value());
		return eval3;	
	}
	else if (this->node_data_type == double_data_type)
	{
		Eval_Result & eval3 = *new Eval_Result_Value_Double();
		eval3.set_variable_status(true);
		eval3.set_value(-eval1.get_double_value());
		return eval3;	
	}

}


Eval_Result & Conditional_Expression_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	// Eval_Result eval-result = new Eval_Result();
	// return eval-result;	
	// Eval_Result & eval = rhs->evaluate(eval_env , file_buffer);
	// lhs->set_value_of_evaluation(eval_env, eval);


	// this->print(file_buffer);
	// file_buffer <<endl<< lhs->get_symbol_entry().get_variable_name() << " : ";
	// if (eval.get_result_enum() ==int_result)
	// 	file_buffer << eval.get_int_value();
	// else if (eval.get_result_enum() ==double_result)
	// 	file_buffer << eval.get_double_value();

	// file_buffer << endl;
	if (cond->evaluate(eval_env, file_buffer).get_int_value()) 
		return lhs->evaluate(eval_env,file_buffer);
	else return rhs->evaluate(eval_env,file_buffer);
}



Eval_Result & Relational_Expr_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	// Eval_Result eval-result = new Eval_Result();
	// return eval-result;	

	Eval_Result & eval1 = lhs_condition->evaluate(eval_env , file_buffer);
	Eval_Result & eval2 = rhs_condition->evaluate(eval_env , file_buffer);

	// cout<< "entered relational_expr\n";
	if (eval1.get_result_enum() == int_result)
	{
		Eval_Result & eval3 = *new Eval_Result_Value_Int();
		eval3.set_variable_status(true);

		switch(rel_op) { 
	    case less_equalto: 
			eval3.set_value((int)(eval1.get_int_value() <= eval2.get_int_value()));
	        break; 
	    case less_than: 
			eval3.set_value((int)(eval1.get_int_value() < eval2.get_int_value()));
	        break;
	    case greater_than: 
			eval3.set_value((int)(eval1.get_int_value() > eval2.get_int_value()));
			// cout<<"entered here\n";
	        break; 
	    case greater_equalto: 
			eval3.set_value((int)(eval1.get_int_value() >= eval2.get_int_value()));
	        break;
	    case equalto: 
			eval3.set_value((int)(eval1.get_int_value() == eval2.get_int_value()));
	        break; 
	    case not_equalto: 
			eval3.set_value((int)(eval1.get_int_value() != eval2.get_int_value()));
	        break; 
	}

		// eval3.set_value(eval1.get_int_value() + eval2.get_int_value());
		return eval3;
	}
	else if (eval1.get_result_enum() == double_result)
	{
		Eval_Result & eval3 = *new Eval_Result_Value_Int();
		eval3.set_variable_status(true);
		switch(rel_op) { 
	    case less_equalto: 
			eval3.set_value((int)(eval1.get_double_value() <= eval2.get_double_value()));
	        break; 
	    case less_than: 
			eval3.set_value((int)(eval1.get_double_value() < eval2.get_double_value()));
	        break;
	    case greater_than: 
			eval3.set_value((int)(eval1.get_double_value() > eval2.get_double_value()));
	        break; 
	    case greater_equalto: 
			eval3.set_value((int)(eval1.get_double_value() >= eval2.get_double_value()));
	        break;
	    case equalto: 
			eval3.set_value((int)(eval1.get_double_value() == eval2.get_double_value()));
	        break; 
	    case not_equalto: 
			eval3.set_value((int)(eval1.get_double_value() != eval2.get_double_value()));
	        break; 
		return eval3;
	
	}
}
}


Eval_Result & Logical_Expr_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	// Eval_Result eval-result = new Eval_Result();
	// return eval-result;
	
	switch(bool_op) { 
	    case _logical_not: 
	    {
	        Eval_Result & eval2 = rhs_op->evaluate(eval_env , file_buffer);
	        Eval_Result & eval3 = *new Eval_Result_Value_Int();
	        eval3.set_variable_status(true);
	        eval3.set_value((int)(!eval2.get_int_value()));
	        return eval3; 
	    }
	        break; 

	    case _logical_or:
	    { 
	        Eval_Result & eval1 = lhs_op->evaluate(eval_env , file_buffer);
			Eval_Result & eval2 = rhs_op->evaluate(eval_env , file_buffer);
			Eval_Result & eval3 = *new Eval_Result_Value_Int();
			eval3.set_variable_status(true);
	        eval3.set_value((int)(eval1.get_int_value() || eval2.get_int_value()));
	        return eval3; 
	    }

	        break;
	    case _logical_and: 
	    {
	        Eval_Result & eval1 = lhs_op->evaluate(eval_env , file_buffer);
			Eval_Result & eval2 = rhs_op->evaluate(eval_env , file_buffer);
			Eval_Result & eval3 = *new Eval_Result_Value_Int();
			eval3.set_variable_status(true);
	        eval3.set_value((int)(eval1.get_int_value() && eval2.get_int_value()));
	        return eval3; 

	    }
	        break; 
	}





}

Eval_Result & Selection_Statement_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	if (cond->evaluate(eval_env, file_buffer).get_int_value())
	{
		// cout<< "entered if"<<endl;
		then_part->evaluate(eval_env, file_buffer);
	}
	else if (else_part!= NULL)
	{
		else_part->evaluate(eval_env, file_buffer);
	}
}

Eval_Result & Iteration_Statement_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	// Eval_Result eval-result = new Eval_Result();
	// return eval-result;	
	if (is_do_form)
	{
		do
		{
			body->evaluate(eval_env, file_buffer);
		}
		while(cond->evaluate(eval_env, file_buffer).get_int_value());
	}
	else
	{
		while(cond->evaluate(eval_env, file_buffer).get_int_value())
		{
			body->evaluate(eval_env, file_buffer);
		}
	}
}


Eval_Result & Sequence_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	// Eval_Result eval-result = new Eval_Result();
	// return eval-result;
	for(list<Ast *>::iterator it=statement_list.begin(); it != statement_list.end(); ++it){
		(*it)->evaluate(eval_env, file_buffer);
		
	}	
}


Eval_Result & Call_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer)
{

}


Eval_Result & Return_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer)
{
	
}