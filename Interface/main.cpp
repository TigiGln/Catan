#include "Interface.hpp"

#include <gtkmm.h>


int main(int argc, char* argv[])
{
	srand(time(NULL));
	// Initialize gtkmm
	Gtk::Main app(argc, argv);
	// Create the window
	Interface I;
	// Start main loop
	Gtk::Main::run(I);
	return 0;
}