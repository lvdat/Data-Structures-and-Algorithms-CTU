#include <stdio.h>
#define MaxLength 100
typedef int ElementType;

typedef struct {
    ElementType Elements[MaxLength];
    int Front, Rear;
} Queue;

// Cài đặt queue dùng mảng di chuyển tịnh tiến, tất cả có DPT O(1)

void makenullQueue(Queue *pQ){
    pQ->Front = -1;
    pQ->Rear = -1;
}

int emptyQueue(Queue Q){
    return Q.Front == -1;
}
int fullQueue(Queue Q){
    return Q.Rear - Q.Front == MaxLength - 1;
}

void deQueue(Queue *pQ){
    pQ->Front++;
    if(pQ->Front > pQ->Rear)
        makenullQueue(pQ);
}
void enQueue(ElementType x, Queue *pQ){
    // riêng hàm này thì DPT O(n) (vòng lặp)
    if(fullQueue(*pQ))
        printf("Queue day");
    else{
        if(emptyQueue(*pQ)) pQ->Front = 0;
        if(pQ->Rear == MaxLength - 1){
            // Hàng đang bị tràn
            int i;
            // dời về trước Front - 1 phần tử
            for(i = pQ->Front; i <= pQ->Rear; i++)
                pQ->Elements[i-pQ->Front] = pQ->Elements[i];
            pQ->Rear -= pQ->Front; // pQ->Rear = MaxLength - 1 - pQ->Front;
            pQ->Front = 0;
        }
        pQ->Rear++; // tăng rear lên để lưu biến mới
        pQ->Elements[pQ->Rear] = x; // thêm x vào cuối queue
    }
}
int solve(Queue *pQ1, Queue *pQ2){
    int k = 0;
    while(!emptyQueue(*pQ1)){
        if(pQ1->Elements[pQ1->Front] == pQ2->Elements[pQ2->Front]){
            deQueue(pQ1);
            deQueue(pQ2);
        }else{
            enQueue(pQ1->Elements[pQ1->Front], pQ1);
            deQueue(pQ1);
        }
        k++;
    }
    return k;
}
int main(){
    Queue Q1, Q2; makenullQueue(&Q1); makenullQueue(&Q2);
    int N, i, var; scanf("%d\n", &N);
    for(i = 0; i < N; i++){
        scanf("%d", &var);
        enQueue(var, &Q1);
    }
    for(i = 0; i < N; i++){
        scanf("%d", &var);
        enQueue(var, &Q2);
    }
    printf("%d", solve(&Q1, &Q2));
}