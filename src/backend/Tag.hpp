/*
 * Tag.hpp
 *
 * Author
 *     Andy Brown <andybrown85@gmail.com>
 */
#ifndef TAG_HPP
#define TAG_HPP
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
using namespace std;



/**
 * @brief
 *     XML tag holding a map of attributes and their values.
 * @ingroup backend
 */
class Tag {
	
	
	public :
		
		bool closing;
		map<string,string> attributes;
		string name;
		
		Tag();
		void error(string key) const;
		void get(const string &key,
		         char &value) const;
		void get(const string &key,
		         float &value) const;
		void get(const string &key,
		         int &value) const;
		void get(const string &key,
		         string &value) const;
		
		friend ostream& operator<<(ostream &stream,
		                           const Tag &tag);
};

#endif
