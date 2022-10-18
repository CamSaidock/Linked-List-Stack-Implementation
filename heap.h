#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items 
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
	void heapify(int index);
	std::vector<T> items_;
	void push_Heap(int index);
	int m_;
  PComparator c_;

};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) : m_(m), c_(c) {
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap() {
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw(std::underflow_error("Underflow Error. Heap is empty."));

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
	else {
		return items_[0];
	}
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw(std::underflow_error("Underflow Error. Heap is empty."));
  }

	else {
		items_[0] = items_.back();
		items_.pop_back();
		if(items_.size() == 1) {
			return;
		}
		else {
			heapify(0);
		}
	}

}

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapify(int index) { //Heapify/trickleDown
	if((unsigned)index >= items_.size()) {  //If index is out of bounds, return. Also checks if leaf node
		return;
	}	
  
	int priorityChild = m_ * index + 1; //Start with left node
	int rightChild = priorityChild + 1; //Iterate through right nodes

  while((unsigned)rightChild < items_.size() && rightChild - priorityChild < m_) { //While rightChild is within bounds and while the nodes are in the same parent node
    if(c_(items_[rightChild], items_[priorityChild])) {
      priorityChild = rightChild;
    }
		rightChild += 1; //Increment rightChild to iterate through heap
  }

	if((unsigned)priorityChild < items_.size()) { //Make sure that priorityChild is within bounds
		if(c_(items_[priorityChild], items_[index])) {
			std::swap(items_[index], items_[priorityChild]); //Swap nodes at index index and at index priorityChild if they are > < (based on comparator)
			heapify(priorityChild); //Recursively call heapify
		}
	}

	else {
		return;
	}
	
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push_Heap(int index) {
	int parent = (index-1)/m_;
	while((parent >= 0) && (c_(items_[index], items_[parent]))) {
		std::swap(items_[parent], items_[index]);
		index = parent;
		parent = (index-1)/m_;
	}
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item) {
	items_.push_back(item);
	push_Heap(items_.size()-1);
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const {
  return items_.size();
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const {
  if(items_.size() == 0) {
    return true;
  }
  else {
    return false;
  }
}


#endif

