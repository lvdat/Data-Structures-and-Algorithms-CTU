#include "avl.c"
// Chỉ include avl.c khi chạy trên vscode, DevC,...

// tìm số lớn nhất trong 2 số nguyên
int max(int a,int b){
    return (a > b) ? a : b;
}

// Hàm in khóa của những nút lá trong cây AVL
void printLeaves(AVLTree root){
    if(root != NULL){
        if(root->Left == NULL && root->Right == NULL)
            printf("%d ", root->Key);
        printLeaves(root->Left);
        printLeaves(root->Right);
        
    }
}

// Hàm tính hệ số cân bằng của một nút trên cây AVL
int getBalance(AVLTree node){
    if(node == NULL)
        return 0;
    return getHeight(node->Left) - getHeight(node->Right);
}

// Hàm xen một nút có khóa key vào cây AVL
AVLTree insertNode(KeyType key, AVLTree root){
    if(root == NULL){
        AVLTree temp = (struct Node*)malloc(sizeof(struct Node));
        temp->Key = key;
        temp->Left = NULL;
        temp->Right = NULL;
        return temp;
    }
    if(key < root->Key)
        root->Left = insertNode(key, root->Left);
    else if(key > root->Key)
        root->Right = insertNode(key, root->Right);
    else
        return root;
    
    root->Height = 1 + max(getHeight(root->Left), getHeight(root->Right));

    int balance = getBalance(root);
    if(balance > 1 && key < root->Left->Key)
        return rightRotate(root);
    if(balance > 1 && key > root->Left->Key)
        return leftrightRotate(root);
    if(balance < -1 && key > root->Right->Key)
        return leftRotate(root);
    if(balance < -1 && key < root->Right->Key)
        return rightleftRotate(root);
    return root;
}

// Hàm in kết quả duyệt hậu tự cây AVL
void printLRN(AVLTree root){
    if(root != NULL){
        printLRN(root->Left);
        printLRN(root->Right);
        printf("(%d - %d); ", root->Key, root->Height);
    }
}

// Hàm tìm chiều cao của một nút trên cây AVL
int getHeight(AVLTree T){
    int kq = 0, l, r;
    if(T != NULL){
        l = T->Left != NULL ? getHeight(T->Left) + 1 : 0;
        r = T->Right != NULL ? getHeight(T->Right) + 1 : 0;
        kq += (l > r ? l : r);
        return kq;
    }
    return -1;
}

// Hàm kiểm tra xem một cây có là cây AVL hay không
int isAVL(AVLTree root){
    int k = getBalance(root);
    return k >= -1 && k <= 1;
}

// Hàm xử lý trường hợp mất cân bằng bên trái của con phải
AVLTree rightleftRotate(AVLTree node){
    node->Right = rightRotate(node->Right);
    return leftRotate(node);
}

// Hàm xử lý trường hợp mất cân bằng bên phải của con trái
AVLTree leftrightRotate(AVLTree node){
    node->Left = leftRotate(node->Left);
    return rightRotate(node);
}

// Hàm in kết quả duyệt tiền tự cây AVL
void printNLR(AVLTree root){
    if(root != NULL){
        printf("(%d - %d); ", root->Key, root->Height);
        printNLR(root->Left);
        printNLR(root->Right);
    }
}

// Hàm in các khóa của những nút có cùng chiều cao height
void printHeight(int height, AVLTree root){
    if(root != NULL){
        if(getHeight(root) == height)
            printf("%d ", root->Key);
        printHeight(height, root->Left);
        printHeight(height, root->Right);
    }
}

// Hàm xử lý trường hợp mất cân bằng bên trái của con trái
AVLTree rightRotate(AVLTree node){
    AVLTree temp = node->Left;
    node->Left = temp->Right;
    temp->Right = node;
    node->Height = 1 + max(getHeight(node->Left), getHeight(node->Right));
    temp->Height = 1 + max(getHeight(temp->Left), getHeight(temp->Right));
    return temp;
}

// Hàm xử lý trường hợp mất cân bằng bên phải của con phải
AVLTree leftRotate(AVLTree node){
    AVLTree temp = node->Right;
    node->Right = temp->Left;
    temp->Left = node;
    node->Height = 1 + max(getHeight(node->Left), getHeight(node->Right));
    temp->Height = 1 + max(getHeight(temp->Left), getHeight(temp->Right));
    return temp;
}

// Hàm tìm và trả về nút có khóa key trong cây AVL
AVLTree search(KeyType key, AVLTree root){
    if(root == NULL) return NULL;
    return (root->Key == key) ? root : (root->Key < key) ? search(key, root->Right) : search(key, root->Left);
}

