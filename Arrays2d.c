
#include <stdio.h>
//prototypes

void rowSum(size_t rowInput, size_t columnInput, int a[rowInput][columnInput]);
void Maximum (size_t rowInput, size_t columnInput,int a[rowInput][columnInput]);
void columnSum(size_t rowInput, size_t columnInput, int a[rowInput][columnInput]);
void isSquare(size_t rowInput, size_t columnInput, int a[rowInput][columnInput]);
void displayOutputs(size_t rowInput, size_t columnInput, int a[rowInput][columnInput]);

int main(void){
    int rowInput;
    int columnInput;
    int userInput;
    printf("Let's create a 2Dim array!\n");
    printf("\n");
    printf("%s","\tHow many rows? ");
    scanf("%d",&rowInput);
    printf("%s","\tHow many columns? ");
    scanf("%d",&columnInput);
    printf("\n");
    int a[rowInput][columnInput];
    for (size_t row=0; row<rowInput; ++row){
        for(size_t column=0; column<columnInput; ++column ){
            printf( "\tenter [%lu][%lu]: ",row, column);
            scanf("%d", &userInput);
            a[row][column]=userInput;
        }
    }
    // for (size_t row=0; row<rowInput; ++row){
    //     for(size_t column=0; column<columnInput; ++column ){
    //         printf( "a[%lu][%lu]=%d\n", row, column, a[row][column]);
    //     }
    // }
    printf("\n");
    rowSum( rowInput, columnInput,  a);
    printf("\n");
    Maximum(rowInput,columnInput,a);
    printf("\n");
    columnSum(rowInput, columnInput, a);
    printf("\n");
    isSquare(rowInput, columnInput, a);
    printf("\n");
    displayOutputs(rowInput, columnInput, a);
    printf("\n");
}
void Maximum (size_t rowInput, size_t columnInput,int a[rowInput][columnInput]){
    int max=a[0][0];
    for (size_t row=0; row<rowInput; ++row){
        for(size_t column=0; column<columnInput;++column){
            if(max<a[row][column]){
                max=a[row][column];
            }
        }
    }
    printf("The maximum value in the array is: %d \n", max );
}
void rowSum(size_t rowInput, size_t columnInput, int a[rowInput][columnInput]){
    int rowSum=0;
    for (size_t row=0; row<rowInput; ++row){
        for (size_t column=0; column<columnInput; ++column){
            rowSum+=a[row][column];
        }
        printf("Sum of row %lu = %d\n", row+1, rowSum );
        rowSum=0;
    }
}
void columnSum(size_t rowInput, size_t columnInput, int a[rowInput][columnInput]){
    int columnSum=0;
    int columnCount=1;
    for (size_t column=0; column<columnInput; ++column){
        for (size_t row=0; row<rowInput; ++row){
            columnSum+=a[row][column];
        }
        printf("Sum of column %d = %d\n", columnCount++, columnSum);
        columnSum=0;
}
}
void isSquare(size_t rowInput, size_t columnInput, int a[rowInput][columnInput]){
    if (rowInput==columnInput){
        printf("This is a square array.");
    }
    else{
        printf("This is not a square array.");
    }
}
void displayOutputs(size_t rowInput, size_t columnInput, int a[rowInput][columnInput]){
    printf("\n");
    printf("Here is your 2Dim array:\n");
    for (size_t row=0; row<rowInput; ++row){
        printf("[");
        for (size_t column=0; column<columnInput; ++column){
            if(column<columnInput-1){
                printf("%d,", a[row][column]);
            }
            else if(column==columnInput-1){
                printf("%d", a[row][column]);
            }
        }
        printf("]\n");
}
}