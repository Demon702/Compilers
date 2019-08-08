#include "icode.hh"
#include "reg-alloc.hh"

template class Const_Opd<double>;
template class Const_Opd<int>;
///////////////////////Instruction_Descriptor
/////////////////////////////////////////////
////////////////////////////////////////////////
Instruction_Descriptor::Instruction_Descriptor (Tgt_Op op, string name, string mnn, string ics, Icode_Format icf, Assembly_Format af)
{
	inst_op = op;
	mnemonic= mnn;
	ic_symbol = ics;       /* symbol for printing in intermediate code */
	this->name = name;
	ic_format = icf; /* format for printing in intemediate code */
	assem_format = af;
}
Instruction_Descriptor::Instruction_Descriptor()
{
	inst_op = load;
	mnemonic= "";
	ic_symbol = "";       /* symbol for printing in intermediate code */
	this->name = "";
	ic_format = i_op; /* format for printing in intemediate code */
	assem_format = a_op;
}

Tgt_Op Instruction_Descriptor::get_op()
{
	return inst_op;
}
string Instruction_Descriptor::get_name()
{
	return name;
}
string Instruction_Descriptor::get_mnemonic()
{
	return mnemonic;
}
string Instruction_Descriptor::get_ic_symbol()
{
	return ic_symbol;
}
Icode_Format Instruction_Descriptor::get_ic_format()
{
	return ic_format;
}
Assembly_Format Instruction_Descriptor::get_assembly_format()
{
	return assem_format;
}
 
void Instruction_Descriptor::print_instruction_descriptor(ostream & file_buffer)
{

}


////////////////////////////////////Ics_Opd/////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



Register_Descriptor * Ics_Opd::get_reg(){}





////////////////////////////////Mem_Addr_Opd////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

Mem_Addr_Opd::Mem_Addr_Opd(Symbol_Table_Entry & se)
{
	symbol_entry = &se;
}


void Mem_Addr_Opd::print_ics_opd(ostream & file_buffer)
{
	file_buffer<< symbol_entry->get_variable_name();
	
}


void Mem_Addr_Opd::print_asm_opd(ostream & file_buffer)
{
	if (symbol_entry->get_symbol_scope() == global)
	{
		file_buffer<< symbol_entry->get_variable_name();
	}
	else if (symbol_entry-> get_ref_offset() == fp_ref)
		file_buffer<<symbol_entry->get_start_offset()<<"($fp)";
	else if (symbol_entry-> get_ref_offset() == sp_ref)
		file_buffer<<symbol_entry->get_start_offset()<<"($sp)";
}

Mem_Addr_Opd & Mem_Addr_Opd::operator= (const Mem_Addr_Opd & rhs)
{
	symbol_entry = rhs.symbol_entry;
}



////////////////////////////////////Register_Addr_Opd//////////////////////////////
//////////////////////////////////////////////////////////////////////////////////


Register_Addr_Opd::Register_Addr_Opd(Register_Descriptor * rd)
{
	register_description = rd;
}

Register_Descriptor * Register_Addr_Opd::get_reg()
{
	return register_description;
}
void Register_Addr_Opd::print_ics_opd(ostream & file_buffer)
{
	file_buffer<<register_description->get_name();
}
void Register_Addr_Opd::print_asm_opd(ostream & file_buffer)
{
	file_buffer<<"$"<<register_description->get_name();
}

Register_Addr_Opd & Register_Addr_Opd::operator=(const Register_Addr_Opd & rhs)
{
	this->register_description = rhs.register_description;
}


///////////////////////////////////////Const_Opd///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
template<typename T>
Const_Opd<T>::Const_Opd(T num)
{
	this->num = num;
}


template<typename T>
void Const_Opd<T>::print_ics_opd(ostream & file_buffer)
{
	file_buffer<< num;
}

template<typename T>	
void Const_Opd<T>::print_asm_opd(ostream & file_buffer)
{
	file_buffer<< num;
}

template<typename T>
Const_Opd<T> & Const_Opd<T>::operator=(const Const_Opd & rhs)
{
	this->num = rhs.num;
}


/////////////////////////////////Icode_stmt//////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////



