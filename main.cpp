/* Steve Nwachukwu
   Data Structures and Algorithms
   Spring 2023
   P6 - HuffHeap
*/

//libraries used
#include <iostream>
#include <fstream>
#include <vector>
#include "huffman.h"
#include <string>
#include "huffheap.h"

using namespace std;

void Banner(ostream& out) {
    out << "-------Welcome to Program 6 HuffHeap by Steve Nwachukwu!---------\n" << endl;
    out << "My Major is Computer Science        Graduation Year: 2025\n" << endl;
    out << "Favorite Quote: Your time is limited, so don't waste it living someone else's life. - Steve Jobs \n" << endl;
    out << "About Me: I'm really tech savy and I like going out for walks. Also, I like to play video games and watch cartoons.\n" << endl;
} //the function prototype for my banner

void Bye(ostream& out) {
    out << "\nThe program has successfully terminated, thank you and have a nice day!" << endl;
} //the function prototype for my bye output at the end


int main() {
    string FileInput; //variable used to find the text file

    Banner(cout); //calling the banner
    cout << "Please enter in your file name:" << endl;
    cin >> FileInput; //user inputs p5message.txt for the file input
    huffman obj(FileInput); //creation of the file input object to work with the elements/features of huffman.h and huffman.cpp
    obj.compress(); //the file input object gets acted upon by the compress function
    Bye(cout); //calling the bye function
}
