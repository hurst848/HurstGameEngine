#include "SDL.h"
#include "glew.h"

namespace HGE
{
	/*! \brief Stores the Application Window
	*
	* The Screen Structure holds the SDL window for the Core, and safely
	* destroys it when done.
	*/
	struct Screen
	{
		friend struct Core;

	public:
		//! Base constructor for Screen, defaults to 640 X 480 resolution (Screen)
		Screen();
		//! Constructor for Screen (Screen) that takes a resolution as a parameter (int, int)  
		Screen(int _x, int _y);
		//! Destructor for Screen to destroy the SDL_Window*
		~Screen();

	private:

		SDL_Window* window;
	
	};

}
