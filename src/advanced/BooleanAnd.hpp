/*
 * BooleanAnd.hpp
 * 
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#ifndef BOOLEANAND_HPP
#define BOOLEANAND_HPP
#include <cstdlib>
#include <iostream>
#include <string>
#include "Boolean.hpp"
#include "UniformSampler.hpp"
using namespace std;


/**
 * @ingroup advanced
 * @brief Boolean AND operation of two shapes.
 */
class BooleanAnd : public Boolean {
public:
	BooleanAnd(const Tag &tag) : Boolean(tag,getTraits()) {}
	virtual void associate();
	UniformSampler* findSampler(Shape *shape);
	virtual void findUnits();
	static ShapeTraits getTraits();
protected:
	virtual void initPoints();
	virtual void initCoords();
	virtual void updateTangible();
private:
	GLfloat points[24][3], coords[2][24][3];
	list<int> units;
};


#endif
