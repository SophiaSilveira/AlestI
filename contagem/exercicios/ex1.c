#include <stdio.h>

int funcao ( int n) {
    int op = 0;
    for ( int i =0; i <n; i ++)
        for ( int j =i; j <i +3; j ++)
            for ( int k =j; k <j +2; k ++)
                op ++;
    return op ;
}

int main(){
    for(int i = 0; i< 1000; ++i){
        printf("%d %d\n", i, funcao(i));
    }

    return 1;
}
