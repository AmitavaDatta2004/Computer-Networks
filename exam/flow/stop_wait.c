#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(){
    int n,i,error;
    printf("Enter the number of frames to be sent:");
    scanf("%d",&n);

    srand(time(NULL));

    for(i=0;i<n;i++){
        while(1){
            printf("Sending frame %d\n",i+1);
            printf("Waiting for acknowledgement...\n");
            sleep(1);
            error=rand()%2;
            if(error==1){
                printf("ACK %d received successfully\n",i+1);
                printf("Sending next frame\n");
                break;
            } else {
                printf("ACK lost\n");
                printf("Resending frame %d\n",i+1);
            }
        }
    }
    printf("All frames sent successfully.\n");
    return 0;
}