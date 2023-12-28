#pragma once
#include "huffman.h"
#include "huffheap.h"

class HuffTree 
{
public:
	void add(Node*obj); 
	Node* remove(); 
	void heapToTree(HuffHeap obj); //the function needed in hufftree
	void HuffTreePrint(Node* obj, string str); //the function needed in hufftree
	void mapCode(Node* obj, string str, unordered_map<char, string>); //the function needed in hufftree
};
