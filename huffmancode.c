#include <stdio.h>
 #include <stdlib.h>
struct Node { 
char data;
 int freq;
 struct Node *left, *right;
 };
 struct Node* newNode(char data, int freq) { 
struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
temp->data = data;
temp->freq = freq;
temp->left = temp->right = NULL;

return temp;
}
 int findMin(struct Node* nodes[], int n) {
 int min = 0;
for (int i = 1; i < n; i++) {
    if (nodes[i]->freq < nodes[min]->freq)
        min = i;
}

return min;
}
 void printCodes(struct Node* root, int code[], int top) {
 if (root->left) {
 code[top] = 0;
 printCodes(root->left, code, top + 1);
 }
if (root->right) {
    code[top] = 1;
    printCodes(root->right, code, top + 1);
}

if (!root->left && !root->right) {
    printf("%c : ", root->data);

    for (int i = 0; i < top; i++)
        printf("%d", code[i]);

    printf("\n");
} 
}
void huffman(char data[], int freq[], int n) { 
struct Node* nodes[100];
for (int i = 0; i < n; i++)
    nodes[i] = newNode(data[i], freq[i]);

int size = n;

while (size > 1) {

   int min1 = findMin(nodes, size);

    struct Node* left = nodes[min1];

    nodes[min1] = nodes[size - 1];
    size--;

    int min2 = findMin(nodes, size);

    struct Node* right = nodes[min2];

    nodes[min2] = nodes[size - 1];
    size--;

    struct Node* parent = newNode('$', left->freq + right->freq);

    parent->left = left;
    parent->right = right;
    nodes[size] = parent;
    size++;
}

int code[100];

printf("\nHuffman Codes:\n");
printCodes(nodes[0], code, 0); 
}
int main() {
 int n;
printf("Enter number of characters: ");
scanf("%d", &n);

char data[100];
int freq[100];

printf("Enter characters:\n");
for (int i = 0; i < n; i++)
    scanf(" %c", &data[i]);

printf("Enter frequencies:\n");
for (int i = 0; i < n; i++)
    scanf("%d", &freq[i]);

huffman(data, freq, n);

return 0;
}
