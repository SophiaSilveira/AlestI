#include <stdio.h>


double fat( int n){
    if ((n==1) || (n==0)) return 1;               
   else
      return fat(n-1)*n;
}

double euler(int n){
 if(n ==  0) return 1;
 else return 1.0/fat(n) + euler(n-1);
}

void main(){
    double n = euler(0);

    printf("%g", n);
}

