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


/** @brief %BasicException backed by a stringstream for easy message building.
 */
class BasicException : public exception {
public:
	BasicException() {};
	BasicException(const BasicException &e);
	BasicException(const string &message);
	~BasicException() throw() {}
	string getMessage() const;
	const char* what() const throw();
	ostream& operator<<(const string &message);
	ostream& operator<<(const BasicException &e);
private:
	ostringstream buffer;
};


#endif
