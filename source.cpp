#include <iostream>
#include <string>
#include <unistd.h>
#include "pthread_array.h"




void* func(void *_struct)
{
   int size_array=((pthread_array*)_struct)->get_size();
   int count_thread=((pthread_array*)_struct)->get_thread_count();
   int number_thread=(*((pthread_array*)_struct)->_thread_number[((pthread_array*)_struct)->index]);
   int begin=(size_array/count_thread)*number_thread;
   int end=(size_array/count_thread)*(number_thread+1);
   for (int i = begin; i < end; ++i)
   {
      ((pthread_array*)_struct)->_sum_array+= ((pthread_array*)_struct)->_array[i];
   }
  
   
   return 0;
}

int main()
{
  pthread_array temp_arr(100000);
  temp_arr.set_value(1);
  temp_arr.set_thread_count(100);
  temp_arr.start_treading(&func);
  temp_arr.print_array();
  std::cout<<"SUM= "<<temp_arr._sum_array<<std::endl;
  return 0;
}