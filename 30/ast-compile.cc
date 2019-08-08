#include "ast.hh"
#include "icode.hh"
#include <string>
template class Number_Ast<double>;
template class Number_Ast<int>;

Code_For_Ast &  Ast::compile(){

}

Code_For_Ast & Ast::compile_and_optimize_ast(Lra_Outcome & lra)
{
	
}

Code_For_Ast & Ast::create_store_stmt(Register_Descriptor * store_register)
{

}

Code_For_Ast &  Assignment_Ast::compile()
{
	Code_For_Ast code_for_ast_rhs = rhs->compile();

	Code_For_Ast* code_for_ast = new Code_For_Ast();

	*code_for_ast = code_for_ast_rhs;
	Register_Descriptor * register_new;
	Mem_Addr_Opd* result = new Mem_Addr_Opd(lhs->get_symbol_entry());
	Register_Addr_Opd* opd1 = new Register_Addr_Opd(code_for_ast_rhs.get_reg());

	
	Move_IC_Stmt* stmt;
	if (lhs->get_data_type() == int_data_type)
	{
		stmt = new Move_IC_Stmt(store,opd1, result);
	}
	else if (lhs->get_data_type() == double_data_type)
	{
		stmt = new Move_IC_Stmt(store_d, opd1, result);
	}

	code_for_ast->append_ics(*stmt);
	code_for_ast_rhs.get_reg()->reset_register_occupied();

	return *code_for_ast;
}


Code_For_Ast & Assignment_Ast::compile_and_optimize_ast(Lra_Outcome & lra)
{

}

Code_For_Ast &  Name_Ast::compile()
{
	Register_Descriptor * register_new;
	Mem_Addr_Opd* opd1 = new Mem_Addr_Opd(*variable_symbol_entry);
	Move_IC_Stmt* stmt;
	if (variable_symbol_entry->get_data_type() == int_data_type)
	{
		register_new = machine_desc_object.get_new_register<int_reg>();
		Register_Addr_Opd* result = new Register_Addr_Opd(register_new);
		stmt = new Move_IC_Stmt(load, opd1, result);
	}
	else if (variable_symbol_entry->get_data_type() == double_data_type)
	{
		register_new = machine_desc_object.get_new_register<float_reg>();
		Register_Addr_Opd* result = new Register_Addr_Opd(register_new);
		stmt = new Move_IC_Stmt(load_d, opd1, result);
	}



	Code_For_Ast* code_for_ast = new Code_For_Ast();

	code_for_ast->append_ics(*stmt);
	code_for_ast->set_reg(register_new);
	return *code_for_ast;

}

Code_For_Ast & Name_Ast::compile_and_optimize_ast(Lra_Outcome & lra)
{

}


Code_For_Ast & Name_Ast::create_store_stmt(Register_Descriptor * store_register)
{

}

template <class T>
Code_For_Ast &  Number_Ast<T>::compile()
{
	Register_Descriptor * register_new;
	Move_IC_Stmt* stmt;
	if (get_data_type() == int_data_type)
	{
		register_new = machine_desc_object.get_new_register<int_reg>();
		Const_Opd<int>* opd1 = new Const_Opd<int>(constant);
		Register_Addr_Opd* result = new Register_Addr_Opd(register_new);
		stmt = new Move_IC_Stmt(imm_load, opd1, result);

	}
	else if (get_data_type() == double_data_type)
	{
		register_new = machine_desc_object.get_new_register<float_reg>();
		Const_Opd<double>* opd1 = new Const_Opd<double>(constant);
		Register_Addr_Opd* result = new Register_Addr_Opd(register_new);
		stmt = new Move_IC_Stmt(imm_load_d, opd1, result);
		
	}

	Code_For_Ast* code_for_ast = new Code_For_Ast();

	code_for_ast->append_ics(*stmt);
	code_for_ast->set_reg(register_new);
	return *code_for_ast;



}

template <class T>
Code_For_Ast & Number_Ast<T>::compile_and_optimize_ast(Lra_Outcome & lra)
{
	
}

Code_For_Ast &  Arithmetic_Expr_Ast::compile()
{


}


Code_For_Ast & Arithmetic_Expr_Ast::compile_and_optimize_ast(Lra_Outcome & lra)
{

}

