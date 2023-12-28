#include "huffheap.h"

HuffHeap::HuffHeap (unordered_map<char, int> tally ) {
	for (auto x : tally) {
		if (x.second >= 1) {
			Node* obj = new Node();
			obj->ch = x.first;
			obj->tally = x.second;
			arrayTree[tallyNum] = obj;
			tallyNum++;
		} 
	}
} //the public constructor for this huffman program

void HuffHeap::buildHeap() {
	unordered_map<char, int> tally;
	for (;;) {
		if (arrayTree[leftChild]->tally > arrayTree[parent]->tally) {
			upHeap(leftChild);
		}
		if (arrayTree[rightChild]->tally > arrayTree[parent]->tally) {
			upHeap(rightChild);
		}
		if (arrayTree[parent]->tally > arrayTree[leftChild]->tally || arrayTree[parent]->tally > arrayTree[rightChild]->tally) {
			return;
		}
	}
} //my build heap algorithmn
void HuffHeap::upHeap(int K) {
	parent = K / 2;

	if (arrayTree[parent]->tally < arrayTree[K]->tally) {
		return;
	}
	else {
		char movCh = arrayTree[K]->ch;
		int movTally = arrayTree[K]->tally;

		arrayTree[K]->ch = arrayTree[parent]->ch;
		arrayTree[K]->tally = arrayTree[parent]->tally;

		arrayTree[parent]->ch = movCh;
		arrayTree[parent]->tally = movTally;

		upHeap(parent);
	}

} //my upheap algorithmn
void HuffHeap::downHeap(int K) {
	leftChild = 2 * K;
	rightChild = 2 * K + 1;
	parent = K;

	if (arrayTree[leftChild]->tally < arrayTree[rightChild]->tally) {
		if (arrayTree[leftChild]->tally < arrayTree[parent]->tally) {
			char movCh = arrayTree[leftChild]->ch;
			int movTally = arrayTree[leftChild]->tally;

			arrayTree[leftChild]->ch = arrayTree[parent]->ch;
			arrayTree[leftChild]->tally = arrayTree[parent]->tally;

			arrayTree[parent]->ch = movCh;
			arrayTree[parent]->tally = movTally;
			
			downHeap(parent);
		}
	}
	else {
		if (arrayTree[rightChild]->tally < arrayTree[parent]->tally) {
			char movCh = arrayTree[rightChild]->ch;
			int movTally = arrayTree[rightChild]->tally;

			arrayTree[rightChild]->ch = arrayTree[parent]->ch;
			arrayTree[rightChild]->tally = arrayTree[parent]->tally;

			arrayTree[parent]->ch = movCh;
			arrayTree[parent]->tally = movTally;

			downHeap(parent);
			
		}
	}
	
} //my downheap algorithmn

void HuffHeap::printTrees() {
	cout << "\nThe number of trees in the heap are: " << tallyNum << endl; //prints out the number of trees in the heap
	cout << "\nThe list of all the trees: " << endl;
	for (int i = 0; i < tallyNum; i++) {
		if (arrayTree[i]->ch == 32) {
			cout << "\n" << (int)arrayTree[i]->ch << "\t" << arrayTree[i]->tally << endl;
			continue;
		} //if the character value is a space then it will print out the ASCII code
		cout << arrayTree[i]->ch  << "\t" << arrayTree[i]->tally << endl;
	} //lists out all the trees of the program
} //my print trees function for this program

void HuffHeap::add(Node* obj) {
	for (int i = 0; i < tallyNum; i++) {
		if (arrayTree[i] == nullptr) {
			arrayTree[i] = obj;
			upHeap(i);
			break;
		}
	}
	tallyNum++;
} //my add function

Node* HuffHeap::remove() {
	if (tallyNum == 0) {
		return nullptr;
	}
	Node* obj = arrayTree[0];
	arrayTree[0] = arrayTree[tallyNum - 1];
	tallyNum--;
	downHeap(0);

	return obj;
} //my remove function
