#include<stdio.h>

int main(){
    int n,i,sent_parity,received_parity;
    printf("Enter the no of bits sent:");
    scanf("%d",&n);

    int sent[n];
    int received[n];

    printf("Enter the data to be sent -->\n");
    int ones=0;
    for(i=0;i<n;i++){
        printf("Enter the data of %d bit :",i);
        scanf("%d",&sent[i]);
        if(sent[i]==1){
            ones++;
        }
    }

    if(ones%2==0){
        sent_parity=1;
    } else {
        sent_parity=0;
    }
    ones=0;
    printf("Enter the data received (bits separated by a space):");
    for(i=0;i<n;i++){
        scanf("%d",&received[i]);
        if(received[i]==1){
            ones++;
        }
    }

    if(ones%2==0){
        received_parity=1;
    } else {
        received_parity=0;
    }


    if (received_parity==sent_parity){
        printf("No error");
    } else {
        printf("Error detected");
    }

}