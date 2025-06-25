#include<iostream>
#include<SDL2/SDL.h>
#include<vector>
#include<algorithm>

namespace SACC{

    using T = unsigned short;

    const size_t WINDOW_WIDTH = 1000;
	const size_t WINDOW_HEIGHT = 500;
    const int DELAY = 10;

    void drawState(SDL_Renderer* rend, const std::vector<T>& data, size_t blue, size_t red);

} //namespace SACC