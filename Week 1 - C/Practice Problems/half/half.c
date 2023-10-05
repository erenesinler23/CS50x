// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

float calculateTotal(float bill, float tax, int tip);
float splitBill(float totalAmount);

int main(void)
{
    float billAmount, taxPercent;
    int tipPercent;

    printf("Enter the bill amount before tax and tip: $");
    scanf("%f", &billAmount);

    printf("Enter the sales tax percent: ");
    scanf("%f", &taxPercent);

    printf("Enter the tip percent: ");
    scanf("%d", &tipPercent);

    float totalAmount = calculateTotal(billAmount, taxPercent, tipPercent);
    float eachOwes = splitBill(totalAmount);

    printf("Each person owes: $%.2f\n", eachOwes);

    return 0;
}

// Calculate the total bill including tax and tip
float calculateTotal(float bill, float tax, int tip)
{
    // Convert tax from percent to decimal
    float taxDecimal = tax / 100.0;

    // Convert tip from percent to decimal
    float tipDecimal = tip / 100.0;

    // Calculate the total bill with tax and tip
    float total = bill + (bill * taxDecimal) + (bill * tipDecimal);

    return total;
}

// Split the bill equally among two people
float splitBill(float totalAmount)
{
    return totalAmount / 2.0;
}
