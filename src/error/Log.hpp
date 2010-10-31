/*
 * Log.hpp
 * 
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#ifndef EDO_LOG_HPP
#define EDO_LOG_HPP
#include "edo_common.h"
#include <iomanip>                      // For floats
using namespace std;

/* Type definitions */
typedef basic_ostream< char,char_traits<char> > char_ostream_t;
typedef char_ostream_t& (*manip_func_t)(char_ostream_t&);

/* Interface for receiving updates from the log. */
class LogListener {
public:
	virtual void onLogUpdate(const string &text) = 0;
};

/** @brief Utility for logging messages.
 * @warning Assumes messages don't include newline character.
 */
class Log {
public:
	typedef list<string>::iterator iterator;
public:
	Log();
	void addListener(LogListener *listener);
	iterator begin();
	iterator end();
	void fireUpdate(const string& text);
	Log& operator<<(const string& text);
	Log& operator<<(int number);
	Log& operator<<(double number);
	Log& operator<<(manip_func_t manip);
private:
	list<string> lines;
	ostringstream buff;
	list<LogListener*> listeners;
};

/** @return Iterator to the first line in the log. */
inline Log::iterator Log::begin() {return lines.begin();}

/** @return Iterator just past the last line in the log. */
inline Log::iterator Log::end() {return lines.end();}

/** Global log */
extern Log glog;

#endif
