/*
 * About.cpp
 * 
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#include "About.hpp"


/** Shows an %About dialog parented to @e window. */
void About::show(Gtk::Window *parent) {
	
	Gtk::AboutDialog dialog;
	vector<string> authors;
	
	// Set up
	authors.push_back("Andrew Brown <adb1413@rit.edu>");
	
	// Pack
	dialog.set_program_name(PACKAGE_NAME);
	dialog.set_version(PACKAGE_VERSION);
	dialog.set_website(PACKAGE_URL);
	dialog.set_logo(Gdk::Pixbuf::create_from_file(getIconFilename()));
	dialog.set_authors(authors);
	
	// Run
	if (parent != NULL) {
		dialog.set_transient_for(*parent);
	}
	dialog.run();
}


string About::getIconFilename() {
	
	ostringstream stream;
	
	stream << GANDER_DATA_DIR << '/' << "ui/gander.png";
	return stream.str();
}

