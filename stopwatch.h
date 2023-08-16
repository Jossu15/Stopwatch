//
// Created by Lenovo on 16/08/2023.
//

#ifndef JOS_CVB_STOPWATCH_H
#define JOS_CVB_STOPWATCH_H

#include <ctime>


class Stopwatch {
    clock_t start_time;
    bool running;
    double elapsed_time;
public:
    Stopwatch();
    void start();
    void stop();
    void reset();
    [[nodiscard]] double elapsed() const;
    [[nodiscard]] bool is_running() const;
};

#endif //JOS_CVB_STOPWATCH_H
