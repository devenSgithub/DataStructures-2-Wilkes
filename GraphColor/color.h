//color.h


#include<cassert>
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct graphnode
{
    int name;
    graphnode *next;
};

struct inDegree{
    int nodename;
    int indegreeOfNode;
};

typedef struct graphnode* graphnodep;
typedef struct inDegree* inDegreep;

class colorgraph
{
    public:
        colorgraph();//done
    
        ~colorgraph();//destructor 
        //colorit
        int colorit();
        void Printcolor();
        //printcolor




    private:
        graphnodep *adj;
        inDegreep *indegreearray;
        int *coloredarray;
        //graphnode* graphnodep;
        int numberofelements;
        void mergeSort(inDegreep * a);
        void mergeSort(inDegreep * a, inDegreep * tmpArray, int left, int right);
        void merge(inDegreep * a, inDegreep * tmpArray, int leftPos, int rightPos, int rightEnd);


};