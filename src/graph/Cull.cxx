/*
 * Cull.cxx
 * 
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#include "Cull.hpp"
#include "Tester.hpp"
#include "GeneralFactory.hpp"
#include "UniformFactory.hpp"


int main(int argc,
         char *argv[]) {
	
	try {
		Tester::init(argc, argv);
		Tester::install(new GeneralFactory());
		Tester::install(new UniformFactory());
		Tester::open("Cull.xml");
		Tester::start();
	} catch (const char *e) {
		cerr << e << endl;
	}
	return 0;
}

