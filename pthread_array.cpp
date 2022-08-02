#include "pthread_array.h"

pthread_array::pthread_array(int size):_size{size},_array{new int [size]},_thread_number{nullptr},_thread_count{0},_sum_array{0}
{
    for (size_t i = 0; i < _size; ++i)
    {
       _array[i]=0;
    }
}
void pthread_array::set_thread_count(int count)
{
    this->_thread_count=count;
    this->_thread_number=new int*[count];
}
int pthread_array:: get_thread_count()
{
    return this->_thread_count;
}
int pthread_array::get_size()
{
    return this->_size;
}
void pthread_array::start_treading(void* (*function)(void*))
{
    pthread_t *threads=new pthread_t [this->_thread_count];


    for (size_t i = 0; i < this->_thread_count; ++i)
    {
        this->_thread_number[i]=new int (i);
        this->index=i;
        pthread_create(&threads[i],NULL,function,(void*)this);

    }

    for (size_t i = 0; i < this->_thread_count; ++i)
    {
        pthread_join(threads[i],NULL);
    }
    delete[] threads;
   
}
void pthread_array::set_value(int value)
{
    for (size_t i = 0; i < this->_size; i++)
    {
        this->_array[i]=value;
    }
    
}
void pthread_array::set_random_value()
{
    srand(time(NULL));
    for (size_t i = 0; i < this->_size; ++i)
    {
        this->_array[i]=1+rand()%10;
    }
    
}
void pthread_array::print_array()
{
    for (size_t i = 0; i < this->_size; ++i)
    {
        std::cout<<this->_array[i]<<std::endl;
    }
    
}
pthread_array::~pthread_array()
{
    delete[] this->_array;
    for (size_t i = 0; i < this->_thread_count; ++i)
    {
        delete[] this->_thread_number[i];
    }
    
    delete[] this->_thread_number;
}