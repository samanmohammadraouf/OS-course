struct stat;
struct rtcdate;

// system calls
int fork(void);
int exit(void) __attribute__((noreturn));
int wait(void);
int pipe(int*);
int write(int, const void*, int);
int read(int, void*, int);
int close(int);
int kill(int);
int exec(char*, char**);
int open(const char*, int);
int mknod(const char*, short, short);
int unlink(const char*);
int fstat(int fd, struct stat*);
int link(const char*, const char*);
int mkdir(const char*);
int chdir(const char*);
int dup(int);
int getpid(void);
char* sbrk(int);
int sleep(int);
int uptime(void);

int clone(void *,int);
int join(void);


// ulib.c
int stat(const char*, struct stat*);
char* strcpy(char*, const char*);
void *memmove(void*, const void*, int);
char* strchr(const char*, char c);
int strcmp(const char*, const char*);
void printf(int, const char*, ...);
char* gets(char*, int max);
uint strlen(const char*);
void* memset(void*, int, uint);
void* malloc(uint);
void free(void*);
int atoi(const char*);




//Lets define our lock right here,
typedef struct __lock_t {
   volatile uint flag;
} lock_t;

struct user_thread {
    int pid;
    int used;
    void * ustack;
};


//Lets add the thread library here so the user an access them
int thread_create(void*(*fcn)(void*),void *arg);
int thread_join(void);

//Now the locks
void lock_acquire(struct __lock_t *);
void lock_release(struct __lock_t *);
void lock_init(struct __lock_t *);
