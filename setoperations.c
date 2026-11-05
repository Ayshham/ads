 #include <stdio.h>
  
   #define SIZE 9
  
  5 typedef struct {
  6     unsigned char x : 1;
  7 } bit;
  8
   const int uset[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
 10
 11 void readset(bit a[], int n);
 12 void printset(const bit a[]);
 13 void unionset(const bit a[], const bit b[], bit c[]);
 14 void intersect(const bit a[], const bit b[], bit c[]);
 15 void difference(const bit a[], const bit b[], bit c[]);
 16
 17 int main(void)
 18 {
 19     bit a[SIZE] = {{0}}, b[SIZE] = {{0}}, c[SIZE] = {{0}};
 20     int n;
 21
 22     printf("Universal set: {1,2,3,4,5,6,7,8,9}\n\n");
 23
 24     printf("No. of elements in set A: ");
 25     if (scanf("%d", &n) != 1)
 26         return 1;
 27     readset(a, n);
 28
 29     printf("No. of elements in set B: ");
 30     if (scanf("%d", &n) != 1)
 31         return 1;
 32     readset(b, n);
 33
 34     printf("\nSet A: ");
 35     printset(a);
 36
 37     printf("Set B: ");
 38     printset(b);
 39
 40     unionset(a, b, c);
 41     printf("\n\tA U B = ");
 42     printset(c);
 43
 44     intersect(a, b, c);
 45     printf("\n\tA intersect B = ");
 46     printset(c);
 47
 48     difference(a, b, c);
 49     printf("\n\tA - B = ");
 50     printset(c);
     return 0;
 53 }
 54
 55 void readset(bit a[], int n)
 56 {
 57     int i, k, x;
 58
 59     if (n < 0 || n > SIZE) {
 60         printf("Invalid size; must be between 0 and %d.\n", SIZE);
 61         return;
 62     }
 63
 64     printf("Enter %d elements: ", n);
 65
 66     for (i = 0; i < n; i++) {
 67         if (scanf("%d", &x) != 1) return;
 68
 69         for (k = 0; k < SIZE; k++) {
 70             if (uset[k] == x) {
 71                 a[k].x = 1;
 72                 break;
 73             }
 74         }
 75
 76         if (k == SIZE)
 77             printf("%d is not in the universal set, ignored.\n", x);
 78     }
 79 }
 80 void printset(const bit a[])
 81 {
 82     int k, first = 1;
 83
 84     printf("{");
 85
 86     for (k = 0; k < SIZE; k++) {
 87         if (a[k].x) {
 88             printf(first ? "%d" : ",%d", uset[k]);
 89             first = 0;
 90         }
 91     }
 92
 93     printf("}\n");
 94 }
 95
 96 void unionset(const bit a[], const bit b[], bit c[])
 97 {
 98     for (int k = 0; k < SIZE; k++)
 99         c[k].x = a[k].x | b[k].x;
100 }
101
102 void intersect(const bit a[], const bit b[], bit c[])
103 {
104     for (int k = 0; k < SIZE; k++)
105         c[k].x = a[k].x & b[k].x;
106 }
107
108 void difference(const bit a[], const bit b[], bit c[])
109 {
110     for (int k = 0; k < SIZE; k++)
111         c[k].x = a[k].x && !b[k].x;
112 }



                    output

Universal set: {1,2,3,4,5,6,7,8,9}

No. of elements in set A: 4
Enter 4 elements: 1 3 2 4
No. of elements in set B: 5
Enter 5 elements: 3 4 6 2 7

Set A: {1,2,3,4}
Set B: {2,3,4,6,7}

        A U B = {1,2,3,4,6,7}

        A intersect B = {2,3,4}

        A - B = {1}

   
                                                         
                                    