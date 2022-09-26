//assigncolor.cpp


//
// assigncolor.cpp
// Deven Schwartz
// 5/13/2021
// assigncolor
// Assigment 11: Graph Coloring
// Description: the program reads edges from a file and creates a graph with the data. the graph is then colored and the output printed.
// Flow: Program creates a colored graph.
// References: List examples provided on website: http://mathcs.wilkes.edu/~bracken/cs226/sp2014/1529_001.pdf.
// Assistance: None
//
//Testing: I have tested my code and have errors/problems that I have not fixed.   

//1.) none, everything seems to be woring correctly. 
//an empty file will cause problems but since it is assumed all files will have data I did not fix that
 
//Time: ~2 hours. Not sure on the exact time spent






#include "color.h"
using namespace std;
int main()
{

    //common output
    cout<<"Deven Schwartz"<<endl;
    cout<<"Assignment 11: Graph Coloring"<<endl;
    cout<<"Given a file with edges, a graph is created and colored.\n"<<endl;
    //

    
    colorgraph mygraph;
    int numocolor;
    numocolor = mygraph.colorit();
    cout<<"The graph has "<<numocolor<<" colors."<<endl;
    mygraph.Printcolor();






}//end main