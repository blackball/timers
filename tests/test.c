#include "../timer.h"
#include <unistd.h>
#include <stdio.h>

int
main(int argc, char *argv[]) {
    struct timer t;
    timer_start(&t);
    sleep(1);    
    timer_stop(&t);
    printf("should be ~1000: %lf\n", timer_duration_ms(&t));
    return 0;
}
