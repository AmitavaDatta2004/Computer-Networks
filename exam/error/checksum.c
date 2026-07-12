#include <stdio.h>

int binaryToDecimal(int arr[], int n)
{
    int i, decimal = 0;

    for(i = 0; i < n; i++)
        decimal = decimal * 2 + arr[i];

    return decimal;
}

void decimalToBinary(int num)
{
    int binary[20], i = 0, j;

    if(num == 0)
    {
        printf("0");
        return;
    }

    while(num > 0)
    {
        binary[i++] = num % 2;
        num /= 2;
    }

    for(j = i - 1; j >= 0; j--)
        printf("%d", binary[j]);
}

int main()
{
    int n, i;
    int a[20], b[20];
    int ra[20], rb[20];
    int senderSum, receiverSum;

    printf("Enter number of bits: ");
    scanf("%d", &n);

    // Sender
    printf("Enter First Binary Number:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter Second Binary Number:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &b[i]);

    senderSum = binaryToDecimal(a, n) + binaryToDecimal(b, n);

    printf("\nSender Sum = %d", senderSum);

    printf("\nChecksum (Binary) = ");
    decimalToBinary(senderSum);

    // Receiver
    printf("\n\n----- Receiver -----\n");

    printf("Enter Received First Binary Number:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &ra[i]);

    printf("Enter Received Second Binary Number:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &rb[i]);

    receiverSum = binaryToDecimal(ra, n) + binaryToDecimal(rb, n);

    printf("\nReceiver Sum = %d\n", receiverSum);

    if(senderSum == receiverSum)
        printf("No Error Detected.\n");
    else
        printf("Error Detected.\n");

    return 0;
}