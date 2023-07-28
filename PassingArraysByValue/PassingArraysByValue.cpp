/*
* This program illustarates how we could pass an Array to a fucntion by value. 
* Since Arrays are passed to a funciton by reference. If we even want to pass an 
* Array by value, we should use structures to do so. 
* 
* However, sice the size of and array must be a constant expression and must be  known during compile time,
* using a macros definition  would make things a bit easier. 
* But Whenever we change the array size, we should also change the value of our macros value!!. 
*/

#include <iostream>
#define arrSize 4		// The macros I used for the array size. 

struct Wrapper
{
	int myArrayz[arrSize];
};

void arrDoubler(struct Wrapper myStr) {   // Creating a variable of type struct Wrapper and passing it as an argument 		   
	std::cout << "Showing the values of the array in the stack frame of arrDoubler: " << std::endl; 
	for (int i = 0; i < arrSize; i++) 
		std::cout << myStr.myArrayz[i] << std::endl; 

	std::cout << "\nDouble the values of the Array elements" << std::endl; 
	for (int i = 0; i < arrSize; i++)
		myStr.myArrayz[i] *= 2; 

	std::cout << "Showing the modified values of the array in the stack frame of arrDoubler" << std::endl; 
	for (int i = 0; i < arrSize; i++)
		std::cout << myStr.myArrayz[i] << std::endl; 
}

int main() {
	int theArray[] = {1, 3, 5, 7};
	 
	struct Wrapper myObj; 
	for (int i = 0; i < arrSize; i++)		// Copy the array elements to the structure 
		myObj.myArrayz[i] = theArray[i];	// 

	arrDoubler(myObj);

	std::cout << "\n\n************************************************" << std::endl; 
	std::cout << "Showing the values of the array in the main () stack frame\n"; 
	for (int i = 0; i < arrSize; i++)
		std::cout << theArray[i] << std::endl; 

	return 0; 
}
