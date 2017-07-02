int main(int argc, char **argv)
  {
 -    int i;
 +    int i, copy = 1;
  
      left = SIZE;
      pthread_mutex_init(&lock, NULL);
      int main(int argc, char **argv)
      assert(threadpool_add(pool[0], &dummy_task, &(tasks[i]), 0) == 0);
      }
  
 -    while(left > 0) {
 +    while(copy > 0) {
      usleep(10);
 +    pthread_mutex_lock(&lock);
 +    copy = left;
 +    pthread_mutex_unlock(&lock);
      }
  
     for(i = 0; i < QUEUES; i++) {
 -   threadpool_destroy(pool[i], 0);
 +   assert(threadpool_destroy(pool[i], 0) == 0);
     }
  
     pthread_mutex_destroy(&lock);
  
