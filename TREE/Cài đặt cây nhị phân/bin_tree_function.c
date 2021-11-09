#include "bin_tree.c"
// Chỉ include bin_tree.c khi chạy trên vscode, DevC,...

// Hàm khởi tạo và trả về một cây rỗng
Tree initTree(){
    Tree T;
    T = (struct Node*)malloc(sizeof(struct Node));
    T = NULL;
    return T;
}

// Hàm kiểm tra cây có gốc là T có rỗng hay không?
int isEmpty(Tree T){
    return T == NULL;
}

// Hàm duyệt tiền tự cây nhị phân T
void preOrder(Tree T){
    if(T != NULL){
        printf("%d ", T->Data);
        preOrder(T->Left);
        preOrder(T->Right);
    }
}

// Hàm duyệt trung tự cây nhị phân T
void inOrder(Tree T){
    if(T != NULL){
        inOrder(T->Left);
        printf("%d ", T->Data);
        inOrder(T->Right);
    }
}

// Hàm duyệt hậu tự cây nhị phân T
void postOrder(Tree T){
    if(T != NULL){
        postOrder(T->Left);
        postOrder(T->Right);
        printf("%d ", T->Data);
    }
}

// Hàm tạo một cây nhị phân từ giá trị x và hai cây con có sẵn l, r.
Tree createTree(int x, Tree l, Tree r){
    Tree T;
    T = (struct Node*)malloc(sizeof(struct Node));
    T->Data = x;
    T->Left = l;
    T->Right = r;
    return T;
}

// Hàm tính chiều cao của một cây nhị phân T
int getHeight(Tree T){
    int kq = 0, l, r;
    if(T != NULL){
        l = T->Left != NULL ? getHeight(T->Left) + 1 : 0;
        r = T->Right != NULL ? getHeight(T->Right) + 1 : 0;
        kq += (l > r ? l : r);
    }
    return kq;
}

// Hàm đếm số nút lá của một cây nhị phân T
int getLeaves(Tree T){
    return (T == NULL) ? 0 : (T != NULL && T->Left == NULL && T->Right == NULL) ? 1 : getLeaves(T->Left) + getLeaves(T->Right);
}

// Hàm tạo một nút có giá trị x.
Tree createNode(int x){
   struct Node* N;
   N = (struct Node*)malloc(sizeof(struct Node));
   N->Data = x;
   N->Left = NULL;
   N->Right = NULL;
   return N;
}
