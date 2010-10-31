/*
 * Parser.cxx
 * 
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#include <iostream>
#include <cassert>
#include "Parser.hpp"

/** Test fixture for Parser. */
class ParserTest {
public:
	void testOpen();
	void testEmptyAttributes();
};

/** Ensures an XML file can be opened properly. */
void ParserTest::testOpen() {
	
	Parser parser;
	vector<Tag> tags;
	
	cout << "ParserTest::TestOpen()" << endl;
	parser.open("test/text/Parser-1.xml");
	tags = parser.getTags();
	assert(tags[0].getName() == "program");
	assert(tags[0].isClosing() == false);
	assert(tags[1].getName() == "shader");
	assert(tags[1].isLeaf() == true);
	assert(tags[1]["type"] == "vertex");
	assert(tags[1]["file"] == "shader-file.frag");
	assert(tags[2].getName() == "translate");
	assert(tags[2].isClosing() == false);
	assert(tags[2]["x"] == "1.0");
	assert(tags[2]["y"] == "2.0");
	assert(tags[2]["z"] == "3.0");
	assert(tags[3].getName() == "shape");
	assert(tags[3].isLeaf() == true);
	assert(tags[3]["type"] == "box");
	assert(tags[3]["size"] == "1.0");
	assert(tags[4].getName() == "uniform");
	assert(tags[4].isLeaf() == true);
	assert(tags[4]["type"] == "vec4");
	assert(tags[4]["name"] == "position");
	assert(tags[4]["value"] == "1.0 2.0 -3.0 4.0");
	assert(tags[5].getName() == "translate");
	assert(tags[5].isClosing() == true);
	assert(tags[6].getName() == "program");
	assert(tags[6].isClosing() == true);
	cout << "PASSED" << endl;
}

/** Ensures an exception will be thrown if an empty attribute is found. */
void ParserTest::testEmptyAttributes() {
	
	Parser parser;
	
	cout << "ParserTest::testEmptyAttributes()" << endl;
	try {
		parser.open("test/text/Parser-2.xml");
		assert(false);
	} catch (exception &e) {
		cout << "PASSED" << endl;
	}
}

/* Runs the test. */
int main(int argc, char **argv) {
	
	ParserTest test;
	
	test.testOpen();
	test.testEmptyAttributes();
	cout << "PASSED ALL TESTS" << endl;
	return 0;
}

