/*
 * Exception.cxx
 * 
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#include "BasicException.hpp"


int main(int argc,
         char *argv[]) {
	
	int line=45;
	
	// Test
	try {
		BasicException e;
		e << "This is an exception from " << line << ".";
		throw e;
	} catch (BasicException &e) {
		cout << e.what() << endl;
	}
}