Code_For_Ast &  Plus_Ast::compile()
{
	Code_For_Ast code_for_ast_lhs = lhs->compile();
	Code_For_Ast code_for_ast_rhs = rhs->compile();

	Code_For_Ast* code_for_ast = new Code_For_Ast();
	list<Icode_Stmt *> rhs_list = code_for_ast_rhs.get_icode_list();
	*code_for_ast = code_for_ast_lhs;
	for(list<Icode_Stmt *>::iterator it=rhs_list.begin(); it != rhs_list.end(); ++it)
	{
		
		code_for_ast->append_ics(**it);
		
	}
	Register_Addr_Opd* opd1 = new Register_Addr_Opd(code_for_ast_lhs.get_reg());
	Register_Addr_Opd* opd2 = new Register_Addr_Opd(code_for_ast_rhs.get_reg());
	Compute_IC_Stmt* stmt;
	Register_Descriptor * register_new;
	if (get_data_type() == int_data_type)
	{
		register_new = machine_desc_object.get_new_register<int_reg>();
		Register_Addr_Opd* result = new Register_Addr_Opd(register_new);
		stmt = new Compute_IC_Stmt(add,opd1,opd2,result);
	}

	else if (get_data_type() == double_data_type)
	{
		register_new = machine_desc_object.get_new_register<float_reg>();
		Register_Addr_Opd* result = new Register_Addr_Opd(register_new);
		stmt = new Compute_IC_Stmt(add_d,opd1,opd2,result);
	}

	code_for_ast->append_ics(*stmt);
	code_for_ast->set_reg(register_new);
	code_for_ast_lhs.get_reg()->reset_register_occupied();
	code_for_ast_rhs.get_reg()->reset_register_occupied();
	return *code_for_ast;
}

Code_For_Ast & Plus_Ast::compile_and_optimize_ast(Lra_Outcome & lra)
{

}


Code_For_Ast &  Minus_Ast::compile()
{
	Code_For_Ast code_for_ast_lhs = lhs->compile();
	Code_For_Ast code_for_ast_rhs = rhs->compile();

	Code_For_Ast * code_for_ast = new Code_For_Ast();
	list<Icode_Stmt *> rhs_list = code_for_ast_rhs.get_icode_list();
	*code_for_ast = code_for_ast_lhs;
	for(list<Icode_Stmt *>::iterator it=rhs_list.begin(); it != rhs_list.end(); ++it)
	{
		
		code_for_ast->append_ics(**it);
		
	}
	Register_Addr_Opd* opd1 = new Register_Addr_Opd(code_for_ast_lhs.get_reg());
	Register_Addr_Opd* opd2 = new Register_Addr_Opd(code_for_ast_rhs.get_reg());
	Compute_IC_Stmt* stmt;
	Register_Descriptor * register_new;
	if (get_data_type() == int_data_type)
	{
		register_new = machine_desc_object.get_new_register<int_reg>();
		Register_Addr_Opd* result = new Register_Addr_Opd(register_new);
		stmt = new Compute_IC_Stmt(sub,opd1,opd2,result);
	}

	else if (get_data_type() == double_data_type)
	{
		register_new = machine_desc_object.get_new_register<float_reg>();
		Register_Addr_Opd* result = new Register_Addr_Opd(register_new);
		stmt = new Compute_IC_Stmt(sub_d,opd1,opd2,result);
	}

	code_for_ast->append_ics(*stmt);
	code_for_ast->set_reg(register_new);
	code_for_ast_lhs.get_reg()->reset_register_occupied();
	code_for_ast_rhs.get_reg()->reset_register_occupied();
	return *code_for_ast;

}


Code_For_Ast & Minus_Ast::compile_and_optimize_ast(Lra_Outcome & lra)
{

}

Code_For_Ast &  Divide_Ast::compile()
{
	Code_For_Ast code_for_ast_lhs = lhs->compile();
	Code_For_Ast code_for_ast_rhs = rhs->compile();

	Code_For_Ast *code_for_ast = new Code_For_Ast();
	list<Icode_Stmt *> rhs_list = code_for_ast_rhs.get_icode_list();
	*code_for_ast = code_for_ast_lhs;
	for(list<Icode_Stmt *>::iterator it=rhs_list.begin(); it != rhs_list.end(); ++it)
	{
		
		code_for_ast->append_ics(**it);
		
	}
	Register_Addr_Opd* opd1 = new Register_Addr_Opd(code_for_ast_lhs.get_reg());
	Register_Addr_Opd* opd2 = new Register_Addr_Opd(code_for_ast_rhs.get_reg());
	Compute_IC_Stmt* stmt;
	Register_Descriptor * register_new;
	if (get_data_type() == int_data_type)
	{
		register_new = machine_desc_object.get_new_register<int_reg>();
		Register_Addr_Opd* result = new Register_Addr_Opd(register_new);
		stmt = new Compute_IC_Stmt(divd,opd1,opd2,result);
	}

	else if (get_data_type() == double_data_type)
	{
		register_new = machine_desc_object.get_new_register<float_reg>();
		Register_Addr_Opd* result = new Register_Addr_Opd(register_new);
		stmt = new Compute_IC_Stmt(div_d,opd1,opd2,result);
	}

	code_for_ast->append_ics(*stmt);
	code_for_ast->set_reg(register_new);
	code_for_ast_lhs.get_reg()->reset_register_occupied();
	code_for_ast_rhs.get_reg()->reset_register_occupied();
	return *code_for_ast;
}

