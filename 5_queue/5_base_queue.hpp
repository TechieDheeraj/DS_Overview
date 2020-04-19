namespace BaseQueue {

   class Queue {
      
      private:
         class Node {

            private:
               int data;
               Queue *next;

            public:
               Node() {
                  data = 0;
                  next = NULL;
               }
         };

      public:

         Node *head = new Node; // Creating object of Node class

         Queue(int data) {
            head->data = data;
         }
   };
}
