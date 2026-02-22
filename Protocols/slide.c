#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_FRAME 100

int window_size,total_frames;

void send_frames(int base,int end){
    int i;
    for(i=base;i<end;i++){
        printf("Sending frame %d\n");
        sleep(1);
    }
}


int main(){
    srand(time(0));
    printf("Enter the window size:");
    scanf("%d",&window_size);
    printf("Enter the total_frame:");
    scanf("%d",&total_frames);

    if(total_frames>MAX_FRAME||window_size>total_frames){
        printf("Invalid input.\n");
    }

    int base=0;
    while(base<total_frames){
        int end;
        if(base+window_size<total_frames){
            end=base+window_size;
        } else {
            end=total_frames;
        }

        send_frames(base,end);

        int ack=base+rand()%(window_size+1);

        if(ack>=end){
            
        }
    }
}
