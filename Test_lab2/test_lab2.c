#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ageman {
	int number ; // person's number
	char name[ 100 ] ; //person's name 
	char date[ 100 ] ; //Birthday date
} typedef age ; //keyword

int takedata ( age [] ) ; //take data to structure and 
void showdata ( age [], int ) ; // show data and the oldest/youngest 

int main(){
	age human[ 100 ] ; //announce array structure
	int number ; // number to count people
	number = takedata( human ) ;
	printf("-------------------------------\n") ; //segmented input and output
	showdata( human, number ) ;
	return 0 ;
}

int takedata ( age human[] ) {
	FILE *fo ; //file reader
	int count ;//count people
	
	fo = fopen( "data.txt", "r" ) ;//read file
	if ( fo == NULL ) {
		printf( " Not found file location " ) ;
		exit( 0 ) ;
	}//end if
	fscanf(fo,  "%s\t%s\t\t%s\n", human[ 0 ].name, human[ 0 ].name, human[ 0 ].name ) ;
	printf("%s\t%s\t\t%s\n", "No", "Name", "Birthday") ;
	strcpy(human[0].name, "\0") ;
	for (int x = 0 ; x < 100 ; x++){
		if (fscanf( fo, "%d\t%s\t\t%s\n", &human[ x ].number, human[ x ].name, human[ x ].date) != EOF) {
			count++ ;
			printf("%d\t%s\t\t%s\n", human[ x ].number, human[ x ].name, human[ x ].date) ;
		}
		else {
			break ;
		}//end if	
	}//end for
	fclose( fo ) ;//end
	return count ; //return number of people
}

void showdata ( age human[], int count) {
	int oldest = -999 ; //oldest values movement
	int youngest = 999 ; //oldest values movement
	char holderall[ 100 ], holder[ 100 ] ;// holder string and pre string date to integer date
	int year, month, day ;// date per person 
	char *pointname ; // point name
	int alltoday[ 100 ] ;//all day age
	for (int b = 0 ; b < count ; b++) {
		strcpy(holderall, human[b].date) ;
		for(int c = 0 ; c < 4 ; c++ ) {
			holder[ c ] = holderall[ c ] ;
		}//end for
		holder[ 4 ] = '\0' ;
		year = atoi( holder ) ;
		for(int c = 0 ; c < 2 ; c++ ) {
			holder[ c ] = holderall[ c + 5 ] ;
		}//end for
		holder[ 2 ] = '\0' ;
		month = atoi( holder ) ;
		
		for(int c = 0 ; c < 2 ; c++ ) {
			holder[ c ] = holderall[ c + 8 ] ;
		}//end for
		holder[ 2 ] = '\0' ;
		day = atoi( holder ) ;
		alltoday[ b ] =  ( 2018 - year ) * 365 + ( 6 - month ) * 30 + ( 21 - day ) ;
		printf("%s %d Years, %d Months\n", human[ b ].name, alltoday[ b ]/ 365, ( alltoday[ b ] % 365) / 30 ) ;
	}//end for
	
	for (int a = 0; a < count ; a++) {
		if ( alltoday[ a ] > oldest ) {
			oldest = alltoday[ a ] ;
			pointname = human[ a ].name ;
		}//end if
	}//end for
	printf( "\nMax : %s [%d Years, %d months]\n", pointname, oldest/365, (oldest%365)/30) ;

	for (int a = 0; a < count ; a++) {
		if ( alltoday[ a ] < youngest) {
			youngest = alltoday[ a ] ;
			pointname = human[ a ].name ;
		}//end if
	}//end for
	printf( "Min : %s [%d Years, %d months]", pointname, youngest/365, (youngest%365)/30) ;
}