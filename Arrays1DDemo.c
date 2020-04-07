#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 10
#define RAND_MIN 0
#define RAND_MAXX 20
//Benson LI Section 2 Assignment 4 Arrays1DDemo Assignnment
//prototype
void fillArray(int a[], int size);
void findwithRange(int a[], int size, int low, int high);
void reverseArray(int a[], int size);
void reverseArrayRange(int a[], int size, int low, int high);
int findSequence(int a[], int size);

int main(void) {
    int low; 
    int high;
    printf("hello");
    printf("%s","This is for the functions findwithRange and reverseArrayRange. Enter value for low (starting index to look at):");
    scanf("%d", &low);
    printf("%s","This is for the functions findwithRange and reverseArrayRange. Enter value for high (index to stop looking at):");
    scanf("%d", &high);
    int a[SIZE]; // ARRAY OF SIZE "Constant SIZE" INDICES 0-9
    fillArray(a,SIZE);
    findwithRange(a,SIZE,low,high);
    reverseArray(a, SIZE);
    reverseArrayRange(a,SIZE,low,high);
    findSequence(a,SIZE);
}


void fillArray(int a[], int size){
    puts("------------------------------------------------------------------------------------------------------------------------");
    puts("This is the fillArray Program:");
    srand((unsigned)time(NULL));
    printf("{");
    for (size_t i=0 ; i< SIZE; ++i){
        a[i]= rand() % (RAND_MAXX+1)+ RAND_MIN;
        if(i<SIZE-1){
            printf("%d,",a[i]);
        }
        else if(i==SIZE-1){
        printf("%d",a[i]);
        }
    }
    printf("}\n");
}

void findwithRange(int a[], int size, int low, int high){
    puts("------------------------------------------------------------------------------------------------------------------------");
    puts("This is the findwithRange Program:");
    if (high<low){
        puts("please don't input a value of 'high' that is less than 'low'");
    }
    else if(high==size){
        puts("don't have high=size or else this will result in an index out of bounds exception");
    }
    else{
    int max=a[low];
    for (size_t i=low; i<=high; i++){
        if (a[i]>max){
            max=a[i];
        }
    }
    printf("The maximum value in the range is: %d\n", max);
}
}
void reverseArray(int a[], int size){
    puts("------------------------------------------------------------------------------------------------------------------------");
    puts("This is the reverseArray Program:");
    int b[size];
    printf("{");
    //create a temporary array "b" in which to store the reverse values of a
    for (size_t i=0; i<size;++i){
        b[i]=a[size-1-i];
    }
    //use this to print the values of b out
    for (size_t j=0; j<size;++j ){
        if(j<size-1){
        printf("%d,",b[j]);
        }
        else if (j==size-1){
            printf("%d",b[j]);
        }
    }
    printf("}\n");
}
void reverseArrayRange(int a[], int size, int low, int high){
    puts("------------------------------------------------------------------------------------------------------------------------");
    puts("This is the reverseArrayRange Program:");
    if (high<low){
        puts("please don't input a value of 'high' that is less than 'low'");
    }
    else if (high==size){
        puts("don't have high=size or else this will result in an index out of bounds exception");
    }
    else{
    printf("{");
    int b[size];
    //stores values of a into b from  0 to low
    for (size_t i=0; i<low; ++i){
        b[i]=a[i];
    }
    //reverse array values in a certain range from low to high
    for (size_t j=low; j<=high; ++j){
        b[j]=a[high-j+low];
    }
    //stores values of a into b from high+1 to size
    for (size_t k=high+1;k<size;++k){
        b[k]=a[k];
    }
    //prints out the new array
    for (size_t k=0; k<size; ++k){
        printf("%d,",b[k]);
    }
   
    printf("}\n");
}
}

int findSequence(int a[], int size){
    int number1;
    int number2;
    int index=-1;
    int numbertofind;
    puts("------------------------------------------------------------------------------------------------------------------------");
    puts("This is the findSequence PROGRAM");
    printf("%s", "Enter First Integer:");
    scanf("%d",&number1);
    printf("%s", "Enter Second Integer:");
    scanf("%d",&number2);
    for (size_t i=0; i<SIZE; ++i){
        if ( ( (a[i]==number1 && a[i+1]==number2) && a[i]==number1) ){
            index=i;
            break;
        }
    } 
    if (index==-1){
        printf("Sequence not found :(, so I'll return a %d instead\n", index);
    }
    else {
    printf("sequence located at index:%d \n",index); 
    }
    
    return index;
}