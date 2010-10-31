/*
 * Text.cxx
 * 
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#include "Text.hpp"
#include <cassert>

/** Test fixture for Text class. */
class TextTest {
public:
	void testCount();
	void testFirstWord();
	void testFirstWordCharacter();
	void testFirstNotWordCharacter();
	void testReplacements();
	void testTrim();
	void testStripLeadingSpaces();
	void testStripTrailingSpaces();
	void testSplit();
};

void TextTest::testCount() {
	
	int result;
	
	cout << "TextTest::testCount" << endl;
	result = Text::count("abracadabra", 'a');
	assert(result == 5);
	cout << "PASSED" << endl;
}

void TextTest::testFirstWordCharacter() {
	
	int result;
	
	cout << "TextTest::testFirstWordCharacter" << endl;
	result = Text::findFirstWordCharacter("    (foo)", 0);
	assert(result == 5);
	cout << "PASSED" << endl;
}

void TextTest::testFirstNotWordCharacter() {
	
	int result;
	
	cout << "TextTest::testFirstNotWordCharacter" << endl;
	result = Text::findFirstNotWordCharacter("    (foo)", 5);
	assert(result == 8);
	cout << "PASSED" << endl;
}

void TextTest::testFirstWord() {
	
	pair<int,int> result;
	string text;
	
	cout << "TextTest::testFirstWord" << endl;
	text = "    (foo)";
	result = Text::findFirstWord(text);
	assert(result.first  == 5);
	assert(result.second == 3);
	assert(text.substr(result.first,result.second) == "foo");
	text = " 78 * 45";
	result = Text::findFirstWord(text);
	assert(result.first  == -1);
	assert(result.second == 0);
	text = " 123foobar";
	result = Text::findFirstWord(text);
	assert(result.first  == 4);
	assert(result.second == 6);
	assert(text.substr(result.first,result.second) == "foobar");
	cout << "PASSED" << endl;
}

void TextTest::testReplacements() {
	
	map<string,string> dictionary;
	string result;
	
	cout << "TextTest::testReplacements" << endl;
	dictionary["PI_CONSTANT"] = "3.14";
	dictionary["E_CONSTANT"] = "2.72";
	result = Text::replace("4*PI_CONSTANT + E_CONSTANT BLAH", dictionary);
	assert(result == "4*3.14 + 2.72 BLAH");
	cout << "PASSED" << endl;
}

void TextTest::testTrim() {
	
	string result;
	
	cout << "TextTest::testTrim" << endl;
	result = Text::trim("  blah blah blah  ");
	assert(result == "blah blah blah");
	result = Text::trim("  \"blah blah blah\"  ", "'\" ");
	assert(result == "blah blah blah");
	cout << "PASSED" << endl;
}

void TextTest::testSplit() {
	
	pair<string,string> result;
	
	cout << "TextTest::testSplit" << endl;
	result = Text::split("spot.ambient", '.');
	assert(result.first == "spot");
	assert(result.second == "ambient");
	cout << "PASSED" << endl;
}

void TextTest::testStripLeadingSpaces() {
	
	string result;
	
	cout << "TextTest::testStripLeadingSpaces" << endl;
	result = Text::stripLeadingSpaces("\t // This is a comment");
	assert(result == "// This is a comment");
	cout << "PASSED" << endl;
}

void TextTest::testStripTrailingSpaces() {
	
	string result;
	
	cout << "TextTest::testStripTrailingSpaces" << endl;
	result = Text::stripTrailingSpaces("// This is a comment    ");
	assert(result == "// This is a comment");
	cout << "PASSED" << endl;
}

/* Runs the test. */
int main(int argc, char *argv[]) {
	
	TextTest test;
	
	test.testCount();
	test.testFirstWordCharacter();
	test.testFirstNotWordCharacter();
	test.testFirstWord();
	test.testReplacements();
	test.testTrim();
	test.testSplit();
	test.testStripLeadingSpaces();
	test.testStripTrailingSpaces();
	cout << "ALL TESTS PASSED" << endl;
	return 0;
}

