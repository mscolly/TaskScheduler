#ifndef TaskScheduler_h
#define TaskScheduler_h

#include "Arduino.h"

typedef struct {
    unsigned long when;
    void (*func)();
} Task;

class TaskScheduler {

    public:
        TaskScheduler(int size);
        void schedule(unsigned long when, void (*func)());
        void scan();
        void clear();
    private:
        int _list_size;
        Task *_task_list;
};

#endif
