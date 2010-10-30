/*
 * Exception.cxx
 * 
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#include "BasicException.hpp"

/** Test for BasicException. */
class BasicExceptionTest {
public:
	void testThrowCatch();
};

/** Ensures an exception can be thrown and caught.
 * 
 * "This is an exception from 45" should be printed to standard out.
 */
void BasicExceptionTest::testThrowCatch() {
	
	int line=45;
	
	// Test
	try {
		BasicException e;
		e << "This is an exception from " << line;
		throw e;
	} catch (BasicException &e) {
		cout << e.what() << endl;
		cout << "PASSED" << endl;
		return;
	}
	cerr << "Exception was not caught!" << endl;
	cerr << "FAILED!" << endl;
}

/* Runs the test */
int main(int argc, char *argv[]) {
	
	BasicExceptionTest test;
	
	test.testThrowCatch();
	cout << "ALL TESTS PASSED" << endl;
}

