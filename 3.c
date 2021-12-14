#include<stdio.h>
#include<stdlib.h>
#include <string.h>


//creating a structure Node to make nodes for the AVL tree which has
//a left_child child and a right_child child and a data value and a parameter height
struct Node
{
	int data;
	struct Node *left_child;
	struct Node *right_child;
	int height;
};

// A utility function to get height of the tree
int height(struct Node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

// A utility function to get maximum of two integers
int max(int a, int b)
{
	return (a > b)? a : b;
}

//function newNode to allocate memory whenever a data is inserted into the AVL tree
struct Node* newNode(int data)
{
	struct Node* node = (struct Node*)
						malloc(sizeof(struct Node));
	node->data = data;
	node->left_child = NULL;
	node->right_child = NULL;
	node->height = 1; // new node is initially added at leaf
	return(node);
}

// A utility function to right_child rotate subtree rooted with node y
struct Node *right_childRotate(struct Node *y)
{
	struct Node *x = y->left_child;
	struct Node *T2 = x->right_child;

	// Perform rotation
	x->right_child = y;
	y->left_child = T2;

	// Update heights
	y->height = max(height(y->left_child), height(y->right_child))+1;
	x->height = max(height(x->left_child), height(x->right_child))+1;

	// Return new root
	return x;
}

// A utility function to left_child rotate subtree rooted with node x
struct Node *left_childRotate(struct Node *x)
{
	struct Node *y = x->right_child;
	struct Node *T2 = y->left_child;

	// Perform rotation
	y->left_child = x;
	x->right_child = T2;

	// Update heights
	x->height = max(height(x->left_child), height(x->right_child))+1;
	y->height = max(height(y->left_child), height(y->right_child))+1;

	// Return new root
	return y;
}

// Get Balance factor of node N
int getBalance(struct Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left_child) - height(N->right_child);
}

//function to insert the hash values of the names into the AVL tree
struct Node* insert(struct Node* node, int data)
{
	//1. Perform the normal BST rotation
	if (node == NULL)
		return(newNode(data));

	if (data < node->data)
		node->left_child = insert(node->left_child, data);
	else if (data > node->data)
		node->right_child = insert(node->right_child, data);
	else // Equal datas not allowed
		return node;

	// 2. Update height of this ancestor node
	node->height = 1 + max(height(node->left_child),
						height(node->right_child));

	// 3. Get the balance factor of this ancestor node to check whether this node became unbalanced
	int balance = getBalance(node);

	// If this node becomes unbalanced, then there are 4 cases

	// left left Case
	if (balance > 1 && data < node->left_child->data)
		return right_childRotate(node);

	// right right Case
	if (balance < -1 && data > node->right_child->data)
		return left_childRotate(node);

	// left right Case
	if (balance > 1 && data > node->left_child->data)
	{
		node->left_child = left_childRotate(node->left_child);
		return right_childRotate(node);
	}

	// right left Case
	if (balance < -1 && data < node->right_child->data)
	{
		node->right_child = right_childRotate(node->right_child);
		return left_childRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;
}

// Given a non-empty binary search tree, return the node with minimum data value found in that tree
struct Node * minValueNode(struct Node* node)
{
	struct Node* curr = node;

	// loop down to find the left_childmost leaf
	while (curr->left_child != NULL)
		curr = curr->left_child;

	return curr;
}

// Recursive function to delete a node with given data
// from subtree with given root. It returns root of
// the modified subtree.
struct Node* deleteNode(struct Node* root, int data)
{
	// STEP 1: PERFORM STANDARD BST DELETE

	if (root == NULL)
		return root;

	// If the data to be deleted is smaller than the
	// root's data, then it lies in left_child subtree
	if ( data < root->data )
		root->left_child = deleteNode(root->left_child, data);

	// If the data to be deleted is greater than the
	// root's data, then it lies in right_child subtree
	else if( data > root->data )
		root->right_child = deleteNode(root->right_child, data);

