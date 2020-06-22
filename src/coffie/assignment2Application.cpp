/* 

   assignment2Application.cpp - the application file for the ant path location sorting problem
   ============================================================================================

   Author
   ===========================================================================================

   Isaac Coffie, MSIT Carnegie Mellon University Africa
   February 17th 2020


   The functionality of the program is defined as follows.
   ============================================================================================

   The purpose of this assignment is to sort the ant path location data per test case
   
   This location data has been stored in an input file (input.txt) with several test cases. For each test case, we apply a sorting algorithm on the records
   We then output the resulting solution unto a text file (output.txt)
   
   Both the output and input file is located in the ./data/ directory 
  

  Format of the input and output file
  =============================================================================================

   Input file
   ----------
   The input file has several lines of ant location data
   The first line denotes the number of test cases available
   The remaining lines of records is the actual location data, which has 3 columns (time (t), x position and y position of ant)
   One test case is differentiated from the other when you read in a negative time value (thus t < 0)
   The number of location data, is does not exceed 27,000 records


   Output file
   ------
   The output file is formatted in this way:

   first line is my Andrew ID
   The remaining line containts the sorted ant location path for each test case, delimeted by 17 dashes

	coffie (Andrew ID)

    TIME	X_LOC	Y_LOC
    xxx		xxx		xxx
	xxx		xxx		xxx
    ----------------------

    xxx		xxx		xxx
	xxx		xxx		xxx
   ----------------------



   Solution Strategy
   =================================================================================
   The key component of this assisgment is to decide on the sorting algorithm... in this case insertion sort was used becaused it is inplace and also stable
   It functions by maintaing two sub lists of arrays and inserting the elements in their correct order

   Since this tasks it a multi key sorting problem, I had to decide on the order of sorting that will result in the right output
   Per class discussion, it came to light that sorting the ant path problem by time, y and x will result in the accurate output
   I adopted this approach in my solution strategy by using these integer keys to specify the column:
	TIME = 1
	X_POSITION = 2
	Y_POSITION = 3


   I also hid my implementation details for the adding record to an array and printing the content of the array

   How does this strategy fit in?

   I maintained an array of structs to keep the elements for a particular test case
   Initialize a pointer to keep track of the number of elements in the array

   WHILE the input data has some content:
		
		read the content of the row and ADD it to the ARRAY

		IF we encounter a negative time value:
			CALL the INSERTION_SORT() algorithm on the time parameter
			CALL the INSERTION_SORT() algorithm on the y position parameter
			CALL the INSERTION_SORT() algorithm on the x position parameter

			CALL the PRINT_ARRAY() function to write the output of the sorted array into a file

			REINITIALIZE my number of element counter variable to zero so I can start processing the next test case

  END WHILE
   


   Test Strategy
   =================================================================================

   This program has been tested with variety of test data sets that reflect all valid conditions, including boundary conditions:

	#TEST 1: input file with zero test cases
			
			INPUT:

			
			EXPECTED OUTPUT:
			no content in the output file other than my AndrewID

	#TEST 2: input file with more than 1 test case
			
			INPUT:
				2
				0.000 0.000 0.000
				0.100 0.050 0.000
				0.200 0.100 0.000
				0.300 0.190 0.000
				0.400 0.300 0.000
				0.500 0.400 0.000
				0.600 0.500 0.000
				0.700 0.600 0.000
				0.800 0.700 0.000
				0.900 0.800 0.000
				1.000 0.900 0.000
				1.100 0.000 1.000
				1.200 0.000 1.010
				1.300 0.000 1.020
				1.400 0.000 2.000
				1.500 0.000 2.000
				1.600 0.000 4.000
				1.700 0.000 4.090
				1.800 0.000 5.000
				1.900 0.000 4.000
				2.000 0.000 2.000
				-1.00 0.000 0.000
				60.063 -28.247 20.743
				60.165 -28.292 20.564
				60.267 -28.430 20.522
				60.370 -28.442 20.456
				60.471 -28.476 20.337
				60.573 -28.638 20.146
				60.676 -28.938 20.071
				60.781 -29.181 19.92
				60.885 -29.163 19.891
				60.993 -29.252 19.84
				61.097 -29.269 19.701
				61.201 -29.340 19.658
				61.302 -29.319 19.586
				61.404 -29.453 19.365
				61.507 -29.621 19.112
				61.608 -29.912 19.067
				61.710 -30.145 18.923
				61.811 -30.221 18.872
				61.918 -30.291 18.892
				62.020 -30.365 18.788
				62.122 -30.462 18.663
				62.223 -30.683 18.633
				62.332 -31.042 18.653
				62.436 -31.328 18.606
				62.537 -31.913 18.621
				62.638 -32.051 18.531
				62.740 -32.824 18.672
				62.841 -32.802 18.745
				62.942 -32.756 18.752
				63.044 -32.655 18.718
				63.147 -32.207 18.516
				63.249 -32.002 18.066
				63.350 -31.847 17.958
				63.452 -31.565 17.685
				63.555 -31.320 17.205
				63.656 -30.980 16.569
				63.837 -30.829 16.044
				63.940 -30.632 16.115
				64.044 -30.407 16.049
				64.145 -30.176 16.052
				64.250 -29.799 16.266
				64.352 -29.582 16.433
				64.456 -29.283 17.090
				64.559 -29.019 17.464
				64.667 -28.514 18.610
				-1.00 0.000 0.000

			EXPECTED OUTPUT:
				
					coffie
					0.000    0    0 
					0.100    0    0 
					0.200    0    0 
					0.300    0    0 
					0.400    0    0 
					0.500    0    0 
					0.600    0    0 
					0.700    0    0 
					0.800    0    0 
					0.900    0    0 
					1.000    0    0 
					1.100    0    1 
					1.200    0    1 
					1.300    0    1 
					1.400    0    2 
					1.500    0    2 
					2.000    0    2 
					1.600    0    4 
					1.700    0    4 
					1.900    0    4 
					1.800    0    5 
				-----------------
				62.638  -32   18 
				62.740  -32   18 
				62.841  -32   18 
				62.942  -32   18 
				63.044  -32   18 
				63.147  -32   18 
				63.249  -32   18 
				63.350  -31   17 
				63.452  -31   17 
				63.555  -31   17 
				62.332  -31   18 
				62.436  -31   18 
				62.537  -31   18 
				63.656  -30   16 
				63.837  -30   16 
				63.940  -30   16 
				64.044  -30   16 
				64.145  -30   16 
				61.710  -30   18 
				61.811  -30   18 
				61.918  -30   18 
				62.020  -30   18 
				62.122  -30   18 
				62.223  -30   18 
				64.250  -29   16 
				64.352  -29   16 
				64.456  -29   17 
				64.559  -29   17 
				60.781  -29   19 
				60.885  -29   19 
				60.993  -29   19 
				61.097  -29   19 
				61.201  -29   19 
				61.302  -29   19 
				61.404  -29   19 
				61.507  -29   19 
				61.608  -29   19 
				64.667  -28   18 
				60.063  -28   20 
				60.165  -28   20 
				60.267  -28   20 
				60.370  -28   20 
				60.471  -28   20 
				60.573  -28   20 
				60.676  -28   20 
				-----------------


#TEST3: - input file with boundary cases

		INPUT:
			1
			126.396    36.202    25.644
			126.499    36.481    25.506
			138.301    36.481    25.506
			138.403    36.481    25.575
			138.606    36.481    25.575
			138.707    36.411    25.644
			138.808    36.411    25.644
			138.909    36.341    25.713
			139.013    36.341    25.713
			139.114    36.341    25.781
			139.216    36.341    25.850
			139.317    36.271    25.919
			139.419    36.271    25.988
			139.727    36.271    25.988
			139.829    36.271    25.919
			139.930    36.271    25.850
			140.033    36.341    25.781
			140.135    36.341    25.713
			140.236    36.341    25.644
			140.542    36.341    25.644
			140.643    36.411    25.575
			140.846    36.411    25.575
			140.948    36.411    25.506
			143.373    36.411    25.506
			143.476    36.411    25.438
			143.577    36.481    25.369
			143.680    36.481    25.300
			143.782    36.551    25.300
			145.208    36.551    25.300
			145.310    36.551    25.369
			145.615    36.551    25.369
			145.714    36.551    25.438
			145.916    36.551    25.438
			146.018    36.551    25.506
			146.118    36.551    25.506
			146.219    36.551    25.575
			146.321    36.551    25.575
			146.422    36.551    25.644
			169.497    36.551    25.644
			169.598    36.481    25.644
			314.607    36.481    25.644
			314.707    36.551    25.713
			314.809    36.620    25.781
			314.909    36.690    25.850
			315.009    36.760    25.919
			315.109    36.830    25.988
			316.517    36.830    25.988
			316.616    36.760    25.988
			316.716    36.760    25.988
			316.817    36.690    25.988
			317.117    36.690    25.988
			317.217    36.690    26.056
			317.317    36.690    26.056
			317.417    36.760    26.056
			317.517    36.760    26.125
			321.156    36.760    26.125
			321.258    36.830    26.125
			324.590    36.830    26.125
			324.695    36.760    26.125
			335.341    36.760    26.125
			335.445    36.760    25.988
			335.546    36.760    25.919
			335.647    36.760    25.850
			335.749    36.760    25.781
			335.851    36.760    25.713
			335.952    36.760    25.644
			336.054    36.830    25.575
			336.155    36.830    25.506
			360.057    36.900    25.781
			360.156    36.969    25.781
			360.257    36.969    25.850
			370.391    36.969    25.850
			370.497    36.969    25.781
			370.598    36.969    25.781
			370.700    36.969    25.713
			370.902    36.969    25.713
			371.004    37.039    25.713
			371.207    37.039    25.713
			371.308    37.039    25.644
			371.412    37.039    25.644
			371.513    37.039    25.575
			371.617    37.039    25.506
			372.023    37.039    25.506
			372.124    37.039    25.438
			374.364    37.039    25.438
			-374.364    37.039    25.438


		EXPECTED OUTPUT:

			coffie
			126.396   36   25 
			126.499   36   25 
			138.301   36   25 
			138.403   36   25 
			138.606   36   25 
			138.707   36   25 
			138.808   36   25 
			138.909   36   25 
			139.013   36   25 
			139.114   36   25 
			139.216   36   25 
			139.317   36   25 
			139.419   36   25 
			139.727   36   25 
			139.829   36   25 
			139.930   36   25 
			140.033   36   25 
			140.135   36   25 
			140.236   36   25 
			140.542   36   25 
			140.643   36   25 
			140.846   36   25 
			140.948   36   25 
			143.373   36   25 
			143.476   36   25 
			143.577   36   25 
			143.680   36   25 
			143.782   36   25 
			145.208   36   25 
			145.310   36   25 
			145.615   36   25 
			145.714   36   25 
			145.916   36   25 
			146.018   36   25 
			146.118   36   25 
			146.219   36   25 
			146.321   36   25 
			146.422   36   25 
			169.497   36   25 
			169.598   36   25 
			314.607   36   25 
			314.707   36   25 
			314.809   36   25 
			314.909   36   25 
			315.009   36   25 
			315.109   36   25 
			316.517   36   25 
			316.616   36   25 
			316.716   36   25 
			316.817   36   25 
			317.117   36   25 
			335.445   36   25 
			335.546   36   25 
			335.647   36   25 
			335.749   36   25 
			335.851   36   25 
			335.952   36   25 
			336.054   36   25 
			336.155   36   25 
			360.057   36   25 
			360.156   36   25 
			360.257   36   25 
			370.391   36   25 
			370.497   36   25 
			370.598   36   25 
			370.700   36   25 
			370.902   36   25 
			317.217   36   26 
			317.317   36   26 
			317.417   36   26 
			317.517   36   26 
			321.156   36   26 
			321.258   36   26 
			324.590   36   26 
			324.695   36   26 
			335.341   36   26 
			371.004   37   25 
			371.207   37   25 
			371.308   37   25 
			371.412   37   25 
			371.513   37   25 
			371.617   37   25 
			372.023   37   25 
			372.124   37   25 
			374.364   37   25 
			-----------------

#TEST4: input records more than 27,000

			EXPECTED OUTPUT: Program terminates unexpectedly
			ERROR FIXED: I make sure to check you're not giving more than 27,000 test cases.. I only process the MAX SIZE which is 27,000



    Time Complexity = g(n) = O(N^2)
   =================================================================================
   The order of complexity of this program is a quadractic function of order N = 2
   This is because the outer loop iterates through the number of elements in the input file, which is equal to O(N)
   Within this loop, we call the INSERTION_SORT() function three time, with each having a worst case scenario of O(N^2)
   We also perform come constant operations during the loop (such as if statements, incrementing counter, adding record to array) which is O(1)
   So, Overall, our time complexity ~ 0(N) + 0(N^2) + K
   Therefore the overall worst case time complexity is O(N^2)



   File organization -    This segement of comment is adopted from Prof David Vernon
   -----------------

   assignment2.h                  interface file:      
                              contains the declarations required to use the functions that implement the solution to this problem
                              typically, these will include the definitions of the abstract data types used in the implementation

   assignment2Implementation.cpp  implementation file: 
                              contains the definitions of the functions that implement the algorithms used in the implementation
 
   assignment2Application.cpp     application file:    
                              contains the code that instantiates the abstract data types and calls the associated functions
                              in order to effect the required functionality for this application


   Audit Trail
   -----------

   - Added prompt_and_exit() to allow users to read the terminal messages before it is closed.  David Vernon, 06/01/2019.

*/
 
