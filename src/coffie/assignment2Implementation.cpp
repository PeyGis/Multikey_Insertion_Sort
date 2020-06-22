/* 

   assignment2Implementation.cpp - implementation file for the ant path location sorting problem
   ============================================================================

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

 
//include the header file 
#include "assignment2.h"

void prompt_and_exit(int status) {
   printf("Press any key to continue and close terminal\n");
   getchar();
   exit(status);
}

//this function simply prints a message to file with no complex formatting
void print_message_to_file(FILE *fp, char message[]) {
 
   fprintf(fp,"The message is: %s\n", message);
}


/* A function to add an element of type location to the array
@param loc_array pointer to the location array
@param loc_new a location struct object
@param num_elements a pointer to the number of elements in the array
@returns nothing since it's void
*/
void add_record_to_array(struct location *loc_array, struct location loc_new, int *num_elements){

	//dereference the num_elements pointer and insert the new location record into the array index
	loc_array[*num_elements] = loc_new;
	*num_elements +=1; //we then increment the number of elements in the array for successive insertion
}

/* A function that implements the insertion sort algorith
@param loc_array pointer to the location array
@param num_elements a pointer to the number of elements in the array
@param column_index the index which defines which column to apply the sort on {1:time, 2:x_position, 3: y_position}
@returns nothing since it's void
*/
void do_insertion_sort(struct location *loc_array, int *num_elements, int column_index){
	
		//loop through all elements in the array
		for(int i=1; i < *num_elements; i++){

			//declare local variables to store temp values
			struct location cur_loc = loc_array[i];
			float time = loc_array[i].time;
			int x_pos = loc_array[i].x_pos;
			int y_pos = loc_array[i].y_pos;

			//update the inner while loop counter
			int j = i-1;


			//if column index equals 1 then we sort by time
			if (column_index == 1){

				//push elements one index ahead to make way for the insertion
				while(j >=0 && loc_array[j].time > time){
					
					loc_array[j+1] = loc_array[j];
					j--;
				}

			//if column index equals 2 then we sort by x position
			}else if(column_index == 2){

				//push elements one index ahead to make way for the insertion
				while(j >=0 && loc_array[j].x_pos > x_pos){
					
					loc_array[j+1] = loc_array[j];
					j--;
				}

			//if column index equals 3 then we sort by y position	
			}else if (column_index == 3){
				//push elements one index ahead to make way for the insertion
				while(j >=0 && loc_array[j].y_pos > y_pos){
					
					loc_array[j+1] = loc_array[j];
					j--;
				}
			//if column index is not any of the above we assume the user wants to sort by time
			}else{
				while(j >=0 && loc_array[j].time > time){
					//push elements one index ahead to make way for the insertion
					loc_array[j+1] = loc_array[j];
					j--;
				}
			}
			
			//we can now insert the current location object at its correct index
			loc_array[j+1] = cur_loc;
		}
}


/* A function to print the content of an array
@param loc_array pointer to the location array
@param size the size or number of elements in the array
@param fp a pointer to the file output stream
@returns nothing since it's void
*/
void print_sorted_records(FILE *fp, struct location *loc_array, int size){

	for(int i=0; i < size; i++){

		//finally print this new unique location to the output file
		float t = loc_array[i].time;
		int x = loc_array[i].x_pos;
		int y = loc_array[i].y_pos;
		fprintf(fp, "%6.3f %4d %4d \n", t, x, y);
	}
}