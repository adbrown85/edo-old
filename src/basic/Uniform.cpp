/*
 * Uniform.cpp
 * 
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#include "Uniform.hpp"


/**
 * Creates a new %Uniform from an XML tag.
 * 
 * @param tag XML tag with "type", "name", "value", and "link" information.
 */
Uniform::Uniform(const Tag &tag) {
	
	// Basics
	className = "Uniform";
	program = NULL;
	
	// Initialize
	tag.get("type", type);
	tag.get("name", name, true, false);
	tag.get("link", link, false, false);
}


/**
 * Finds a Program node that is an ancestor of this node.
 * 
 * @throws const_char* if program cannot be found.
 */
void Uniform::associate() {
	
	// Look for a Program ancestor
	program = Program::find(parent);
	if (program == NULL) {
		ostringstream message;
		message << "[Uniform] Program for uniform named '" << name
		        << "' cannot be found.";
		throw message.str().c_str();
	}
}


/**
 * Finds the variable's location in the program.
 * 
 * @throws const_char* if location for uniform cannot be found
 */
void Uniform::finalize() {
	
	// Look up location
	location = glGetUniformLocation(program->getHandle(), name.c_str());
	if (location == -1) {
		ostringstream message;
		message << "[Uniform] Location for uniform '" << name
		        << "' cannot be found.";
		throw message.str().c_str();
	}
}


string Uniform::toString() const {
	
	ostringstream stream;
	
	// Build string
	stream << Node::toString();
	stream << " name='" << name << "'"
	       << " location='" << location << "'";
	if (!link.empty()) {
		stream << " link='" << link << "'";
	}
	return stream.str();
}
