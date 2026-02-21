#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define TIMEOUT 3

int receiver(int frame , int seq){
    int received = rand()%2;

    if (received==1){
        printf("Receiver: Frame %d received (seq=%d)\n",frame,seq);
        printf("Receiver: Sending ACK\n");
        return 1;
    } else {
        printf("Receiver: Frame %d lost (seq=%d)",frame,seq);
        return 0;
    }
}

void sender(int total_frames){
    int frame=0;
    int seq=0;
    int ack;

    while(frame<total_frames){
        printf("Sender: Sending frame %d with seq=%d\n",frame,seq);
        sleep(1);

        ack=receiver(frame,seq);

        if(ack==1){
            printf("Sender: ACK %d received\n",seq);
            frame++;
            seq=1-seq;
        } else {
            printf("Sender: Waiting for ACK %d\n",seq);
            sleep(TIMEOUT);
            printf("Sender: Timeout! Retransmitting frame %d (seq=%d)\n",frame,seq);

        }
    }
    printf("Sender: All frames received successfully\n");
}


int main(){
    int total_frames;
    printf("Enter the no of frames:");
    scanf("%d",&total_frames);

    srand(time(NULL));
    sender(total_frames);
    return 0;
}