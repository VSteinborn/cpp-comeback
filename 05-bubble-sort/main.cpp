#include <iostream>


void printArray(int array[], int length){
	for (int n=0; n<length; n++){
		std::cout << array[n] << ' ';
	}
	std::cout << std::endl;
}

void bubbleSortPrint(int array [], int length){
	for(int k=1; k<(length); k++){
		for(int j=(length-1); j>(k-1); j--){
			if( array[j-1] > array[j]){
				int temp=array[j-1];
				array[j-1] = array[j];
				array[j]=temp;
			}
			std::cout << "k=" << k << " j="<< j << " : ";
			printArray(array, length);
		}
	}
}


int main(){
	int N;
	int sortingArray [N];
	std::cout << "Specify size of array N:" << std::endl;
	std::cout << "N:" << std::endl;
	std::cin >> N;
	std::cout << "Enter elements:" << std::endl;
	for(int i=0; i<N; i++){
		std::cout << "Element at a_" << i << " : ";
		std::cin >> sortingArray[i];
	}
	std::cout << "Initial Array:" << std::endl;
	printArray(sortingArray, N);
	bubbleSortPrint(sortingArray, N);
}