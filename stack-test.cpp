#include "stack.h"
#include<iostream>

using namespace std;

int main() {
	Stack<int> z;
	z.push(5);
	z.push(6);
	z.push(7);

	cout << "Size: " << z.size() << endl;
	cout << "Top: " << z.top() << endl;
	cout << "Empty: " << z.empty() << endl;
	cout << endl;

	z.pop();
	cout << "Size: " << z.size() << endl;
	cout << "Top: " << z.top() << endl;
	cout << "Empty: " << z.empty() << endl;
	cout << endl;

	z.push(8);
	z.push(9);
	cout << "Size: " << z.size() << endl;
	cout << "Top: " << z.top() << endl;
	cout << "Empty: " << z.empty() << endl;
	cout << endl;

	z.pop();
	cout << "Size: " << z.size() << endl;
	cout << "Top: " << z.top() << endl;
	cout << "Empty: " << z.empty() << endl;
	cout << endl;

	z.pop();
	z.pop();
	z.pop();
	cout << "Size: " << z.size() << endl;
	cout << "Empty: " << z.empty() << endl;



}
