#include <stdio.h>
#include <stdlib.h>

// Benson Li  CIS 2107 Section 2 
//2-2-2020 LAB 2 PAYCHECK
//Goal: TO calculate the pay of a temple employee
int main(void)
{
     double EMPLOYEEID;
     double HOURLYPAY;
     double WEEKLY;
     double NUMBER;
     double OVERTIME;
     double REGPAY;
     double OVERTIMEPAY;
     double NETPAY;
    
    printf("Welcome to \"TEMPLE HUMAN RESOURCES\"\n\n");
    printf("%s", "\tEnter Employee Number: ");
    scanf("%lf",&EMPLOYEEID);
    if (EMPLOYEEID==0 || EMPLOYEEID<0){
        printf("\n\tThis is not a valid Employee Number.");
        printf("\n\tPlease run the program again\n\n");
        printf("Thank you for using \"TEMPLE HUMAN RESOURCES\"\n\n");
        exit(0);
    }
    printf("%s", "\tEnter Hourly Salary: ");
    scanf("%lf",&HOURLYPAY);
    if (HOURLYPAY==0 || HOURLYPAY<0){
        printf("\n\tThis is not a valid hourly salary amount.");
        printf("\n\tPlease run the program again\n\n");
        printf("Thank you for using \"TEMPLE HUMAN RESOURCES\"\n\n");
        exit(0);
    }
    printf("%s", "\tEnter Weekly Time: ");
    scanf("%lf",&WEEKLY);
    if (WEEKLY==0 || WEEKLY<0){
        printf("\n\tThis is not a weekly time.");
        printf("\n\tPlease run the program again\n\n");
        printf("Thank you for using \"TEMPLE HUMAN RESOURCES\"\n\n");
        exit(0);
    }
    if (WEEKLY<=40){
        OVERTIME=0;
        REGPAY=HOURLYPAY*WEEKLY;
        OVERTIMEPAY=0;
    }
    else if(WEEKLY>40){
        OVERTIME=(WEEKLY-40);
        REGPAY=(40*HOURLYPAY);
        OVERTIMEPAY=1.5*OVERTIME*HOURLYPAY;
    }
    NETPAY=REGPAY+OVERTIMEPAY;
    printf("==============================\n");
    printf("\tEmployee #: %.0lf \n",EMPLOYEEID);
    printf("\tHourly Salary: $%.1lf \n", HOURLYPAY);
    printf("\tWeekly Time: %.1lf\n", WEEKLY);
    printf("\tRegular Pay: $%.1lf \n", REGPAY);
    printf("\tOvertime Pay: $%.1lf \n", OVERTIMEPAY );
    printf("\tNet Pay: $%.1lf \n", NETPAY );
    printf("==============================\n");

   


    printf("Thank you for using \"TEMPLE HUMAN RESOURCES\"\n\n");

}