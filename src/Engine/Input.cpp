#include "Input.h"

#include "Core.h"

namespace HGE
{
	void Inputs::Update()
	{

		mousePosDelta = vec2(0, 0);

		SDL_Event event = { 0 };
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{

			}
			else if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					if (!GetKeyDown(Keyboard.FUNC_ESCAPE)) { keysDown.push_back(Keyboard.FUNC_ESCAPE); }
					break;
				case SDLK_F1:
					if (!GetKeyDown(Keyboard.FUNC_F1)) { keysDown.push_back(Keyboard.FUNC_F1); }
					break;
				case SDLK_F2:
					if (!GetKeyDown(Keyboard.FUNC_F2)) { keysDown.push_back(Keyboard.FUNC_F2); }
					break;
				case SDLK_F3:
					if (!GetKeyDown(Keyboard.FUNC_F3)) { keysDown.push_back(Keyboard.FUNC_F3); }
					break;
				case SDLK_F4:
					if (!GetKeyDown(Keyboard.FUNC_F4)) { keysDown.push_back(Keyboard.FUNC_F4); }
					break;
				case SDLK_F5:
					if (!GetKeyDown(Keyboard.FUNC_F5)) { keysDown.push_back(Keyboard.FUNC_F5); }
					break;
				case SDLK_F6:
					if (!GetKeyDown(Keyboard.FUNC_F6)) { keysDown.push_back(Keyboard.FUNC_F6); }
					break;
				case SDLK_F7:
					if (!GetKeyDown(Keyboard.FUNC_F7)) { keysDown.push_back(Keyboard.FUNC_F7); }
					break;
				case SDLK_F8:
					if (!GetKeyDown(Keyboard.FUNC_F8)) { keysDown.push_back(Keyboard.FUNC_F8); }
					break;
				case SDLK_F9:
					if (!GetKeyDown(Keyboard.FUNC_F9)) { keysDown.push_back(Keyboard.FUNC_F9); }
					break;
				case SDLK_F10:
					if (!GetKeyDown(Keyboard.FUNC_F10)) { keysDown.push_back(Keyboard.FUNC_F10); }
					break;
				case SDLK_F11:
					if (!GetKeyDown(Keyboard.FUNC_F11)) { keysDown.push_back(Keyboard.FUNC_F11); }
					break;
				case SDLK_F12:
					if (!GetKeyDown(Keyboard.FUNC_F12)) { keysDown.push_back(Keyboard.FUNC_F12); }
					break;
				case SDLK_PRINTSCREEN:
					if (!GetKeyDown(Keyboard.FUNC_PRINTSCRN)) { keysDown.push_back(Keyboard.FUNC_PRINTSCRN); }
					break;
				case SDLK_SCROLLLOCK:
					if (!GetKeyDown(Keyboard.FUNC_SCRLK)) { keysDown.push_back(Keyboard.FUNC_SCRLK); }
					break;
				case SDLK_PAUSE:
					if (!GetKeyDown(Keyboard.FUNC_PAUSEBRAKE)) { keysDown.push_back(Keyboard.FUNC_PAUSEBRAKE); }
					break;
				case SDLK_BACKQUOTE:
					if (!GetKeyDown(Keyboard.SYM_BACKQUOTE)) { keysDown.push_back(Keyboard.SYM_BACKQUOTE); }
					break;
				case SDLK_1:
					if (!GetKeyDown(Keyboard.NUM_1)) { keysDown.push_back(Keyboard.NUM_1); }
					break;
				case SDLK_2:
					if (!GetKeyDown(Keyboard.NUM_2)) { keysDown.push_back(Keyboard.NUM_2); }
					break;
				case SDLK_3:
					if (!GetKeyDown(Keyboard.NUM_3)) { keysDown.push_back(Keyboard.NUM_3); }
					break;
				case SDLK_4:
					if (!GetKeyDown(Keyboard.NUM_4)) { keysDown.push_back(Keyboard.NUM_4); }
					break;
				case SDLK_5:
					if (!GetKeyDown(Keyboard.NUM_5)) { keysDown.push_back(Keyboard.NUM_5); }
					break;
				case SDLK_6:
					if (!GetKeyDown(Keyboard.NUM_6)) { keysDown.push_back(Keyboard.NUM_6); }
					break;
				case SDLK_7:
					if (!GetKeyDown(Keyboard.NUM_7)) { keysDown.push_back(Keyboard.NUM_7); }
					break;
				case SDLK_8:
					if (!GetKeyDown(Keyboard.NUM_8)) { keysDown.push_back(Keyboard.NUM_8); }
					break;
				case SDLK_9:
					if (!GetKeyDown(Keyboard.NUM_9)) { keysDown.push_back(Keyboard.NUM_9); }
					break;
				case SDLK_0:
					if (!GetKeyDown(Keyboard.NUM_0)) { keysDown.push_back(Keyboard.NUM_0); }
					break;
				case SDLK_MINUS:
					if (!GetKeyDown(Keyboard.SYM_MINUS)) { keysDown.push_back(Keyboard.SYM_MINUS); }
					break;
				case SDLK_EQUALS:
					if (!GetKeyDown(Keyboard.SYM_EQUALS)) { keysDown.push_back(Keyboard.SYM_EQUALS); }
					break;
				case SDLK_BACKSPACE:
					if (!GetKeyDown(Keyboard.FUNC_BACKSPACE)) { keysDown.push_back(Keyboard.FUNC_BACKSPACE); }
					break;
				case SDLK_INSERT:
					if (!GetKeyDown(Keyboard.FUNC_INSERT)) { keysDown.push_back(Keyboard.FUNC_INSERT); }
					break;
				case SDLK_HOME:
					if (!GetKeyDown(Keyboard.FUNC_HOME)) { keysDown.push_back(Keyboard.FUNC_HOME); }
					break;
				case SDLK_PAGEUP:
					if (!GetKeyDown(Keyboard.FUNC_PGUP)) { keysDown.push_back(Keyboard.FUNC_PGUP); }
					break;
				case SDLK_NUMLOCKCLEAR:
					if (!GetKeyDown(Keyboard.FUNC_NUMLK)) { keysDown.push_back(Keyboard.FUNC_NUMLK); }
					break;
				case SDLK_KP_DIVIDE:
					if (!GetKeyDown(Keyboard.SYM_KEYPAD_DIVIDE)) { keysDown.push_back(Keyboard.SYM_KEYPAD_DIVIDE); }
					break;
				case SDLK_KP_MULTIPLY:
					if (!GetKeyDown(Keyboard.SYM_KEYPAD_MULTIPLY)) { keysDown.push_back(Keyboard.SYM_KEYPAD_MULTIPLY); }
					break;
				case SDLK_KP_MINUS:
					if (!GetKeyDown(Keyboard.SYM_KEYPAD_MINUS)) { keysDown.push_back(Keyboard.SYM_KEYPAD_MINUS); }
					break;
				case SDLK_TAB:
					if (!GetKeyDown(Keyboard.FUNC_TAB)) { keysDown.push_back(Keyboard.FUNC_TAB); }
					break;
				case SDLK_q:
					if (!GetKeyDown(Keyboard.Q)) { keysDown.push_back(Keyboard.Q); }
					break;
				case SDLK_w:
					if (!GetKeyDown(Keyboard.W)) { keysDown.push_back(Keyboard.W); }
					break;
				case SDLK_e:
					if (!GetKeyDown(Keyboard.E)) { keysDown.push_back(Keyboard.E); }
					break;
				case SDLK_r:
					if (!GetKeyDown(Keyboard.R)) { keysDown.push_back(Keyboard.R); }
					break;
				case SDLK_t:
					if (!GetKeyDown(Keyboard.T)) { keysDown.push_back(Keyboard.T); }
					break;
				case SDLK_y:
					if (!GetKeyDown(Keyboard.Y)) { keysDown.push_back(Keyboard.Y); }
					break;
				case SDLK_u:
					if (!GetKeyDown(Keyboard.U)) { keysDown.push_back(Keyboard.U); }
					break;
				case SDLK_i:
					if (!GetKeyDown(Keyboard.I)) { keysDown.push_back(Keyboard.I); }
					break;
				case SDLK_o:
					if (!GetKeyDown(Keyboard.O)) { keysDown.push_back(Keyboard.O); }
					break;
				case SDLK_p:
					if (!GetKeyDown(Keyboard.P)) { keysDown.push_back(Keyboard.P); }
					break;
				case SDLK_a:
					if (!GetKeyDown(Keyboard.A)) { keysDown.push_back(Keyboard.A); }
					break;
				case SDLK_s:
					if (!GetKeyDown(Keyboard.S)) { keysDown.push_back(Keyboard.S); }
					break;
				case SDLK_d:
					if (!GetKeyDown(Keyboard.D)) { keysDown.push_back(Keyboard.D); }
					break;
				case SDLK_f:
					if (!GetKeyDown(Keyboard.F)) { keysDown.push_back(Keyboard.F); }
					break;
				case SDLK_g:
					if (!GetKeyDown(Keyboard.G)) { keysDown.push_back(Keyboard.G); }
					break;
				case SDLK_h:
					if (!GetKeyDown(Keyboard.H)) { keysDown.push_back(Keyboard.H); }
					break;
				case SDLK_j:
					if (!GetKeyDown(Keyboard.J)) { keysDown.push_back(Keyboard.J); }
					break;
				case SDLK_k:
					if (!GetKeyDown(Keyboard.K)) { keysDown.push_back(Keyboard.K); }
					break;
				case SDLK_l:
					if (!GetKeyDown(Keyboard.L)) { keysDown.push_back(Keyboard.L); }
					break;
				case SDLK_z:
					if (!GetKeyDown(Keyboard.Z)) { keysDown.push_back(Keyboard.Z); }
					break;
				case SDLK_x:
					if (!GetKeyDown(Keyboard.X)) { keysDown.push_back(Keyboard.X); }
					break;
				case SDLK_c:
					if (!GetKeyDown(Keyboard.C)) { keysDown.push_back(Keyboard.C); }
					break;
				case SDLK_v:
					if (!GetKeyDown(Keyboard.V)) { keysDown.push_back(Keyboard.V); }
					break;
				case SDLK_b:
					if (!GetKeyDown(Keyboard.B)) { keysDown.push_back(Keyboard.B); }
					break;
				case SDLK_n:
					if (!GetKeyDown(Keyboard.N)) { keysDown.push_back(Keyboard.N); }
					break;
				case SDLK_m:
					if (!GetKeyDown(Keyboard.M)) { keysDown.push_back(Keyboard.M); }
					break;
				case SDLK_LEFTBRACKET:
					if (!GetKeyDown(Keyboard.SYM_LEFTBRACKET)) { keysDown.push_back(Keyboard.SYM_LEFTBRACKET); }
					break;
				case SDLK_RIGHTBRACKET:
					if (!GetKeyDown(Keyboard.SYM_RIGHTBRACKET)) { keysDown.push_back(Keyboard.SYM_RIGHTBRACKET); }
					break;
				case SDLK_BACKSLASH:
					if (!GetKeyDown(Keyboard.SYM_BACKSLASH)) { keysDown.push_back(Keyboard.SYM_BACKSLASH); }
					break;
				case SDLK_DELETE:
					if (!GetKeyDown(Keyboard.FUNC_DELETE)) { keysDown.push_back(Keyboard.FUNC_DELETE); }
					break;
				case SDLK_END:
					if (!GetKeyDown(Keyboard.FUNC_END)) { keysDown.push_back(Keyboard.FUNC_END); }
					break;
				case SDLK_PAGEDOWN:
					if (!GetKeyDown(Keyboard.FUNC_PGDN)) { keysDown.push_back(Keyboard.FUNC_PGDN); }
					break;
				case SDLK_QUOTE:
					if (!GetKeyDown(Keyboard.SYM_QUOTE)) { keysDown.push_back(Keyboard.SYM_QUOTE); }
					break;
				case SDLK_RETURN:
					if (!GetKeyDown(Keyboard.FUNC_ENTER)) { keysDown.push_back(Keyboard.FUNC_ENTER); }
					break;
				case SDLK_KP_4:
					if (!GetKeyDown(Keyboard.NUM_KEYPAD_4)) { keysDown.push_back(Keyboard.NUM_KEYPAD_4); }
					break;
				case SDLK_KP_5:
					if (!GetKeyDown(Keyboard.NUM_KEYPAD_5)) { keysDown.push_back(Keyboard.NUM_KEYPAD_5); }
					break;
				case SDLK_KP_6:
					if (!GetKeyDown(Keyboard.NUM_KEYPAD_6)) { keysDown.push_back(Keyboard.NUM_KEYPAD_6); }
					break;
				case SDLK_LSHIFT:
					if (!GetKeyDown(Keyboard.FUNC_LEFTSHIFT)) { keysDown.push_back(Keyboard.FUNC_LEFTSHIFT); }
					break;
				case SDLK_COMMA:
					if (!GetKeyDown(Keyboard.SYM_COMMA)) { keysDown.push_back(Keyboard.SYM_COMMA); }
					break;
				case SDLK_PERIOD:
					if (!GetKeyDown(Keyboard.SYM_FULLSTOP)) { keysDown.push_back(Keyboard.SYM_FULLSTOP); }
					break;
				case SDLK_SEMICOLON:
					if (!GetKeyDown(Keyboard.SYM_SEMICOLON)) { keysDown.push_back(Keyboard.SYM_SEMICOLON); }
					break;
				case SDLK_SLASH:
					if (!GetKeyDown(Keyboard.SYM_SLASH)) { keysDown.push_back(Keyboard.SYM_SLASH); }
					break;
				case SDLK_RSHIFT:
					if (!GetKeyDown(Keyboard.FUNC_RIGHTSHIFT)) { keysDown.push_back(Keyboard.FUNC_RIGHTSHIFT); }
					break;
				case SDLK_UP:
					if (!GetKeyDown(Keyboard.FUNC_UP)) { keysDown.push_back(Keyboard.FUNC_UP); }
					break;
				case SDLK_KP_1:
					if (!GetKeyDown(Keyboard.NUM_KEYPAD_1)) { keysDown.push_back(Keyboard.NUM_KEYPAD_1); }
					break;
				case SDLK_KP_2:
					if (!GetKeyDown(Keyboard.NUM_KEYPAD_2)) { keysDown.push_back(Keyboard.NUM_KEYPAD_2); }
					break;
				case SDLK_KP_3:
					if (!GetKeyDown(Keyboard.NUM_KEYPAD_3)) { keysDown.push_back(Keyboard.NUM_KEYPAD_3); }
					break;
				case SDLK_KP_ENTER:
					if (!GetKeyDown(Keyboard.FUNC_KEYPAD_ENTER)) { keysDown.push_back(Keyboard.FUNC_KEYPAD_ENTER); }
					break;
				case SDLK_LCTRL:
					if (!GetKeyDown(Keyboard.FUNC_LEFTCTRL)) { keysDown.push_back(Keyboard.FUNC_LEFTCTRL); }
					break;
				case SDLK_LGUI:
					if (!GetKeyDown(Keyboard.FUNC_LEFTGUI)) { keysDown.push_back(Keyboard.FUNC_LEFTGUI); }
					break;
				case SDLK_LALT:
					if (!GetKeyDown(Keyboard.FUNC_LEFTALT)) { keysDown.push_back(Keyboard.FUNC_LEFTALT); }
					break;
				case SDLK_SPACE:
					if (!GetKeyDown(Keyboard.FUNC_SPACE)) { keysDown.push_back(Keyboard.FUNC_SPACE); }
					break;
				case SDLK_RALT:
					if (!GetKeyDown(Keyboard.FUNC_RIGHTALT)) { keysDown.push_back(Keyboard.FUNC_RIGHTALT); }
					break;
				case SDLK_RGUI:
					if (!GetKeyDown(Keyboard.FUNC_RIGHTGUI)) { keysDown.push_back(Keyboard.FUNC_RIGHTGUI); }
					break;
				case SDLK_MENU:
					if (!GetKeyDown(Keyboard.FUNC_MENU)) { keysDown.push_back(Keyboard.FUNC_MENU); }
					break;
				case SDLK_RCTRL:
					if (!GetKeyDown(Keyboard.FUNC_RIGHTCTRL)) { keysDown.push_back(Keyboard.FUNC_RIGHTCTRL); }
					break;
				case SDLK_LEFT:
					if (!GetKeyDown(Keyboard.FUNC_LEFT)) { keysDown.push_back(Keyboard.FUNC_LEFT); }
					break;
				case SDLK_DOWN:
					if (!GetKeyDown(Keyboard.FUNC_DOWN)) { keysDown.push_back(Keyboard.FUNC_DOWN); }
					break;
				case SDLK_RIGHT:
					if (!GetKeyDown(Keyboard.FUNC_RIGHT)) { keysDown.push_back(Keyboard.FUNC_RIGHT); }
					break;
				case SDLK_KP_0:
					if (!GetKeyDown(Keyboard.NUM_KEYPAD_0)) { keysDown.push_back(Keyboard.NUM_KEYPAD_0); }
					break;
				case SDLK_KP_PERIOD:
					if (!GetKeyDown(Keyboard.SYM_KEYPAD_FULLSTOP)) { keysDown.push_back(Keyboard.SYM_KEYPAD_FULLSTOP); }
					break;
				default:
					break;
				}
			}
			else if (event.type == SDL_KEYUP)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					if (!GetKeyUp(Keyboard.FUNC_ESCAPE)) { removeKey(Keyboard.FUNC_ESCAPE); }
					break;
				case SDLK_F1:
					if (!GetKeyUp(Keyboard.FUNC_F1)) { removeKey(Keyboard.FUNC_F1); }
					break;
				case SDLK_F2:
					if (!GetKeyUp(Keyboard.FUNC_F2)) { removeKey(Keyboard.FUNC_F2); }
					break;
				case SDLK_F3:
					if (!GetKeyUp(Keyboard.FUNC_F3)) { removeKey(Keyboard.FUNC_F3); }
					break;
				case SDLK_F4:
					if (!GetKeyUp(Keyboard.FUNC_F4)) { removeKey(Keyboard.FUNC_F4); }
					break;
				case SDLK_F5:
					if (!GetKeyUp(Keyboard.FUNC_F5)) { removeKey(Keyboard.FUNC_F5); }
					break;
				case SDLK_F6:
					if (!GetKeyUp(Keyboard.FUNC_F6)) { removeKey(Keyboard.FUNC_F6); }
					break;
				case SDLK_F7:
					if (!GetKeyUp(Keyboard.FUNC_F7)) { removeKey(Keyboard.FUNC_F7); }
					break;
				case SDLK_F8:
					if (!GetKeyUp(Keyboard.FUNC_F8)) { removeKey(Keyboard.FUNC_F8); }
					break;
				case SDLK_F9:
					if (!GetKeyUp(Keyboard.FUNC_F9)) { removeKey(Keyboard.FUNC_F9); }
					break;
				case SDLK_F10:
					if (!GetKeyUp(Keyboard.FUNC_F10)) { removeKey(Keyboard.FUNC_F10); }
					break;
				case SDLK_F11:
					if (!GetKeyUp(Keyboard.FUNC_F11)) { removeKey(Keyboard.FUNC_F11); }
					break;
				case SDLK_F12:
					if (!GetKeyUp(Keyboard.FUNC_F12)) { removeKey(Keyboard.FUNC_F12); }
					break;
				case SDLK_PRINTSCREEN:
					if (!GetKeyUp(Keyboard.FUNC_PRINTSCRN)) { removeKey(Keyboard.FUNC_PRINTSCRN); }
					break;
				case SDLK_SCROLLLOCK:
					if (!GetKeyUp(Keyboard.FUNC_SCRLK)) { removeKey(Keyboard.FUNC_SCRLK); }
					break;
				case SDLK_PAUSE:
					if (!GetKeyUp(Keyboard.FUNC_PAUSEBRAKE)) { removeKey(Keyboard.FUNC_PAUSEBRAKE); }
					break;
				case SDLK_BACKQUOTE:
					if (!GetKeyUp(Keyboard.SYM_BACKQUOTE)) { removeKey(Keyboard.SYM_BACKQUOTE); }
					break;
				case SDLK_1:
					if (!GetKeyUp(Keyboard.NUM_1)) { removeKey(Keyboard.NUM_1); }
					break;
				case SDLK_2:
					if (!GetKeyUp(Keyboard.NUM_2)) { removeKey(Keyboard.NUM_2); }
					break;
				case SDLK_3:
					if (!GetKeyUp(Keyboard.NUM_3)) { removeKey(Keyboard.NUM_3); }
					break;
				case SDLK_4:
					if (!GetKeyUp(Keyboard.NUM_4)) { removeKey(Keyboard.NUM_4); }
					break;
				case SDLK_5:
					if (!GetKeyUp(Keyboard.NUM_5)) { removeKey(Keyboard.NUM_5); }
					break;
				case SDLK_6:
					if (!GetKeyUp(Keyboard.NUM_6)) { removeKey(Keyboard.NUM_6); }
					break;
				case SDLK_7:
					if (!GetKeyUp(Keyboard.NUM_7)) { removeKey(Keyboard.NUM_7); }
					break;
				case SDLK_8:
					if (!GetKeyUp(Keyboard.NUM_8)) { removeKey(Keyboard.NUM_8); }
					break;
				case SDLK_9:
					if (!GetKeyUp(Keyboard.NUM_9)) { removeKey(Keyboard.NUM_9); }
					break;
				case SDLK_0:
					if (!GetKeyUp(Keyboard.NUM_0)) { removeKey(Keyboard.NUM_0); }
					break;
				case SDLK_MINUS:
					if (!GetKeyUp(Keyboard.SYM_MINUS)) { removeKey(Keyboard.SYM_MINUS); }
					break;
				case SDLK_EQUALS:
					if (!GetKeyUp(Keyboard.SYM_EQUALS)) { removeKey(Keyboard.SYM_EQUALS); }
					break;
				case SDLK_BACKSPACE:
					if (!GetKeyUp(Keyboard.FUNC_BACKSPACE)) { removeKey(Keyboard.FUNC_BACKSPACE); }
					break;
				case SDLK_INSERT:
					if (!GetKeyUp(Keyboard.FUNC_INSERT)) { removeKey(Keyboard.FUNC_INSERT); }
					break;
				case SDLK_HOME:
					if (!GetKeyUp(Keyboard.FUNC_HOME)) { removeKey(Keyboard.FUNC_HOME); }
					break;
				case SDLK_PAGEUP:
					if (!GetKeyUp(Keyboard.FUNC_PGUP)) { removeKey(Keyboard.FUNC_PGUP); }
					break;
				case SDLK_NUMLOCKCLEAR:
					if (!GetKeyUp(Keyboard.FUNC_NUMLK)) { removeKey(Keyboard.FUNC_NUMLK); }
					break;
				case SDLK_KP_DIVIDE:
					if (!GetKeyUp(Keyboard.SYM_KEYPAD_DIVIDE)) { removeKey(Keyboard.SYM_KEYPAD_DIVIDE); }
					break;
				case SDLK_KP_MULTIPLY:
					if (!GetKeyUp(Keyboard.SYM_KEYPAD_MULTIPLY)) { removeKey(Keyboard.SYM_KEYPAD_MULTIPLY); }
					break;
				case SDLK_KP_MINUS:
					if (!GetKeyUp(Keyboard.SYM_KEYPAD_MINUS)) { removeKey(Keyboard.SYM_KEYPAD_MINUS); }
					break;
				case SDLK_TAB:
					if (!GetKeyUp(Keyboard.FUNC_TAB)) { removeKey(Keyboard.FUNC_TAB); }
					break;
				case SDLK_q:
					if (!GetKeyUp(Keyboard.Q)) { removeKey(Keyboard.Q); }
					break;
				case SDLK_w:
					if (!GetKeyUp(Keyboard.W)) { removeKey(Keyboard.W); }
					break;
				case SDLK_e:
					if (!GetKeyUp(Keyboard.E)) { removeKey(Keyboard.E); }
					break;
				case SDLK_r:
					if (!GetKeyUp(Keyboard.R)) { removeKey(Keyboard.R); }
					break;
				case SDLK_t:
					if (!GetKeyUp(Keyboard.T)) { removeKey(Keyboard.T); }
					break;
				case SDLK_y:
					if (!GetKeyUp(Keyboard.Y)) { removeKey(Keyboard.Y); }
					break;
				case SDLK_u:
					if (!GetKeyUp(Keyboard.U)) { removeKey(Keyboard.U); }
					break;
				case SDLK_i:
					if (!GetKeyUp(Keyboard.I)) { removeKey(Keyboard.I); }
					break;
				case SDLK_o:
					if (!GetKeyUp(Keyboard.O)) { removeKey(Keyboard.O); }
					break;
				case SDLK_p:
					if (!GetKeyUp(Keyboard.P)) { removeKey(Keyboard.P); }
					break;
				case SDLK_a:
					if (!GetKeyUp(Keyboard.A)) { removeKey(Keyboard.A); }
					break;
				case SDLK_s:
					if (!GetKeyUp(Keyboard.S)) { removeKey(Keyboard.S); }
					break;
				case SDLK_d:
					if (!GetKeyUp(Keyboard.D)) { removeKey(Keyboard.D); }
					break;
				case SDLK_f:
					if (!GetKeyUp(Keyboard.F)) { removeKey(Keyboard.F); }
					break;
				case SDLK_g:
					if (!GetKeyUp(Keyboard.G)) { removeKey(Keyboard.G); }
					break;
				case SDLK_h:
					if (!GetKeyUp(Keyboard.H)) { removeKey(Keyboard.H); }
					break;
				case SDLK_j:
					if (!GetKeyUp(Keyboard.J)) { removeKey(Keyboard.J); }
					break;
				case SDLK_k:
					if (!GetKeyUp(Keyboard.K)) { removeKey(Keyboard.K); }
					break;
				case SDLK_l:
					if (!GetKeyUp(Keyboard.L)) { removeKey(Keyboard.L); }
					break;
				case SDLK_z:
					if (!GetKeyUp(Keyboard.Z)) { removeKey(Keyboard.Z); }
					break;
				case SDLK_x:
					if (!GetKeyUp(Keyboard.X)) { removeKey(Keyboard.X); }
					break;
				case SDLK_c:
					if (!GetKeyUp(Keyboard.C)) { removeKey(Keyboard.C); }
					break;
				case SDLK_v:
					if (!GetKeyUp(Keyboard.V)) { removeKey(Keyboard.V); }
					break;
				case SDLK_b:
					if (!GetKeyUp(Keyboard.B)) { removeKey(Keyboard.B); }
					break;
				case SDLK_n:
					if (!GetKeyUp(Keyboard.N)) { removeKey(Keyboard.N); }
					break;
				case SDLK_m:
					if (!GetKeyUp(Keyboard.M)) { removeKey(Keyboard.M); }
					break;
				case SDLK_LEFTBRACKET:
					if (!GetKeyUp(Keyboard.SYM_LEFTBRACKET)) { removeKey(Keyboard.SYM_LEFTBRACKET); }
					break;
				case SDLK_RIGHTBRACKET:
					if (!GetKeyUp(Keyboard.SYM_RIGHTBRACKET)) { removeKey(Keyboard.SYM_RIGHTBRACKET); }
					break;
				case SDLK_BACKSLASH:
					if (!GetKeyUp(Keyboard.SYM_BACKSLASH)) { removeKey(Keyboard.SYM_BACKSLASH); }
					break;
				case SDLK_DELETE:
					if (!GetKeyUp(Keyboard.FUNC_DELETE)) { removeKey(Keyboard.FUNC_DELETE); }
					break;
				case SDLK_END:
					if (!GetKeyUp(Keyboard.FUNC_END)) { removeKey(Keyboard.FUNC_END); }
					break;
				case SDLK_PAGEDOWN:
					if (!GetKeyUp(Keyboard.FUNC_PGDN)) { removeKey(Keyboard.FUNC_PGDN); }
					break;
				case SDLK_QUOTE:
					if (!GetKeyUp(Keyboard.SYM_QUOTE)) { removeKey(Keyboard.SYM_QUOTE); }
					break;
				case SDLK_RETURN:
					if (!GetKeyUp(Keyboard.FUNC_ENTER)) { removeKey(Keyboard.FUNC_ENTER); }
					break;
				case SDLK_KP_4:
					if (!GetKeyUp(Keyboard.NUM_KEYPAD_4)) { removeKey(Keyboard.NUM_KEYPAD_4); }
					break;
				case SDLK_KP_5:
					if (!GetKeyUp(Keyboard.NUM_KEYPAD_5)) { removeKey(Keyboard.NUM_KEYPAD_5); }
					break;
				case SDLK_KP_6:
					if (!GetKeyUp(Keyboard.NUM_KEYPAD_6)) { removeKey(Keyboard.NUM_KEYPAD_6); }
					break;
				case SDLK_LSHIFT:
					if (!GetKeyUp(Keyboard.FUNC_LEFTSHIFT)) { removeKey(Keyboard.FUNC_LEFTSHIFT); }
					break;
				case SDLK_COMMA:
					if (!GetKeyUp(Keyboard.SYM_COMMA)) { removeKey(Keyboard.SYM_COMMA); }
					break;
				case SDLK_PERIOD:
					if (!GetKeyUp(Keyboard.SYM_FULLSTOP)) { removeKey(Keyboard.SYM_FULLSTOP); }
					break;
				case SDLK_SEMICOLON:
					if (!GetKeyUp(Keyboard.SYM_SEMICOLON)) { removeKey(Keyboard.SYM_SEMICOLON); }
					break;
				case SDLK_SLASH:
					if (!GetKeyUp(Keyboard.SYM_SLASH)) { removeKey(Keyboard.SYM_SLASH); }
					break;
				case SDLK_RSHIFT:
					if (!GetKeyUp(Keyboard.FUNC_RIGHTSHIFT)) { removeKey(Keyboard.FUNC_RIGHTSHIFT); }
					break;
				case SDLK_UP:
					if (!GetKeyUp(Keyboard.FUNC_UP)) { removeKey(Keyboard.FUNC_UP); }
					break;
				case SDLK_KP_1:
					if (!GetKeyUp(Keyboard.NUM_KEYPAD_1)) { removeKey(Keyboard.NUM_KEYPAD_1); }
					break;
				case SDLK_KP_2:
					if (!GetKeyUp(Keyboard.NUM_KEYPAD_2)) { removeKey(Keyboard.NUM_KEYPAD_2); }
					break;
				case SDLK_KP_3:
					if (!GetKeyUp(Keyboard.NUM_KEYPAD_3)) { removeKey(Keyboard.NUM_KEYPAD_3); }
					break;
				case SDLK_KP_ENTER:
					if (!GetKeyUp(Keyboard.FUNC_KEYPAD_ENTER)) { removeKey(Keyboard.FUNC_KEYPAD_ENTER); }
					break;
				case SDLK_LCTRL:
					if (!GetKeyUp(Keyboard.FUNC_LEFTCTRL)) { removeKey(Keyboard.FUNC_LEFTCTRL); }
					break;
				case SDLK_LGUI:
					if (!GetKeyUp(Keyboard.FUNC_LEFTGUI)) { removeKey(Keyboard.FUNC_LEFTGUI); }
					break;
				case SDLK_LALT:
					if (!GetKeyUp(Keyboard.FUNC_LEFTALT)) { removeKey(Keyboard.FUNC_LEFTALT); }
					break;
				case SDLK_SPACE:
					if (!GetKeyUp(Keyboard.FUNC_SPACE)) { removeKey(Keyboard.FUNC_SPACE); }
					break;
				case SDLK_RALT:
					if (!GetKeyUp(Keyboard.FUNC_RIGHTALT)) { removeKey(Keyboard.FUNC_RIGHTALT); }
					break;
				case SDLK_RGUI:
					if (!GetKeyUp(Keyboard.FUNC_RIGHTGUI)) { removeKey(Keyboard.FUNC_RIGHTGUI); }
					break;
				case SDLK_MENU:
					if (!GetKeyUp(Keyboard.FUNC_MENU)) { removeKey(Keyboard.FUNC_MENU); }
					break;
				case SDLK_RCTRL:
					if (!GetKeyUp(Keyboard.FUNC_RIGHTCTRL)) { removeKey(Keyboard.FUNC_RIGHTCTRL); }
					break;
				case SDLK_LEFT:
					if (!GetKeyUp(Keyboard.FUNC_LEFT)) { removeKey(Keyboard.FUNC_LEFT); }
					break;
				case SDLK_DOWN:
					if (!GetKeyUp(Keyboard.FUNC_DOWN)) { removeKey(Keyboard.FUNC_DOWN); }
					break;
				case SDLK_RIGHT:
					if (!GetKeyUp(Keyboard.FUNC_RIGHT)) { removeKey(Keyboard.FUNC_RIGHT); }
					break;
				case SDLK_KP_0:
					if (!GetKeyUp(Keyboard.NUM_KEYPAD_0)) { removeKey(Keyboard.NUM_KEYPAD_0); }
					break;
				case SDLK_KP_PERIOD:
					if (!GetKeyUp(Keyboard.SYM_KEYPAD_FULLSTOP)) { removeKey(Keyboard.SYM_KEYPAD_FULLSTOP); }
					break;
				default:
					break;
				}
			}
			else if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				switch (event.button.button)
				{
				case SDL_BUTTON_LEFT:
					if (!GetMouseDown(Mouse.MOUSE_LEFTBUTTON)) { mouseButtonsDown.push_back(Mouse.MOUSE_LEFTBUTTON); }
					break;
				case SDL_BUTTON_MIDDLE:
					if (!GetMouseDown(Mouse.MOUSE_MIDDLEBUTTON)) { mouseButtonsDown.push_back(Mouse.MOUSE_MIDDLEBUTTON); }
					break;
				case SDL_BUTTON_RIGHT:
					if (!GetMouseDown(Mouse.MOUSE_RIGHTBUTTON)) { mouseButtonsDown.push_back(Mouse.MOUSE_RIGHTBUTTON); }
					break;
				default:
					break;
				}
			}
			else if (event.type == SDL_MOUSEBUTTONUP)
			{
				switch (event.button.button)
				{
				case SDL_BUTTON_LEFT:
					if (!GetMouseUp(Mouse.MOUSE_LEFTBUTTON)) { removeMouseButton(Mouse.MOUSE_LEFTBUTTON); }
					break;
				case SDL_BUTTON_MIDDLE:
					if (!GetMouseUp(Mouse.MOUSE_MIDDLEBUTTON)) { removeMouseButton(Mouse.MOUSE_MIDDLEBUTTON); }
					break;
				case SDL_BUTTON_RIGHT:
					if (!GetMouseUp(Mouse.MOUSE_RIGHTBUTTON)) { removeMouseButton(Mouse.MOUSE_RIGHTBUTTON); }
					break;
				default:
					break;
				}
			}
			else if (event.type == SDL_MOUSEMOTION)
			{
				mousePosDelta.x += event.motion.xrel;
				mousePosDelta.y += event.motion.yrel;
			}
			else
			{

			}
		}
		mousePosPrevious += mousePosDelta;
	}

	bool Inputs::GetKeyDown(const int _key)
	{
		for (int i = 0; i < keysDown.size(); i++)
		{
			if (keysDown.at(i) == _key) { return true; }
		}
		return false;
	}

	bool Inputs::GetKeyUp(const int _key)
	{
		for (int i = 0; i < keysDown.size(); i++)
		{
			if (keysDown.at(i) == _key) { return false; }
		}
		return true;
	}

	void Inputs::removeKey(const int _key)
	{
		for (int i = 0; i < keysDown.size(); i++)
		{
			if (keysDown.at(i) == _key) { keysDown.erase(std::next(keysDown.begin(), i)); return; }
		}
	}

	bool Inputs::GetMouseDown(const int _button)
	{
		for (int i = 0; i < mouseButtonsDown.size(); i++)
		{
			if (mouseButtonsDown.at(i) == _button) { return true; }
		}
		return false;
	}
	bool Inputs::GetMouseUp(const int _button)
	{
		for (int i = 0; i < mouseButtonsDown.size(); i++)
		{
			if (mouseButtonsDown.at(i) == _button) { return false; }
		}
		return true;
	}
	vec2 Inputs::GetMouseData(const int _charateristic)
	{
		if (_charateristic == Mouse.MOUSE_DELTA)
		{
			return mousePosDelta;
		}
		else if (_charateristic == Mouse.MOUSE_LOCATION)
		{
			return mousePosPrevious;
		}
	}
	void Inputs::removeMouseButton(const int _button)
	{
		for (int i = 0; i < mouseButtonsDown.size(); i++)
		{
			if (mouseButtonsDown.at(i) == _button) { mouseButtonsDown.erase(std::next(mouseButtonsDown.begin(), i)); return; }
		}
	}
	void Inputs::SetMouseMode(const int _setting)
	{
		if (_setting == Mouse.MOUSE_RELATIVETRUE)
		{
			SDL_SetRelativeMouseMode(SDL_TRUE);
		}
		else if (_setting == Mouse.MOUSE_RELATIVEFALSE)
		{
			SDL_SetRelativeMouseMode(SDL_FALSE);
		}
	}
}