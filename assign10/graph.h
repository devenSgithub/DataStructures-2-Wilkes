//graph.h



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
typedef struct graphnode* graphnodep;
class graph
{
    public:
        graph();//done
    
        graph(const graph &g1); //graph copy constructor
    
        ~graph();//destructor 



        bool DFS(int V);//done
        bool BFS(int V);//done
        void topological();//done

  

    private:
        graphnodep *adj;
        //graphnode* graphnodep;
        int numberofelements;
        bool cycletest;
        graphnode *topologicallist;
        void DFSVisit(int V, int* vistedcolorarray);


};