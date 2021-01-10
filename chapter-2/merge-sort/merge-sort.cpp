#include <iostream>
#include <climits>

void merge(int* array, size_t p, size_t q, size_t r);

void merge_sort(int* array, size_t p, size_t q );

void printArray(int* array, size_t size){
	std::cout << "{ ";
	for(size_t i = 0; i < size - 1; ++i){
		std::cout << array[i] << ", ";
	}
	std::cout << array[size-1] <<  " }";
}


int main(){
	int array1[10] = {-1, 2,-20, 0, 5, 8,-25, 3, 9, 2};
	
	printArray(array1, 10);

	merge_sort(array1, 0, 9);	
	
	printArray(array1,10);
	return 0;
}


/**
 * array is the original array to sort with
 * p being the beggining index of a subarray sorted [p - q] and
 * q being the beggining index of a subarray sorted [q+1 - r]
 *
 * where p <= q < r
 */
void merge(int* array, size_t p, size_t q, size_t r){
	int sizeL = (q - p + 1);  
	int sizeR = (r - q); 

	//adjust for additional centinels
	int left[sizeL + 1];
	int right[sizeR + 1];

	//copy original values to the temporal arrays
	//[0,0] for p q  copies the index 0 to left	
	int arrayIndex = p;
	int leftIndex = 0;
	for( ; arrayIndex <= q && leftIndex <= sizeL; ++arrayIndex, ++leftIndex) {
		left[ leftIndex ] = array[ arrayIndex ];  
	}
	
	//[0,1] for q, r copies nothing to right
	arrayIndex = q + 1;
	int rightIndex = 0;
	for ( ; arrayIndex <= r && rightIndex <= sizeR; ++arrayIndex, ++rightIndex ){
		right[ rightIndex ] = array [ arrayIndex ];
	}
	
	//centinels
	left[sizeL] = INT_MAX;
	right[sizeR] = INT_MAX;
		
	std::cout << "\nmerging Left";
	printArray(left, sizeL);
	std::cout << " with Right: ";
	printArray(right, sizeR);

	int leftI = 0, rightI = 0;
	int size;
	for(int i = p, size = r - p + 1;  leftI + rightI < size; ++i ){
		if(left[leftI] <= right[rightI]){
			array[i] = left[leftI];
			++leftI;
		} else {
			array[i] = right[rightI];
			++rightI;
		}
	}
	std::cout << " Result: ";
	printArray(array, 10);
}

/**
 * merge sort implemented using c++ integer division instead of floor like function
 */
void merge_sort(int* array, size_t p, size_t r ){
	if(p < r){
		int q  = (p + r)/2; 
		merge_sort(array, p, q);
		merge_sort(array, q + 1, r);
		merge(array, p, q, r);		
	}
}

