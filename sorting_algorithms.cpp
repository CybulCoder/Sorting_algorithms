#include"sorting_algorithms.h"

namespace SACC{

/*
*   INSERTION SORT
*/

void Insertion_sort(std::vector<T>& data){
    for (size_t i = 1; i < data.size(); i++) {
            T key = data[i];         // choosing element to ,,insert"
            int j = i - 1;

            // Moving elements bigger than "key" to the right
            while (j >= 0 && data[j] > key) {
                data[j + 1] = data[j];
                j--;
            }

            // inserting key at the correct place
            data[j + 1] = key;
    }
}


} //namespace SACC