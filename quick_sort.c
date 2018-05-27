/*
* @amnolan
* traditional quick sort
* using middle or left-of-middle pivot
*/

#include <stdio.h>
#include <stdlib.h>

void print_ra(int array [], int size){
	for( int i = 0; i < size; i++){
		printf(" %d ", array[i] );
	}
	printf("\n");
}
void quicksort_int_array(int array_to_srt[], int left, int right){
	// second step - get pivot, this is either the middle element or the element to the left of the middle
	// pick the pivot as the center most point or if even, left of center (int by int division)
	int pivot_index = left + (right - left) / 2;
	int pivot = array_to_srt[ pivot_index ];
	int i = left;
	int j = right;
	// while i is to the left of j or i and j converge
	while( i <= j ){
		// while the value of i is less than the pivot
		while(array_to_srt[i] < pivot){
			// keep moving "i" rightwards
			i++;
		}
		while(array_to_srt[j] > pivot){
			// keep moving "j" leftwards
			j--;
		}
		if( i <= j){
			// swap the value at ra spot "i" with that of ra spot "j" using a temporary storage
			// "swap dance"
		    int temp = array_to_srt[i];
		    array_to_srt[i] = array_to_srt[j];
		    array_to_srt[j] = temp;
		    // after swapping, i and j move right and leftwards respectively
            i++;
            j--;
		}
	}
	// call again until function finishes and call stack returns to main
	if( left < j ){
		// call recursively until reaching base case
		quicksort_int_array(array_to_srt, left, j);
	}
	if( i < right){
		// call recursively until reaching base case
		quicksort_int_array(array_to_srt, i, right);
	}
}

int main(){
	// first step - check array is size 0 or 1, just return the array
	int array_to_srt [] = { 8, 1, 6 ,9 ,6, 3, 5, 2, 7, 0 };
	if( sizeof(array_to_srt) == 0 || sizeof(array_to_srt) == 1 ){
		printf("Nothing to sort!\n");
		exit(0);
	}
	// i = 0 ; j = size - 1;
	printf("Unsorted array: ");
	print_ra(array_to_srt, (sizeof(array_to_srt) / sizeof(int)));
	quicksort_int_array( array_to_srt, 0, sizeof(array_to_srt) / sizeof(int) - 1);
	printf("Sorted array: ");
	print_ra(array_to_srt, (sizeof(array_to_srt) / sizeof(int)));
}