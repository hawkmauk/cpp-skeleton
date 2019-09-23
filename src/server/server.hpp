#ifndef SKELETON_SERVER_H
#define SKELETON_SERVER_H

#include <string>

using namespace std;

class Server {
	public:
		//constructors
		Server();
		Server( const string name );
		
		//methods
        string getVersion();
		string greet();

		//accessors
		string getName() { return m_name; };
		string setName(string name) { m_name = name; };

	private:
		string m_name;
};

#endif /* SKELETON_SERVER_H */
