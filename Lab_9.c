#include<math.h>
#include<time.h>
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 10 // the number of elements in the array


int program_1()
{
    printf("Size of char = %d\n", sizeof(char));
    printf("Size of * char = %d\n", sizeof(char*));
    printf("Size of short = %d\n", sizeof(short));
    printf("Size of * short = %d\n", sizeof(short*));
    printf("Size of int = %d\n", sizeof(int));
    printf("Size of * int = %d\n", sizeof(int*));
    printf("Size of long = %d\n", sizeof(long));
    printf("Size of * long = %d\n", sizeof(long*));
    printf("Size of float = %d\n", sizeof(float));
    printf("Size of * float = %d\n", sizeof(float*));
    printf("Size of double = %d\n", sizeof(double));
    printf("Size of * double = %d\n", sizeof(double*));
    printf("Size of long double = %d\n", sizeof(long double));
    printf("Size of * long double = %d\n", sizeof(long double*));
    return 0;
}


void program_3() {

    int i;
    int max = 0; // Stores information how many times the most frequent number is encountered
    char str[20];  // Create a line of 20 characters
    char* p = str; // A pointer to move on a line
    char* j = p; // A pointer to move through the string to compare the code of a symbol with the current *p
    char* mx = NULL; // A pointer that stores the address of the most frequently encountered number
    int count; // Incremented to calculate the number of identical characters in a string (temporary)

    printf("Enter 20 elements (spaces and enters are considered): \n");
    for (i = 0; i < 20; i++) // score the other elements from zero to 18, the last element 19 is enter
        scanf("%c", &str[i]);

  
    while (*p != '\0') // While we haven't encountered a null byte yet (the *p pointer is incremented at the end, which allows us to leave the loop).
    {
        count = 0; // Zero the intermediate variable so that count is counted for each element
        j = str; // Assign the pointer j address to the first element of the array
        for (i = 0; i < sizeof(str); i++) // The loop from the first to the last element
        { // Here we compare the current symbol from the loop while with all in a string and count the following:
            if (((short)*p) == ((short)*j)) // If the code of the current item symbol in the loop WHILE is equal to the current item in the FOR loop
                count++; // Then we increase the intermediate counter
            if ((count >= max) && (((short)*p) > 47 && ((short)*p) < 58))
                // If the intermediate counter is greater than or equal to the most frequently stored digits, the current symbol code from 48 to 57 (ascii number codes) means this number
            {
                max = count;
                mx = p;
            } // Write intermediate variables into the most frequently stored digits
            j++; // Increment j at each iteration to move on an intermediate line                                                
        }
        *(p++); // Increment *p to move on the main line
    }



        if (max > 0) { // Checking to see if there are numbers in our line
            printf("The most common number = %c ", *mx); printf("meet %d times\n", max); // If we have the results, we'll print them out
        }
        else {
            printf("There are no numbers in the line.\n"); // If we don't say there are no numbers
        }

}


double program_6(double a[], int i)
{
    srand((unsigned)time(NULL)); // random number generator base (current time)
    for (i = 0; i < N; i++)
    {
        a[i] = rand() % 100 - 50; // generates random numbers from -50 to 49 in an array a[i]
        printf("%f\t", *(a + i));
    }
    printf("\n");

    for (i = 0; i < N; i++)
    {
        a[i] = a[i] * a[i]; // squared all the elements of the array
    }
    for (int i = 0; i < N; i++)
    {
        printf("%f\t", *(a + i));
    }
    return 0;
}


double program_8(double a[], int i)
{
    srand((unsigned)time(NULL)); // random number generator base (current time)
    for (i = 0; i < N; i++)
    {
        a[i] = rand() % 100 - 50; // generates random numbers from -50 to 49 in an array a[i]
        printf("%f\t", *(a + i));
    }
    printf("\n\n");
    {
        printf("a[0] = %f\n", *a);
        printf("a[2] = %f\n", *(a + 2));
        printf("a[4] = %f\n", *(a + 4));
    }
    return 0;
}


void show_menu() // Menu
{
	system("cls");
	printf("\n-------------------------\n");
	printf("\n1 - Write a program that creates an array of 10 integers from the [-50;50] segment that the user specifies from the console. Display the entire array and on a separate line - the value of the minimum element of the array. To bypass an array, use pointers (it is forbidden to refer to array elements by indexes)");
	printf("\n3 - Write a program which, for a line entered from the keyboard (maximum length of a line is 20 characters), tells which digit is most often found in it, or informs that there are no digits in the line at all. If there are several digits of the same frequency in a line, then as a leader print outany of the appropriate numbers. Use pointers to bypass strings");
	printf("\n6 - This is an array of 10 numbers of double type. Write a program that doubles...element values in an array. Solve the task via pointers");
	printf("\n8 - This is an array of 10 numbers of double type. Display the value of zero, the second and fourth elements of the array, using a pointer\n");
	printf("Print '0' then 'Enter' to show menu.\n");
}


int main()
{
    int  n, i = 0;
    double a[N];
	
    show_menu();
	
    do
    {
	printf("\nInput number of task:\n");
	printf("-------------------------\n");

	scanf_s("%d", &n);
	switch (n)
        {
	case 1: program_1();
            break;
	case 3: program_3();
            break;
	case 6: program_6(&a[N], i);
            break;
	case 8: program_8(&a[N], i);
            break;
	case 0:
        {
            show_menu();
            break;
        }
        default:
            printf("\nThere are no tasks under this number\n");
        }
    } while (n != -1);
    printf("\nThe end\n");
    return 0;
}