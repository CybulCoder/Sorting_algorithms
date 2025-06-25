#include"sorting_algorithms.h"

namespace SACC{

/*
*   INSERTION SORT
*/

void Insertion_sort(std::vector<T>& data, SDL_Renderer* rend){
    SDL_Event e;

    for (size_t i = 1; i < data.size(); i++) {
            T key = data[i];         // choosing element to ,,insert"
            int j = i - 1;

            // Moving elements bigger than "key" to the right
            while (j >= 0 && data[j] > key) {
                data[j + 1] = data[j];
                j--;
                
                while (SDL_PollEvent(&e)) {
                if (e.type == SDL_QUIT) return;
                }
                
                drawState(rend, data, i, j);
                SDL_Delay(DELAY);
            }

            // inserting key at the correct place
            data[j + 1] = key;
            while (SDL_PollEvent(&e)) {
                if (e.type == SDL_QUIT) return;
            }
            drawState(rend, data, i, j);
            SDL_Delay(DELAY);
    }
}


} //namespace SACC