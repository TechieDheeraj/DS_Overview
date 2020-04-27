#include "7_graphAM.hpp"
#include <queue>
#include <stack>

/* 
   Finding BFS and DFS for graph in Adjacency Matrix

   NOTE: BFS and DFS both can be different on basis of starting Vertex
*/

class GraphTraversal {
   
   public:
      vector<int> visited;  // Creating vector of visited nodes
      queue<int> queue; // Creating Queue for exploring adjacent nodes in BFS
      stack<int> stack; // Creating Queue for exploring adjacent nodes in DFS

      GraphTraversal(int vert) {
         visited.resize(vert);
      }

      void graphBfs(int startIndex, GraphAM &gObj) { // Start Index should be in 0 - (vertices-1)

         int front = 0;
         cout << "\n************** BFS **************** \n";

         std::fill(visited.begin(), visited.end(), 0); // filling with zero(0) because visited array is also used in graphDfs()

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
         std::fill(visited.begin(), visited.end(), 0);
         cout << "************************************\n";
      }

      void graphDfs(int index, GraphAM &gObj) {

/*
         int top = 0;

         std::fill(visited.begin(), visited.end(), 0);

         visited[startIndex] = 1;
         stack.push(startIndex);

         while(!stack.empty()) {

            top = stack.top();
            
            gObj.gptr
         }
*/

         if (visited[index] == 0) {

            visited[index] = 1;
            cout << "\nVisited: " << index << "\n";

            for(int i=0; i < gObj.vert; ++i) {
               if (((*gObj.gptr)[index][i] == 1) && (visited[i] == 0))
                  graphDfs(i, gObj);
            }
         }
      }
};

int main() {

   int vertices;

   cout << "Enter size of vertices" << "\n";
   cin >> vertices;

   GraphAM gObj(vertices);
   GraphTraversal gBfs(vertices);

   gObj.addEdge(0, 1);
   gObj.addEdge(0, 4);
   gObj.addEdge(1, 3);
   gObj.addEdge(1, 4);
   gObj.addEdge(2, 3);
   gObj.addEdge(3, 4);

   gObj.printGraph();

   gBfs.graphBfs(0, gObj); // Find BFS of Graph
   gBfs.graphDfs(0, gObj); // Find DFS of Graph

   return 0;
}
