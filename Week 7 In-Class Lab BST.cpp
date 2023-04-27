#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

//Get minimum value in the BST
struct node* getMin(struct node* root) {
  while(root && root->left) { // while the tree is not empty and while there exists a left subtree
    root = root->left;
  }

  return root;
}

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root == NULL) { // if tree is empty nothing to print
    return;
  }

  traverseInOrder(root->left); // first go to left
  
  cout << root->key << " "; // then root

  traverseInOrder(root->right); // then right
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
  struct node *temp = new struct node; 
  struct node *parent;
  struct node *current;

  temp->key = key;
  temp->left = NULL;
  temp->right = NULL;

  if (node == NULL) { // if tree is empty, we simply create the root
    node = temp;
    return node;
  }

  else {
    current = node;
    parent = NULL;

    while (true) {
      parent = current;

      if (key < parent->key) { // if key to be inserted is less that of the parent key, we only look in the left subtree
        current = current->left;

        if (current == NULL) { //parent has no left node
          parent->left = temp; //so we put new node as the left node of parent
          return node;
        }
      }

      else if (key > parent->key) { // if key to be inserted is greater than that of the parent key, we only look in the right subtree
        current = current->right;
        
        if (current == NULL) { //parent has no right node
          parent->right = temp; //so we put new node as the right node of the parent
          return node;
        }
      }

      else { // if key already exists, we don't insert as the tree doesn't support duplicates
        return node;
      }
    }
  }
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  if (root == NULL) {
    return root;
  }

  if (key < root->key) {
    root->left = deleteNode(root->left, key);
  }

  else if (key > root->key) {
    root->right = deleteNode(root->right, key);
  }

  else {
    if (root->left == NULL && root->right == NULL) {
      return NULL;
    }

    else if (root->left == NULL) {
      struct node* temp = root->right;
      delete root;
      return temp;
    }

    else if (root->right == NULL) {
      struct node* temp = root->left;
      delete root;
      return temp;
    }

    struct node* temp = getMin(root->right); //In-order successor will be the minimum of right subtree
    root->key = temp->key;
    root->right = deleteNode(root->right, key);
  }
  return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}