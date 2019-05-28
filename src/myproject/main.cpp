#include "greeter.hpp"

int main(){
	Greeter g;
	g.setName( "main" );
	cout << g.greet();

	return 0;
}
