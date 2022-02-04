
#include "types.h"
#include "stat.h"
#include "x86.h"
#include "user.h"
#include "stddef.h"
#include "mmu.h"
#include "fs.h"
#include "param.h"
#include "fcntl.h"
#include "syscall.h"




lock_t lock;

int thread_create(void *(*fcn)(void*), void *arg){

  printf(1,"In the thread_create : Add counter function\n");
  int pid;
  void * newStack = malloc(4096);
  
  //Call system call clone
  pid = clone(newStack, 4096);
  if(pid == 0)
  {
    lock_acquire(&lock);
    (*fcn)(arg);
    free(newStack);
    lock_release(&lock);
    exit();
  }
  return pid;
}


int thread_join(void){
  return join();
}


void lock_init(lock_t * lock){
  xchg(&lock->flag, 0);//xchg is a function that can be user for atomic swap
}

void lock_acquire(lock_t * lock)
{
  while(xchg(&lock->flag, 1) == 1)
  {};
}

void lock_release(lock_t * lock)
{
  xchg(&lock->flag, 0);
}



