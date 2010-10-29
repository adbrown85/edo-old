/*
 * Parser.cxx
 * 
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#include <iostream>
#include "Parser.hpp"


/**
 * Simple test program.
 */
int main(int argc, char **argv) {
	
	Parser parser;
	
	// Start
	cout << endl;
	cout << "****************************************" << endl;
	cout << "Parser" << endl;
	cout << "****************************************" << endl;
	cout << endl;
	
	// Test
	try {
		parser.open("Parser.xml");
		parser.print();
		cout << "Line number: " << parser.getLineNumber() << endl;
	} catch (BasicException &e) {
		cerr << e.what() << endl;
	}
	
	// Finish
	cout << endl;
	cout << "****************************************" << endl;
	cout << "Parser" << endl;
	cout << "****************************************" << endl;
	cout << endl;
	return 0;
}

