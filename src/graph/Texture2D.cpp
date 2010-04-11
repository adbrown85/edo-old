/*
 * Texture2D.cpp
 * 
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#include "Texture2D.hpp"
bool Texture2D::librariesLoaded=false;


/**
 * Creates a new 2D texture from a file that can be referenced by name.
 * 
 * @param name Name another node can reference.
 * @param filename Path to a file containing the texture.
 */
Texture2D::Texture2D(const string &name,
                     const string &filename) :
                     Texture(GL_TEXTURE_2D, name, filename) {
	
	// Initialize
	Texture2D::init();
}


/**
 * Creates a new 2D texture that can be referenced by name.
 * 
 * @param name Name another node can reference.
 * @param size Size of the texture's width or height in pixels.
 */
Texture2D::Texture2D(const string &name,
                     int size) :
                     Texture(GL_TEXTURE_2D, name) {
	
	// Initialize
	Texture2D::init();
	this->size = size;
}


/**
 * Creates a new 2D texture from an XML tag.
 * 
 * @param tag XML tag with "size" attributes.
 */
Texture2D::Texture2D(const Tag &tag) :
                     Texture(GL_TEXTURE_2D, tag) {
	
	// Initialize
	Texture2D::init();
	tag.get("size", size, false);
}


/**
 * Generates or loads the texture.
 * 
 * Is done here rather than @c finalize() because other nodes might need to get 
 * the texture's handle.
 */
void Texture2D::associate() {
	
	// Find unit
	Texture::associate();
	
	// Activate texture unit
	glActiveTexture(GL_TEXTURE0 + unit);
	glEnable(GL_TEXTURE_2D);
	
	// Generate or load
	if (filename.empty())
		generate();
	else
		load();
}


/**
 * Finds a %Texture2D with a specific name.
 * 
 * @param node Node to start looking.
 * @param pointer Pointer to the %Texture2D.
 * @param name Name of the node as specified by the user.
 */
void Texture2D::find(Node *node,
                     Texture2D *&pointer,
                     const string &name) {
	
	// Search
	node = node->getParent();
	while (node != NULL) {
		pointer = dynamic_cast<Texture2D*>(node);
		if (pointer != NULL) {
			if (name.compare(pointer->getName()) == 0)
				break;
			else
				pointer = NULL;
		}
		node = node->getParent();
	}
}


/**
 * Generates a blank texture.
 */
void Texture2D::generate() {
	
	// Create the texture
	glGenTextures(1, &handle);
	glBindTexture(GL_TEXTURE_2D, handle);
	glTexImage2D(GL_TEXTURE_2D,
	             0,
	             GL_RGBA8,
	             size,
	             size,
	             0,
	             GL_RGBA,
	             GL_UNSIGNED_BYTE,
	             NULL);
	
	// Set parameters
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
}


/**
 * Initializes attributes common to all constructors.
 */
void Texture2D::init() {
	
	// Attributes
	className = "Texture2D";
	this->image = 0;
	this->size = 0;
}


/**
 * Initializes required libraries, currently just DevIL.
 * 
 * Checks that DevIL libraries being run by the user are not older than the 
 * libraries used to compile Gander.  If they are, warnings are issued.  Either
 * way DevIL is initialized by calling 'ilInit'.
 * 
 * @throws const_char* if DevIL version is incorrect.
 */
void Texture2D::initLibraries() {
	
	ILint ilVersion, iluVersion, ilutVersion;
	
	// Check if already loaded
	if (librariesLoaded)
		return;
	
	// Check DevIL components
	ilVersion = ilGetInteger(IL_VERSION_NUM);
	if (ilVersion < IL_VERSION) {
		ostringstream msg;
		msg << "[Texture2D] DevIL (IL) compiled with " << IL_VERSION
		     << " but running " << ilVersion << ".";
		throw msg.str().c_str();
	}
	iluVersion = iluGetInteger(ILU_VERSION_NUM);
	if (iluVersion < ILU_VERSION) {
		ostringstream msg;
		msg << "[Texture2D] DevIL (ILU) compiled with " << ILU_VERSION
		    << " but running " << iluVersion << ".";
		throw msg.str().c_str();
	}
	ilutVersion = ilutGetInteger(ILUT_VERSION_NUM);
	if (ilutVersion < ILUT_VERSION) {
		ostringstream msg;
		msg << "[Texture2D] DevIL (ILUT) compiled with " << ILUT_VERSION
		    << " but running " << ilutVersion << ".";
		throw msg.str().c_str();
	}
	
	// Initialize DevIL
	ilInit();
	ilutRenderer(ILUT_OPENGL);
	librariesLoaded = true;
}


/**
 * Loads an image into the texture.
 * 
 * @throws const_char* if the image cannot be loaded or bound.
 */
void Texture2D::load() {
	
	// Initialize DevIL
	initLibraries();
	
	// Load image
	ilGenImages(1, &image);
	ilBindImage(image);
	if (ilLoadImage(filename.c_str()))
		cerr << "[Texture2D] DevIL loaded '" << filename
		     << "'." << endl;
	else {
		ostringstream msg;
		msg << "[Texture2D] DevIL could not load '" << filename 
		    << "'.";
		throw msg.str().c_str();
	}
	size = ilGetInteger(IL_IMAGE_WIDTH);
	
	// Load into texture
	ilBindImage(image);
	handle = ilutGLBindTexImage();
	if (handle == 0)
		throw "[Texture2D] DevIL did not bind image to texture.";
}


/**
 * Forms a string from the object's attributes.
 */
string Texture2D::toString() const {
	
	ostringstream stream;
	
	// Build string
	stream << Texture::toString();
	stream << " size='" << size << "'";
	return stream.str();
}

