#include "7_graphAM.hpp"
#include <queue>

/* 

   Finding BFS for graph in Adjacency Matrix

   NOTE: BFS can be different on basis of starting Vertex
*/

class GraphTraversal {
   
   public:
      vector<int> visited;  // Creating vector of visited nodes
      queue<int> queue; // Creating Queue for exploring adjacent nodes

      GraphTraversal(int vert) {
         visited.resize(vert);
      }

      void graphBfs(int startIndex, GraphAM &gObj) { // Start Index should be in 0 - (vertices-1)

         int front = 0;

         visited[startIndex] = 1;
         queue.push(startIndex);
         
         cout << "\nVisited: " << startIndex << endl; // Visited prints will tell BFS traversal of graph

         while(!queue.empty()) {
            
            front = queue.front();
            queue.pop();

            for (int i=0; i < gObj.vert; ++i) {
               if (((*gObj.gptr)[front][i] == 1) && (visited[i] == 0)) {

                  cout << "\nVisited: " << i << endl;
                  visited[i] = 1;
                  queue.push(i);
               }
            }
         }
      }
};

int main() {

   int vertices;

   cout << "Enter size of vertices" << "\n";
   cin >> vertices;

   GraphAM gObj(vertices);
   GraphBFS gBfs(vertices);

   gObj.addEdge(0, 1);
   gObj.addEdge(0, 4);
   gObj.addEdge(1, 3);
   gObj.addEdge(1, 4);
   gObj.addEdge(2, 3);
   gObj.addEdge(3, 4);

   gObj.printGraph();

   gBfs.graphBfs(0, gObj); // Find BFS of Graph

   return 0;
}