Code_For_Ast & Divide_Ast::compile_and_optimize_ast(Lra_Outcome & lra)
{

}

Code_For_Ast &  Mult_Ast::compile()
{
	Code_For_Ast code_for_ast_lhs = lhs->compile();
	Code_For_Ast code_for_ast_rhs = rhs->compile();

	Code_For_Ast* code_for_ast = new Code_For_Ast();
	list<Icode_Stmt *> rhs_list = code_for_ast_rhs.get_icode_list();
	*code_for_ast = code_for_ast_lhs;
	for(list<Icode_Stmt *>::iterator it=rhs_list.begin(); it != rhs_list.end(); ++it)
	{
		
		code_for_ast->append_ics(**it);
		
	}
	Register_Addr_Opd* opd1 = new Register_Addr_Opd(code_for_ast_lhs.get_reg());
	Register_Addr_Opd* opd2 = new Register_Addr_Opd(code_for_ast_rhs.get_reg());
	Compute_IC_Stmt* stmt;
	Register_Descriptor * register_new;
	if (get_data_type() == int_data_type)
	{
		register_new = machine_desc_object.get_new_register<int_reg>();
		Register_Addr_Opd* result = new Register_Addr_Opd(register_new);
		stmt = new Compute_IC_Stmt(mult,opd1,opd2,result);
	}

	else if (get_data_type() == double_data_type)
	{
		register_new = machine_desc_object.get_new_register<float_reg>();
		Register_Addr_Opd* result = new Register_Addr_Opd(register_new);
		stmt = new Compute_IC_Stmt(mult_d,opd1,opd2,result);
	}

	code_for_ast->append_ics(*stmt);
	code_for_ast->set_reg(register_new);
	code_for_ast_lhs.get_reg()->reset_register_occupied();
	code_for_ast_rhs.get_reg()->reset_register_occupied();
	return *code_for_ast;
}


Code_For_Ast & Mult_Ast::compile_and_optimize_ast(Lra_Outcome & lra)
{

}


Code_For_Ast &  UMinus_Ast::compile()
{
	Code_For_Ast code_for_ast_lhs = lhs->compile();

	Code_For_Ast* code_for_ast = new Code_For_Ast();

	*code_for_ast = code_for_ast_lhs;
	Register_Addr_Opd* opd1 = new Register_Addr_Opd(code_for_ast_lhs.get_reg());

	
	Move_IC_Stmt* stmt;
	Register_Descriptor * register_new;
	if (lhs->get_data_type() == int_data_type)
	{
		register_new = machine_desc_object.get_new_register<int_reg>();
		Register_Addr_Opd* result = new Register_Addr_Opd(register_new);
		stmt = new Move_IC_Stmt(uminus, opd1, result);
	}
	else if (lhs->get_data_type() == double_data_type)
	{
		register_new = machine_desc_object.get_new_register<float_reg>();
		Register_Addr_Opd* result = new Register_Addr_Opd(register_new);
		stmt = new Move_IC_Stmt(uminus_d, opd1, result);
	}

	code_for_ast->append_ics(*stmt);
	code_for_ast->set_reg(register_new);
	code_for_ast_lhs.get_reg()->reset_register_occupied();

	return *code_for_ast;


}

Code_For_Ast & UMinus_Ast::compile_and_optimize_ast(Lra_Outcome & lra)
{

}

