#include "../timer.hpp"
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
    Timer timer;
    timer.start();
    sleep(1);
    timer.stop();
    printf("should be ~1000: %f!\n", timer.get_duration_ms());
    return 0;
}
