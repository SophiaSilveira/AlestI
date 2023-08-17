#include <stdio.h>

//substituir dois lacos

void mat(int l, int c, int d){
    if(c <= 0 ) {
        c = d;
        l--;
    }
    if(l <= 0) return;
    mat(l, c-1, d);
    printf("%d %d\n", l-1, c);
}

int main(){
    mat(5, 4, 4);
}

