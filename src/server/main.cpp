#include "server.hpp"
#include <iostream>

int main(){
    //initialise the server
	Server g;
    std::cout << g.getVersion() << std::endl;
	return 0;
}
