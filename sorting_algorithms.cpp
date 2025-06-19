#include"sorting_algorithms.h"

namespace SACC{

/*
*   INSERTION SORT
*/

void Insertion_sort(std::vector<T>& data){
    for (size_t i = 1; i < data.size(); i++) {
            T key = data[i];         // choosing element to ,,insert"
            int j = i - 1;

            // Przesuwamy elementy większe od key w prawo
            while (j >= 0 && data[j] > key) {
                data[j + 1] = data[j];
                j--;
            }

            // Wstawiamy key w odpowiednie miejsce
            data[j + 1] = key;
    }
}


} //namespace SACC