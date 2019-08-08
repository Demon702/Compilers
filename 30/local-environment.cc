#include "local-environment.hh"
#include <stdlib.h>
// Eval_Result::
void Symbol_Table:: create(Local_Environment & local_global_variables_table)
{
	for (list<Symbol_Table_Entry *>::iterator it = variable_table.begin(); it != variable_table.end(); it++ )
	{
		Eval_Result* eval;	
		if ((*it)->get_data_type() == int_data_type) 
		{
			eval = new Eval_Result_Value_Int();
			if (scope == global)
			{
				eval->set_variable_status(true);
				local_global_variables_table.put_variable_value(*eval, (*it)->get_variable_name());

			}
			else local_global_variables_table.put_variable_value(*eval, (*it)->get_variable_name());
		}
		else if ((*it)->get_data_type() == double_data_type)
		{
			eval = new Eval_Result_Value_Double();
			// cout<< eval->get_double_value()<<endl;
			if (scope == global)
			{
				eval->set_variable_status(true);
				// cout<< (*it)->get_variable_name()<< " "<<eval->is_variable_defined()<< " "<<eval->get_double_value() << endl;
				local_global_variables_table.put_variable_value(*eval, (*it)->get_variable_name());

			}
			local_global_variables_table.put_variable_value(*eval, (*it)->get_variable_name());
		}
	}

}

Local_Environment::Local_Environment()
{
	variable_table.clear();
}

Local_Environment::~Local_Environment()
{

}

int Eval_Result::get_int_value(){
}

void Eval_Result::set_value(int value){
}

double Eval_Result::get_double_value(){
}

void Eval_Result::set_value(double value){
}

bool Eval_Result::is_variable_defined(){
}

void Eval_Result::set_variable_status(bool def){
}

// Eval_Result_Value::
void Eval_Result_Value::set_value(int number){
}

void Eval_Result_Value::set_value(double number){
}

int Eval_Result_Value::get_int_value(){
}

double Eval_Result_Value::get_double_value(){
}


// Eval_Result_Value_Int::
///////////////////////////////////////////////////
/////////////////////////////////////////////////



Eval_Result_Value_Int::Eval_Result_Value_Int()
{
	result_type = int_result;
	value = 0;
	defined = false;
}


Eval_Result_Value_Int::~Eval_Result_Value_Int()
{

}

void Eval_Result_Value_Int::set_value(int number){
	value = number;
}
void Eval_Result_Value_Int::set_value(double number){
	return;
}
int Eval_Result_Value_Int::get_int_value(){
	return value;
}

void Eval_Result_Value_Int::set_variable_status(bool def){
	defined = def;
}

bool Eval_Result_Value_Int::is_variable_defined(){
 	return defined;
}

void Eval_Result_Value_Int::set_result_enum(Result_Enum res){
	result_type = res;
}

Result_Enum Eval_Result_Value_Int::get_result_enum(){
	return result_type;
}

// Eval_Result_Value_Double::
////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////


Eval_Result_Value_Double:: Eval_Result_Value_Double()
{
	result_type = double_result;
	value = 0.0;
	defined = false;
}


Eval_Result_Value_Double::~Eval_Result_Value_Double()
{

}


void Eval_Result_Value_Double::set_value(int number){

}
void Eval_Result_Value_Double::set_value(double number){
	value = number;
}
double Eval_Result_Value_Double::get_double_value(){
	return value;
}

void Eval_Result_Value_Double::set_variable_status(bool def){
	defined = def;
}
bool Eval_Result_Value_Double::is_variable_defined(){
 	return defined;
}

void Eval_Result_Value_Double::set_result_enum(Result_Enum res){
	result_type = res;
}

Result_Enum Eval_Result_Value_Double::get_result_enum(){
	return result_type;
}


void Local_Environment::print(ostream & file_buffer){

	// file_buffer << "RANDOM STRING";
	for (map<string, Eval_Result *>::iterator it = variable_table.begin(); it != variable_table.end(); it++ )
	{	
	    file_buffer <<VAR_SPACE<< it->first  // string (key)
	              << " : ";
	    if (it->second->is_variable_defined())
	    {
	    	if (it->second->get_result_enum() ==int_result)
	    		file_buffer << it->second->get_int_value();
	    	else if (it->second->get_result_enum() ==double_result)
	    		file_buffer << it->second->get_double_value();
	    }
	    else file_buffer<<"undefined";	  // string's value 
	    	
	              file_buffer<< std::endl ;
	}

	return ;
}
bool Local_Environment::is_variable_defined(string name){
	map<string, Eval_Result *>::iterator it =  variable_table.find(name);
	if (it != variable_table.end())
		return (it->second)->is_variable_defined();
	return false;
}
Eval_Result * Local_Environment::get_variable_value(string name){
	// Eval_Result eval-result = new Eval_Result();
	// result eval-result;
	return variable_table[name];
}

void Local_Environment::put_variable_value(Eval_Result & value, string name){
	map<string, Eval_Result *>::iterator it = variable_table.find(name);
	if (it!= variable_table.end()){
		// cout << "in if\n";
		it->second = &value;
	} 
	else 
	{
		variable_table[name]= &value;
	}

}
bool Local_Environment::does_variable_exist(string name){
	return variable_table.find(name)!= variable_table.end();
}