Instruction_Descriptor & Icode_Stmt::get_op()
{
	return op_desc;
}
Ics_Opd * Icode_Stmt::get_opd1(){}
Ics_Opd * Icode_Stmt::get_opd2(){}
Ics_Opd * Icode_Stmt::get_result(){}

void Icode_Stmt::set_opd1(Ics_Opd * io){}
void Icode_Stmt::set_opd2(Ics_Opd * io){}
void Icode_Stmt::set_result(Ics_Opd * io){}


/////////////////////////////////////Print_IC_Stmt///////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////


Print_IC_Stmt::Print_IC_Stmt()
{
}
 Print_IC_Stmt::~Print_IC_Stmt(){}
 void Print_IC_Stmt::print_icode(ostream & file_buffer) 
 {
 	file_buffer<<"	";
 	file_buffer<<"print";
 	file_buffer<<"\n";
 }
 void Print_IC_Stmt::print_assembly(ostream & file_buffer)
 {
 	file_buffer<<"	";
 	file_buffer<<"syscall";
 	file_buffer<<"\n";
 }


//////////////////////////////////////Move_ic_stmt///////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

Move_IC_Stmt::Move_IC_Stmt(Tgt_Op inst_op, Ics_Opd * opd1, Ics_Opd * result)
{
	op_desc = Instruction_Descriptor(inst_op, machine_desc_object.spim_instruction_table[inst_op]->get_name() , 
		machine_desc_object.spim_instruction_table[inst_op]->get_mnemonic(),
		machine_desc_object.spim_instruction_table[inst_op]->get_ic_symbol(),
		machine_desc_object.spim_instruction_table[inst_op]->get_ic_format(),
		machine_desc_object.spim_instruction_table[inst_op]->get_assembly_format());
	this->opd1 = opd1;
	this->result = result; 
}

Move_IC_Stmt & Move_IC_Stmt::operator=(const Move_IC_Stmt & rhs)
{
	this->op_desc = rhs.op_desc;
	this->opd1 = rhs.opd1;
	this->result = rhs.result;
}

Instruction_Descriptor & Move_IC_Stmt::get_inst_op_of_ics()
{
	return op_desc;
}

Ics_Opd * Move_IC_Stmt::get_opd1()
{
	return opd1;
}
void Move_IC_Stmt::set_opd1(Ics_Opd * io)
{
	opd1 = io;
}

Ics_Opd * Move_IC_Stmt::get_result()
{
	return result;
}
void Move_IC_Stmt::set_result(Ics_Opd * io)
{
	result = io;
}

void Move_IC_Stmt::print_icode(ostream & file_buffer)
{
	file_buffer<<"	";
	file_buffer<<op_desc.get_name()<<":    	";
	result->print_ics_opd(file_buffer);
	file_buffer<<" <- ";
	opd1->print_ics_opd(file_buffer);
	file_buffer<<"\n";
}

void Move_IC_Stmt::print_assembly(ostream & file_buffer)
{
	file_buffer<<"	";
	file_buffer<<op_desc.get_mnemonic()<<" ";
	if (op_desc.get_op() == store or op_desc.get_op() == store_d)
	{
		opd1->print_asm_opd(file_buffer);
		file_buffer<<", ";
		result->print_asm_opd(file_buffer);
	}
	else
	{
		result->print_asm_opd(file_buffer);
		file_buffer<<", ";
		opd1->print_asm_opd(file_buffer);
	}
	file_buffer<<"\n";
}

/////////////////////////////////////Compute_IC_Stmt/////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

Compute_IC_Stmt::Compute_IC_Stmt(Tgt_Op inst_op, Ics_Opd * opd1, Ics_Opd * opd2, Ics_Opd * result)
{
	op_desc= Instruction_Descriptor(inst_op, machine_desc_object.spim_instruction_table[inst_op]->get_name() , 
		machine_desc_object.spim_instruction_table[inst_op]->get_mnemonic(),
		machine_desc_object.spim_instruction_table[inst_op]->get_ic_symbol(),
		machine_desc_object.spim_instruction_table[inst_op]->get_ic_format(),
		machine_desc_object.spim_instruction_table[inst_op]->get_assembly_format());
	this->opd1 = opd1;
	this->opd2 = opd2;
	this->result = result;
} 
 
