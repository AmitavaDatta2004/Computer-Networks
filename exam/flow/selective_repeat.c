#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(){
    int n,window,i=0,j,error,errorframe;

    printf("Enter the number of frames to be sent:");
    scanf("%d",&n);

    printf("Entere the window size:");
    scanf("%d",&window);

    srand(time(NULL));

    while(i<n){
        printf("Frames sent --> ");
        for(j=i;j<i+window&&j<n;j++){
            printf("%d ",j);
        }
        printf("\nWaiting for ACK\n");
        sleep(1);

        error=rand()%2;

        if(error==1){
            printf("ACK received for all frames\n");
            
        } else {
            errorframe=rand()%window+i;

            if (errorframe>n){
                errorframe=n;
            }
            printf("ACK lost at frame %d\n",errorframe);

            printf("Retransmitting frame %d\n",errorframe);
            sleep(1);
            while(1){
                int reerror=rand()%2;
                if(reerror==1){
                    printf("ACK received for frame %d\n",errorframe);
                    break;
                } else {
                    printf("ACK lost...\n");
                    printf("Retransmitting frame %d\n",errorframe);
                }
            }
        }
        i=i+window;
    }
    printf("All frames sent successfully\n");
    return 0;
}