 Enter_information(){
    
    char choice = 'y' ; 
    int c = 0 ;
    Employee am[100] ;
    while(choice == 'y') {
        printf ("Do you want to Enter Employee Information? (y/n) : ");
        scanf (" %c", &choice);
        switch(choice) {
            case 'y': { Input_employee (am,c) ; c++ ; break;
            }
            default : break;
        }
    }
    show_output (am, c) ;
}

void Input_employee (Employee am[] , int c) {
    printf ( "Employee name: " ) ;
    getchar() ;
    gets (am[c].name) ;
    printf ( "Salary (Bath/Month): " ) ;
    scanf ("%f",&am[c].salary) ;