Compute_IC_Stmt & Compute_IC_Stmt::operator=(const Compute_IC_Stmt & rhs)
{
	this->op_desc = rhs.op_desc;
	this->opd1 = rhs.opd1;
	this->opd2 = rhs.opd2;
	this->result = rhs.result;
}

Instruction_Descriptor & Compute_IC_Stmt::get_inst_op_of_ics()
{
	return op_desc;
}

Ics_Opd * Compute_IC_Stmt::get_opd1()
{
	return opd1;
}
void Compute_IC_Stmt::set_opd1(Ics_Opd * io)
{
	opd1 = io;
}

Ics_Opd * Compute_IC_Stmt::get_opd2()
{
	return opd2;
}
void Compute_IC_Stmt::set_opd2(Ics_Opd * io)
{
	opd2 = io;
}

Ics_Opd * Compute_IC_Stmt::get_result()
{
	return result;
}
void Compute_IC_Stmt::set_result(Ics_Opd * io)
{
	result = io;
}

void Compute_IC_Stmt::print_icode(ostream & file_buffer)
{
	file_buffer<<"	";
	file_buffer<<op_desc.get_name()<<":    	";
	result->print_ics_opd(file_buffer);
	file_buffer<<" <- ";
	opd1->print_ics_opd(file_buffer);
	file_buffer<<" , ";
	opd2->print_ics_opd(file_buffer);
	file_buffer<<"\n";
}
void Compute_IC_Stmt::print_assembly(ostream & file_buffer)
{
	file_buffer<<"	";
	file_buffer<<op_desc.get_mnemonic()<<" ";
	result->print_asm_opd(file_buffer);
	file_buffer<<", ";
	opd1->print_asm_opd(file_buffer);
	file_buffer<<", ";
	opd2->print_asm_opd(file_buffer);
	file_buffer<<"\n";
}


////////////////////////////////////Control_Flow_IC_Stmt/////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////


// Control_Flow_IC_Stmt::Control_Flow_IC_Stmt(Tgt_Op inst_op, Ics_Opd * opd1, string label)
// {
// 	op_desc = Instruction_Descriptor(inst_op, machine_desc_object.spim_instruction_table[inst_op]->get_name() , 
// 		machine_desc_object.spim_instruction_table[inst_op]->get_mnemonic(),
// 		machine_desc_object.spim_instruction_table[inst_op]->get_ic_symbol(),
// 		machine_desc_object.spim_instruction_table[inst_op]->get_ic_format(),
// 		machine_desc_object.spim_instruction_table[inst_op]->get_assembly_format());
// 	this->opd1 = opd1;
// 	this->label = label;
// } 
Control_Flow_IC_Stmt::Control_Flow_IC_Stmt(Tgt_Op inst_op, Ics_Opd * o1, Ics_Opd * o2, string label, int size)
{

	///////////           isko thoda sahi karna hai, aur neeche bhi       //////////
	op_desc = Instruction_Descriptor(inst_op, machine_desc_object.spim_instruction_table[inst_op]->get_name() , 
		machine_desc_object.spim_instruction_table[inst_op]->get_mnemonic(),
		machine_desc_object.spim_instruction_table[inst_op]->get_ic_symbol(),
		machine_desc_object.spim_instruction_table[inst_op]->get_ic_format(),
		machine_desc_object.spim_instruction_table[inst_op]->get_assembly_format());
	this->opd1 = o1;
	this->opd2 = o2;
	this->offset = label;
	this->actual_param_size = size;
	// this->label = label;
} 


Control_Flow_IC_Stmt& Control_Flow_IC_Stmt::operator=(const Control_Flow_IC_Stmt& rhs){
	this->op_desc = rhs.op_desc;
	this->opd1 = rhs.opd1;
	this->opd2 = rhs.opd2;
	this->offset = rhs.offset;
	this->actual_param_size = rhs.actual_param_size;
	// this->label = rhs.label;
}

Instruction_Descriptor & Control_Flow_IC_Stmt::get_inst_op_of_ics()
{
	return op_desc;
}

Ics_Opd * Control_Flow_IC_Stmt::get_opd1()
{
	return opd1;
}

void Control_Flow_IC_Stmt::set_opd1(Ics_Opd * io)
{
	opd1 = io;
}

