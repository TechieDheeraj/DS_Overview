#include<iostream>

using namespace std;

class FullQueue : public exception {};
class EmptyQueue : public exception {};
         
/* 
   Program For Circular Queue 
*/

template<class T>
class Queue {

   private:
      int size;
      int front;
      int rear;
      T *queue;

   public:
      
      Queue(int sz) {
         size = sz + 1;  // one is Extra for front 
         front = rear = 0;
         queue = new T[size];
      }

      void enqueue(T) throw(FullQueue);
      T dequeue() throw(EmptyQueue);
      bool isEmpty();
      bool isFull();
      void display();
      int getFront();
      int getRear();
      int getValueAt(int index) {
         return queue[index];
      }
};

template<class T>
void Queue<T>::enqueue(T data) throw(FullQueue) {

   if ((rear + 1) % size == front) // Made Circular Queue, modulo is used to make it go to front of queue 
      throw FullQueue();
   
   rear = (rear+1) % size;

   queue[rear] = data;
}
   
template<class T>
T Queue<T>::dequeue() throw(EmptyQueue) {
   
   T data;

   if (front == rear)
      throw EmptyQueue();

   front = (front + 1) % size; 
   data = queue[front]; 
   queue[front] = 0;

   return data;
}

template<class T>
bool Queue<T>::isEmpty() {
   
   if (front == rear)
      return true;
   else
      return false;
}

template<class T>
bool Queue<T>::isFull() {

   if ((rear + 1) % size == front)
      return true;
   else
      return false;
}

template<class T>
int Queue<T>::getRear() {
   return rear;
}

template<class T>
int Queue<T>::getFront() {
   return front;
}

template<class T>
void Queue<T>::display() {

   cout << "\n\n";
   cout << " \t <<<<<<<<< CIRCULAR QUEUE >>>>>>>>>>>> \n" << endl;

   for (int i = (size-1); i >= 0; --i) {
      if (i == rear)
         cout << "\t\t | " << queue[i] << " | " << " <- rear " << endl;
      else if (i == front)
         cout << "\t\t | " << queue[i] << " | " << " <- front " << endl;
      else
         cout << "\t\t | " << queue[i] << " | " << endl;
   }

   cout << "\t\t|=====| " << endl;
}

int main() {

   int sz;
   int value;
   int choice;
   int index;

   cout << "*********** Queue Operation ************\n\n" << endl;

   cout << "\t Enter Size of Queue: ";
   cin >> sz;

   Queue<int> queueObj(sz);

   do {
      cout << "\n\t\t1. Enqueue Value into Queue" << endl;
      cout << "\n\t\t2. Dequeue  Value from Queue" << endl;
      cout << "\n\t\t3. Check if Queue is Empty" << endl;
      cout << "\n\t\t4. Check if Queue is Full" << endl;
      cout << "\n\t\t5. Get Front of Queue" << endl;
      cout << "\n\t\t6. Get Rear of Queue" << endl;
      cout << "\n\t\t7. Display" << endl;
      cout << "\n\t\t8. Quit" << endl;

      cout << "\n\t Enter Your Choice: ";
      cin >> choice;

      switch (choice) {
      
         case 1:
            cout << "\n\t\t Enter Value: ";
            cin >> value;

            try {
               queueObj.enqueue(value);
            }
            catch (FullQueue) {
               cout << " \t\t\n Got FullQueue Exception" << endl;
            }
            break;

         case 2:
            try {
               cout << "\nDequeued value is: " << queueObj.dequeue() << endl;
            }
            catch (EmptyQueue) {
               cout << " \t\t\n Got EmptyQueue Exception" << endl;
            }
            break;

         case 3:
            cout << "\nQueue is Empty: " << boolalpha << queueObj.isEmpty() << endl;
            break;

         case 4:
            cout << "\nQueue is Full: " << boolalpha << queueObj.isFull() << endl;
            break;
         
         case 5:
            index = queueObj.getFront();
            cout << "\nQueue Front is: \n" << index << " ---> " << queueObj.getValueAt(index+1) << endl;
            break;

         case 6:
            index = queueObj.getRear();
            cout << "\nQueue Rear is: \n" << index << " ---> " << queueObj.getValueAt(index) << endl;
            break;

         case 7:
               queueObj.display();
               break;

         case 8:
            cout << "Exiting ..... " << endl;
            break;

         default:
            cout << "Enter Valid Choice " << endl;
            break;
      }
   }
   while (choice != 8);

   return 0;
}
