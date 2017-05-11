#ifndef C_TIMER_H
#define C_TIMER_H

#ifdef _WIN32

#define NOMINMAX
#define WINDOWS_LEAN_AND_MEAN
#include <windows.h>

struct timer {
    LARGE_INTEGER start, stop;
};

static void
timer_start(struct timer *t) {
    QueryPerformanceCounter(&(t->start));
}

static void
timer_stop(struct timer *t) {
    QueryPerformanceCounter(&(t->stop));
}

static float
timer_duration_ms(const struct timer *t) {
    LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency);
    return (float)(stop.QuadPart - start.QuadPart) / frequency.QuadPart;
}

#else

#include <sys/time.h>

struct timer {
    struct timeval start, stop;
};

static void
timer_start(struct timer *t) {
    gettimeofday(&(t->start), 0);
}

static void
timer_stop(struct timer *t) {
    gettimeofday(&(t->stop), 0);
}

static float
timer_duration_ms(const struct timer *t) {
    const long micros_used= (((t->stop.tv_sec - t->start.tv_sec)*1000000) + t->stop.tv_usec) - (t->start.tv_usec);
    return (float)micros_used / 1000.f;
}

#endif 


#endif /* C_TIMER_H */
