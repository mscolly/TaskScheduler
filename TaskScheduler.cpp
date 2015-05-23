#include "Arduino.h"
#include "TaskScheduler.h"

TaskScheduler::TaskScheduler(int size) {
    _list_size = size;
    _task_list = new Task[size];
    TaskScheduler::clear();
}

void TaskScheduler::schedule(unsigned long when, void (*func)()) {
    for (int i = 0; i < _list_size; i++) {
        if ( _task_list[i].when == 0 ) {
            _task_list[i].when = when + millis();
            _task_list[i].func = func;
            break;
        }
    }
}

void TaskScheduler::scan() {
    for (int i = 0; i < _list_size; i++) {
        if ( _task_list[i].when ) {
            if ( _task_list[i].when <= millis() ) {
                _task_list[i].func();
                _task_list[i].when = 0;
            }
        }
    }
}

void TaskScheduler::clear() {
    for (int i = 0; i < _list_size; i++) {
        _task_list[i].when = 0;
    }
}