#include "assignment2.h"
 
int main() {

	//Declare and initialize variables
   int debug = TRUE;
   int number_of_test_cases;
   float time, x_pos, y_pos;
   char buffer[MAX_BUFFER_SIZE];
   struct location unique_location_array[UPPER_BOUND_TEST_RECORDS];
   int num_elements = 0;
   FILE *fp_in, *fp_out;


   //attempt reading in the input data
   if ((fp_in = fopen("../data/input.txt","r")) == 0) {
	  printf("Error can't open input input.txt\n");
     prompt_and_exit(1);
   }
   // attempt reading in the output data
   if ((fp_out = fopen("../data/output.txt","w")) == 0) {
	  printf("Error can't open output output.txt\n");
     prompt_and_exit(1);
   }

   //Read number of test cases
	fscanf(fp_in, "%d", &number_of_test_cases);
	printf("Number of Test Cases %d\n", number_of_test_cases);

	fprintf(fp_out, "coffie\n");


	/*Read all location data until there is none*/

	while(fscanf(fp_in, "%f %f %f", &time, &x_pos, &y_pos) != EOF){

		//check for MAX_ARRAY_SIZE_ INDEX OUT OF BOUNDS

		if(num_elements == UPPER_BOUND_TEST_RECORDS){
			//call the sort function three times

			do_insertion_sort(unique_location_array, &num_elements,1);
			do_insertion_sort(unique_location_array, &num_elements,3);
			do_insertion_sort(unique_location_array, &num_elements,2);

			// then write the sorted values unto the output file
			print_sorted_records(fp_out, unique_location_array, num_elements);

			fprintf(fp_out, "-----------------\n");
			break; //terminate the loop
		
			}

		// create an object of location struct and set their values to the ones just read
		//Also truncate the values of x and y from floats to integer values

		struct location cur_loc;
		cur_loc.time = time;
		cur_loc.x_pos = (int)x_pos;
		cur_loc.y_pos = (int)y_pos;

		// this is to check if we have finished processing the content of a particular test case
		//from the problem, new test case are encountered when we see a negative time value
		//when we find a new test case, we reinitialize apply the sorting algorithm and pass control to the next iteration
		if(time < 0){

			//call the sort function three times
			do_insertion_sort(unique_location_array, &num_elements,1);
			do_insertion_sort(unique_location_array, &num_elements,3);
			do_insertion_sort(unique_location_array, &num_elements,2);

			// then write the sorted values unto the output file
			print_sorted_records(fp_out, unique_location_array, num_elements);

			num_elements = 0;
			fprintf(fp_out, "-----------------\n");
			continue;
		}
		//add record to array
		add_record_to_array(unique_location_array, cur_loc, &num_elements);
	}
	
   printf("Ant paths are successfully proceeded, check the output text file for result\n");
   fclose(fp_in);
   fclose(fp_out);

   prompt_and_exit(0);
}