Code_For_Ast &  Conditional_Expression_Ast::compile()
{
	string label_string1 = get_new_label();
	string label_string2 = get_new_label();
	Code_For_Ast code_for_ast_cond = cond->compile();
	Code_For_Ast* code_for_ast = new Code_For_Ast();
	*code_for_ast = code_for_ast_cond;

	Register_Addr_Opd* opd1 = new Register_Addr_Opd(code_for_ast_cond.get_reg());

	////////////////////////
	Register_Addr_Opd* opd2 = new Register_Addr_Opd(code_for_ast_cond.get_reg());

	Icode_Stmt* cond_stmt;
	if (cond->get_data_type() == double_data_type)
	{
		cond_stmt = new Label_IC_Stmt(bc1t, label_string1);
		machine_desc_object.get_new_register<int_reg>()->set_register_occupied();
	}
	else
	{
		////////////////////////
		cond_stmt = new Control_Flow_IC_Stmt(beq, opd1, opd2, label_string1,0);
	}	
	code_for_ast->append_ics(*cond_stmt);


	Code_For_Ast code_for_ast_lhs = lhs->compile();
	Code_For_Ast code_for_ast_rhs = rhs->compile();

	list<Icode_Stmt *> lhs_list = code_for_ast_lhs.get_icode_list();
	list<Icode_Stmt *> rhs_list = code_for_ast_rhs.get_icode_list();

	for(list<Icode_Stmt *>::iterator it=lhs_list.begin(); it != lhs_list.end(); ++it)
	{
		
		code_for_ast->append_ics(**it);
		
	}

	Register_Addr_Opd* opd1_or1 = new Register_Addr_Opd(code_for_ast_lhs.get_reg());
	Register_Addr_Opd* opd2_or1 = new Register_Addr_Opd(machine_desc_object.spim_register_table[zero]);
	Register_Descriptor * register_new_or1;

	if (lhs->get_data_type() == int_data_type)
		register_new_or1 = machine_desc_object.get_new_register<int_reg>();
	else if (lhs->get_data_type() == double_data_type)
		register_new_or1 = machine_desc_object.get_new_register<float_reg>();


	Register_Addr_Opd* result_or1 = new Register_Addr_Opd(register_new_or1);

	Compute_IC_Stmt* stmt_or1 =  new Compute_IC_Stmt(or_t,opd1_or1,opd2_or1,result_or1);

	code_for_ast->append_ics(*stmt_or1);
	code_for_ast_lhs.get_reg()->reset_register_occupied();

	Label_IC_Stmt* goto_stmt = new Label_IC_Stmt(j, label_string2);
	code_for_ast->append_ics(*goto_stmt);

	Label_IC_Stmt* label_stmt1 = new Label_IC_Stmt(label, label_string1);
	code_for_ast->append_ics(*label_stmt1);

	for(list<Icode_Stmt *>::iterator it=rhs_list.begin(); it != rhs_list.end(); ++it)
	{
		
		code_for_ast->append_ics(**it);
		
	}


	Register_Addr_Opd* opd1_or2 = new Register_Addr_Opd(code_for_ast_rhs.get_reg());
	Register_Addr_Opd* opd2_or2 = new Register_Addr_Opd(machine_desc_object.spim_register_table[zero]);
	// Register_Descriptor * register_new_or2 = machine_desc_object.get_new_register<int_reg>();
	// Register_Addr_Opd* result_or2 = new Register_Addr_Opd(register_new_or2);
	Compute_IC_Stmt* stmt_or2 =  new Compute_IC_Stmt(or_t,opd1_or2,opd2_or2,result_or1);

	code_for_ast->append_ics(*stmt_or2);
	code_for_ast_rhs.get_reg()->reset_register_occupied();

	Label_IC_Stmt* label_stmt2 = new Label_IC_Stmt(label, label_string2);
	code_for_ast->append_ics(*label_stmt2);

	code_for_ast->set_reg(register_new_or1);


	return *code_for_ast;




}




