/*
 * Log.cxx
 * 
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#include "Log.hpp"
#include <cassert>


/* Fake listener for log. */
class FakeLogListener : public LogListener {
public:
	FakeLogListener();
	virtual void onLogUpdate(const string &text);
	virtual int getTally();
private:
	int tally;
};

/* Initializes the listener. */
FakeLogListener::FakeLogListener() {
	tally = 0;
}

/* Prints a message and increases the tally. */
void FakeLogListener::onLogUpdate(const string &text) {
	cerr << "Log updated!" << endl;
	++tally;
}

/* Return number of times a message was received. */
int FakeLogListener::getTally() {
	return tally;
}

/** Test fixture for Log. */
class LogTest {
public:
	void testInsertion();
	void testIterator();
};

/** Ensures messages can be inserted and that listeners get notifications.
 * 
 * Should print three messages to standard error from testInsertion.  For each 
 * message there should also be a line between saying "Log updated!", which is
 * printed by FakeLogListener.
 */
void LogTest::testInsertion() {
	
	FakeLogListener listener;
	
	glog.addListener(&listener);
	glog << "This is a message!" << endl;
	glog << "This is a message with a " << 1.5 << endl;
	glog << "This is a message with a " << 1 << endl;
	assert(listener.getTally() == 3);
	cout << "PASSED" << endl;
}

/** Makes sure the log stores its messages and that they're accessible. */
void LogTest::testIterator() {
	
	Log::iterator it;
	int messages;
	
	messages = 0;
	for (it=glog.begin(); it!=glog.end(); ++it) {
		cout << "  " << *it << endl;
		++messages;
	}
	assert(messages == 3);
	cout << "PASSED" << endl;
}

/* Runs the test. */
int main(int argc, char *argv[]) {
	
	LogTest test;
	
	test.testInsertion();
	test.testIterator();
	cout << "ALL TESTS PASSED" << endl;
	return 0;
}
