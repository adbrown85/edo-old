/*
 * Client.hpp
 *     Client for visualizing volumes.
 *
 * Author
 *     Andy Brown <adb1413@rit.edu>
 */
#ifndef __CLIENT_HPP__
#define __CLIENT_HPP__
#include <cstdlib>
#include <GL/glut.h>
#include <iostream>
#include <string>
#include "Display.hpp"
#include "Interpreter.hpp"
#include "Keyboard.hpp"
#include "Menu.hpp"
#include "Mouse.hpp"
#include "Scene.hpp"
using std::cerr;
using std::endl;
using std::string;


/**
 * @mainpage
 * <table align="center" border="0" width="70%">
 * <tr>
 *     <td><img src="../gander-big.png"></td>
 * </tr>
 * <tr>
 *     <td><p>This document describes the C++ classes that make up 
 *         <a href="../" target="_parent">Gander</a>.  We suggest starting 
 *         with the <i>Modules</i> page, which gives a good overview of how the 
 *         application is divided up into several different layers, starting 
 *         at the bottom with <i>Data</i> and moving all the way up to 
 *         <i>Graph</i>, <i>Backend</i>, <i>Frontend</i>, and finally 
 *         <i>%Client</i>.
 *         <p>After that, check out the <i>Class Hierarchy</i> to get a 
 *         better idea of how the classes work together.  Finally, go ahead 
 *         and dive in to the actual classes themselves.
 *         <p>For source code, check out our <a 
 *         href="http://gander.git.sourceforge.net"
 *         target="_parent">Git repository</a>.
 * </td>
 * </tr>
 * </table>
 */
/**
 * @defgroup client Client
 * @defgroup frontend Frontend
 * @defgroup backend Backend
 * @defgroup graph Graph
 * @defgroup data Data
 */
/**
 * @brief
 *     Ties together a %Display with %Mouse, %Keyboard, and %Menu controls.
 * @ingroup client
 */
class Client {
	
	
	public :
		
		
		Client();
		~Client();
		
		void parse(int argc, char *argv[]);
		void print();
		void start();
		
		string getName() {return name;}
		void setName(string filename);
	
	
	private :
		
		Scene *scene;
		string name, sceneFilename;
};


#endif