#include<iostream>

template <class T>
class GraphAM { // Creating graph with Adjacency Matrix

   private:
      int row, col; 
      T **graph;

   public:
      GraphAM(int r, int c) {
         graph = new T*[r]; // Linear memory for 2D Matrix

         for (int i=0; i < r; ++i)
            graph[i] = new T[c];
      }
};

int main() {
   
   return 0;
}