Code_For_Ast &  Relational_Expr_Ast::compile()
{
	Code_For_Ast code_for_ast_lhs = lhs_condition->compile();
	Code_For_Ast code_for_ast_rhs = rhs_condition->compile();

	Code_For_Ast* code_for_ast = new Code_For_Ast();
	list<Icode_Stmt *> rhs_list = code_for_ast_rhs.get_icode_list();
	*code_for_ast = code_for_ast_lhs;
	for(list<Icode_Stmt *>::iterator it=rhs_list.begin(); it != rhs_list.end(); ++it)
	{
		
		code_for_ast->append_ics(**it);
		
	}
	Register_Addr_Opd* opd1 = new Register_Addr_Opd(code_for_ast_lhs.get_reg());
	Register_Addr_Opd* opd2 = new Register_Addr_Opd(code_for_ast_rhs.get_reg());
	Icode_Stmt* stmt;
	Register_Descriptor * register_new;
	if (lhs_condition->get_data_type() == int_data_type)
	{
		register_new = machine_desc_object.get_new_register<int_reg>();
		Register_Addr_Opd* result = new Register_Addr_Opd(register_new);
		switch(rel_op) { 
	    case less_equalto: 
	        stmt = new Compute_IC_Stmt(sle,opd1,opd2,result);
	        break; 
	    case less_than: 
	        stmt = new Compute_IC_Stmt(slt,opd1,opd2,result);
	        break;
	    case greater_than: 
	        stmt = new Compute_IC_Stmt(sgt,opd1,opd2,result);
	        break; 
	    case greater_equalto: 
	       	stmt = new Compute_IC_Stmt(sge,opd1,opd2,result);
	        break;
	    case equalto: 
	        stmt = new Compute_IC_Stmt(seq,opd1,opd2,result);
	        break; 
	    case not_equalto: 
	        stmt = new Compute_IC_Stmt(sne,opd1,opd2,result);
	        break; 
		}
	}

	else if (lhs_condition->get_data_type() == double_data_type)
	{
		register_new = machine_desc_object.get_new_register<float_reg>();
		Register_Addr_Opd* result = new Register_Addr_Opd(register_new);
		switch(rel_op) { 
	    case less_equalto: 
	        stmt = new Move_IC_Stmt(sle_d,opd2, opd1);
	        break; 
	    case less_than: 
	        stmt = new Move_IC_Stmt(slt_d,opd2, opd1);
	        break;
	    case greater_than: 
	        stmt = new Move_IC_Stmt(sgt_d,opd2, opd1);
	        break; 
	    case greater_equalto: 
	        stmt = new Move_IC_Stmt(sge_d,opd2, opd1);
	        break;
	    case equalto: 
	        stmt = new Move_IC_Stmt(seq_d,opd2, opd1);
	        break; 
	    case not_equalto: 
	        stmt = new Move_IC_Stmt(sne_d,opd2, opd1);
	        break; 
	
	}
}

	code_for_ast->append_ics(*stmt);
	code_for_ast->set_reg(register_new);
	code_for_ast_lhs.get_reg()->reset_register_occupied();
	code_for_ast_rhs.get_reg()->reset_register_occupied();
	return *code_for_ast;
	
}




Code_For_Ast &  Logical_Expr_Ast::compile()
{

	Code_For_Ast* code_for_ast = new Code_For_Ast();
	Register_Addr_Opd* not_result;
	Compute_IC_Stmt* stmt;
	if (lhs_op== NULL)
	{
		Register_Descriptor * register_not = machine_desc_object.get_new_register<int_reg>();
		Const_Opd<int>* opd1 = new Const_Opd<int>(1);
		not_result = new Register_Addr_Opd(register_not);
		Move_IC_Stmt* stmt1 = new Move_IC_Stmt(imm_load, opd1, not_result);
		code_for_ast->append_ics(*stmt1);

	}
	Code_For_Ast code_for_ast_lhs;
	if (lhs_op!= NULL)
	 	code_for_ast_lhs= lhs_op->compile();
	Code_For_Ast code_for_ast_rhs = rhs_op->compile();
	list<Icode_Stmt *> rhs_list = code_for_ast_rhs.get_icode_list();


	if (lhs_op!= NULL)
		*code_for_ast = code_for_ast_lhs;

	for(list<Icode_Stmt *>::iterator it=rhs_list.begin(); it != rhs_list.end(); ++it)
	{
		
		code_for_ast->append_ics(**it);
		
	}
	Register_Descriptor * register_new = machine_desc_object.get_new_register<int_reg>();
	Register_Addr_Opd* result = new Register_Addr_Opd(register_new);
	Register_Addr_Opd* opd2 = new Register_Addr_Opd(code_for_ast_rhs.get_reg());

	switch(bool_op) { 
	    case _logical_not: 
	        stmt =  new Compute_IC_Stmt(not_t,opd2,not_result,result);
	        not_result->get_reg()->reset_register_occupied();
	        break; 
	    case _logical_or: 
	    {
	    	Register_Addr_Opd* opd1 = new Register_Addr_Opd(code_for_ast_lhs.get_reg());
	        stmt =  new Compute_IC_Stmt(or_t,opd1,opd2,result);
	        break;
	    }
	    case _logical_and: 
	    {
	    	Register_Addr_Opd* opd1 = new Register_Addr_Opd(code_for_ast_lhs.get_reg());
	        stmt =  new Compute_IC_Stmt(and_t,opd1,opd2,result);
	        break; 
	    }
	}


	code_for_ast->append_ics(*stmt);
	code_for_ast->set_reg(register_new);
	if (lhs_op!=NULL)
		code_for_ast_lhs.get_reg()->reset_register_occupied();
	code_for_ast_rhs.get_reg()->reset_register_occupied();
	return *code_for_ast;

}




