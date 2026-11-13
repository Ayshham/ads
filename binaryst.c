 #include <stdio.h>
 #include <stdlib.h>
  
   struct Node {
       int data;
       struct Node *left, *right;
   };
  
  struct Node* newNode(int key) {
      struct Node* node = (struct Node*)malloc(sizeof(struct Node));
      node->data = key;
      node->left = node->right = NULL;
      return node;
  }
 
  struct Node* insert(struct Node* root, int key) {
      if (root == NULL)
          return newNode(key);
 
      if (key < root->data)
          root->left = insert(root->left, key);
      else if (key > root->data)
          root->right = insert(root->right, key);
      else
          printf("%d already exists.\n", key);
 
      return root;
 }
 
  struct Node* minNode(struct Node* root) {
      while (root->left != NULL)
          root = root->left;
 
      return root;
  }
 
  struct Node* deleteNode(struct Node* root, int key) {
     if (root == NULL) {
          printf("%d not found.\n", key);
          return NULL;
      }
 
      if (key < root->data)
          root->left = deleteNode(root->left, key);
      else if (key > root->data)
         root->right = deleteNode(root->right, key);
      else {
          if (root->left == NULL) {
              struct Node* temp = root->right;
              free(root);
               return temp;
         }
 
          if (root->right == NULL) {
              struct Node* temp = root->left;
              free(root);
              return temp;
          }
 
          struct Node* succ = minNode(root->right);
          root->data = succ->data;
          root->right = deleteNode(root->right, succ->data);
      }
 
      return root;
  }
 
  void inorder(struct Node* root) {
      if (root == NULL)
          return;
 
      inorder(root->left);
     printf("%d ", root->data);
      inorder(root->right);
  }
 
  void preorder(struct Node* root) {
      if (root == NULL)
          return;
 
      printf("%d ", root->data);
 preorder(root->left);
      preorder(root->right);
  }
 
  void postorder(struct Node* root) {
      if (root == NULL)
          return;
 
      postorder(root->left);
      postorder(root->right);
      printf("%d ", root->data);
  }
 
  void search(struct Node* root, int key) {
      if (root == NULL) {
           printf("%d not found.\n", key);
          return;
     }

     if (key == root->data) {
         printf("%d found in the BST.\n", key);
     }
     else if (key < root->data) {
         search(root->left, key);
     }
     else {
        search(root->right, key);
     }
 }

 int main() {
     struct Node* root = NULL;
     int choice, value;

     while (1) {
         printf("\n--- Binary Search Tree ---\n");
         printf("1. Insert\n");
         printf("2. Delete\n");
         printf("3. Inorder\n");
         printf("4. Preorder\n");
         printf("5. Postorder\n");
         printf("6. Search\n");
         printf("7. Exit\n");

         printf("Enter choice: ");
         scanf("%d", &choice);

         switch (choice) {
             case 1:
                 printf("Enter value to insert: ");
                 scanf("%d", &value);
                 root = insert(root, value);
                 break;

            case 2:
                 printf("Enter value to delete: ");
                 scanf("%d", &value);
                 root = deleteNode(root, value);
                 break;

             case 3:
                 printf("Inorder: ");
                 inorder(root);
                 printf("\n");
                 break;

             case 4:
                 printf("Preorder: ");
                 preorder(root);
                 printf("\n");
                 break;

             case 5:
                printf("Postorder: ");
                 postorder(root);
                 printf("\n");
                 break;

             case 6:
                 printf("Enter value to search: ");
                 scanf("%d", &value);
                 search(root, value);
                 break;
            case 7:
return 0;

             default:
                 printf("Invalid choice.\n");
         }
     }

     return 0;
 }

output




--- Binary Search Tree ---
1. Insert
2. Delete
3. Inorder
4. Preorder
5. Postorder
6. Search
7. Exit
Enter choice: 1
Enter value to insert: 1

--- Binary Search Tree ---
1. Insert
2. Delete
3. Inorder
4. Preorder
5. Postorder
6. Search
7. Exit
Enter choice: 1
Enter value to insert: 34

--- Binary Search Tree ---
1. Insert
2. Delete
3. Inorder
4. Preorder
5. Postorder
6. Search
7. Exit
Enter choice: 1
Enter value to insert: 45

--- Binary Search Tree ---
1. Insert
2. Delete
3. Inorder
4. Preorder
5. Postorder
6. Search
7. Exit
Enter choice:  1
Enter value to insert: 56

--- Binary Search Tree ---
1. Insert
2. Delete
3. Inorder
4. Preorder
5. Postorder
6. Search
7. Exit
Enter choice: 3
Inorder: 1 34 45 56

--- Binary Search Tree ---
1. Insert
2. Delete
3. Inorder
4. Preorder
5. Postorder
6. Search
7. Exit
Enter choice: 4
Preorder: 1 34 45 56

--- Binary Search Tree ---
1. Insert
2. Delete
3. Inorder
4. Preorder
5. Postorder
6. Search
7. Exit
Enter choice: 5
Postorder: 56 45 34 1

--- Binary Search Tree ---
1. Insert
2. Delete
3. Inorder
4. Preorder
5. Postorder
6. Search
7. Exit
Enter choice: 6
Enter value to search: 34
34 found in the BST.

--- Binary Search Tree ---
1. Insert
2. Delete
3. Inorder
4. Preorder
5. Postorder
6. Search
7. Exit
Enter choice: 2
Enter value to delete: 45

--- Binary Search Tree ---
1. Insert
2. Delete
3. Inorder
4. Preorder
5. Postorder
6. Search
7. Exit
Enter choice: 7



