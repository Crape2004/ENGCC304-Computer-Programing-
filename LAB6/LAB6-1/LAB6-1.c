#include <stdio.h>

int main() {
        int a ;
        printf("Enter Your Line : ") ;
        scanf("%d", &a) ;
        for(int y = 1 ; y <= a ; y++) {
            for(int x = 1 ; x <= y ; x++){
                printf("*") ;
            }//end for
        printf("\n") ;
        }//end for
    return 0;
}//end function