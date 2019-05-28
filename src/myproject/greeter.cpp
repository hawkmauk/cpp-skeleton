#include "greeter.hpp"

Greeter::Greeter(){
	m_name = "user";
}

Greeter::Greeter( string name ){
	m_name = name;
}

string Greeter::greet(){
	return "Hello " + getName() + "!";
}

