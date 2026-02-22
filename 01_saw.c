#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define TIMEOUT 3
#define IDLE 0
#define WAIT_FOR_ACK 1

int simulate_error(){
    return rand()%2;
}

int main(){
    int total_frames;
    int frame=0;
    int seq=0;
    int state=IDLE;

    printf("Enter no of frames to transmit:");
    scanf("%d",&total_frames);

    srand(time(NULL));
    while(frame<total_frames){
        if(state==IDLE){
            if(simulate_error()){
                printf("Frame %d sent successfully (seq=%d)\n",frame,seq);
                sleep(1);
                state=WAIT_FOR_ACK;
            } else {
                printf("Frame %d lost. Resending frame %d (seq=%d)\n\n",frame,frame,seq);
            }
        }

        if(state==WAIT_FOR_ACK){
            if(simulate_error()){
                printf("ACK received for frame %d (seq=%d)\n",frame,seq);
                frame++;
                seq=1-seq;
            } else {
                printf("Waiting for ACK of frame %d (seq=%d)\n",frame,seq);
                sleep(TIMEOUT);
                printf("ACK lost for frame %d. resending frame %d (seq=%d)\n\n",frame,frame,seq);
            }
            state=IDLE;
        }
    }
    printf("All frames transmitted successfully...\n");
}