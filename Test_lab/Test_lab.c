#include<stdio.h>
#include<string.h>

struct Employee {
    char name[ 100 ] ;
    float salary ;
    int duration ;
}typedef Employee ;

int main() {
    
    Enter_information() ;
    
}//end main

void Enter_information() {
    
    char choose = 'y' ; 
    int c = 0 ;
    Employee em[ 100 ] ;
    while( choose == 'y' ) {
        printf ( "Do you want to Enter Employee Information? (y/n) : " ) ;
        scanf ( " %c", &choose ) ;
        switch( choose ) {
            case 'y': { 
                Input_employee (em,c) ; c++ ; 
                    break ;
            }
            case 'n' : 
                break ;
        }
    }
    show_output ( em, c ) ;
}//end Enter_information

void Input_employee ( Employee em[] , int c ) {
    printf ( "Employee name: " ) ;
    getchar() ;
    gets ( em[ c ] . name ) ;
    printf ( "Salary (Bath/Month): " ) ;
    scanf ( "%f",&em[ c ] . salary ) ;
    printf ( "Duration (year): " ) ;
    scanf ( "%d",&em[ c ] . duration ) ;
}//end Input_employee

void show_output ( Employee em[], int c ) {
    int index = 0 , x = 0 ;
    float sum = 0 ;
    int Most_Salary ;
    float highsalary = -1 ;
    while ( index < c ) {
        sum = sum + em[ index ].salary ;
        index++  ;
    }//end while
    printf ( "Average of Salary: %.2f Bath\n ", sum/c ) ; 
    printf ( "Payment of every month: %.2f Bath\n ", sum ) ; 
    printf ( "Most Salary in this business\n" ) ; 
    while ( x < c ) {
        switch (em[ x ] . salary>highsalary) {
            case 1 : highsalary = em[ x ].salary ; Most_Salary = x ;
            break ;
        }
        x++ ;
    }//end while
    printf ( " Name : %s ( %d years )\n" , em[ Most_Salary ].name , em[ Most_Salary ].duration ) ; 
    printf ( " Salary : %.2f ( Bath )\n" , em[ Most_Salary ].salary ) ; 
}//end show_output
