 #include <stdio.h>
   #include <stdlib.h>
  
   struct Node {
       int data;
       struct Node *next;
   };
  
   struct Node *front = NULL;
  struct Node *rear = NULL;
 
  void enqueue(int value) {
      struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
 
      if (newNode == NULL) {
          printf("Queue overflow\n");
        return;
      }
 
      newNode->data = value;
      newNode->next = NULL;
 
      if (rear == NULL) {
          front = rear = newNode;
      } else {
          rear->next = newNode;
         rear = newNode;
      }
 
      rear->next = front;   // close the circle
      printf("%d enqueued to queue\n", value);
  }
 
  void dequeue() {
     if (front == NULL) {
          printf("Queue underflow\n");
          return;
      }
 
     struct Node *temp = front;
      printf("%d dequeued from queue\n", front->data);
 
      if (front == rear) {  // only one node
          front = rear = NULL;
      } else {
          front = front->next;
          rear->next = front;  // keep the circle
      }
 
     free(temp);
 }
 
  void display() {
      if (front == NULL) {
         printf("Queue is empty\n");
          return;
      }
 
     struct Node *temp = front;
     printf("Queue elements: ");
 
      do {
          printf("%d -> ", temp->data);
          temp = temp->next;
      } while (temp != front);
 
      printf("(back to front)\n");
  }
 
  int main() {
      int choice, value;
 
      while (1) {
          printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
          printf("Enter choice: ");
          scanf("%d", &choice);
 
          switch (choice) {
              case 1:
                  printf("Enter value: ");
                  scanf("%d", &value);
                  enqueue(value);
                  break;
 
              case 2:
                  dequeue();
                  break;
 
              case 3:
                  display();
                  break;
 
              case 4:
                  return 0;
 
              default:
                  printf("Invalid choice\n");
          }
      }
 }


output
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 1
Enter value: 12
12 enqueued to queue

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 1
Enter value: 23
23 enqueued to queue

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 1
Enter value: 34
34 enqueued to queue

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 3
Queue elements: 12 -> 23 -> 34 -> (back to front)

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 2
12 dequeued from queue

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 2
23 dequeued from queue

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 4

                                       