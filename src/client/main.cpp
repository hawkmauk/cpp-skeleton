#include "client.hpp"
#include <iostream>

int main(){
	Client g;
	cout << g.greet() << std::endl;
    cout << g.getVersion() << std::endl;
	return 0;
}
