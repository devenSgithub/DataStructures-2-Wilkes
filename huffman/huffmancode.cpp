

//
// huffmancode.cpp
// Deven Schwartz
// 4/27/2021
// huffman
// Assigment 10: Huffman Code
// Description: The program takes a file and inserts the characters and their frequencys into a priority queue 
//then converts it into the proper huffman code displaying along the way.
// Flow: Program creates the huffman code using the frequency.
// References: List examples provided on website: http://mathcs.wilkes.edu/~bracken/cs226/sp2014/1529_001.pdf.
// Assistance: None
//
//Testing: I have tested my code and have many errors/problems that I have not fixed.   
// I changed several things in the skeleton file to get it to work, for example the insert function I changed to a normal huffman node not a const hufnode 
//1.) It looks like I have the min heap incorrectly (have not throughly checked might just be the specific case im looking at looks wrong but is not)
//2.) Heapdelete is doing nothing so the actual huffman tree is not being built and also the desturctor is not doing anything
//3.) the only display currently is the original data and the data once in the priority queue
//I commented-out/removed necessary code so that it would compile for turnin  
 
//Time: ~5 hours. Not sure on the exact time spent






#include "huffman.h"
using namespace std;
int main()
{

//common output
  cout<<"Deven Schwartz"<<endl;
  cout<<"Assignment 10: Huffman Code"<<endl;
  cout<<"produces huffman code for a file input.\n"<<endl;
  //


string fn;
cout<<"enter the name of a file containing the characters"<<endl;

// check for valid input have user reenter until a valid input is accepted
while(true){
      
    cin >> fn;
    if(cin.good()){
        break;
    }else{
        cout<<"You entered invalid input, reenter a file name \n";
        cin.clear();
        cin.ignore(120,'\n');
    }

}

cout << "You entered: " << fn << endl;





huffman myhuffman(fn);
myhuffman.displayCode();
}//end main