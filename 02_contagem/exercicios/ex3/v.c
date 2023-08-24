#include <stdio.h>

int funcao ( int n) {
    int seq = 0, op = 0;

    for(int i = 1; i <= n; i++){
        int valueN = i;
        for(int j = i + 1 ; valueN <=n; j++){
            if(valueN == n){
                seq++;
            }
            valueN +=j;
            ++op;
        }
    }
    //return seq;
    return op;
}

int main(){
    //funcao(15);
    for(int i = 0; i< 1000; ++i){
        printf("%d %d\n", i, funcao(i));
    }
    return 1;
}