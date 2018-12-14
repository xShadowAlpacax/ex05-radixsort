//
// Created by vscilab on 12/10/2018.
//

#ifndef EX05_RADIXSORT_RADIXSORT_H
#define EX05_RADIXSORT_RADIXSORT_H

#include <cstdint>
#include <math.h>
#include <iostream>

namespace edu { namespace vcccd { namespace vc { namespace csv15 {

    template<class Alpaca>
    void radixsort(Alpaca array[], size_t size) {
        Alpaca buckets[10000][10];
        size_t bucket_counts[10];
        Alpaca biggest = 0;
        int64_t digits = 0;
        for (uint64_t m = 0; m < size; m++) {
            if (array[m] > biggest) {
                biggest = array[m];
            }
        }
        std::cout << "The largest value is: " << biggest << std::endl;
        while (biggest != 0){
            biggest /= 10;
            digits++;
            std::cout << "Number of digits: " << digits << std::endl;
        }


        for (uint64_t k = 1; k <= pow(10, digits); k *= 10 ){

            for(uint64_t j = 0; j < size; j++){
                size_t bin = (array[j] / k) % 10;
                buckets[bin][bucket_counts[bin]] = array[j];
                bucket_counts[bin]++;
            }
            uint64_t c = 0;
            for(uint64_t b = 0; b < 10; b++){
                for (uint64_t n = 0; n < bucket_counts[b]; n++) {
                    array[c] = buckets[b][n];
                    c++;
                }
                bucket_counts[b] = 0;
            }
        }
    }

}}}}

#endif //EX05_RADIXSORT_RADIXSORT_H
