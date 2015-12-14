#ifndef SELECTIONSORT
#define SELECTIONSORT
//C++ Iteratorators
#include <algorithm>
template <class Iterator>
void selection_sort(Iterator a, Iterator end){
    while(a!=end){
        std::iter_swap(a, std::min_element(a, end) );
        ++a;
    }
}


//C array
#include <cstddef>
#include <utility>
template<typename T>
void selection_sort(T array[], std::size_t size)
{
    for (std::size_t idx_i = 0; idx_i < size - 1; idx_i++){
        std::size_t min_idx = idx_i;
        for (std::size_t idx_j = idx_i + 1; idx_j < size; idx_j++){
            if (array[idx_j] < array[min_idx]){
                min_idx = idx_j;
            }
        }
        if (min_idx != idx_i){
            std::swap(array[idx_i], array[min_idx]);
        }
    }
}
#endif // SELECTIONSORT