Code_For_Ast &  Selection_Statement_Ast::compile()
{

	Code_For_Ast code_for_ast_cond = cond->compile();


	Code_For_Ast* code_for_ast = new Code_For_Ast();
	*code_for_ast = code_for_ast_cond;

	Register_Addr_Opd* opd1 = new Register_Addr_Opd(code_for_ast_cond.get_reg());

	//////////////////
	Register_Addr_Opd* opd2 = new Register_Addr_Opd(code_for_ast_cond.get_reg());
	string label_string = get_new_label();

	Icode_Stmt* cond_stmt;
	if (cond->get_data_type() == double_data_type)
	{
		cond_stmt = new Label_IC_Stmt(bc1t, label_string);
		machine_desc_object.get_new_register<int_reg>()->set_register_occupied();
	}
	else
	{
		Register_Addr_Opd* opd1 = new Register_Addr_Opd(code_for_ast_cond.get_reg());
		cout<<"label"<< label_string;
		cond_stmt = new Control_Flow_IC_Stmt(beq, opd1, opd2, label_string,0);
	}
	code_for_ast->append_ics(*cond_stmt);

	Code_For_Ast code_for_ast_then = then_part->compile();

	list<Icode_Stmt *> then_list = code_for_ast_then.get_icode_list();

	for(list<Icode_Stmt *>::iterator it=then_list.begin(); it != then_list.end(); ++it)
	{
		
		code_for_ast->append_ics(**it);
		
	}
	string label_string2 ;
	if (else_part!= NULL)
	{
		label_string2 = get_new_label();
		Label_IC_Stmt* goto_stmt = new Label_IC_Stmt(j, label_string2);
		code_for_ast->append_ics(*goto_stmt);
	}

	Label_IC_Stmt* label_stmt = new Label_IC_Stmt(label, label_string);
	code_for_ast->append_ics(*label_stmt);

	if (else_part!= NULL)
	{
		Code_For_Ast code_for_ast_else = else_part->compile();
		list<Icode_Stmt *> else_list = code_for_ast_else.get_icode_list();

		for(list<Icode_Stmt *>::iterator it=else_list.begin(); it != else_list.end(); ++it)
		{
		
			code_for_ast->append_ics(**it);
		
		}

		Label_IC_Stmt* label_stmt2 = new Label_IC_Stmt(label, label_string2);
		code_for_ast->append_ics(*label_stmt2);
	}

	// if (cond->get_data_type() == double_data_type)
	// {
	// 	// cond_stmt = new Label_IC_Stmt(bc1t, label_string);
	// 	machine_desc_object.spim_register_table[v0]->reset_register_occupied();
	// }

	code_for_ast_cond.get_reg()->reset_register_occupied();

	return *code_for_ast;



}




Code_For_Ast &  Iteration_Statement_Ast::compile()
{
	string label_string1 = get_new_label();
	string label_string2 = get_new_label();
	Code_For_Ast* code_for_ast = new Code_For_Ast();
	if (!is_do_form)
	{
		Label_IC_Stmt* goto_stmt = new Label_IC_Stmt(j, label_string2);
		code_for_ast->append_ics(*goto_stmt);
	}

	Label_IC_Stmt* label_stmt1 = new Label_IC_Stmt(label, label_string1);
	code_for_ast->append_ics(*label_stmt1);
	Code_For_Ast code_for_ast_body = body->compile();
	list<Icode_Stmt *> body_list = code_for_ast_body.get_icode_list();

	for(list<Icode_Stmt *>::iterator it=body_list.begin(); it != body_list.end(); ++it)
	{
		
		code_for_ast->append_ics(**it);
		
	}

	Label_IC_Stmt* label_stmt2 = new Label_IC_Stmt(label, label_string2);
	code_for_ast->append_ics(*label_stmt2);

	Code_For_Ast code_for_ast_cond = cond->compile();
	list<Icode_Stmt *> cond_list = code_for_ast_cond.get_icode_list();

		
	for(list<Icode_Stmt *>::iterator it=cond_list.begin(); it != cond_list.end(); ++it)
	{
		
		code_for_ast->append_ics(**it);
		
	}

	Register_Addr_Opd* opd1 = new Register_Addr_Opd(code_for_ast_cond.get_reg());

	//////////////////////
	Register_Addr_Opd* opd2 = new Register_Addr_Opd(code_for_ast_cond.get_reg());
	Icode_Stmt* cond_stmt;
	if (cond->get_data_type() == double_data_type)
	{
		cond_stmt = new Label_IC_Stmt(bc1t, label_string1);
		machine_desc_object.get_new_register<int_reg>()->set_register_occupied();
	}
	else
	{
		cond_stmt = new Control_Flow_IC_Stmt(bne, opd1, opd2, label_string1,0);
	}

	code_for_ast->append_ics(*cond_stmt);
	code_for_ast_cond.get_reg()->reset_register_occupied();
	return *code_for_ast;
}


