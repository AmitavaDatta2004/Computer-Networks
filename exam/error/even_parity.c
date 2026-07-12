#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    int i,n,parity;
    printf("Enter the length of the data:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the data to send: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int ones=0;
    for(i=0;i<n;i++){
        if(arr[i]==1){
            ones++;
        }
    }

    if(ones%2==0){
        parity=0;
    } else {
        parity=1;
    }

    printf("The transmitted data is : ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("%d\n",parity);


    int receive[n+1];
    printf("Enter the received data: ");
    for(i=0;i<n+1;i++){
        scanf("%d",&receive[i]);
    }

    int rec_ones=0;
    for(i=0;i<n+1;i++){
        if(receive[i]==1){
            rec_ones++;
        }
    }

    int rev_parity;
    
    if(rec_ones%2==0){
        printf("No error\n");
    } else {
        printf("Error detected\n");
    }
}