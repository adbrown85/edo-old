/*
 * Box.hpp
 * 
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#ifndef BOX_HPP
#define BOX_HPP
#include <cstdlib>
#include <iostream>
#include <string>
#include "Hexahedron.hpp"
using namespace std;


/**
 * @ingroup basic
 * @brief Six-sided shape with 2D texture coordinates for each face.
 */
class Box : public Hexahedron {
public:
	Box(const Tag &tag) : Hexahedron(tag) {};
protected:
	virtual void initCoords();
};


#endif
