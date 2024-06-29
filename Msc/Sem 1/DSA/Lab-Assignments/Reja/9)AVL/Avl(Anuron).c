#include <stdio.h>
#include <stdlib.h>

// AVL tree node structure
struct AVLNode {
    int data;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
};
int max(int a,int b)
{
	return a>b?a:b;
}
// Calculate height of a node
int height(struct AVLNode* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Create a new node
struct AVLNode *newNode(int data) {
    struct AVLNode* node = (struct AVLNode*)malloc(sizeof(struct AVLNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

// Right rotate subtree rooted with y
struct AVLNode* rightRotate(struct AVLNode* y) {
    struct AVLNode* x = y->left;
    struct AVLNode* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// Left rotate subtree rooted with x
struct AVLNode* leftRotate(struct AVLNode* x) {
    struct AVLNode* y = x->right;
    struct AVLNode* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Get balance factor of a node
int getBalance(struct AVLNode* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// Find the node with the minimum value in a tree
struct AVLNode* minValueNode(struct AVLNode* node) {
    struct AVLNode* current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}
struct AVLNode* insert(struct AVLNode* node, int key) {
    // Perform normal BST insertion
    if (node == NULL) 
	{
        return (newNode(key));
    }
    if (key < node->data) {
        node->left = insert(node->left, key);
    }
    else if (key > node->data) {
        node->right = insert(node->right, key);
    }
    else {
        return node;
    }
    
    // Update the height of the current node
    node->height = 1 + max(height(node->left), height(node->right));
    
    // Check if the current node is unbalanced
    int balance = getBalance(node);
    
    // If the node is unbalanced, there are four possible cases
    // Left Left Case
    if (balance > 1 && key < node->left->data) {
        return rightRotate(node);
    }
    // Right Right Case
    if (balance < -1 && key > node->right->data) {
        return leftRotate(node);
    }
    // Left Right Case
    if (balance > 1 && key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // Right Left Case
    if (balance < -1 && key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
// Delete a node from a tree
struct AVLNode* deleteNode(struct AVLNode* root, int data) {
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            struct AVLNode* temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;

            free(temp);
        } else {
            struct AVLNode* temp = minValueNode(root->right);

            root->data = temp->data;

            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;
    root->height = 1 + max(height(root->left), height(root->right));

// Get balance factor of the current node
int balance = getBalance(root);

// If the node is unbalanced, there are four possible cases

// Left Left Case
if (balance > 1 && getBalance(root->left) >= 0)
    return rightRotate(root);

// Left Right Case
if (balance > 1 && getBalance(root->left) < 0) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
}

// Right Right Case
if (balance < -1 && getBalance(root->right) <= 0)
    return leftRotate(root);

// Right Left Case
if (balance < -1 && getBalance(root->right) > 0) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
}

return root;
}

// Inorder traversal of the tree
void inorder(struct AVLNode* root) {
if (root != NULL) {
inorder(root->left);
printf("%d ", root->data);
inorder(root->right);
}
}

int main() {
struct AVLNode* root = NULL;
// Insert nodes into the tree
root = insert(root, 10);
root = insert(root, 20);
root = insert(root, 30);
root = insert(root, 40);
root = insert(root, 50);
root = insert(root, 25);

printf("Inorder traversal of the constructed AVL tree:\n");
inorder(root);

// Delete a node from the tree
root = deleteNode(root, 30);

printf("\nInorder traversal of the AVL tree after deletion of 30:\n");
inorder(root);

return 0;
}
