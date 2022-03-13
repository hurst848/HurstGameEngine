#include "Maths.h"

#include <SDL.h>

#include <vector>
#include <memory>
namespace HGE 
{
	/*! \brief Stores all the Key Data
	*
	* The Keys Structure stores all of the bindings to the SDLK input ints.
	* Used in the Inputs Class. 
	* FUNC refers to a keyboard function,
	* SYM refers to a keyboard symbol,
	* NUM refers to a number,
	* KEYPAD referes to a key on the number pad
	*/
	struct Keys
	{
	public:

		const int FUNC_ESCAPE = SDLK_ESCAPE;				const int FUNC_F1 = SDLK_F1;					const int FUNC_F2 = SDLK_F2;
		const int FUNC_F3 = SDLK_F3;						const int FUNC_F4 = SDLK_F4;					const int FUNC_F5 = SDLK_F5;
		const int FUNC_F6 = SDLK_F6;						const int FUNC_F7 = SDLK_F7;					const int FUNC_F8 = SDLK_F8;
		const int FUNC_F9 = SDLK_F9;						const int FUNC_F10 = SDLK_F10;					const int FUNC_F11 = SDLK_F11;
		const int FUNC_F12 = SDLK_F12;						const int FUNC_PRINTSCRN = SDLK_PRINTSCREEN;	const int FUNC_SCRLK = SDLK_SCROLLLOCK;
		const int FUNC_PAUSEBRAKE = SDLK_PAUSE;				const int SYM_BACKQUOTE = SDLK_BACKQUOTE;		const int NUM_1 = SDLK_1;
		const int NUM_2 = SDLK_2;							const int NUM_3 = SDLK_3;						const int NUM_4 = SDLK_4;
		const int NUM_5 = SDLK_5;							const int NUM_6 = SDLK_6;						const int NUM_7 = SDLK_7;
		const int NUM_8 = SDLK_8;							const int NUM_9 = SDLK_9;						const int NUM_0 = SDLK_0;
		const int SYM_MINUS = SDLK_MINUS;					const int SYM_EQUALS = SDLK_EQUALS;				const int FUNC_BACKSPACE = SDLK_BACKSPACE;
		const int FUNC_INSERT = SDLK_INSERT;				const int FUNC_HOME = SDLK_HOME;				const int FUNC_PGUP = SDLK_PAGEUP;
		const int FUNC_NUMLK = SDLK_NUMLOCKCLEAR;			const int Q = SDLK_q;							const int W = SDLK_w;
		const int E = SDLK_e;								const int R = SDLK_r;							const int T = SDLK_t;
		const int Y = SDLK_y;								const int U = SDLK_u;							const int I = SDLK_i;
		const int O = SDLK_o;								const int P = SDLK_p;							const int S = SDLK_s;
		const int D = SDLK_d;								const int F = SDLK_f;							const int G = SDLK_g;
		const int H = SDLK_h;								const int J = SDLK_j;							const int K = SDLK_k;
		const int L = SDLK_l;								const int Z = SDLK_z;							const int X = SDLK_x;
		const int C = SDLK_c;								const int V = SDLK_v;							const int B = SDLK_b;
		const int N = SDLK_n;								const int M = SDLK_m;							const int SYM_KEYPAD_DIVIDE = SDLK_KP_DIVIDE;
		const int SYM_KEYPAD_MULTIPLY = SDLK_KP_MULTIPLY;	const int SYM_KEYPAD_MINUS = SDLK_KP_MINUS;		const int FUNC_TAB = SDLK_TAB;
		const int SYM_LEFTBRACKET = SDLK_LEFTBRACKET;		const int SYM_RIGHTBRACKET = SDLK_RIGHTBRACKET;	const int SYM_BACKSLASH = SDLK_BACKSLASH;
		const int FUNC_DELETE = SDLK_DELETE;				const int FUNC_END = SDLK_END;					const int FUNC_PGDN = SDLK_PAGEDOWN;
		const int NUM_KEYPAD_7 = SDLK_KP_7;					const int NUM_KEYPAD_8 = SDLK_KP_8;				const int NUM_KEYPAD_9 = SDLK_KP_9;
		const int SYM_KEYPAD_PLUS = SDLK_KP_PLUS;			const int FUNC_CAPSLK = SDLK_CAPSLOCK;			const int A = SDLK_a;
		const int SYM_QUOTE = SDLK_QUOTE;					const int FUNC_ENTER = SDLK_RETURN;				const int NUM_KEYPAD_4 = SDLK_KP_4;
		const int NUM_KEYPAD_5 = SDLK_KP_5;					const int NUM_KEYPAD_6 = SDLK_KP_6;				const int FUNC_LEFTSHIFT = SDLK_LSHIFT;
		const int SYM_COMMA = SDLK_COMMA;					const int SYM_FULLSTOP = SDLK_PERIOD;			const int SYM_SEMICOLON = SDLK_SEMICOLON;
		const int SYM_SLASH = SDLK_SLASH;					const int FUNC_RIGHTSHIFT = SDLK_RSHIFT;		const int FUNC_UP = SDLK_UP;
		const int NUM_KEYPAD_1 = SDLK_KP_1;					const int NUM_KEYPAD_2 = SDLK_KP_2;				const int NUM_KEYPAD_3 = SDLK_KP_3;
		const int FUNC_KEYPAD_ENTER = SDLK_KP_ENTER;		const int FUNC_LEFTCTRL = SDLK_LCTRL;			const int FUNC_LEFTGUI = SDLK_LGUI;
		const int FUNC_LEFTALT = SDLK_LALT;					const int FUNC_SPACE = SDLK_SPACE;				const int FUNC_RIGHTALT = SDLK_RALT;


