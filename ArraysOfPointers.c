#include <stdio.h>
#include <stdlib.h>


//prototype
void printArray(size_t studentsInput, size_t examsInput,int grades[studentsInput][examsInput]);
void minimum(size_t studentsInput, size_t examsInput,int grades[studentsInput][examsInput]);
void maximum(size_t studentsInput, size_t examsInput,int grades[studentsInput][examsInput]);
void average(size_t studentsInput, size_t examsInput,int grades[studentsInput][examsInput]);

int main(void)
{
    int studentsInput;
    int examsInput;
    int userInput;
    int menuChoice;
    int testGrades;
    printf("Let's create a 2Dim array to input grades into!\n");
    printf("\n");
    printf("%s","\tHow many students would you like in the 2d array? ");
    scanf("%d",&studentsInput);
    printf("%s","\tHow many exams would you like in the 2d array? ");
    scanf("%d",&examsInput);
    printf("\n");
    int grades[studentsInput][examsInput];
    for (size_t students=0; students<studentsInput; ++students){
        for(size_t exams=0; exams<examsInput; ++exams ){
            printf( "\tEnter test grades: [%lu][%lu] ",students, exams);
            scanf("%d", &testGrades);
            grades[students][exams]=testGrades;
        }
    }
    void (*processGrades[4])(size_t, size_t, int grades[studentsInput][examsInput])={printArray, minimum, maximum, average};
    
    while(menuChoice!=4){
        printf("%s","\nEnter a choice:\n");
        printf("\t0 Print the array of grades\n");
        printf("\t1 Find the minumum grade\n");
        printf("\t2 Find the maximum grade\n");
        printf("\t3 Print the average on all tests for each student\n");
        printf("\t4 End Program\n");
        scanf("%d", &menuChoice);
        if (menuChoice==0){
            //print array of grades
            //printArray
            (*processGrades[menuChoice])(studentsInput, examsInput, grades);
        }
        if(menuChoice==1){
            //minimum
            (*processGrades[menuChoice])(studentsInput, examsInput, grades);
        }
        if(menuChoice==2){
            //maximum
            (*processGrades[menuChoice])(studentsInput, examsInput, grades);
        }
        if(menuChoice==3){
            //average
            (*processGrades[menuChoice])(studentsInput, examsInput, grades);
        }
        if(menuChoice==4){
            exit(0);
        }
    }
}
void printArray(size_t studentsInput, size_t examsInput,int grades[studentsInput][examsInput]){
    printf("\n");
    for (size_t students=0; students<studentsInput; ++students){
        printf("These are the exam grades for student %lu ", students);
        printf("[");
        for (size_t exams=0; exams<examsInput; ++exams){
            if(exams<examsInput-1){
                printf("%d,", grades[students][exams]);
            }
            else if(exams==examsInput-1){
                printf("%d", grades[students][exams]);
            }
        }
        printf("]\n");
    }
}
void minimum(size_t studentsInput, size_t examsInput,int grades[studentsInput][examsInput]){
    int Lowest=100;
    for (size_t students=0; students<studentsInput; ++students){
        for (size_t exams=0; exams<examsInput; ++exams){
            if( grades[students][exams]<Lowest){
                Lowest=grades[students][exams];
            }
        }
    }
    printf("The Lowest Score is: %d\n", Lowest);
}
void maximum(size_t studentsInput, size_t examsInput,int grades[studentsInput][examsInput]){
    int Highest=0;
    for (size_t students=0; students<studentsInput; ++students){
        for (size_t exams=0; exams<examsInput; ++exams){
            if(grades[students][exams]>Highest){
                Highest=grades[students][exams];
            }
        }
    }
    printf("Highest Score: %d\n", Highest);
    
}
void average(size_t studentsInput, size_t examsInput,int grades[studentsInput][examsInput]){
    double AverageStudent=0;
    for (size_t students=0; students<studentsInput; ++students){
        for (size_t exams=0; exams<examsInput; ++exams){
                AverageStudent+=grades[students][exams];
        }
            AverageStudent/=examsInput;
            printf("The Average for student %lu is: %.2lf\n", students, AverageStudent);
            AverageStudent=0;
        }

}