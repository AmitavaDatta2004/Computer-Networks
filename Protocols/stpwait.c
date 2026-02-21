#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define IDLE 0
#define WAIT 1
#define TIMEOUT 3

int simulate_error() {
    return rand() % 2;   // 0 = success, 1 = error
}

int main() {
    int state = IDLE;
    int seq_num = 0;
    int frame = 0;
    int total_frames = 5;

    srand(time(NULL));

    while (frame < total_frames) {

        /* IDLE STATE */
        if (state == IDLE) {
            if (simulate_error()) {
                printf("Frame lost: Data %d, Seq %d\n", frame, seq_num);
            } else {
                printf("Frame sent successfully: Data %d, Seq %d\n",
                       frame, seq_num);
            }
            state = WAIT;
        }

        /* WAIT STATE */
        if (state == WAIT) {
            sleep(TIMEOUT);

            if (simulate_error()) {
                printf("ACK lost: Resending frame %d\n", frame);
                state = IDLE;
            } else {
                printf("ACK received: Data %d, Seq %d\n",
                       frame, seq_num);
                seq_num = 1 - seq_num;   // toggle seq
                frame++;                 // next data
                state = IDLE;
            }
        }
    }

    printf("\nAll frames transmitted successfully.\n");
    return 0;
}