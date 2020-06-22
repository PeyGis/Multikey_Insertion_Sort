/* 

   assignment2.h - interface file for the ant path location sorting problem
   ======================================================

   This program is for Assignment No. 2, Course 04-630 Data Structures and Algorithms for Engineers. 

   Please refer to the application file - assignment2Application.cpp - for details of the functionality of this program

      
   File organization
   -----------------

   assignment2.h                  interface file:      
                              contains the declarations required to use the functions that implement the solution to this problem
                              typically, these will include the definitions of the abstract data types used in the implementation

   assignment2Implementation.cpp  implementation file: 
                              contains the definitions of the functions that implement the algorithms used in the implementation
 
   assignment2Application.cpp     application file:    
                              contains the code that instantiates the abstract data types and calls the associated functions
                              in order to effect the required functionality for this application
                                                    
   Author
   ------

   Isaac Coffie, Carnegie Mellon University Africa
  February 17th, 2020

*/

 
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <ctype.h>

#define TRUE 1
#define FALSE 0
#define MAX_MESSAGE_LENGTH 81
#define MAX_BUFFER_SIZE 1024
#define UPPER_BOUND_TEST_RECORDS 27000

/* function prototypes go here */

/*A structure to store location details*/
struct location {float time; int x_pos; int y_pos;};

void prompt_and_exit(int status);
void print_message_to_file(FILE *fp, char message[]);


/*This function contains the implementation of the insertion sort algorithm*/
void do_insertion_sort(struct location *loc_array, int *num_elements, int column_index);

/*A function to hide the implementation of adding a record to the list*/
void add_record_to_array(struct location *loc_array, struct location loc_new, int *num_elements);

/*This function prints the contents of elements in the array*/
void print_sorted_records(FILE *fp, struct location *loc_array, int size);