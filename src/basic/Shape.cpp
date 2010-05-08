/*
 * Shape.cpp
 * 
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#include "Shape.hpp"


/** Creates a shape from an XML tag.
 * 
 * @param tag XML tag with attributes for Drawable.
 * @param count Number of vertices in the shape.
 * @param attributes List of generic vertex attributes.
 * @param mode GL_TRIANGLES or GL_QUADS.
 * @param usage GL_STATIC_DRAW or GL_DYNAMIC_DRAW.
 */
Shape::Shape(const Tag &tag,
             GLuint count,
             list<string> attributes,
             GLenum mode,
             GLenum usage) : Drawable(tag) {
	
	// Copy
	this->count = count;
	this->mode = mode;
	this->usage = usage;
	
	// Store attributes
	list<string>::iterator it;
	int i=0;
	for (it=attributes.begin(); it!=attributes.end(); ++it) {
		Attribute attribute;
		attribute.name = *it;
		attribute.number = i;
		attribute.location = i;
		this->attributes.push_back(attribute);
		++i;
	}
}


/** Finds a program to bind the shape's vertex attributes to.
 * 
 * @throws NodeException if a program cannot be found.
 */
void Shape::associate() {
	
	// Find program
	program = Program::find(parent);
	if (program == NULL) {
		NodeException e(tag);
		e << "[Shape] No shader program found to bind attributes to.";
		throw e;
	}
}


/** Renders the shape. */
void Shape::draw() const {
	
	list<Attribute>::const_iterator it;
	
	// Enable buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	
	// Enable attributes
	for (it=attributes.begin(); it!=attributes.end(); ++it) {
		glEnableVertexAttribArray(it->location);
		glVertexAttribPointer(it->location,
		                      3,
		                      GL_FLOAT,
		                      false,
		                      0,
		                      (void*)offset(it->number));
	}
	
	// Draw
	glDrawArrays(mode, 0, count);
	
	// Disable attributes
	for (it=attributes.begin(); it!=attributes.end(); ++it) {
		glDisableVertexAttribArray(it->location);
	}
	
	// Disable buffer
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}


/** Loads the vertex data into the vertex buffer so it's ready to render. */
void Shape::finalize() {
	
	// Initialize the buffer
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, offset(attributes.size()), NULL, usage);
	
	// Bind attributes
	list<Attribute>::iterator it;
	for (it=attributes.begin(); it!=attributes.end(); ++it) {
		program->setAttributeLocation(it->location, it->name);
	}
	
	// Initialize attributes
	initAttributeValues();
}

