#include <stdio.h>
#include <malloc.h>

struct Node {
    int Data;
    struct Node *Left, *Right;
};
typedef struct Node* Tree;