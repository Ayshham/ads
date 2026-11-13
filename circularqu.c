1 #include <stdio.h>
  2 #define SIZE 5
  3
  4 int queue[SIZE];
  5 int front = -1, rear = -1;
  6
  7 void enqueue(int value)
  8 {
  9     if ((rear + 1) % SIZE == front)
 10     {
 11         printf("Queue is FULL.\n");
 12         return;
 13     }
 14
 15     if (front == -1)
 16         front = 0;
 17
 18     rear = (rear + 1) % SIZE;
 19     queue[rear] = value;
 20
 21     printf("%d inserted.\n", value);
 22 }
 23
 24 void dequeue()
 25 {
 26     if (front == -1)
 27     {
 28         printf("Queue is EMPTY.\n");
 29         return;
 30     }
 31
 32     printf("%d deleted.\n", queue[front]);
 33
 34     if (front == rear)
 35         front = rear = -1;
 36     else
 37         front = (front + 1) % SIZE;
 38 }
 39
 40 void display()
 41 {
 42     if (front == -1)
 43     {
 44         printf("Queue is EMPTY.\n");
 45         return;
 46     }
 47
 48     printf("Queue: ");
 49     int i = front;
 50
   while (1)
 52     {
 53         printf("%d ", queue[i]);
 54
 55         if (i == rear)
 56             break;
 57
 58         i = (i + 1) % SIZE;
 59     }
 60     printf("\n");
 61 }
 62
 63 int main()
 64 {
 65     int choice, value, i, count;
 66
 67     while (1)
 68     {
 69         printf("\n--- Circular Queue ---\n");
 70         printf("1. Insert\n");
 71         printf("2. Delete\n");
 72         printf("3. Display\n");
 73         printf("4. Exit\n");
 74
 75         printf("Enter choice: ");
 76         scanf("%d", &choice);
 77
 78         switch (choice)
 79         {
 80             case 1:
 81                 count = (rear - front + SIZE) % SIZE + 1;
 82                 if (front == -1)
 83                     count = 0;
 84
 85                 if (count == SIZE)
 86                 {
 87                     printf("Queue is FULL.\n");
 88                     break;
 89                 }
 90
 91                 printf("Enter values: ");
 92
 93                 for (i = count; i < SIZE; i++)
 94                 {
 95                     scanf("%d", &value);
 96                     enqueue(value);
 97                 }
 98                 break;
 99
100             case 2:
101                 dequeue();
102                 break;
103
104             case 3:
105                 display();
106                 break;
107
108             case 4:
109                 return 0;
110
111             default:
112                 printf("Invalid choice.\n");
113         }
114     }
115 }

            output

--- Circular Queue ---
1. Insert
2. Delete
3. Display
4. Exit
Enter choice: 1
Enter values: 12 34 21 32 42
12 inserted.
34 inserted.
21 inserted.
32 inserted.
42 inserted.

--- Circular Queue ---
1. Insert
2. Delete
3. Display
4. Exit
Enter choice: 2
12 deleted.

--- Circular Queue ---
1. Insert
2. Delete
3. Display
4. Exit
Enter choice: 2
34 deleted.

--- Circular Queue ---
1. Insert
2. Delete
3. Display
4. Exit
Enter choice: 3
Queue: 21 32 42

--- Circular Queue ---
1. Insert
2. Delete
3. Display
4. Exit
Enter choice: 4

        
  
                   
                                       
                                                