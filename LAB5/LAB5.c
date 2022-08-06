#include <stdio.h>

int main() {
        int year ;
        printf("Enter Year : ") ;
        scanf("%d", &year) ;
        if (year % 4 == 0)
            if(year % 400 == 0)
                printf("Feb = 29 Day") ;
            else if(year % 100 == 0)
                printf("Feb = 28 Day") ;
            else
                printf("Feb = 29 Day") ;
        else 
            printf("Feb = 28 Day") ;

    return 0;
}//end function