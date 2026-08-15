#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* insert(struct Node* node, int key) {
    if (node == NULL) {
        return createNode(key);
    }

    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    } else {
        printf("Value %d already exists in the BST. Duplicates not allowed.\n", key);
    }

    return node;
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        printf("Value %d not found in the tree.\n", key);
        return root;
    }

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        // Case 1 & 2: Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            printf("Node deleted successfully.\n");
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            printf("Node deleted successfully.\n");
            return temp;
        }

        // Case 3: Node with two children
        struct Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, val;

    while (1) {
        printf("1. Insert an Element\n");
        printf("2. Delete an Element\n");
        printf("3. Display Tree (Inorder Traversal)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch (choice) {
            case 1:
                printf("Enter integer to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;

            case 2:
                if (root == NULL) {
                    printf("Tree is already empty.\n");
                } else {
                    printf("Enter integer to delete: ");
                    scanf("%d", &val);
                    root = deleteNode(root, val);
                }
                break;

            case 3:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("Inorder Traversal (Sorted): ");
                    inorder(root);
                    printf("\n");
                }
                break;

            case 4:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Please select an option between 1 and 4.\n");
        }
    }
    return 0;
}

