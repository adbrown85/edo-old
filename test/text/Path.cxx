/*
 * Path.cxx
 * 
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#include "Path.hpp"
#include <cassert>

/* Unit test for Path. */
class PathTest {
public:
	void testBasename();
	void testDirname();
	void testExtension();
	void testExpand();
	void testInternals();
	void testRelativePath();
	void testTokenize();
};

void PathTest::testBasename() {
	
	string result;
	
	cout << "PathTest::testBasename" << endl;
	result = Path::getBasename("input/scene.xml");
	assert(result == "scene.xml");
	cout << "PASSED" << endl;
}

void PathTest::testDirname() {
	
	string result;
	
	cout << "PathTest::testDirname" << endl;
	result = Path::getDirname("../../scene.xml");
	assert(result == "../..");
	result = Path::getDirname("input/scene.xml");
	assert(result == "input");
	result = Path::getDirname("scene.xml");
	assert(result == ".");
	result = Path::getDirname("/scene.xml");
	assert(result == "/");
	cout << "PASSED" << endl;
}

void PathTest::testExtension() {
	
	string result;
	
	cout << "PathTest::testExtension" << endl;
	result = Path::getExtension("scene.xml");
	assert(result == "xml");
	cout << "PASSED" << endl;
}

void PathTest::testExpand() {
	
	string result;
	
	cout << "PathTest::testExpand" << endl;
	result = Path::expand("${USER}/glsl/outline.glsl");
	assert(result == string(getenv("USER")) + "/glsl/outline.glsl");
	result = Path::expand("/usr/local/gander/glsl/outline.glsl");
	assert(result == "/usr/local/gander/glsl/outline.glsl");
	cout << "PASSED" << endl;
}

void PathTest::testInternals() {
	
	string result;
	
	cout << "PathTest::testInternals" << endl;
	result = Path::getInternals("input/scene.xml");
	assert(result == "input");
	result = Path::getInternals("/input/scene.xml");
	assert(result == "input");
	result = Path::getInternals("./input/scene.xml");
	assert(result == "input");
	result = Path::getInternals("../../input/scene.xml");
	assert(result == "../../input");
	result = Path::getInternals("scene.xml");
	assert(result == "");
	result = Path::getInternals("gander/input/scene.xml");
	assert(result == "gander/input");
	result = Path::getInternals("C:\\scene.xml");
	assert(result == "");
	result = Path::getInternals("C:\\gander/input/scene.xml");
	assert(result == "gander/input");
	cout << "PASSED" << endl;
}

void PathTest::testRelativePath() {
	
	string result;
	
	cout << "PathTest::testRelativePath" << endl;
	
	// Test both relative
	result = Path::getRelativePath("input\\scene.xml", "glsl/file.frag");
	assert(result == "input/glsl/file.frag");
	result = Path::getRelativePath("input/scene.xml", "../glsl/file.frag");
	assert(result == "glsl/file.frag");
	result = Path::getRelativePath("input/scene.xml", "../../glsl/file.frag");
	assert(result == "../glsl/file.frag");
	result = Path::getRelativePath("../../input/basic.vert", "file.frag");
	assert(result == "../../input/file.frag");
	
	// Test if any are absolute paths
	result = Path::getRelativePath(
			"input/scene.xml",
			"/home/user/gander/glsl/file.frag");
	assert(result == "/home/user/gander/glsl/file.frag");
	result = Path::getRelativePath(
			"/home/user/gander/input/scene.xml",
			"glsl/file.frag");
	assert(result == "/home/user/gander/input/glsl/file.frag");
	result = Path::getRelativePath(
			"/home/user/gander/input/scene.xml",
			"../glsl/file.frag");
	assert(result == "/home/user/gander/glsl/file.frag");
	
	// Test if A has no directory
	result = Path::getRelativePath("scene.xml", "../../glsl/file.frag");
	assert(result == "../../glsl/file.frag");
	
	// Test if A is in root
	try {
		Path::getRelativePath("/scene.xml", "../glsl/file.frag");
		assert(false);
	} catch (BasicException &e) {}
	try {
		Path::getRelativePath("C:\\scene.xml", "../glsl/file.frag");
		assert(false);
	} catch (BasicException &e) {}
	
	cout << "PASSED" << endl;
}

void PathTest::testTokenize() {
	
	vector<string> tokens;
	
	cout << "PathTest::testTokenize" << endl;
	Path::tokenize("input/scene.xml", tokens);
	assert(tokens[0] == "input");
	assert(tokens[1] == "scene.xml");
	cout << "PASSED" << endl;
}

/* Run test. */
int main() {
	
	PathTest test;
	
	test.testBasename();
	test.testDirname();
	test.testExtension();
	test.testExpand();
	test.testInternals();
	test.testTokenize();
	test.testRelativePath();
	cout << "ALL TESTS PASSED" << endl;
	return 0;
}

