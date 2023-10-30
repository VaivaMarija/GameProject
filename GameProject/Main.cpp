/*
This tells the preprocessor to inform the linker that there
are some additional static libraries we wish to link with

Gives us access to the SFML bitcode so that we can use SFML content
*/
#if _DEBUG
#pragma comment(lib, "SFML-system-d")
#pragma comment(lib, "SFML-window-d")
#pragma comment(lib, "SFML-graphics-d")
#pragma comment(lib, "SFML-audio-d")
#else
#pragma comment(lib, "SFML-system")
#pragma comment(lib, "SFML-window")
#pragma comment(lib, "SFML-graphics")
#pragma comment(lib, "SFML-audio")
#endif

#include "Application.h"

int main()
{
	CApplication application("Game", 1600, 900);
	application.Run();
	return 0;
}

// push