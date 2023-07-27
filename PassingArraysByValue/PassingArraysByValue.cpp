/*
* This program illustarates how we could pass an Array to a fucntion by value. 
* Since Arrays are passed to a funciton by reference. Hence, if we even want to pass an 
* Array by value, we should use structures to accomplish our task. 
* 
* However, the size of the array must also be know in the structure as well. 
* So using a macros would make things a bit easier. But Whenever we change the array, 
* we should also change the value of our macros value!!. 
*/

#include <iostream>
#define N 4

struct Wrapper
{
	int myArrayz[N]; 
};

void arrDoubler(struct Wrapper myStr, int arrSize) {   // Creating an object of struct Wrapper and passing it as
	int* myPtr = myStr.myArrayz;					   // a funciton argument along with the array's size. 

	std::cout << "Showing the incoming values of the array in the stack frame of arrDoubler: " << std::endl; 
	for (int i = 0; i < arrSize; i++) 
		std::cout << myStr.myArrayz[i] << std::endl; 

	std::cout << "\nTime to modify and double the elements of the Array!" << std::endl; 
	for (int i = 0; i < arrSize; i++)
		myStr.myArrayz[i] *= 2; 

	std::cout << "Showing the modified values of the array in the stack frame of arrDoubler" << std::endl; 
	for (int i = 0; i < arrSize; i++)
		std::cout << myStr.myArrayz[i] << std::endl; 
}

int main() {
	int theArray[] = {1, 3, 5, 7};
	 
	struct Wrapper myObj; 
	for (int i = 0; i < N; i++)
		myObj.myArrayz[i] = theArray[i]; 

	arrDoubler(myObj, N);

	std::cout << "\n\n************************************************" << std::endl; 
	std::cout << "Showing the values of the array in the main () stack frame\n"; 
	for (int i = 0; i < N; i++)
		std::cout << theArray[i] << std::endl; 

	return 0; 
}
