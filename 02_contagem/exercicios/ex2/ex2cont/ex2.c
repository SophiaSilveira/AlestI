#include <stdio.h>

int funcao ( int n) {
    int op = 0;
    for ( int i =0; i <n; i ++)
        for ( int j =i; j <2* i; j ++)
            op ++;
    return op ;
}


int main(){
    for(int i = 0; i< 1000; ++i){
        printf("%d %d\n", i, funcao(i));
    }

    return 1;
}