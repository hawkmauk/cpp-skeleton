#ifndef GREETER_H
#define GREETER_H

#include <iostream>
#include <string>

using namespace std;

class Greeter {
	public:
		//constructors
		Greeter();
		Greeter( const string name );
		
		//methods
		string greet();

		//accessors
			string getName() { return m_name; };
			string setName(string name) { name = m_name; };

	private:
		string m_name;
};

#endif /* GREETER_H */
