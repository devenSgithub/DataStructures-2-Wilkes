//
// MCollection.cpp
// Deven Schwartz
// 3/3/2021
// MCollection
// Assigment 1: Class Templates
// Description: The program take 4 files, 2 integer and 2 characters, 
//and adds them to collections. With those collections it compares them and 
//creates 2 new collections, one of each type. The new collections are 
//then compared and finally the integer collections are chained and 
//displayed for a final time.
// Flow: Program inputs files and converts the data to collections. 
//Program then compares and assigns new collections using the original collections.
// References: Example Programs and Lecture recordings.
// Assistance: Help from Dr. Bracken - Help with the assignment operator and caught a 
//fix to the File constructor (had as member function needed to be a constructor)
//
//Testing: Some testing but not a throughly as possible found several errors/problems that I did not fix
//Errors found not fixed: 
//1.) No error message if file is not found (program ends with a default error message).
//2.) If no white space afer last value in files the value will not be added to the collection.
//3.) If data value in file is not the corrcet type program crashes. 
//4.) does not work correctly if file is empty: == will be incorrect but assignment is good 
//5.) Not sure if assignment operator is exactly what I was supposed to do but in all of the tests I did both operators worked
//Time: Several hours over a few days. Not sure on exact time spent

#include "collection.h"
int main(){

    cout<<"Deven Schwartz"<<endl;
    cout<<"Assignment 1: Class Templates"<<endl;
    cout<<"Using file data stored as collections the data is assigned and compared in the program.\n"<<endl;


    //#1 Ask user for the filename of integer file
    string file;
    cout<<"Enter the name of a integer file "<<endl;
    cin>>file;
    cout<<"You entered: " + file <<endl;
    //#2 using the filename and file constructor create a collection called icol1
    collection<int> icol1(file);
    //#3 display the first integer collection
    cout<<"The collection is:"<<endl;
    icol1.Display();


    //#4 Ask the user for a second file containing integers.
    cout<<"Enter the name of a second integer file "<<endl;
    cin>>file;
    cout<<"You entered: " + file <<endl;
    //#5 use the file and file constructor to create a second collection called icol2
    collection<int> icol2(file);
    //#6 display the second integer collection
    cout<<"The collection is:"<<endl;
    icol2.Display();


    //#7 Ask user for the filename of characters file
    cout<<"Enter the name of a character file "<<endl;
    cin>>file;
    cout<<"You entered: " + file <<endl;
    //#8 use that file and the file constructor to create a character collection called ccol1
    collection<char>ccol1(file);
    //#9 display that collection
    cout<<"The collection is:"<<endl;
    ccol1.Display();


    //#10 Ask the user for a second character file 
    cout<<"Enter the name of a second character file "<<endl;
    cin>>file;
    cout<<"You entered: " + file <<endl;
    //#11 use file and file constructor to create a second collection called ccol2
    collection<char>ccol2(file);
    //#12 display that collection
    cout<<"The collection is:"<<endl;
    ccol2.Display();



    //#13 use the == operator to compare the two integer collections and pint the result
    if (icol1 == icol2){
        cout<<"Integer collection 1 and 2 are equal"<<endl;
    }else{
        cout<<"Integer collection 1 and 2 are not equal"<<endl;
    }

    //#14 use the == operator to coompare the two character collections and print the results
    if (ccol1 == ccol2){
        cout<<"Character collection 1 and 2 are equal"<<endl;
    }else{
        cout<<"Character collection 1 and 2 are not equal"<<endl;
    }




    //#15 create a third integer collection using the default operator
    collection<int>icol3;
    //#16 set that collection to the first integer collection
    icol3 = icol1;
    //#17 display the third integer collection
    cout<<"The thrid integer collection is:"<<endl;
    icol3.Display();


    //#18 create a third character collection using the default operator
    collection<char>ccol3;
    //#19 set that collection to the first character collection
    ccol3 = ccol1;
    //#20 display the collection
    cout<<"The thrid character collection is:"<<endl;
    ccol3.Display();



    //#21 compare the 1 and 3 integer collectios and the 2 and 3 collections
    //1+3
    if(icol3 == icol1){
        cout<<"The first and thrid integer collections are equal"<<endl;
    }else{
        cout<<"The first and thrid integer collections are not equal"<<endl;
    }
    //3+2
    if(icol3 == icol2){
        cout<<"The second and thrid integer collections are equal"<<endl;
    }else{
        cout<<"The second and thrid integer collections are not equal"<<endl;
    }

    //#22 compare the 1 and 3 character collections and the 2 and 3
    //1+3
    if(ccol3 == ccol1){
        cout<<"The first and thrid character collections are equal"<<endl;
    }else{
        cout<<"The first and thrid character collections are not equal"<<endl;
    }
    //3+2
    if(ccol3 == ccol2){
        cout<<"The second and thrid character collections are equal"<<endl;
    }else{
        cout<<"The second and thrid character collections are not equal"<<endl;
    }


    //#23 chain the three integer collections
    icol2 = icol3 = icol1;

    //#24 display the three integer collections
    cout<<"The first integer collection is:"<<endl;
    icol1.Display();
    cout<<"The second integer collection is:"<<endl;
    icol2.Display();
    cout<<"The thrid integer collection is:"<<endl;
    icol3.Display();


    cout<<"\nmain exiting"<<endl;

}