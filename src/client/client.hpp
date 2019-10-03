#ifndef SKELETON_CLIENT_H
#define SKELETON_CLIENT_H
#define APPLICATION_NAME PACKAGE_NAME "-cli"
#include <string>

using namespace std;

class Client {
	public:
		//constructors
		Client();
		Client( const string name );
		
		//methods
        string getVersion();

		//accessors
		string getName() { return m_name; };
		string setName(string name) { m_name = name; };

	private:
		string m_name;
};

#endif /* SKELETON_CLIENT_H */
