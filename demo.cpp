#include<iostream>
#include"data_utils.h"
#include"sorting_algorithms.h"
#include<SDL2/SDL.h>
#include<vector>
#include<algorithm>

using T = unsigned short;

int main(int argc, char *argv[]){
	std::cout << "Hello!\n";

	std::vector<SACC::T> v;
	SACC::RecordFactory factory;

	v = factory.MakeRandom(100,1,100);
	//v = factory.MakeAlmostSorted(1,1000,70);
	std::cout << v.size() << '\n';

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		std::cout << "ERROR!\n";
	}

	window = SDL_CreateWindow("Visualizer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SACC::WINDOW_WIDTH, SACC::WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	std::cout << "\nSorting...\n";
	SACC::Bubble_sort(v, renderer);

	SDL_Delay(1000);


	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = nullptr;
	renderer = nullptr;
	SDL_Quit();

	std::cout << "\n\nAnd... That's it...\n";
	return 0;
}