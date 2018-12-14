#include "radixsort.h"

using namespace std;
using namespace edu::vcccd::vc::csv15;

int main(){
    int64_t numbers[] = {12345, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int64_t arraySize = (sizeof(numbers)/sizeof(int64_t));
    radixsort(numbers, arraySize);

    std::cout << "{";
    for(int64_t k = 0; k < arraySize; k++){
        std::cout <<  numbers[k];
        if (k < arraySize - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "}" << std::endl;

}