		const int FUNC_RIGHTGUI = SDLK_RGUI;				const int FUNC_MENU = SDLK_MENU;				const int FUNC_RIGHTCTRL = SDLK_RCTRL;
		const int FUNC_LEFT = SDLK_LEFT;					const int FUNC_DOWN = SDLK_DOWN;				const int FUNC_RIGHT = SDLK_RIGHT;
		const int NUM_KEYPAD_0 = SDLK_KP_0;					const int SYM_KEYPAD_FULLSTOP = SDLK_KP_PERIOD;

	};
	/*! \brief Stores all the Mouse Data
	*
	* The Mousecharateristics Structure stores all of the bindings to the SDLK input ints.
	* Stores all the SDLK bindings for all standard mouse buttons, as well as the mouse location.
	* Mouse sensitivity is also set here
	*/
	struct MouseCharateristics
	{
	public:
		const int MOUSE_LEFTBUTTON = SDL_BUTTON_LEFT;
		const int MOUSE_RIGHTBUTTON = SDL_BUTTON_RIGHT;
		const int MOUSE_MIDDLEBUTTON = SDL_BUTTON_MIDDLE;
		const int MOUSE_LOCATION = -1;
		const int MOUSE_DELTA = -2;

		const int MOUSE_RELATIVETRUE = -3;
		const int MOUSE_RELATIVEFALSE = -4;

		float Sensitivity = 0.5f;
		
	};
	/*! \brief Where inputs for the game engine are handled
	*
	* The Inputs Structure allows the user to retrive the state of any key or mouse charteristc
	* specified int the Keys or MouseCharateristics structures.
	*/
	struct Inputs
	{
		friend struct Core;

	public:
		//! Stores all of the SDLK keyboard bindings (Keys)
		Keys Keyboard;
		//! Stores all of the SDLK mouse bindings (MouseCharateristics)
		MouseCharateristics Mouse;
		//! Returns (bool) true a mouse button is held down and false if it is up, given an int specifing a mouse charteristic (int)
		bool GetMouseDown(const int _button);
		//! Returns (bool) true a mouse button is not held down and false if it is down, given an int specifing a mouse charteristic (int)
		bool GetMouseUp(const int _button);
		//! Returns a mouse position (vec2), given an int specifing a mouse charteristic (int)
		vec2 GetMouseData(const int _charateristic);
		//! Sets the mouse mode to relative of free, given an int specifing a mouse charteristic (int)
		void SetMouseMode(const int _setting);
		//! Returns (bool) true a key is held down and false if it is up, given an int specifing a key (int) 
		bool GetKeyDown(const int _key);
		//! Returns (bool) true a key is not held down and false if it is down, given an int specifing a key (int)
		bool GetKeyUp(const int _key);
	private:
		vec2 mousePosPrevious = vec2(0,0);
		vec2 mousePosDelta = vec2(0, 0);
	

		std::vector<int> keysDown;
		std::vector<int> mouseButtonsDown;

		void Update();
		void removeKey(const int _key);
		void removeMouseButton(const int _button);
	};
}