#include "../timer.h"
#include <stdio.h>

#ifdef _WIN32
  #include <windows.h>
  #define SLEEP(n) Sleep(n * 1000)
#else
  #include <unistd.h>
  #define SLEEP(n) sleep(n)
#endif 

int
main(int argc, char *argv[]) {
    struct timer t;
    timer_start(&t);
    SLEEP(1);    
    timer_stop(&t);
    printf("should be ~1000: %lf\n", timer_duration_ms(&t));
    return 0;
}
