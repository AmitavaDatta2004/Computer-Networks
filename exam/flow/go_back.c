#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(){
    int n,i=0,j,error,window,errorframe;
    printf("Enter the no of frames to transmit:");
    scanf("%d",&n);
    printf("Enter the window size:");
    scanf("%d",&window);

    srand(time(NULL));
    while(i<=n){
        printf("Sending frames ");
        for(j=i;j<i+window && j<n;j++){
            printf("%d ",j+1);
        }

        error=rand()%2;
        printf("Waiting for ACK\n");
        sleep(1);
        
        if(error==1){
            printf("ACK received for all frames\n");
            i=i+window;
        } else {
            errorframe=rand()%window+i;
            
            if (errorframe>n){
                errorframe=n;
            }

            printf("Timeout\n");
            printf("Frame lost at %d\n",errorframe);
            i=errorframe;
        }        
    }
    printf("All frames sent successfully\n");
    return 0;
}