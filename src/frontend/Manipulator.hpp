/*
 * Manipulator.hpp
 * 
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#ifndef MANIPULATOR_HPP
#define MANIPULATOR_HPP
#include "common.h"
#include "Delegate.hpp"                 // For sending commands to scene
#include "Vector.hpp"                   // For axis
#include "Transform.hpp"                // Projection matrix
#include "Traverser.hpp"


/**
 * @ingroup frontend
 * @brief Abstract base class for an item that manipulates other items.
 */
class Manipulator : public Identifiable {
public:
	Manipulator(char axis,
	            int command,
	            string filename,
	            float bias=1.0,
	            const string &warning="May not be able to use manipulator.");
	virtual ~Manipulator();
	virtual void draw(Node *node, Canvas *canvas) const;
	static float findPixelFactor(Canvas *canvas, GLuint shapeID);
	virtual Vector getAxis() const;
	virtual int getCommand() const;
	virtual bool isEnabled() const;
	virtual void setEnabled(bool enabled);
	virtual void setDelegate(Delegate *delegate);
	virtual void use(const Vector &movement, GLuint shapeID, Canvas *canvas);
protected:
	bool enabled;
	float bias;
	int command;
	Delegate *delegate;
	Scene *widget;
	Traverser *traverser;
	Vector axis, offset;
	Canvas *canvas;
};

/** @return Direction the manipulator is oriented in. */
inline Vector Manipulator::getAxis() const {return axis;}

/** @return Enumerated command to run when the user drags the manipulator. */
inline int Manipulator::getCommand() const {return command;}

/** @return True if the manipulator should be drawn. */
inline bool Manipulator::isEnabled() const {return enabled;}

/** Determines if the manipulator should be drawn. */
inline void Manipulator::setEnabled(bool enabled) {this->enabled = enabled;}

/** Changes the object to send commands to. */
inline void Manipulator::setDelegate(Delegate *i) {this->delegate = i;}


#endif
