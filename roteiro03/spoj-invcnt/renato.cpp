/*
Esse problema foi resolvido usando o algoritmo MergeSort: aproveitamos que é
possível contar a quantidade de inversões enquanto executamos o MergeSort,
pois é possível contar quantas inversões há em um bloco no passo de merge do
MergeSort de maneira eficiente. Como o MergeSort executa em O(nlogn), em que n
é o tamanho da array, o algoritmo de cálculo de quantidade de inversões tem
essa complexidade.
Esse problema, portanto, foi um exemplo de Divisão e Conquista, paradigma
empregado no MergeSort top down.
 */

#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
#include <cstdint>

typedef std::vector<intmax_t> Vec;
typedef std::vector<intmax_t>::iterator VecIt;

/// Merge step of the mergesort.
uintmax_t merge(VecIt begin, VecIt mid, VecIt end) {
    Vec tmp;
    size_t size = end - begin;
    uintmax_t inv = 0;

    tmp.resize(size);
    VecIt l = begin, r = mid;

    for(auto out = tmp.begin(); out != tmp.end(); ++out) {
        if(l < mid && r < end) {
            if(*l <= *r)
                *out = *l++;
            else {
                inv += mid - l;
                *out = *r++;
            }
        }
        else if(l < mid)
            *out = *l++;
        else /* if(r < end) */
            *out = *r++;
    }

    std::copy(tmp.begin(), tmp.end(), begin);
    return inv;
}

/// Counts the number of inversions by using mergesort.
uintmax_t countInversions(VecIt begin, VecIt end) {
    if(begin + 1 >= end) // 0 or 1 elements
        return 0; // No inversions, already sorted.

    VecIt mid = std::next(begin, (end - begin) / 2);
    uintmax_t inv = 0;

    inv += countInversions(begin, mid);
    inv += countInversions(mid, end);
    inv += merge(begin, mid, end);

    return inv;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    uintmax_t cases;

    std::cin >> cases;
    while(cases--) {
        Vec a;
        uintmax_t n;

        std::cin >> n;
        a.resize(n);
        for(uintmax_t i = 0; i < n; ++i)
            std::cin >> a[i];

        std::cout << countInversions(a.begin(), a.end()) << "\n";
    }

    return 0;
}
