#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int get_corecount() { return (int)sysconf(_SC_NPROCESSORS_ONLN); }

struct chunk {
  int *arr;
  int start;
  int stop;
  long long sum;
};

void *summing(void *);
long long sum(int *arr, int len);

int main() {
  int len;
  printf("Enter the length of array: ");
  scanf("%d", &len);

  int arr[len];
  printf("Enter the elements: ");
  for (int i = 0; i < len; i++) {
    scanf("%d", &arr[i]);
  }
  long long sumOfArray = sum(arr, len), APsum = len * (len + 1) / 2;

  printf("%lld", APsum - sumOfArray);
}

void *summing(void *a) {
  struct chunk *arr_chunk = (struct chunk *)a;
  for (int i = arr_chunk->start; i < arr_chunk->stop; i++)
    arr_chunk->sum += (arr_chunk->arr)[i];
  return NULL;
}

long long sum(int *arr, int len) {
  // Inputting the array
  int cores = get_corecount();
  long long sum = 0;

  // summing array
  // Chunking the array
  int num_thread = 0;
  if (len < 10000)
    num_thread = 1;
  else
    num_thread = cores;

  // creating and starting threads
  pthread_t threads[num_thread];
  int chunk_size = len / num_thread;
  struct chunk chunk_arr[num_thread];
  for (int i = 0; i < num_thread; i++) {
    int stop = (i == num_thread - 1) ? len : (i + 1) * chunk_size;
    chunk_arr[i] = (struct chunk){arr, i * chunk_size, stop, 0};
    pthread_create(&threads[i], NULL, summing, &chunk_arr[i]);
  }

  // joining threads
  for (int i = 0; i < num_thread; i++)
    pthread_join(threads[i], NULL);

  // summing the partial sums
  for (int i = 0; i < num_thread; i++)
    sum += chunk_arr[i].sum;

  return sum;
}
