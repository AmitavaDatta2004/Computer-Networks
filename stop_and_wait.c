#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define TIMEOUT 3
#define IDLE 0
#define WAIT_ACK 1

int error_simulate(){
    return rand()%2;
}

int main(){
    srand(time(NULL));

    int frame=0;
    int seq=0;
    int total_frame;
    printf("Enter no of frame to transmit:");
    scanf("%d",&total_frame);
    int state=IDLE;

    while(frame<total_frame){
            
        if(state==IDLE){
            if(error_simulate()){
                printf("Sending frame %d (seq+%d)\n",frame,seq);
                state=WAIT_ACK;
            } else {
                printf("Frame %d lost (seq=%d)\nResending frame %d\n",frame,seq,frame);
                sleep(1);
            }
        }

        if(state==WAIT_ACK){
            if(error_simulate()){
                printf("ACK received for frame %d (seq=%d)\n",frame,seq);
                frame++;
                seq=1-seq;
            } else {
                printf("Waiting for ACK for frame %d (seq=%d)\n",frame,seq);
                sleep(TIMEOUT);
                printf("ACK lost for frame %d (seq=%d)\nResending frame %d\n",frame,seq);

            }
            state=IDLE;
        }
    }

    printf("All frames transmitted successfuly.\n");
}