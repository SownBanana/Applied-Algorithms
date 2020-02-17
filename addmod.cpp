#include "stdio.h"
int main(){
    #define P 1000000007;
    int a;
    int b; 
    int rs;
    scanf("%d%d",&a,&b);
    a = a%P;
    b =b%P;
    int tmp = P - a;
    if(tmp > b) rs = a+b;
    else rs = b - tmp;
    printf("%d", rs);
    return 0;
}
