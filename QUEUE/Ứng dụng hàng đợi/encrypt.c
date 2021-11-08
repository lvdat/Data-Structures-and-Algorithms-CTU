#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include "PQueue.c"

void encrypt(char value[], char key[]){
    Queue K; makenullQueue(&K);
    int i = 0;
    for(; i < strlen(key); i++){
        enQueue(key[i], &K);
    }
    for(i = 0; i < strlen(value); i++){
        printf("%c", value[i] + ((int)front(K) - 48));
        enQueue(front(K), &K);
        deQueue(&K);
    }
}
int main(){
    char value[1000], key[1000];
    fgets(value, 1000, stdin);
    value[strlen(value) - 1] = '\0';
    fgets(key, 1000, stdin);
    key[strlen(key) - 1] = '\0';
    encrypt(value, key);
    return (0 - 0); // :D
}