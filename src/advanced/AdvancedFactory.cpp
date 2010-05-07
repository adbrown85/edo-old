/*
 * AdvancedFactory.cpp
 * 
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#include "AdvancedFactory.hpp"
bool AdvancedFactory::installed=false;


void AdvancedFactory::install() {
	
	// Check if already called
	if (installed)
		return;
	installed = true;
	
	// Tags
	BasicFactory::install();
	Factory::install("boolean", &createBoolean);
	Factory::install("blend", &createBlend);
	Factory::install("cull", &createCull);
	Factory::install("framebuffer", &createFramebuffer);
	Factory::install("fullscreen", &createFullscreen);
	Factory::install("group", &createGroup);
	Factory::install("instance", &createInstance);
	Factory::install("octree", &createOctree);
	Factory::install("target", &createTarget);
	Factory::install("wireframe", &createWireframe);
}


Node* AdvancedFactory::createBlend(const Tag &tag) {
	
	return new Blend(tag);
}


/** @throws NodeException if boolean operation not supported. */
Node* AdvancedFactory::createBoolean(const Tag &tag) {
	
	string operation;
	
	tag.get("operation", operation);
	if (operation == "and") {
		return new BooleanAnd(tag);
	} else {
		NodeException e(tag);
		e << "[AdvancedFactory] Boolean operation not supported.";
		throw e;
	}
}


Node* AdvancedFactory::createCull(const Tag &tag) {
	
	return new Cull(tag);
}


Node* AdvancedFactory::createFramebuffer(const Tag &tag) {
	
	return new Framebuffer(tag);
}


Node* AdvancedFactory::createFullscreen(const Tag &tag) {
	
	return new Fullscreen(tag);
}


Node* AdvancedFactory::createGroup(const Tag &tag) {
	
	return new Group(tag);
}


Node* AdvancedFactory::createInstance(const Tag &tag) {
	
	return new Instance(tag);
}


Node* AdvancedFactory::createOctree(const Tag &tag) {
	
	return new Octree(tag);
}


Node* AdvancedFactory::createTarget(const Tag &tag) {
	
	return new Target(tag);
}


Node* AdvancedFactory::createWireframe(const Tag &tag) {
	
	return new Wireframe(tag);
}