Code_For_Ast &  Sequence_Ast::compile()
{
	Code_For_Ast* code_for_ast = new Code_For_Ast();
	for(list<Ast *>::iterator it=statement_list.begin(); it != statement_list.end(); ++it)
	{

		Code_For_Ast code_for_ast_seq = (*it)->compile();
	
		list<Icode_Stmt *> seq_list = code_for_ast_seq.get_icode_list();
		
		for(list<Icode_Stmt *>::iterator it2=seq_list.begin(); it2 != seq_list.end(); ++it2)
		{
			
			code_for_ast->append_ics(**it2);
			
		}

		
	}

	return *code_for_ast;

}



Code_For_Ast &  Print_Ast::compile(){
	Code_For_Ast* code_for_ast = new Code_For_Ast();

	Const_Opd<int>* opd1 ;
	Register_Addr_Opd * v0_result = new Register_Addr_Opd(machine_desc_object.spim_register_table[v0]);

	if (var->get_data_type() == int_data_type)
	{
		opd1 = new Const_Opd<int>(1);
	}
	else if (var->get_data_type() == double_data_type)
	{
		opd1 = new Const_Opd<int>(3);
	}
	Move_IC_Stmt* v0_stmt = new Move_IC_Stmt(imm_load, opd1, v0_result);
	code_for_ast->append_ics(*v0_stmt);
	
	
	Mem_Addr_Opd* opd1_arg = new Mem_Addr_Opd(var->get_symbol_entry());

	Register_Descriptor* register_new ;

	Move_IC_Stmt* arg_stmt;

	if (var->get_data_type() == int_data_type)
	{
		register_new = machine_desc_object.spim_register_table[a0];
		Register_Addr_Opd* result = new Register_Addr_Opd(register_new);
		arg_stmt = new Move_IC_Stmt(load, opd1_arg, result);
	}
	else if (var->get_data_type() == double_data_type)
	{
		register_new = machine_desc_object.spim_register_table[f12];
		Register_Addr_Opd* result = new Register_Addr_Opd(register_new);
		arg_stmt = new Move_IC_Stmt(load_d, opd1_arg, result);
	}
	



	code_for_ast->append_ics(*arg_stmt);

	Print_IC_Stmt* print_stmt = new Print_IC_Stmt();

	code_for_ast->append_ics(*print_stmt);
	machine_desc_object.spim_register_table[v0]->reset_register_occupied();
	register_new->reset_register_occupied();

	return *code_for_ast;
}



