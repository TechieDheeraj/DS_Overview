#include<iostream>
#include<vector>

using namespace std;

class GraphAM { // It is Undirected-Graph

/*
   private:
      int vert;
      vector <int> **gptr;
*/

   public:

      int vert;
      vector <int> **gptr;

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
