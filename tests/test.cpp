#include "../timer.hpp"
#include <stdio.h>
#include <unistd.h>

int
main(int argc, char *argv[]) {
    Timer timer;
    timer.start();
    sleep(1);
    timer.stop();
    printf("should be ~1000: %f!\n", timer.get_duration_ms());
    return 0;
}
