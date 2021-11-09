#include <stdio.h>
#include <malloc.h>

typedef char DataType;
struct Node {
    DataType Data;
    struct Node *Left, *Right;
};

typedef struct Node* Tree;

void makenullTree(Tree *pT){
    (*pT) = NULL;
}

int emptyTree(Tree T){
    return T == NULL;
}

Tree leftChild(Tree T){
    return (T != NULL) ? T->Left : NULL;
}

Tree rightChild(Tree T){
    return (T != NULL) ? T->Right : NULL;
}

int isLeaf(Tree T){
    return T != NULL && T->Left == NULL && T->Right == NULL;
}

int getLeaves(Tree T){
    return (T == NULL) ? 0 : (T != NULL && T->Left == NULL && T->Right == NULL) ? 1 : getLeaves(T->Left) + getLeaves(T->Right);
}

void preOrder(Tree T){
    if(T != NULL){
        printf("%c ", T->Data);
        preOrder(T->Left);
        preOrder(T->Right);
    }
}

void inOrder(Tree T){
    if(T != NULL){
        inOrder(T->Left);
        printf("%c ", T->Data);
        inOrder(T->Right);
    }
}

void postOrder(Tree T){
    if(T != NULL){
        postOrder(T->Left);
        postOrder(T->Right);
        printf("%c ", T->Data);
    }
}

int findIndex(DataType x, char in[], int star, int end){
    int i=star;
    while (i<=end){
         if (x==in[i])
             return i;
 
       else
             i++;
   }
   return i;
}

int max(int a, int b){
    return (a > b) ? a : b;
}