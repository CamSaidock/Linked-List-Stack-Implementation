#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
	//Recursively split elements of a singly-linked list into two output lists
	//One containing elements less than or equal to a given number
	//Other containing elements greater than the number

	//Base case, head == empty
	if(head == nullptr) {
		smaller = nullptr;
		larger = nullptr;
		return;
	}

	if(head->val > pivot) { //If value is above the pivot, add item to larger node
		larger = head;
		llpivot(head->next, smaller, larger->next, pivot); //Recursively go through head, adjusting smaller/larger each iteration
	}

	else if(head->val <= pivot) { //If value is below or equal to the pivot, add item to smaller node
		smaller = head;
		llpivot(head->next, smaller->next, larger, pivot); //Recursively go through head, adjusting smaller/larger each iteration
	}
}

bool Comp::operator()(int input) {
	if(input % 2 == 0) { //Check if input is even
		return false;
	}
	else {
		return true;
	}
}