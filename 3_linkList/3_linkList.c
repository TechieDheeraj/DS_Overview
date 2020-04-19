#include<stdio.h>
#include<stdlib.h>

struct Node {
   int data;
   struct Node *next;
};

/* Creating LinkList using For Loop */

struct Node *createLinklist(struct Node *head, int data) {
   
   struct Node *tmp = NULL; 
   struct Node *node = (struct Node *)malloc(sizeof(struct Node));

   node->data = data;
   node->next = NULL;

   if (head == NULL) {
      head = node;
      return head;
   }
   tmp = head;
   
   while(tmp != NULL) {

      if (tmp->next == NULL) {
         tmp->next = node;
         break;
      }
      tmp = tmp->next;
   }

   return head;
}

/* Creating LinkList using Recursion with returning */

struct Node *createLinklistV1(struct Node *node, int data, int size) {
   
   if (size < 1)
      return NULL;

   node = (struct Node *)malloc(sizeof(struct Node));

   node->data = data;
   node->next = NULL;
   node->next = createLinklistV1(node->next, data+1, size-1);

   return node;
}

/* Creating LinkList using Recursion without returning */

void createLinklistV2(struct Node **node, int data, int size) {

   if (size < 1)
      return;

   *node = (struct Node *)malloc(sizeof(struct Node));

   (*node)->data = data;
   (*node)->next = NULL;

   createLinklistV2(&(*node)->next, data+1, size-1);
}

void displayLinklist(struct Node *node) { // Using Tail Recursion
   
   if (node == NULL)
      return;

   printf("%d(%p) -> ", node->data, node); // Executed at calling Time
   displayLinklist(node->next); // Tail Recursion
   /* Statements written here will be called at returning time */
}
     
int main() {

   struct Node *head = NULL;

   int size = 0;
//   struct Node *head = NULL;
   
   printf("Enter Size of Linklist\n");
   scanf("%d", &size);

/* Creating LinkList using For Loop */

//   for(int i = 0; i < size; ++i)   
//      head = createLinklist(head, i+1);

/* Displaying LinkList using Recursion */
//   displayLinklist(head);

/* Creating LinkList using Recursion with returning*/
   //head = createLinklistV1(head, 1, size);

/* Creating LinkList using Recursion without returning*/
   createLinklistV2(&head, 1, size);

/* Displaying LinkList using Recursion */
   displayLinklist(head);

   return 0;
}