Code_For_Ast & Call_Ast::compile()
{
	// cout<< "called call_ast compile\n";
	Code_For_Ast* code_for_ast = new Code_For_Ast();
	int table_size = 0;
	program_object.get_procedure_prototype(procedure_name)->get_formal_param_list().get_table().reverse();
	actual_param_list.reverse();
	int offset = (**(program_object.get_procedure_prototype(procedure_name)->get_formal_param_list().get_table().begin())).get_start_offset();

	for(list<Ast *>::iterator it=actual_param_list.begin(); it != actual_param_list.end(); ++it)
	{
		if ((*it)->get_data_type() == int_data_type)
			table_size+=4;
		else if ((*it)->get_data_type() == double_data_type)
			table_size+=8;
	}

	Register_Addr_Opd* opd1 = new Register_Addr_Opd(machine_desc_object.spim_register_table[sp]);
	Const_Opd<int>* opd2 = new Const_Opd<int>(table_size);
	Register_Addr_Opd* result = new Register_Addr_Opd(machine_desc_object.spim_register_table[sp]);


	list<Symbol_Table_Entry *>::iterator it_param_table = program_object.get_procedure_prototype(procedure_name)->get_formal_param_list().get_table().begin();
	for(list<Ast *>::iterator it=actual_param_list.begin(); it != actual_param_list.end(); ++it)
	{
		Code_For_Ast code_for_ast_seq = (*it)->compile();
	
		list<Icode_Stmt *> seq_list = code_for_ast_seq.get_icode_list();
		
		for(list<Icode_Stmt *>::iterator it2=seq_list.begin(); it2 != seq_list.end(); ++it2)
		{
			
			code_for_ast->append_ics(**it2);
			
		}

		Register_Addr_Opd* opd1  = new Register_Addr_Opd(code_for_ast_seq.get_reg());
		string * s = new string();
		*s = (*it_param_table)->get_variable_name();
		Symbol_Table_Entry* symbol_entry = new Symbol_Table_Entry(*s,(*it_param_table)->get_data_type() ,(*it_param_table)->get_lineno(), sp_ref);
		// *symbol_entry = **it_param_table;
		(*symbol_entry).set_start_offset((**it_param_table).get_start_offset() - offset);
		(*symbol_entry).set_symbol_scope(local);
		Mem_Addr_Opd* result = new Mem_Addr_Opd(*symbol_entry);


		Move_IC_Stmt* stmt;
		if ((*it)->get_data_type() == int_data_type)
		{
			
			stmt = new Move_IC_Stmt(store,opd1, result);
		}
		else if ((*it)->get_data_type() == double_data_type)
		{
			stmt = new Move_IC_Stmt(store_d, opd1, result);
		}

		code_for_ast->append_ics(*stmt);
		code_for_ast_seq.get_reg()->reset_register_occupied();
		it_param_table++;
	}
	Compute_IC_Stmt* stack_stmt1 = new Compute_IC_Stmt(sub, opd1, opd2, result);
	code_for_ast->append_ics(*stack_stmt1);
	Label_IC_Stmt* label_stmt = new  Label_IC_Stmt(jal, procedure_name);
	code_for_ast->append_ics(*label_stmt);
	// code_for_ast->set_reg(machine_desc_object.spim_register_table[v1]);
	


	Compute_IC_Stmt* stack_stmt2 = new Compute_IC_Stmt(add, opd1, opd2, result);
	code_for_ast->append_ics(*stack_stmt2);




	Register_Addr_Opd* source = new Register_Addr_Opd(machine_desc_object.spim_register_table[v1]);
	Register_Addr_Opd* destination = new Register_Addr_Opd(machine_desc_object.spim_register_table[v0]);
	Move_IC_Stmt* move_stmt = new Move_IC_Stmt(mov,source,destination);
	code_for_ast->append_ics(*move_stmt);
	code_for_ast->set_reg(machine_desc_object.spim_register_table[v0]);

	machine_desc_object.spim_register_table[v1]->reset_register_occupied();
	program_object.get_procedure_prototype(procedure_name)->get_formal_param_list().get_table().reverse();
	return *code_for_ast;
}

Code_For_Ast & Call_Ast::compile_and_optimize_ast(Lra_Outcome & lra)
{

}



Code_For_Ast &  Return_Ast::compile()
{
	Code_For_Ast* code_for_ast = new Code_For_Ast();
	if (return_value!= NULL)
	{
	Code_For_Ast code_for_ast_return_value = return_value->compile();
	*code_for_ast = code_for_ast_return_value;

	Register_Addr_Opd* source = new Register_Addr_Opd(code_for_ast_return_value.get_reg());
	Register_Addr_Opd* destination = new Register_Addr_Opd(machine_desc_object.spim_register_table[v1]);
	Move_IC_Stmt* move_stmt = new Move_IC_Stmt(mov,source,destination);
	code_for_ast->append_ics(*move_stmt);
	code_for_ast_return_value.get_reg()->reset_register_occupied();
}
	Label_IC_Stmt* label_stmt = new  Label_IC_Stmt(j,  "epilogue_" + proc_name);
	code_for_ast->append_ics(*label_stmt);

	// code_for_ast->set_reg(machine_desc_object.spim_register_table[v1]);
	return *code_for_ast;
}

Code_For_Ast & Return_Ast::compile_and_optimize_ast(Lra_Outcome & lra)
{

}