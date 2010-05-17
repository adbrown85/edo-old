/*
 * Cone.hpp
 * 
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#ifndef CONE_HPP
#define CONE_HPP
#include <cstdlib>
#include <iostream>
#include <string>
#include "Shape.hpp"                    // Base class
#include "Numeric.hpp"                  // Calculating circle
using namespace std;


/**
 * @ingroup basic
 * @brief Cone made from triangles.
 */
class Cone : public Shape {
public:
	Cone(const Tag &tag) : Shape(tag,getTraits()) {}
protected:
	static ShapeTraits getTraits();
	virtual void updateBuffer();
	virtual void updateBufferPoints();
	virtual void updateBufferNormals();
};


#endif