/*
 * Target.hpp
 * 
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#ifndef TARGET_HPP
#define TARGET_HPP
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include "Node.hpp"
#include "Framebuffer.hpp"
#include "Tag.hpp"
#include "Texture2D.hpp"
using namespace std;


/**
 * @ingroup graph
 * @brief
 *     Offscreen render location backed by a texture.
 */
class Target : public Node {
	
	public:
		
		Target(const string &link);
		Target(const Tag &tag);
		string toString() const;
	
	protected:
		
		void associate();
		void finalize();
	
	private:
		
		GLuint framebufferHandle, textureHandle;
		int size;
		string link;
};


#endif
