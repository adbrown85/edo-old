/*
 * OctreeNode.hpp
 * 
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#ifndef OCTREENODE_HPP
#define OCTREENODE_HPP
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <GL/glut.h>
using namespace std;


/**
 * @ingroup data
 * @brief Element of an octree.
 */
class OctreeNode {
public:
	OctreeNode();
	OctreeNode* getChild(int index);
	bool isEmpty();
	void setChild(int index, OctreeNode *childNode);
	void setEmpty(bool empty);
	string toString();
protected:
	bool empty;
	OctreeNode *children[8];
};

inline OctreeNode* OctreeNode::getChild(int index) {return children[index];}

inline bool OctreeNode::isEmpty() {return empty;}

inline void OctreeNode::setChild(int i, OctreeNode *c) {children[i] = c;}

inline void OctreeNode::setEmpty(bool empty) {this->empty = empty;}


#endif
