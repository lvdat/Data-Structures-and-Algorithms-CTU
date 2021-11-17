#include <stdio.h>
#define M 100 // so luong phan tu toi da
#define SoPhanTu 100

typedef int ElementType;
// Tất cả hàm bên dưới đều có dpt O(1)

typedef struct {
    ElementType DuLieu[M];
    int Dinh; // vị trí đỉnh stack
} Stack;

typedef Stack NganXep;

void doiNhiPhan(int n, NganXep *pS){
    khoitao(pS);
    int x = n;
    do {
        them(x % 2, pS);
        x /= 2;
    } while(x > 0);
}
void readStack(Stack *pS){
    int n, x; scanf("%d", &n);
    makenullStack(pS);
    for(; n > 0; n--){
        scanf("%d", &x);
        push(x, pS);
    }
}
void printStack(Stack *pS){
    while(!emptyStack(*pS)){
        printf("%d ", top(*pS));
        pop(pS);
    }
}
int ktChuoi(){
    Stack S; makenullStack(&S);
    char ngoac[100];
    fgets(ngoac, 100, stdin);
    ngoac[strlen(ngoac) - 1] = '\0';
    int i = 0;
    for(; i < strlen(ngoac); i++){
        if(ngoac[i] == '('){
            push(ngoac[i], &S);
        }else if(ngoac[i] == ')' && !emptyStack(S)){
            pop(&S);
        }else {
            return 0;
        }
    }
    return emptyStack(S);
}
float tinhGiatri(char bt[]){
    Stack S; makenullStack(&S);
    int i = 0; float x1, x2;
    for(; i < strlen(bt); i++){
        if(bt[i] >= 48 && bt[i] <= 57){
            x1 = (int)bt[i] - 48;
            push(x1, &S);
        } else {
            x1 = (float)top(S);
            pop(&S);
            x2 = (float)top(S);
            pop(&S);
            switch(bt[i]){
                case '+':
                    push(x2 + x1, &S);
                    break;
                case '-':
                    push(x2 - x1, &S);
                    break;
                case '*':
                    push(x2 * x1, &S);
                    break;
                case '/':
                    push(x2 / x1, &S);
                    break;
                default:
                    break;
            }
        }
    }
    return top(S);
}