	// if data is same as root's data, then This is
	// the node to be deleted
	else
	{
		// node with only one child or no child
		if( (root->left_child == NULL) || (root->right_child == NULL) )
		{
			struct Node *temp = root->left_child ? root->left_child : root->right_child;

			// No child case
			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else // One child case
			*root = *temp; // Copy the contents of
							// the non-empty child
			free(temp);
		}
		else
		{
			// node with two children: Get the inorder
			// successor (smallest in the right_child subtree)
			struct Node* temp = minValueNode(root->right_child);

			// Copy the inorder successor's data to this node
			root->data = temp->data;

			// Delete the inorder successor
			root->right_child = deleteNode(root->right_child, temp->data);
		}
	}

	// If the tree had only one node then return
	if (root == NULL)
	return root;

	// STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
	root->height = 1 + max(height(root->left_child),height(root->right_child));

	// STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
	// check whether this node became unbalanced)
	int balance = getBalance(root);

	// If this node becomes unbalanced, then there are 4 cases

	// left left Case
	if (balance > 1 && getBalance(root->left_child) >= 0)
		return right_childRotate(root);

	// left right Case
	if (balance > 1 && getBalance(root->left_child) < 0){
		root->left_child = left_childRotate(root->left_child);
		return right_childRotate(root);
	}

	// right right Case
	if (balance < -1 && getBalance(root->right_child) <= 0)
		return left_childRotate(root);

	// right left Case
	if (balance < -1 && getBalance(root->right_child) > 0){
		root->right_child = right_childRotate(root->right_child);
		return left_childRotate(root);
	}

	return root;
}

// A utility function to print preorder traversal of the tree
void preOrder(struct Node *root)
{
	if(root != NULL){
		printf("%d ", root->data);
		preOrder(root->left_child);
		preOrder(root->right_child);
	}
}

// Compare function to pass to qsort to help sort the names
// This function compares each charater of the 2 strings charater by charater and returns the ASCII difference of the 2 unmatched charater
// If there are no unmatched charater i.e. both the strings are same, then it returns 0.
int compare(const void* one, const void* two)
{
    return strcmp(*(const char**)one, *(const char**)two);
}

// A hash function to hash each name in the names_array into a unique integer value
int hash(const char *str)
{
    int h = 0;
    while (*str)
       h = h << 1 ^ *str++;
    return h;
}


// Beginning of main function
int main(){
    
    // A character array to store the names of 5 friends
    const char* names_array[]= {"Nishant", "Amrit", "Chandan", "Sunandan", "Subhasmita", "Ritika"};
    // We calculate and store the length of the array in n
    int n = sizeof(names_array) / sizeof(names_array[0]);
    
    // qsort is a predefined function which takes an array and a compare funtion to sort the araay based on the compare function 
    qsort(names_array, n, sizeof(const char*), compare);

    // Printing the sorted names of friends
    printf("Sorted names: \n");
    for(int i = 0; i<n; i++){
        printf("%s \n", names_array[i]); 
    }
    
    printf("\n\n");
    
    // An array hashmap to store the hash values of the sorted names
    int hashmap[n];
    for(int i = 0; i<n; i++){
        hashmap[i]=hash(names_array[i]);
    }
    
    // Printing the hash values and the corresponding names in a tabular format
    printf("Names:\t\tHash Values:\n");
    for(int i = 0; i<n; i++){
        printf("%s\t\t%d \n", names_array[i], hashmap[i]);
    }
    
    struct Node *root = NULL;

    /* Constructing tree given in the above figure */

    
    // Making an AVL tree using the hash values obtained above
    for (int data = 0; data < n; data++)
    {
        root = insert(root, hashmap[data]);
    }
    
    
    printf("\n\nPreorder traversal of the constructed AVL "
           "tree is \n");
    preOrder(root);
    
    int j;
    printf("\n\nEnter the hash value of the name you want to delete\n");
    scanf("%d", &j);
    
    root = deleteNode(root, j);
    
    printf("\nPreorder traversal after deletion of the data is \n");
    preOrder(root);
    
    return 0;
}
