#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define TIMEOUT 5
#define MAX_FRAMES 100

int total_frame;
int window_size;

void sender(int base,int end){
    int i;
    for(i=base;i<end;i++){
        printf("Sending frame %d\n",i);
        sleep(1);
    }
}


int main(){
    int frame;

    printf("Enter the no of frame to transmit:");
    scanf("%d",&total_frame);

    printf("Enter the window size:");
    scanf("%d",&window_size);

    srand(time(NULL));

    if(total_frame>MAX_FRAMES || total_frame<window_size){
        printf("Invalid input\n");
        return 1;
    }

    int base=0;
    while(base<total_frame){
        int end;
        if(base+window_size<total_frame){
            end=base+window_size;
        } else{
            end=total_frame;
        }

        sender(base,end);

        int ack=base+rand()%(window_size+1);

        if(ack>=end){
            printf("ACK received for frames %d to %d\n",base,end);
            base=end;
        } else {
            printf("ACK lost at frame %d\n",ack);
            base=ack;
        }
    }
    printf("All frames received.\n");
    return 0;
}