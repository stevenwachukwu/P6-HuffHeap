#pragma once
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <queue>
#include <bitset> //the bitset library will likely be needed for phases 2 and 3
#include <string>
#include "huffman.h"

class HuffHeap {
//things/variables used in P6
private:
	Node* arrayTree[257];
	int subscript = 0;
	int parent = 0;
	int leftChild = 0;
	int rightChild = 0;
	int tallyNum = 0;
	void upHeap(int k);
	void downHeap(int k);
public:
	HuffHeap(unordered_map<char, int> tally);
	void printTrees();
	void buildHeap();
	void add(Node* obj); //creating the add function
	Node* remove(); //creating the remove function
};
