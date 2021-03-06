/*
 * Tag.hpp
 * 
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#ifndef EDO_TAG_HPP
#define EDO_TAG_HPP
#include "edo_common.h"
#include "Text.hpp"
#include "BasicException.hpp"
using namespace std;

/** @brief XML tag holding a map of attributes and their values.
 * @ingroup system
 */
class Tag {
public:
	typedef map<string,string>::iterator iterator;
public:
	Tag();
	Tag(const string &name);
	iterator begin();
	void clear();
	iterator end();
	bool get(const string &key, bool &value, bool required=true) const;
	bool get(const string &key, char &value, bool required=true) const;
	bool get(const string &key, float &value, bool required=true) const;
	bool get(const string &key, float value[4], bool required=true) const;
	bool get(const string &key, int &value, bool required=true) const;
	bool get(const string &k, string &v, bool req=true, bool low=true) const;
	friend ostream& operator<<(ostream &stream, const Tag &tag);
	string& operator[](const string &key);
	string operator[](const string &key) const;
	static string toLocation(string filename, int line);
// Getters and setters
	bool hasAttribute(const string &name) const;
	bool isClosing() const;
	string getFilename() const;
	bool isLeaf() const;
	int getLine() const;
	string getLocation() const;
	string getName() const;
	void setClosing(bool leaf);
	void setLeaf(bool leaf);
	void setLine(int line);
	void setName(const string &name);
	void setFilename(const string &filename);
protected:
	void error(string key) const;
	void error(string key, string type) const;
private:
	bool closing, leaf;
	int line;
	map<string,string> attributes;
	string filename, name;
};

inline Tag::iterator Tag::begin() {return attributes.begin();}
inline Tag::iterator Tag::end() {return attributes.end();}
inline string Tag::getFilename() const {return filename;}
inline int Tag::getLine() const {return line;}
inline string Tag::getName() const {return name;}
inline bool Tag::isClosing() const {return closing;}

/** Indicates if the tag was created with a trailing slash. */
inline bool Tag::isLeaf() const {return leaf;}

inline void Tag::setClosing(bool closing) {this->closing = closing;}
inline void Tag::setFilename(const string &filename) {this->filename = filename;}
inline void Tag::setLeaf(bool leaf) {this->leaf = leaf;}
inline void Tag::setLine(int line) {this->line = line;}
inline void Tag::setName(const string &name) {this->name = Text::toLower(name);}


#endif