// string Control_Flow_IC_Stmt::get_label()
// {
// 	return label;
// }
// void Control_Flow_IC_Stmt::set_label(string label)
// {
// 	this->label = label; 
// }

void Control_Flow_IC_Stmt::print_icode(ostream & file_buffer)
{
	file_buffer<<"	";
	file_buffer<<op_desc.get_name()<<":    	";
	opd1->print_ics_opd(file_buffer);
	file_buffer<<" , zero : goto ";
	file_buffer<<offset;
	file_buffer<<"\n";
}

void Control_Flow_IC_Stmt::print_assembly(ostream & file_buffer)
{
	file_buffer<<"	";
	file_buffer<<op_desc.get_mnemonic()<<" ";
	opd1->print_asm_opd(file_buffer);
	file_buffer<<", ";
	file_buffer<<"$zero";
	file_buffer<<", ";
	file_buffer<<offset<<" ";
	file_buffer<<"\n";	
}



//////////////////////////////



Ics_Opd * Control_Flow_IC_Stmt::get_opd2()
{
	return opd2;
}
void Control_Flow_IC_Stmt::set_opd2(Ics_Opd * io)
{
	opd2 = io;
}

////////////////////////////////////////Label_IC_Stmt////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

Label_IC_Stmt::Label_IC_Stmt(Tgt_Op inst_op, string label)
{
	op_desc = Instruction_Descriptor(inst_op, machine_desc_object.spim_instruction_table[inst_op]->get_name() , 
		machine_desc_object.spim_instruction_table[inst_op]->get_mnemonic(),
		machine_desc_object.spim_instruction_table[inst_op]->get_ic_symbol(),
		machine_desc_object.spim_instruction_table[inst_op]->get_ic_format(),
		machine_desc_object.spim_instruction_table[inst_op]->get_assembly_format());
	this->label = label;
}

Label_IC_Stmt & Label_IC_Stmt::operator=(const Label_IC_Stmt & rhs)
{
	this->op_desc = rhs.op_desc;
	this->label = rhs.label;
}

Instruction_Descriptor & Label_IC_Stmt::get_inst_op_of_ics()
{
	return op_desc;
}

string Label_IC_Stmt::get_label()
{	
	return label;
}

void Label_IC_Stmt::set_label(string label)
{
	this->label = label;
}

void Label_IC_Stmt::print_icode(ostream & file_buffer)
{
	if (op_desc.get_op() == j or op_desc.get_op() == bc1t or op_desc.get_op() == jal)
	{
		file_buffer<<"	"; 
		file_buffer<<op_desc.get_name()<<" ";
		file_buffer<<label;
		file_buffer<<"\n";
	}
	else
	{
		file_buffer<<"\n";
		file_buffer<<label;
		file_buffer<<":    	\n";
	}
}
void Label_IC_Stmt::print_assembly(ostream & file_buffer)
{
	if (op_desc.get_op() == j or op_desc.get_op() == bc1t or op_desc.get_op() == jal)
	{
		file_buffer<<"	"; 
		file_buffer<<op_desc.get_mnemonic()<<" ";
		file_buffer<<label;
		file_buffer<<"\n";
	}
	else
	{
		file_buffer<<"\n";
		file_buffer<<label;
		file_buffer<<":    	\n";
	}
}

/////////////////////////////Code_For_Ast///////////////////////////////////
////////////////////////////////////////////////////////////////////////////

Code_For_Ast::Code_For_Ast()
{
	ics_list = *(new list<Icode_Stmt *>());
}
Code_For_Ast::Code_For_Ast(list<Icode_Stmt *> & ic_l, Register_Descriptor * reg)
{
	ics_list = ic_l;
	result_register = reg;
}

void Code_For_Ast::append_ics(Icode_Stmt & ics)
{
	ics_list.push_back(&ics);
}
list<Icode_Stmt *> & Code_For_Ast::get_icode_list()
{
	return ics_list;
}

Register_Descriptor * Code_For_Ast::get_reg()
{
	return result_register;
}
void Code_For_Ast::set_reg(Register_Descriptor * reg)
{
	result_register = reg;
}

Code_For_Ast & Code_For_Ast::operator=(const Code_For_Ast & rhs)
{
	this->ics_list = rhs.ics_list;

	this->result_register = rhs.result_register;
		
}