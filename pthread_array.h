#include <iostream>
#include <time.h>
#include <cstdlib>
#include <pthread.h>

struct pthread_array
{
    pthread_array(int size);
    ~pthread_array();
    void set_random_value();
    void set_value(int value);
    void print_array();
    void set_thread_count(int count);
    int get_thread_count();
    int get_size();
    void start_treading(void* (*function)(void*));
    int *_array;
    int **_thread_number;
    int _sum_array;
    int index;
private:
    
    int _thread_count;
    int _size;
};
