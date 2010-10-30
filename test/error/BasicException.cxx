/*
 * Exception.cxx
 * 
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#include "BasicException.hpp"

class BasicExceptionTest {
public:
	void testThrowCatch();
};

void BasicExceptionTest::testThrowCatch() {
	
	int line=45;
	
	// Test
	try {
		BasicException e;
		e << "This is an exception from " << line << ".";
		throw e;
	} catch (BasicException &e) {
		cout << e.what() << endl;
		return;
	}
	cerr << "Exception was not caught!" << endl;
	cerr << "TEST FAILED!" << endl;
}

int main(int argc, char *argv[]) {
	
	BasicExceptionTest test;
	
	test.testThrowCatch();
	cout << "PASSED ALL TESTS." << endl;
}

