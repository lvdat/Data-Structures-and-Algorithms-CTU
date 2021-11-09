#include "bin_tree.c"

// Hàm createTree() cho phép dựng một cây nhị phân từ các biểu thức duyệt tiền tự và trung tự.
// Bài này mình dùng kèm hàm createNode
Tree createNode(int x){
   struct Node* N;
   N = (struct Node*)malloc(sizeof(struct Node));
   N->Data = x;
   N->Left = NULL;
   N->Right = NULL;
   return N;
}
int cs = 0;
Tree createTree(char tientu[], char trungtu[], int start, int end){
    int index; Tree T;
    if(start > end) return NULL;
    T = createNode(tientu[cs]);
    cs++;
    if(start == end)
        return T;
    index = findIndex(T->Data, trungtu, start, end);
    T->Left = createTree(tientu, trungtu, start, index - 1);
    T->Right = createTree(tientu, trungtu, index + 1, end);
    return T;
}

// Hàm findMax() tìm giá trị lớn nhất trong cây nhị phân.
int findMax(Tree T){
    if(T == NULL) return 0;
    int l, r, g, k;
    l = T->Left ? findMax(T->Left) : 0;
    r = T->Right ? findMax(T->Right) : 0;
    g = T->Data;
    k = (l > r ? l : r);
    return (k > g ? k : g);
}

// Hàm findElement() xác định xem x có là giá trị của một nút trong cây nhị phân hay không.
Tree findElement(DataType x, Tree T){
    if(T == NULL) return NULL;
    return (T->Data == x) ? T : (findElement(x, T->Left) != NULL) ? findElement(x, T->Left) : findElement(x, T->Right);
}

// Hàm getDiameter() tính đường kính của một cây nhị phân
// Bài này mình dùng cùng hàm getHeight
int getHeight(Tree T){
    int kq = 0, l, r;
    if(T != NULL){
        l = T->Left != NULL ? getHeight(T->Left) + 1 : 0;
        r = T->Right != NULL ? getHeight(T->Right) + 1 : 0;
        kq += (l > r ? l : r);
    }
    return kq;
}

int getDiameter(Tree T, int *d){
    int l, r, dl, dr;
    if(T == NULL) return 0;
    l = getHeight(T->Left) + 1;
    r = getHeight(T->Right) + 1;
    dl = getDiameter(T->Left, d);
    dr = getDiameter(T->Right, d);
    *d = max(l + r + 1, max(dl, dr));
    return *d;
}

// Hàm getFullNodes() đếm số nút có đủ hai con.
int getFullNodes(Tree T){
    if(T == NULL) return 0;
    int k = 0;
    if(T->Left != NULL && T->Right != NULL)
        k++;
    k += getFullNodes(T->Left) + getFullNodes(T->Right);
    return k;
}

// Hàm convertTree() để chuyển đổi một cây nhị phân sang cây phản chiếu của nó.
Tree convertTree(Tree T){
    if(T == NULL)
        return NULL;
    Tree K = T;
    Tree dT;
    convertTree(K->Left);
    convertTree(K->Right);
    dT = K->Left;
    K->Left = K->Right;
    K->Right = dT;
    return K;
}

// Hàm isMirrors() kiểm tra xem hai cây có là phản chiếu của nhau hay không.
int isMirrors(Tree T1, Tree T2){ //KIỂM TRA CÂY PHẢN CHIẾU
    if(T1 == NULL && T2 == NULL) return 1;
    if(T1 == NULL || T2 == NULL) return (0 - 0);
    return T1->Data == T2->Data && isMirrors(T1->Left, T2->Right) && isMirrors(T1->Right, T2->Left);
}

// Hàm printAllPaths() hiển thị tất cả các đường đi (từ nút gốc đến nút lá) và có độ dài đường đi thỏa điều kiện cho trước
void printAllPaths(Tree T, int path[], int len, int pathlen){
    if(T == NULL || len > pathlen)
        return;
    path[len] = T->Data;
    len++;
    if(isLeaf(T) && len == pathlen + 1)
        printArray(path, len);
    else{
        printAllPaths(T->Left, path, len, pathlen);
        printAllPaths(T->Right, path, len, pathlen);
    }
}


