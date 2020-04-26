#include<iostream>

using namespace std;

/*
   Using Dynamic Array instead of LinkList
*/

template <class T>
class GraphAL { // Creating graph with Adjacency List 

   private:
      T **graph;

   public:
      GraphAL(int vert) {
         graph = new T*[vert]; // Linear memory for 2D Matrix Allocating pointers

         for (int i=0; i < vert; ++i)
            graph[i] = new T[vert]; // Allocating memory to each pointers
      }

      void addEdge(int firstEnd, int lastEnd) {
         
         graph[firstEnd][lastEnd] = 1; 
         graph[lastEnd][firstEnd] = 1; 
      }

      void printGraph(int vert) {
         static int i = 0;

         if (i >= vert)
            return;

         cout << "\n";

         for(int j = 0; j < vert; ++j)
            cout << graph[i][j] << "\t";

         cout << "\n";

            ++i;
            printGraph(vert);
      }   
};

int main() {

   int vertices;

   do {
      cout << "Enter the number of vertices" << endl;
      cin >> vertices;
   }
   while (vertices < 5);

   GraphAL<int> gObj(vertices);

   gObj.addEdge(0, 1);
   gObj.addEdge(0, 4);
   gObj.addEdge(1, 3);
   gObj.addEdge(1, 4);
   gObj.addEdge(2, 3);
   gObj.addEdge(3, 4);

   gObj.printGraph(vertices);
   
   return 0;
}
