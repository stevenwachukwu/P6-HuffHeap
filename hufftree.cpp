#include "hufftree.h"

void::HuffTree::heapToTree(HuffHeap heap) {
	while (true) {
		Node* temp;
		Node* temp2;

		temp = heap.remove();
		temp2 = heap.remove();
		if (temp != nullptr && temp2 != nullptr) {
			Node* obj = new Node();
			obj->ch;
			obj->tally = temp->tally + temp2->tally;
			obj->left = temp;
			obj->right = temp2;
			heap.add(obj);
		}
		else {
			return;
		}
	}
} //my heapToTree function

void::HuffTree::HuffTreePrint(Node* obj, string str) {
	if (obj == nullptr) {
		cout << "|";
		return;
	}
	else {
		cout << "- -";
		HuffTreePrint(obj->right, str);
		cout << "   " << obj->ch << endl;
	    str = "    " +  obj->ch;
		HuffTreePrint(obj->left, str);
	}
} //my print function 

void::HuffTree::mapCode(Node* obj, string str, unordered_map <char, string> huffman) {
	if (obj->left == nullptr) {
		obj->ch;
		obj->tally;
		huffman [obj->ch] = str;
		return;
	}
	else {
		cout << " " << obj->ch << endl;
		str = "0";
		mapCode(obj->left, str, huffman);
		str.pop_back();
		str = "1";
		mapCode(obj->right, str, huffman);
		str.pop_back();
	}
} //my mapcode function
