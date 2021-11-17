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
/* Queue makenullQueue(){
    Queue Q;
    Q.Front = -1;
    Q.Rear = -1;
    return Q;
} */

int emptyQueue(Queue Q){
    return Q.Front == -1;
}
int fullQueue(Queue Q){
    return Q.Rear - Q.Front == MaxLength - 1;
}

/* ElementType front(Queue Q){
    if(emptyQueue(Q))
        printf("Queue rong");
    else
        return Q.Elements[Q.Front]; 
} */

void deQueue(Queue *pQ){
    pQ->Front++;
    if(pQ->Front > pQ->Rear)
        makenullQueue(pQ);
}
/* void deQueue(Queue *pQ){
    if(emptyQueue(*pQ))
        printf("Queue day");
    else{
        if(pQ->Front == pQ->Rear)
            makenullQueue(pQ); 
        else
            pQ->Front++;
    }
} */

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

/* == */
int dem(Queue Q){
    return emptyQueue(Q) ? 0 : Q.Rear - Q.Front + 1;
}

int main(){
    Queue Q; makenullQueue(&Q);
    int N, x; char in;
    scanf("%d", &N);
    while(N--){
        scanf("\n");
        scanf("%c ", &in);
        if(in == 'E'){
            scanf(" %d\n", &x);
            enQueue(x, &Q);
            printf("%d\n", dem(Q));
        }else{
            if(emptyQueue(Q)){
                printf("-1 0\n");
            }else{
                printf("%d ", Q.Elements[Q.Front]);
                deQueue(&Q);
                printf("%d\n", dem(Q));
            }
        }
    }
}