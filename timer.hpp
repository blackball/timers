#ifndef CPP_TIMER_H
#define CPP_TIMER_H

#include <chrono>

class Timer {
    std::chrono::high_resolution_clock::time_point _start, _stop;    
public:
    inline void start() {_start = std::chrono::high_resolution_clock::now();}
    inline void stop() {_stop = std::chrono::high_resolution_clock::now();}
    inline float get_duration_ms() const {
        return std::chrono::duration_cast<std::chrono::milliseconds>(_stop - _start).count();
    }
};

#endif /* CPP_TIMER_H */
