#include <stdio.h>
#include <stdlib.h>
// Create a structure Node
struct Node {
	int key; //To store the value of the tree
	struct Node *left; //To store the left subtree
	struct Node *right; //To store the right subtree
	int height; //To store the height of the node in the tree
};

//Function to Calculate height
int height(struct Node *N) {
	if (N == NULL){
		return 0; //Returns 0 if the tree is empty
	}
	return N->height; //Returns the height of the node
}

//Function to calculate max height
int max(int a, int b) {
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}

//Function to Create a node
struct Node *newNode(int key) {
	struct Node *node = (struct Node *)malloc(sizeof(struct Node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return (node);
}

//Function to Right rotate the tree
struct Node *rightRotate(struct Node *y) {
	
	// y points to the node with wrong balance factor
	struct Node *x = y->left;
	struct Node *T2 = x->right;
	
	//Performing the Right Rotation
	x->right = y;
	y->left = T2;
	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;
	return x;
}

// Left rotate
struct Node *leftRotate(struct Node *x) {
	// x points to the node with wrong balance factor
	struct Node *y = x->right;
	struct Node *T2 = y->left;
	//Performing the Left Rotation
	y->left = x;
	x->right = T2;
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;
	return y;
}

// Get the balance factor
int getBalance(struct Node *N) {
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right); //Height of left sub-tree – Height of right sub-tree
}

// Insert node
struct Node *insertNode(struct Node *node, int key) {
	int balance;
	// Find the correct position to insert node and insert it
	if (node == NULL)
		return (newNode(key));
	if (key < node->key)
		node->left = insertNode(node->left, key);
	else if (key > node->key)
		node->right = insertNode(node->right, key);
	else
		return node;
	// Update the balance factor of each node and
	// Balance the tree
	node->height = 1 + max(height(node->left),height(node->right));
	balance = getBalance(node);
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);
	if (balance > 1 && key > node->left->key) {
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	if (balance < -1 && key < node->right->key) {
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	return node;
}

struct Node *minValueNode(struct Node *node) {
	struct Node *current = node;
	while (current->left != NULL)
		current = current->left;
	return current;
}

// Delete a nodes
struct Node *deleteNode(struct Node *root, int key) {
	int balance;
	// Find the node and delete it
	if (root == NULL){
		printf("%d not found", key);
		return root; //Return the root if root is empty
	}
		
	if (key < root->key)
		root->left = deleteNode(root->left, key);
	else if (key > root->key)
		root->right = deleteNode(root->right, key);
	else {
		if ((root->left == NULL) || (root->right == NULL)) {
			struct Node *temp = root->left ? root->left : root->right;
			if (temp == NULL) {
				temp = root;
				root = NULL;
			} 
			else
				*root = *temp;
			free(temp);
		} 
		else {
			struct Node *temp = minValueNode(root->right);
			root->key = temp->key;
			root->right = deleteNode(root->right, temp->key);
		}
	}
	if (root == NULL)
		return root;
	// Update the balance factor of each node and
	// balance the tree
	root->height = 1 + max(height(root->left),height(root->right));
	balance = getBalance(root);
	if (balance > 1 && getBalance(root->left) >= 0)
		return rightRotate(root);
	if (balance > 1 && getBalance(root->left) < 0) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	if (balance < -1 && getBalance(root->right) <= 0)
		return leftRotate(root);
	if (balance < -1 && getBalance(root->right) > 0) {
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}

// Print the tree in preorder traversal
void printPreOrder(struct Node *root) {
	if (root != NULL) {
		printf("%d ", root->key);
		printPreOrder(root->left);
		printPreOrder(root->right);
	}
}
void printInOrder(struct Node *root) {
	if (root != NULL) {
		printInOrder(root->left);
		printf("%d ", root->key);
		printInOrder(root->right);
	}
}
void printPostOrder(struct Node *root) {
	if (root != NULL) {
		printPostOrder(root->left);
		printPostOrder(root->right);
		printf("%d ", root->key);
	}
}

	
	int main() {
	struct Node *root = NULL;
	int x,ch;
	do{
		printf("\n\tMENU\n");
		printf("1. To Insert node \n2. To delete node \n3. To Display (PreOrder), (Inorder) and (PostOrder) \n4. Exit\n");
		printf("Enter your Choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter the data: ");
				scanf("%d",&x);
				root = insertNode(root,x);
				break;
			case 2:
				printf("Enter the key to delete: ");
				scanf("%d",&x);
				root = deleteNode(root,x);
				break;
			case 3:
				printf("The PreOrder Traversal is : ");
				printPreOrder(root);
				printf("\n The InOrder Traversal is : ");
				printInOrder(root);
				printf("\n The PostOrder Traversal is : ");
				printPostOrder(root);
				break;
			case 4:
				return 0;
				default:
				printf("Wrong Choice!!!!");
				break;
		}
	}while(1);
}
