#include "server.hpp"
#include <iostream>

int main(){
	Server g;
	cout << g.greet() << std::endl;
    cout << g.getVersion() << std::endl;
	return 0;
}
