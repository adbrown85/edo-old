/*
 * Tag.cxx
 * 
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#include <cassert>
#include "Tag.hpp"

class TagTest {
public:
	void testCreate();
	void testGetArray();
private:
	Tag tag;
};

void TagTest::testCreate() {
	
	cout << "TagTest::testCreate()" << endl;
	tag.setName("Foo");
	tag["fOO"] = "bAr";
	tag["fIle"] = "/foo/Bar";
	assert(tag.getName() == "foo");
	assert(tag["foo"] == "bAr");
	assert(tag["file"] == "/foo/Bar");
	cout << "PASSED" << endl;
}

void TagTest::testGetArray() {
	
	float value[4];
	
	cout << "TagTest::testGetArray" << endl;
	tag["value"] = "0.4 2.1 4.5 -5.9";
	tag.get("value", value);
	assert(value[0] == 0.4f);
	assert(value[1] == 2.1f);
	assert(value[2] == 4.5f);
	assert(value[3] == -5.9f);
	cout << "PASSED" << endl;
}

int main() {
	
	TagTest test;
	
	test.testCreate();
	test.testGetArray();
	cout << "ALL TESTS PASSED" << endl;
	return 0;
}

