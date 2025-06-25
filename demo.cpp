#include<iostream>
#include"data_utils.h"
//#include"sorting_algorithms.h"
#include<SDL2/SDL.h>
#include<vector>
#include<algorithm>

using T = unsigned short;

	const size_t WINDOW_WIDTH = 800;
	const size_t WINDOW_HEIGHT = 600;

void drawState(SDL_Renderer* rend, const std::vector<T>& data){
	SDL_SetRenderDrawColor(rend, 0, 0, 0, 255); //"choose" the color
	SDL_RenderClear(rend); //use this color as background

	size_t n = data.size();
	T maxVal = *std::max_element(data.begin(), data.end()); //why * is needed??

	int barWidth = WINDOW_WIDTH / static_cast<int>(n);

	for(size_t i=0; i<n; i++){
		int barHeight = static_cast<int>((static_cast<float>(data[i]) / maxVal) * static_cast<int>(WINDOW_HEIGHT));
		int x = static_cast<int>(i * barWidth);
		int y = WINDOW_HEIGHT - barHeight;

		SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
		SDL_Rect rect = {x, y, barWidth, barHeight};
		SDL_RenderFillRect(rend, &rect);
	}

	SDL_RenderPresent(rend);
}

int main(int argc, char *argv[]){
	std::cout << "Hello!\n";

	std::vector<SACC::T> v;
	SACC::RecordFactory factory;

	v = factory.MakeRandom(100,0,100);

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		std::cout << "ERROR!\n";
	}

	window = SDL_CreateWindow("Visualizer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	bool isRunning = true;
	SDL_Event ev;


	while(isRunning){
		while(SDL_PollEvent(&ev) != 0){
			if(ev.type == SDL_QUIT) isRunning = false;
		}
		drawState(renderer, v);
		//SDL_Delay(500);
	}


	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = nullptr;
	renderer = nullptr;
	SDL_Quit();

	std::cout << "\n\nAnd... That's it...\n";
	return 0;
}