#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc,char * argv[])
{
    //i will send the array of proc_info to the function
    //this fetchProcessesInfo will fill the array with the running or runnable processes
    //and also return the number of processes that they are running or runnable 
    //so we have the array and the number of processes
    struct proc_info processes[64];
    //proc_dump(processes);
    int pid = fork();
    if(pid>0)
    {
        // parent here...
        malloc(400000);
        proc_dump(processes);
        exit();
    }
    else{
        malloc(100000);
        fork();
        wait();
    }
    exit();
}


