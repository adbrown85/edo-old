/*
 * Texture.cxx
 *
 * Author
 *     Andy Brown <andybrown85@gmail.com>
 */
#include <sstream>
#include "Texture.hpp"


class FakeTexture : public Texture {
	public:
		FakeTexture(string name,
		            string filename) : Texture(name,filename) {}
		FakeTexture(const Tag &tag) : Texture(tag) {}
	protected:
		void initType() {type = GL_TEXTURE_2D;}
};


/**
 * Unit test for Texture.
 */
int main() {
	
	ostringstream name;
	Node *root, *last;
	Tag tag;
	Texture *texture;
	
	// Test tag
	cout << "\nTesting tag..." << endl;
	tag.attributes["name"] = "foo";
	tag.attributes["file"] = "glsl/bar.frag";
	texture = new FakeTexture(tag);
	texture->print();
	
	// Create textures
	cout << "\nCreating textures..." << endl;
	root = new Node();
	last = root;
	for (int i=0; i<4; ++i) {
		name.str("");
		name << "crate" << i+1;
		texture = new FakeTexture(name.str(), "../../input/crate.jpg");
		last->addChild(texture);
		last = texture;
	}
	
	// Prepare nodes
	cout << "\nPreparing nodes..." << endl;
	root->associateTree();
	root->finalizeTree();
	root->printTree();
}

