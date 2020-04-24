#include<iostream>
#include<vector>

using namespace std;


class GraphAM { // It is Undirected-Graph

   private:
      int vert;
      vector <int> **gptr;

   public:

      GraphAM(int vertices) { // Graph using Adjacency Matrix
         vert = vertices;

         static vector<vector<int> >graph(vertices, vector<int>(vertices)); 
         gptr = (vector <int> **)&graph;
      }
   
      void addEdge(int r, int c) {

         (*gptr)[r][c] = 1; // For Undirected graph it should be set on both side
         (*gptr)[c][r] = 1;
     /*    
         TODO: Direct access of static member of class
         graph[r][c] = 2;
         graph[c][r] = 2;
     */
      }

      void printGraph() {
         static int i = 0;

         if ( i >= vert )
            return;

         cout << "\n";

         for (int j = 0; j < vert; ++j)
            cout << (*gptr)[i][j] << " \t";
         cout << "\n";
         
         ++i;
         printGraph();
      }   
};

int main() {
   
   int vertices;

   do {
      cout << "Enter the number of Vertices (>=5)" << endl;
      cin >> vertices;
   }
   while(vertices < 5);

   GraphAM gObj(vertices);

   gObj.addEdge(0, 1);
   gObj.addEdge(0, 4);
   gObj.addEdge(1, 3);
   gObj.addEdge(1, 4);
   gObj.addEdge(2, 3);
   gObj.addEdge(3, 4);

   gObj.printGraph();

   return 0;
}
