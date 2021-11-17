#include <stdio.h>
#include <string.h>
#define MaxLength 100
typedef char ElementType;

// Tất cả hàm bên dưới đều có dpt O(1)

typedef struct {
    ElementType Elements[MaxLength];
    int Top_idx; // vị trí đỉnh stack
} Stack;

void inThaplucphan(int n){
    Stack S; makenullStack(&S);
    char hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    while(n != 0){
        push(n % 16, &S);
        n /= 16;
    }
    while(!emptyStack(S)){
        printf("%c", hex[(int)top(S)]);
        pop(&S);
    }
}
float tinhGiatri(char bt[]){
    Stack S; makenullStack(&S);
    int i = 0; float x1, x2;
    for(; i < strlen(bt); i++){
        if(bt[i] >= '0' && bt[i] <= '9'){
            push((int)bt[i] - 48, &S);
        } else if(bt[i] != ' ') {
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
int ktChuoi(){
    Stack S; makenullStack(&S);
    char ngoac[100];
    fgets(ngoac, 100, stdin);
    ngoac[strlen(ngoac) - 1] = '\0';
    int i = 0;
    for(; i < strlen(ngoac); i++){
        if(ngoac[i] == '('){
            push(ngoac[i], &S);
        }else if(ngoac[i] == ')'){
            if(!emptyStack(S))
                pop(&S);
            else
                return 0;
        }
    }
    return emptyStack(S);
}