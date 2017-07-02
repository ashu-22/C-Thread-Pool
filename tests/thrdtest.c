   #include <stdio.h>
   #include <pthread.h>
   #include <unistd.h>
 + #include <assert.h>
  
   #include "threadpool.h"
  
   int tasks = 0, done = 0;
   pthread_mutex_t lock;
  
   void dummy_task(void *arg) {
 -    usleep(1000);
 +    usleep(10000);
      pthread_mutex_lock(&lock);
      done++;
      pthread_mutex_unlock(&lock);
      int main(int argc, char **argv)
  
      pthread_mutex_init(&lock, NULL);
  
 -    pool = threadpool_create(THREAD, QUEUE, 0);
 +    assert((pool = threadpool_create(THREAD, QUEUE, 0)) != NULL);
      fprintf(stderr, "Pool started with %d threads and "
              "queue size of %d\n", THREAD, QUEUE);
  
      int main(int argc, char **argv)
          tasks++;
          pthread_mutex_unlock(&lock);
      }
 +
      fprintf(stderr, "Added %d tasks\n", tasks);
  
 -    while(tasks / 2 > done) {
 -    sleep(1);
 +    while((tasks / 2) > done) {
 +    usleep(10000);
      }
 -    fprintf(stderr, "Did %d tasks before shutdown\n", done);
 -    threadpool_destroy(pool, 0);
 +    assert(threadpool_destroy(pool, 0) == 0);
      fprintf(stderr, "Did %d tasks\n", done);
  
      return 0;
