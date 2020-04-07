#include <stdio.h>
#include <stdlib.h>

// Benson Li CIS 2107 Section 2 
//2-2-2020 LAB 2 REVENUE
//Goal: To display the Revenue based on unit and quantity price, while taking discounts into account

int main(void)
{
    double Price;
    double Quantity;
    double Discount;
    double DiscAmount;
    double Cost;
    double Total;
    
    printf("Welcome to \"Temple\" Store\n\n");
    printf("%s", "\tEnter item price: ");
    scanf("%lf",&Price);
    if (Price==0 || Price<0){
        printf("\n\tThis is not a valid item price.");
        printf("\n\tPlease run the program again\n\n");
        printf("\nThank You for using \"Temple\" store\n\n");
        exit(0);
    }
    printf("%s", "\tEnter quantity: ");
    scanf("%lf",&Quantity);
    if (Quantity==0 || Quantity<0){
        printf("\n\tThis is not a valid quantity order.");
        printf("\n\tPlease run the program again\n\n");
        printf("\nThank You for using \"Temple\" store\n\n");
        exit(0);
    }
    
    Cost=Price*Quantity;
    if (Quantity>0 && Quantity<50){
        Discount=0;
    }
    else if (Quantity>=50 && Quantity<100){
        Discount=10;
    }
    else if (Quantity>=100 && Quantity<150){
        Discount=15;
    }
    else if (Quantity>=150){
        Discount=25;
    }
    DiscAmount= (Discount/100)*Cost;
    Total=Cost- DiscAmount;
    printf("\n\tThe item price is: $%.1lf\n", Price);
    printf("\tThe order is: %.0lf item(s)\n", Quantity);
    printf("\tThe cost is: $%.1lf\n", Cost);
    printf("\tThe discount is: %.1lf%%\n", Discount);
    printf("\tThe discount amount is: $%.1lf\n", DiscAmount);
    printf("\tThe total is: $%.1lf\n", Total );
    
    printf("\nThank You for using \"Temple\" store\n\n");
}