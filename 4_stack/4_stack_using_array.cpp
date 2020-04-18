#include<iostream>

/* Creating Stack of any Data-type using Dynamic Array */

class StackOverflow : public exception {};
class StackUnderflow : public exception {};
class InvalidOperation : public exception {};

template <class T>
class Stack {
   
   private:
      int top = -1;
      int size = 0;
      T *stackArray;

   public:
      Stack(int sz) {
         size = sz;
         stackArray = new T[size];
      }

      ~Stack() {
         delete stackArray;
      }

      void push(T data) throw(StackOverflow);
      T pop() throw(StackUnderflow);
      T peek(int index);
      bool isEmpty();
      bool isFull();
};

void Stack<T>::push(T data) {
   
   if (++top == size)
      throw StackOverflow();

   stackArray[top] = data;
}

T Stack<T>::pop() {

   T data;

   if (top < 0)
      throw StackUnderflow();

   data = stackArray[top--];

   return data;
}

T Stack<T>::peek(int index) {

   if (index >= size)
      throw InvalidOperation();

   return stackArray[index];
}

bool Stack<T>::isEmpty() {
   
   if (top < 0)
      return true;
   else
      return false;
}

bool Stack<T>::isFull() {
   
   if (top == size-1)
      return true;
   else
      return false;
}

Stack *allocateStack(string type, int sz) {

   if (type == "int") {
      Stack<int> obj = new Stack<int>(sz);
      return obj;
   }
   if (type == "char") {
      Stack<char> obj = new Stack<char>(sz);
      return obj;
   }
   if (type == "float") {
      Stack<float> obj = new Stack<float>(sz);
      return obj;
   }
   if (type == "string") {
      Stack<string> obj = new Stack<string>(sz);
      return obj;
   }
}

Stack *stackDeclaration(int type, int sz);

   map<int, string> stackType = {{1, "int"}, {2, "char"}, {3, "float"}, {4, "string"}};

   for (auto i : stackType) {
      if ( i->first == type )
         return allocatStack(type, sz); 
   }
}

int main() {

   int choice;
   int dataType;

   do {
      cout << "Enter Type of Stack :" << endl;

      cout << "1. int " << endl;
      cout << "2. char " << endl;
      cout << "3. float " << endl;
      cout << "4. string " << endl;

      cout << "\n\t Enter Your Choice: ";
      cin >> dataType;

      cout << "Enter the size of Stack: " << endl;
      cin >> sz;

      void *ptr = stackDeclaration(dataType, sz); // TODO: How Can I take into specific Stack Object

      cout << "\n\t\t1. Push Value into Stack" << endl;
      cout << "\n\t\t2. Pop  Value from Stack" << endl;
      cout << "\n\t\t3. Peek Value from Stack" << endl;
      cout << "\n\t\t4. Get Top Pointer index in Stack" << endl;
      cout << "\n\t\t4. Check if Stack is Empty" << endl;
      cout << "\n\t\t5. Check if Stack is Full" << endl;

      cout << "\n\t Enter Your Choice: ";
      cin >> choice;

      try {
         stackObj.push(3);
      }
      catch (StackOverflow) {
         cout << "Got StackOverflow Exception" << endl;
      }

      try {
         cout << "Popped value from stack is : " <<  stackObj.pop();
      }
      catch (StackUnderflow) {
         cout << "Got StackUnderflow Exception" << endl;
      }
   }
   while (count != 5);

   return 0;
}
         
