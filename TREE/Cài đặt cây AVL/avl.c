#include <stdio.h>
#include <malloc.h>
// Khai báo cho kiểu dữ liệu cây tìm kiếm nhị phân cân bằng về chiều cao AVL
typedef int KeyType;
struct Node{
    KeyType Key;
    int Height;
    struct Node *Left, *Right;
};
typedef struct Node* AVLTree;

int max(int a,int b){
    return (a > b) ? a : b;
}

