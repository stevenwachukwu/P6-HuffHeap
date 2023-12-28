#pragma once
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <queue>
#include <bitset> //the bitset library will likely be needed for phases 2 and 3
#include <string>

using namespace std;

struct Node {
	char ch;
	int tally;
	Node* left;
	Node* right;
};

class huffman
{
	unordered_map<char, int> tally; //the unordered map for the tally counter (it includes the numerical and character values)
	ifstream fileinput;

	struct comp {
		bool operator()(Node* l, Node* r) {
			return l->tally > r->tally;
		}
	};
	priority_queue<Node*, vector<Node*>, comp> P5pq;

	Node* rootHuffTree = new Node();
	void doTally(string text);

	void printTally (string text);
	
public:
	huffman(string text) {
		fileinput.open(text);
		if (fileinput.is_open()) {
			cout << "\nThe file can open!" << endl;
		}
	} //whenever the p5message.txt file can open the user will get this specific message 

	Node* getNode(char ch, int tally, Node* left, Node* right) {
		Node* node = new Node();
		node->ch = ch;
		node->tally = tally;
		node->left = left;
		node->right = right;
		return node;
	}

	Node heapify(string text, Node* root) {
		for (auto pair : tally) {
			P5pq.push(getNode(pair.first, pair.second, nullptr, nullptr));

		}
		while (P5pq.size() != 1) {
			Node* left = P5pq.top();
			P5pq.pop();
			Node* right = P5pq.top();
			P5pq.pop();
			int sum = left->tally + right->tally;
			P5pq.push(getNode('\0', sum, left, right));
		}
		root = P5pq.top();
		return *root;
	};

	void compress();


	void encode(Node* root, string str, unordered_map<char, string>& huffmanCode);
};
