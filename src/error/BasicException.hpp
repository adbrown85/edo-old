/*
 * BasicException.hpp
 * 
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#ifndef EDO_BASIC_EXCEPTION_HPP
#define EDO_BASIC_EXCEPTION_HPP
#include "edo_common.h"
#include <exception>
using namespace std;


/** @brief Basic exception backed by a stream for easy message building. */
class BasicException : public exception {
public:
	BasicException() {};
	BasicException(const BasicException &e);
	BasicException(const string &message);
	virtual ~BasicException() throw() {}
	virtual string getMessage() const;
	virtual const char* what() const throw();
	ostream& operator<<(const string &message);
	ostream& operator<<(const BasicException &e);
private:
	ostringstream buffer;
};


#endif
