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

/* ===== */

int giatriDinh(NganXep S){
    return S.DuLieu[S.Dinh];
}
int ktRong(NganXep S){
    return S.Dinh == 100;
}
int ktDay(NganXep S){
    return S.Dinh == 0;
}

void xoa(NganXep *pS){
    if(!ktRong(*pS)){
        pS->Dinh++;
    }
}
void khoitao(NganXep *pS){
    pS->Dinh = 100;
}
void hienthi(NganXep *pS){
    while(!ktRong(*pS)){
        printf("%d ", giatriDinh(*pS));
        xoa(pS);
    }
}
void them(int x, NganXep *pS){
    if(pS->Dinh != 0){
        pS->Dinh--;
        pS->DuLieu[pS->Dinh] = x;
    }
}

