 #ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
};

template <typename T>
Stack<T>::Stack(){
}

template <typename T>
Stack<T>::~Stack(){
}

template<typename T>
bool Stack<T>::empty() const {
	if(std::vector<T>::size() == 0) {
		return true;
	}

	else {
		return false;
	}
}

template <typename T>
size_t Stack<T>::size() const {
	return std::vector<T>::size();
}

template <typename T>
void Stack<T>::push(const T& item) {
	std::vector<T>::push_back(item);
}

template <typename T>
void Stack<T>::pop() {
	if(std::vector<T>::size() == 0) { //If the Stack is empty, throw underfow_error
		throw(std::underflow_error("Underflow Error. Stack is empty."));
		return;
	}
	else {
		std::vector<T>::pop_back();
	}
}

template <typename T>
T const & Stack<T>::top() const {
	if(std::vector<T>::size() == 0) { //If the Stack is empty, throw underfow_error
		throw(std::underflow_error("Underflow Error. Stack is empty."));
	}

	else {
		return std::vector<T>::back();
	}
}





#endif