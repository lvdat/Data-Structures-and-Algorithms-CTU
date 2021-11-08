#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "PIQueue.c"
void tinhsoquay(int khach, int soquay, int tgxuly, int tgiandentb, int tg_mt, float *tg_tb){
    Queue Q;
    /* tg_mt: thoi gian muc tieu (la thoi gian trong de)
        tg_tb: la thoi gian tinh toan voi so quay tuong ung, dung de so sanh voi tg_mt
    */
    int tongthoigian, tgdi, tgden, quay = 1, stt_quay, i, tgian_khachtruocdi[soquay];
    // tgian_khachtruocdi: thoi gian khach truoc di de tinh thoi gian hien tai tai quay
    *tg_tb = tg_mt+1;
    while(quay <= soquay && *tg_tb > tg_mt){
        // reset toan bo thoi gian di cua khach
        for(i = 1; i <= quay; i++)
            tgian_khachtruocdi[i-1] = 0;
        
        // them toan bo thoi gian cua khach vao hang doi
        makenullQueue(&Q);
        for(i = 1; i <= khach; i++)
            enQueue(i * tgiandentb, &Q);
        
        tongthoigian = 0;
        while(!emptyQueue(Q)){
            for(stt_quay = 1; stt_quay <= quay && !emptyQueue(Q); stt_quay++){
                tgden = front(Q);
                deQueue(&Q);

                if(tgden >= tgian_khachtruocdi[stt_quay - 1]) // vua vao, phai xu ly ngay
                    tgdi = tgden + tgxuly;
                else
                    tgdi = tgian_khachtruocdi[stt_quay - 1] + tgxuly;
                
                tgian_khachtruocdi[stt_quay - 1] = tgdi;
                tongthoigian += tgdi - tgden;

            }
        }
        *tg_tb = tongthoigian/khach;
        printf("So quay: %d; Thoi gian cho trung binh: %.1f\n", quay, *tg_tb);
        quay++;
    }
    quay--;
    if(quay == soquay && *tg_tb > tg_mt)
        printf("Voi %d quay hien co, khach phai cho it nhat %.1f giay moi duoc phuc vu.", quay, *tg_tb);
    if(quay <= soquay && *tg_tb <= tg_mt)
        printf("=> Sieu thi se mo %d quay", quay);
}

int main(){
    /*
    N: số khách hàng
    M: số quầy thu ngân tối đa
    T1: Thời gian xử lý trung bình cho 1 giao dịch tại quầy thu ngân (s)
    T2: Thời gian trung bình (số giây) mà khách hàng sẽ đến xếp hàng thanh toán. 
    X: Thời gian trung bình mà khách hàng phải đợi để được thanh toán X
    */
    int N, M, T1, T2, X;
    float tb;
    scanf("%d\n%d\n%d\n%d\n%d", &N, &M, &T1, &T2, &X);

    tinhsoquay(N, M, T1, T2, X, &tb);
}
