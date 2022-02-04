#include "threads.c"


//test 
#define numberOfProcesses 2
#define numberOfOuterLoops 3
#define numberOfInnerLoops 10

int counter;

void *addCounter(void* lock)
{
    int i = 0;
    for(i = 0;i<numberOfInnerLoops;i++)
    {
        lock_acquire(lock);
        counter++;
        lock_release(lock);
    }
    return NULL;
}

int main()
{
    counter = 0;

    if(numberOfProcesses>64)
    {
        return -1;
    }
    
    lock_t *lock = malloc(sizeof(lock_t));
    lock_init(lock);

    printf(1,"numberOfProcesses %d ,numberOfOuterLoops %d ,numberOfInnerLoops %d \n",numberOfProcesses,numberOfOuterLoops,numberOfInnerLoops);

    int i=0;
    for(i = 0;i< numberOfOuterLoops ; i++)
    {
        int j=0;
        for(j=0;j<numberOfProcesses;j++)
        {
            thread_create(addCounter,(void *)lock);
        }

        int z = 0;
        for( z =0 ;z<numberOfProcesses;z++)
        {
            thread_join();
        }
    }

    printf(1,"Counter: %d\n", counter);
    exit();
}