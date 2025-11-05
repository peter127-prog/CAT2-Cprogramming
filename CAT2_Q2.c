/*
name:Peter thagana
Reg:CT100/G/26164/25
desc:A program to calculate the gross pay,taxes and your net pay per week
*/


#include <stdio.h>

int main() {
    float hours, rate, grosspay, tax, netpay;

    
    printf("Enter how may hours you worked in that week: ");
    scanf("%f", &hours);
    printf("Enter your  hourly wage: ");
    scanf("%f", &rate);

    
    if (hours <= 40)
        grosspay = hours * rate;
    else
        grosspay = (40 * rate) + ((hours - 40) * rate * 1.5);

   
    if (grosspay <= 600)
        tax = 0.15 * grosspay;
    else
        tax = (0.15 * 600) + (0.20 * (grosspay - 600));

    
    netpay = grosspay - tax;
    
    printf("\nGross Pay: ksh%.2f", grosspay);
    printf("\nTaxes: ksh%.2f", tax);
    printf("\nNet Pay: ksh%.2f\n", netpay);

    return 0;
	
}