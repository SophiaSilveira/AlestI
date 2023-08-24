#include <stdio.h>

int funcao ( int n) {
    int op = 0;
    for ( int i =1; i <n; i=i+i)
        op ++;
    return op ;
}


int main(){
    for(int i = 0; i< 5000; ++i){
        printf("%d %d\n", i, funcao(i));
    }

    return 1;
}
