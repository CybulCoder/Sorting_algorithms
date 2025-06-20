#include<iostream>
//#include"data_utils.h"
//#include"sorting_algorithms.h"
#include<SDL2/SDL.h>

SDL_Surface* OptimizedSurface(std::string filePath, SDL_Surface* windowSurface)
{
	SDL_Surface* optimizedSurface = nullptr;
	SDL_Surface* surface = SDL_LoadBMP(filePath.c_str());
	if(surface == NULL){
		std::cout << "ERROR!\n";
	}

	optimizedSurface = SDL_ConvertSurface(surface, windowSurface->format, 0);

	if(optimizedSurface == NULL){
		std::cout << "ERROR!\n";
	}

	SDL_FreeSurface(surface);
	return optimizedSurface;
}

int main(int argc, char *argv[]){
	std::cout << "Hello!\n";

 	SDL_Window* window = nullptr;
	SDL_Surface* windowSurface = nullptr;
	SDL_Surface *currentImage = nullptr;
	
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("okno", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
	windowSurface = SDL_GetWindowSurface(window);
	currentImage = OptimizedSurface("photo.bmp", windowSurface);
	
	SDL_Rect drawingRect;
	drawingRect.x = drawingRect.y =0;
	drawingRect.w = 640;
	drawingRect.h = 480;

	bool isRunning = true;
	SDL_Event ev;

	while(isRunning){
		while(SDL_PollEvent(&ev) != 0){
			if(ev.type == SDL_QUIT){
				isRunning = false;
			}
		}
		SDL_BlitScaled(currentImage, NULL, windowSurface, &drawingRect);
		SDL_UpdateWindowSurface(window);
	}


	SDL_DestroyWindow(window);
	window = nullptr;
	SDL_FreeSurface(currentImage);
	currentImage = windowSurface = nullptr;
	SDL_Quit();

	std::cout << "\n\nAnd... That's it...\n";
	return 0;
}
