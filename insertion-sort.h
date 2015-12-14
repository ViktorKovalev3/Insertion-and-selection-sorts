#ifndef INSERTIONSORT
#define INSERTIONSORT
//C++ iterators
#include <algorithm>
template<class Iterator>
void insertion_sort( Iterator a, Iterator end ){
    std::iter_swap( a, std::min_element( a, end ) );

    for ( Iterator i = a; ++i < end; a = i)
        for( Iterator j = i; *j < *a; --j, --a )
            std::iter_swap( a, j );
}


//C array
#include <cstddef>
#include <utility>
template<typename T>
void insertion_sort(T a[], std::size_t length) {
    int i, j;
    T min;

    for(i = 1; i < length; i++) {
        min = a[i];
        for (j = i - 1; j >= 0 && a[j] > min; j--) {
            a[j + 1] = a[j];
        }
        a[j+1] = min;
    }
}
#endif // INSERTIONSORT

