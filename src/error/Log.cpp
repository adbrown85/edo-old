/*
 * Log.cpp
 * 
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#include "Log.hpp"
Log glog;

/** Creates a new log. */
Log::Log() {
	
	buff << fixed << setprecision(2);
}

/** Adds an observer that will be notified of updates. */
void Log::addListener(LogListener *listener) {
	
	listeners.push_back(listener);
}

/** Sends an update to all listeners. */
void Log::fireUpdate(const string &text) {
	
	list<LogListener*>::iterator it;
	
	for (it=listeners.begin(); it!=listeners.end(); ++it) {
		(*it)->onLogUpdate(text);
	}
}

/** Inserts an iostream manipulator (endl) into the stream. */
Log& Log::operator<<(manip_func_t manip) {
	
	(*manip)(cerr);
	if (manip == (manip_func_t)endl) {
		lines.push_back(buff.str());
		fireUpdate(buff.str());
		buff.str("");
	} else {
		(*manip)(buff);
	}
	return *this;
}

/** Inserts a string into the log. */
Log& Log::operator<<(const string &text) {
	
	buff << text;
	cerr << text;
	return *this;
}

/** Inserts an integer into the log. */
Log& Log::operator<<(int number) {
	
	buff << number;
	cerr << number;
	return *this;
}

/** Inserts a double into the log. */
Log& Log::operator<<(double number) {
	
	buff << number;
	cerr << number;
	return *this;
}

