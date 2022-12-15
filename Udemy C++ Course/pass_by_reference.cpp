#include <iostream>

using namespace std;

// Pass to function by reference

void func(int& y) { 	// y will be a reference to the callers variable x
	cout << "Address of y is: "<< &y << endl;
		y = 1;
}

int main() {
	int x = 2;
	cout << "Address of x is " << &x << endl;
	func(x); 		// x will now have the value 1
	cout << "Value of x is " << x << endl;
	cout << "After calling func(), x = " << x << endl;
}