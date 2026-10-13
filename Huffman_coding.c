#include <stdio.h>
#include <stdlib.h>

struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
};

struct Node* heap[100];
int heapSize = 0;

void insert(struct Node* node) {
    int i = heapSize++;
    while (i > 0 && node->freq < heap[(i - 1) / 2]->freq) {
        heap[i] = heap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap[i] = node;
}

struct Node* extractMin() {
    struct Node* minNode = heap[0];
    struct Node* lastNode = heap[--heapSize];
    int i = 0, child;
    
    while ((child = 2 * i + 1) < heapSize) {
        if (child + 1 < heapSize && heap[child + 1]->freq < heap[child]->freq) 
            child++;
        if (lastNode->freq <= heap[child]->freq) break;
        heap[i] = heap[child];
        i = child;
    }
    heap[i] = lastNode;
    return minNode;
}

void printCodes(struct Node* root, int code[], int top) {
    if (root->left)  { code[top] = 0; printCodes(root->left, code, top + 1); }
    if (root->right) { code[top] = 1; printCodes(root->right, code, top + 1); }
    
    if (!root->left && !root->right) {
        printf("%c: ", root->ch);
        for (int i = 0; i < top; i++) printf("%d", code[i]);
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter the number of unique characters: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    for (int i = 0; i < n; i++) {
        struct Node* node = (struct Node*)malloc(sizeof(struct Node));
        
        printf("Enter character %d and its frequency (e.g., a 20): ", i + 1);
        scanf(" %c %d", &node->ch, &node->freq);
        
        node->left = node->right = NULL;
        insert(node);
    }

    while (heapSize > 1) {
        struct Node* left = extractMin();
        struct Node* right = extractMin();

        struct Node* parent = (struct Node*)malloc(sizeof(struct Node));
        parent->ch = '$';
        parent->freq = left->freq + right->freq;
        parent->left = left;
        parent->right = right;

        insert(parent);
    }

    int code[100];
    printf("\n--- Generated Huffman Codes ---\n");
    if (heapSize == 1) {
        printCodes(extractMin(), code, 0);
    }

    return 0;
}
