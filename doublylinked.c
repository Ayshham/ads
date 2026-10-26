  1 #include <stdio.h>
  2    #include <stdlib.h>
  3
  4    struct node {
  5        int data;
  6        struct node *prev, *next;
  7    };
  8
  9   struct node *head = NULL;
 10
 11   void insertBeginning() {
 12       struct node *newnode;
 13       int value;
 14
 15       newnode = malloc(sizeof(struct node));
 16
 17       printf("Enter data: ");
 18       scanf("%d", &value);
 19
 20       newnode->data = value;
 21       newnode->prev = NULL;
 22       newnode->next = head;
 23        if (head != NULL)
 24           head->prev = newnode;
 25
 26       head = newnode;
 27   }
 28
 29   void insertEnd() {
 30       struct node *newnode, *temp;
 31       int value;
 32
 33       newnode = malloc(sizeof(struct node));
 34
 35       printf("Enter data: ");
 36       scanf("%d", &value);
 37
 38       newnode->data = value;
 39       newnode->next = NULL;
 40       newnode->prev = NULL;
 41
 42       if (head == NULL) {
 43           head = newnode;
 44           return;
 45       }
 46
 47       temp = head;
 48
 49       while (temp->next != NULL)
 50           temp = temp->next;
 51
 52       temp->next = newnode;
 53       newnode->prev = temp;
 54   }
 55
 56   void displayForward() {
 57       struct node *temp = head;
 58
 59       if (head == NULL) {
 60           printf("List is empty\n");
 61           return;
 62       }
 63
 64       while (temp != NULL) {
 65           printf("%d <-> ", temp->data);
 66           temp = temp->next;
 67       }
 68
 69       printf("NULL\n");
 70   }
 71
 72   void deleteNode() {
 73       struct node *temp = head;
 74      int value;
 75
 76       if (head == NULL) {
 77          printf("List is empty\n");
 78           return;
 79       }
 80
 81       printf("Enter value to delete: ");
 82       scanf("%d", &value);
 83
 84       while (temp != NULL && temp->data != value)
 85           temp = temp->next;
 86
 87       if (temp == NULL) {
 88           printf("Node not found\n");
 89           return;
 90       }
 91
 92       if (temp->prev != NULL)
 93           temp->prev->next = temp->next;
 94       else
 95           head = temp->next;
 96
 97       if (temp->next != NULL)
 98          temp->next->prev = temp->prev;
 99
100      free(temp);
101      printf("Node deleted\n");
102  }
103
104  void displayReverse() {
105      struct node *temp = head;
106
107      if (head == NULL) {
108          printf("List is empty\n");
109          return;
110      }
111
112      while (temp->next != NULL)
113          temp = temp->next;
114
115      while (temp != NULL) {
116          printf("%d <-> ", temp->data);
117          temp = temp->prev;
118      }
119
120      printf("NULL\n");
121  }
122
123  int main() {
124      int choice;
125
126      while (1) {
127          printf("\n1. Insert at beginning\n");
128          printf("2. Insert at end\n");
129          printf("3. Display forward\n");
130          printf("4. Delete a node\n");
131          printf("5. Display reverse\n");
132          printf("6. Exit\n");
133          printf("Enter choice: ");
134          scanf("%d", &choice);
135
136          switch (choice) {
137              case 1:
138                  insertBeginning();
139                  break;
140              case 2:
141                  insertEnd();
142                  break;
143              case 3:
144                  displayForward();
145                  break;
146              case 4:
147                  deleteNode();
148                  break;
149              case 5:
150                  displayReverse();
151                  break;
152              case 6:
153                  return 0;
154              default:
155                  printf("Invalid choice\n");
156          }
157      }
158  }
159
160

   output

1. Insert at beginning
2. Insert at end
3. Display forward
4. Delete a node
5. Display reverse
6. Exit
Enter choice: 1
Enter data: 10

1. Insert at beginning
2. Insert at end
3. Display forward
4. Delete a node
5. Display reverse
6. Exit
Enter choice: 1
Enter data: 20

1. Insert at beginning
2. Insert at end
3. Display forward
4. Delete a node
5. Display reverse
6. Exit
Enter choice: 2
Enter data: 30

1. Insert at beginning
2. Insert at end
3. Display forward
4. Delete a node
5. Display reverse
6. Exit
Enter choice: 2
Enter data: 40

1. Insert at beginning
2. Insert at end
3. Display forward
4. Delete a node
5. Display reverse
6. Exit
Enter choice: 3
20 <-> 10 <-> 30 <-> 40 <-> NULL

1. Insert at beginning
2. Insert at end
3. Display forward
4. Delete a node
5. Display reverse
6. Exit
Enter choice: 4
Enter value to delete: 30
Node deleted

1. Insert at beginning
2. Insert at end
3. Display forward
4. Delete a node
5. Display reverse
6. Exit
Enter choice: 3
20 <-> 10 <-> 40 <-> NULL

1. Insert at beginning
2. Insert at end
3. Display forward
4. Delete a node
5. Display reverse
6. Exit
Enter choice: 5
40 <-> 10 <-> 20 <-> NULL

1. Insert at beginning
2. Insert at end
3. Display forward
4. Delete a node
5. Display reverse
6. Exit
Enter choice: 6

                                 
                                                                                        
                                                            