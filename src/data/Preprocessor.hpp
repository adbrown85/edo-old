/*
 * Preprocessor.hpp
 *
 * Author
 *     Andrew Brown <andrew@andrewdbrown.com>
 */
#ifndef PREPROCESSOR_HPP
#define PREPROCESSOR_HPP
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <stack>
#include <vector>
using namespace std;


/**
 * @ingroup data
 * @brief
 *     Utility for preprocessing C-like code.
 * 
 * Basically, %Preprocessor simply looks through C-like code and performs a few 
 * simple operations.  First, if it finds an @e include directive, it replaces 
 * that line with the lines from the appropriate file.  Define directives can 
 * be used to make sure this only happens once.  Lastly, it strips both 
 * multiline and single line comments, as well as trailing spaces.
 */
class Preprocessor {
	
	public :
		
		Preprocessor(const string &filename);
		vector<string> getLines();
		void printDefines();
		void printLines();
		void start();
	
	protected:
		
		set<string> defines;
		stack<bool> conditionals;
		string filename;
		vector<string> lines;
		
		void addLine(string &line,
		             bool &inComment);
		string getPragmaArgument(const string &line);
		bool isDefine(const string &line);
		bool isEndIf(const string &line);
		bool isIfNotDefined(const string &line);
		bool isInclude(const string &line);
		bool isPragma(const string &line);
		void load(const string &filename);
		void onDefine(const string &line);
		void onEndIf(const string &line);
		void onIfNotDefined(const string &line);
		void onInclude(const string &line);
		bool skipLines();
		string stripComments(const string &line,
		                     bool &inComment);
		string stripQuoted(const string &line);
		string stripTrailingSpaces(const string &line);
};


/**
 * @return the lines of the file that are actual code.
 */
inline vector<string> Preprocessor::getLines() {
	
	return lines;
}


#endif