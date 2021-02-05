#include <iostream>

/**
 *
 * @param array 
 * @param start
 * @param end
 * @param endMax
 * @return
 */
int maxLocal(const int *array, const unsigned start, const unsigned end, unsigned &endMax){
    int maxSum = 0;
    int sum = 0;
    for(unsigned i = start; i < end; ++i ){
        sum += array[i];
        if(sum > maxSum){
            endMax = i;
            maxSum = sum;
        }
    }
    return maxSum;
}

void findMaxSubArray(const int *array, const unsigned length){
    int max = 0, currentMax = 0;
    unsigned endMax = 0, lowMax = array[0], highMax = array[length - 1];
    for(unsigned i = 0; i < length; ++i) {
        currentMax = maxLocal(array, i, length,  endMax);
        if(currentMax > max){
            max = currentMax;
            lowMax = i;
            highMax = endMax;
        }
    }
    std::cout << "for Array [ ";
    for(unsigned i = 0; i < length - 1; ++i){
        std::cout << array[i] << ", ";
    }
    std::cout << array[length - 1] << " ] has a low-max of " <<
        lowMax << " and a high-max of " << highMax << " with  the sum " << max << "\n";
}

int main() {
    constexpr int SIZE = 4;
    int array1[] = {1, 2, 3, -5};
    int array2[] = {-5, 1, 2, 3};
    int array3[] = {0, 0, -1, 5};
    int array4[] = {6, 8, 10, 0};

    findMaxSubArray(array1, SIZE);
    findMaxSubArray(array2, SIZE);
    findMaxSubArray(array3, SIZE);
    findMaxSubArray(array4, SIZE);
}
