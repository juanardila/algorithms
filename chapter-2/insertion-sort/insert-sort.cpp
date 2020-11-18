#include <iostream>

/**
 * array - array of integers to be sorted
 * size - size of the array ex. [1,2] size will be  2
 */
void insertion_sort(int* array, size_t size){
    for(size_t j = 1; j < size; ++j){
	int key = array[j];
	int i = j - 1;
	while(i >= 0 && array[i] > key){
	    array[i+1] = array[i];
	    --i;
	}
	array[i+1] = key;
    }
} 

int main(){
    int array1[5] = {5, 4, 10, 1, -1};
    insertion_sort(array1, 5);
    for(size_t i = 0; i < 5; ++i){
	std::cout << array1[i] << " ";
    }
    return 0;	
}
