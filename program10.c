#include <stdio.h>
#include <stdlib.h>

/* Structure of a BST node */
struct node {
    int data;
    struct node *left;
    struct node *right;
};

/* Create a new node */
struct node* createNode(int value) {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

/* Insert a node into BST */
struct node* insert(struct node *root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

/* In-order Traversal */
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

/* Pre-order Traversal */
void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

/* Post-order Traversal */
void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

/* Main function */
int main() {
    struct node *root = NULL;
    int n, value, i, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }

    do {
        printf("\n--- BST Traversal Menu ---\n");
        printf("1. In-order Traversal\n");
        printf("2. Pre-order Traversal\n");
        printf("3. Post-order Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("In-order Traversal: ");
            inorder(root);
            printf("\n");
            break;

        case 2:
            printf("Pre-order Traversal: ");
            preorder(root);
            printf("\n");
            break;

        case 3:
            printf("Post-order Traversal: ");
            postorder(root);
            printf("\n");
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}
