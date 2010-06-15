/*
 * gander.hxx
 * 
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#ifndef GANDER_HXX
#define GANDER_HXX
#include "common.h"
#include "Display.hpp"
#include "Keyboard.hpp"
#include "Mouse.hpp"
#include "Inspector.hpp"
#include "LogBook.hpp"
#include "DatasetAnalyzer.hpp"
#include "DatasetHeader.hpp"
#include "DatasetViewer.hpp"
#include "DatasetWriter.hpp"
#include "Preprocessor.hpp"
#include "CanvasGTK.hpp"
#include "Menu.hpp"
using namespace std;


/** @mainpage
 * @image html gander.png
 * 
 * <table align="center" border="0" style="width:34em"><tr><td>
 * This document describes the C++ classes that make up %Gander.  We suggest 
 * starting with the @e Modules page, which gives a good overview of how the 
 * application is divided up.</p>
 * 
 * After that, check out the <i>Class Hierarchy</i> to get a better idea of 
 * how the classes work together, or go ahead and dive in to the actual 
 * classes themselves.
 * 
 * For the latest source code, check out our <a 
 * href="http://gander.git.sourceforge.net/git/gitweb.cgi?p=gander/gander" 
 * target="_blank">Git repository</a>.
 * </td></tr></table>
 * 
 * @defgroup system System
 * @defgroup graphics Graphics
 * @defgroup scene Scene
 * @defgroup basic Basic
 * @defgroup advanced Advanced
 * @defgroup command Command
 * @defgroup gui GUI
 */
 
 
/** @brief Main application. */
class Gander {
public:
	Gander(int argc, char *argv[]);
	~Gander();
	void start();
protected:
	void banner();
	void onCompile();
	void onConvert();
	void onDisplay();
	void onHeader();
	void onHistogram();
	void onPreprocess();
	void onRange();
	void onSlices();
	void parse();
	void prime();
	void usage();
private:
	int argc;
	char **argv;
	list<Control*> controls;
	Display *display;
	Delegate *delegate;
	Canvas *canvas;
	Scene *scene;
	Menu *menu;
	string inFilename, option, outFilename, parameter, title;
};


#endif
