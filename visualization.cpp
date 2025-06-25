#include"visualization.h"

namespace SACC{

    void drawState(SDL_Renderer* rend, const std::vector<T>& data, size_t blue, size_t red){
		SDL_SetRenderDrawColor(rend, 0, 0, 0, 255); //"choose" the color
		SDL_RenderClear(rend); //use this color as background

		size_t n = data.size();
		T maxVal = *std::max_element(data.begin(), data.end()); //why * is needed??

		int barWidth = static_cast<int>(WINDOW_WIDTH / static_cast<int>(n));

		for(size_t i=0; i<n; i++){
			int barHeight = static_cast<int>((static_cast<float>(data[i]) / maxVal) * static_cast<int>(WINDOW_HEIGHT));
			int x = static_cast<int>(i * barWidth);
			int y = WINDOW_HEIGHT - barHeight;

            if(i==blue){
                SDL_SetRenderDrawColor(rend, 0, 0, 255, 255);
            }else if(i==red){
                SDL_SetRenderDrawColor(rend, 255, 0, 0, 255);
            }else{
                SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
            }

			SDL_Rect rect = {x, y, barWidth, barHeight};
			SDL_RenderFillRect(rend, &rect);
		}

		SDL_RenderPresent(rend);
	}
} //namespace SACC