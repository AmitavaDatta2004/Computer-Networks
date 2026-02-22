#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_FRAME 100

int total_frames;
int window_size;

void sender(int base,int end){
    int i;
    for(i=base;i<end;i++){
        printf("Sending frame %d\n",i);
        sleep(1);
    }
}


int main(){
    printf("Enter the no of frames:");
    scanf("%d",&total_frames);

    printf("Enter the window size:");
    scanf("%d",&window_size);

    if(total_frames>MAX_FRAME || window_size>total_frames){
        printf("Invalid input!!\n");
        return 1;
    }

    srand(time(0));

    int base=0;

    while(base<total_frames){
        int end;
        if(base+window_size>=total_frames){
            end=total_frames;
        } else {
            end=base+window_size;
        }

        sender(base,end);

        int ack = base+rand()%(window_size+1);
        
        if(ack>=window_size){
            printf("Frames received from %d to %d\n",base,end);
            base=end;
        } else {
            printf("ACK lost at frame %d.\n");
            base=ack;
        }
    }
    printf("Al frames received");
}