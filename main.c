#include <stdio.h>

#define LEN 10

typedef struct{
    int dados[LEN];
    int qntd;

} LES;

int isFull(LES *les){
    return les->qntd == LEN;
}

int getIndex(LES *les, int value){
    int idx = 0;
    while(idx < les->qntd && value > les->dados[idx]){
        idx++;
    }
    return idx;
}

void moveRight(LES *les, int idx){
    for(int n = les->qntd; n>idx; n--){
        les->dados[n] = les->dados[n-1];
    }
}

void insert(LES *les, int value){
    if(isFull(les)){
        return;
    }
    int idx = get_index(les, value);
    moveRight(les, idx);
    les->dados[idx] = value;
    les->qntd++;
}

void show(LES *les){
    for(int i = 0; i<les->qntd; i++){
        printf("%d" , les->dados[i]);
    }
    printf("\n");
}

int main() {
    printf("Hello World\n");
    return 0;
}