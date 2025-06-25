#include<vector>
#include"visualization.h"

namespace SACC{
    using T = unsigned short; //should be same type as in data_utils.h then, it should be safe

    void Insertion_sort(std::vector<T>& data, SDL_Renderer* rend);
} //namespace SACC