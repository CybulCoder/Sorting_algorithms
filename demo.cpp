#include<iostream>
#include"data_utils.h"
#include"sorting_algorithms.h"
#include<SDL2/SDL.h>

void draw_state(std::vector<unsigned short>& data, SDL_Renderer* rend, unsigned int red, unsigned int blue){
	int index = 0;
	for(int i : data){
		SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
		SDL_RenderDrawLine(rend, index, 99, index, i);
		index += 1;
	}
}

int main(){
	std::cout << "Hello!\n";

	using T = SACC::T;
	SACC::RecordFactory factory;
	std::vector<T> data;

	data = factory.MakeRandom(100,1,1000);


 	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_CreateWindowAndRenderer(100*10, 100*10, 0, &window, &renderer);
	SDL_RenderSetScale(renderer,10,10); 


	SDL_SetRenderDrawColor(renderer,0,0,0,255);
	SDL_RenderClear(renderer);
	draw_state(data,renderer,0,0);
	SDL_RenderPresent(renderer);
	SDL_Delay(10);

	std::cout << "\n\nAnd... That's it...\n";
	return 0;
}
