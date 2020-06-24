#include <stdio.h>
#include <math.h> 
#include <memory.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <sys/time.h>
#define ARRSIZE 1000
#define NUMALGO 6
#define NUMEXCUTE 10000

void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);
void mergeSortStart(int arr[], int n);
void mergeSort(int arr[], int tmp[], int start, int end);
void merge(int arr[], int tmp[], int start, int mid, int end);
void quickSortStart(int arr[], int n);
void quickSort(int arr[], int start, int end);
int partition(int arr[], int start, int end);
void countingSortStart(int arr[], int n);
void countingSort(int arr[], int n, int digit);
void radixSort(int arr[], int n);
void bucketSort(int arr[], int n);
void display(int arr[]);

int main() {
   FILE* fp = fopen("results.txt", "w");
   struct timeval start, end;
   srand((unsigned int)time(0));
   int arr[ARRSIZE];
   int intputArr[ARRSIZE];
   int i, j, k;
   int inputSize[3] = { 10, 100, 1000 };
   void (*sort[NUMALGO])(int*, int) = { bubbleSort, insertionSort, mergeSortStart, quickSortStart, radixSort, bucketSort };
   const char* algorName[NUMALGO] = { "bubble sort", "insertion sort", "merge sort", "quick sort", "radix sort", "bucket sort" };

   for (i = 0; i < ARRSIZE; i++)
      arr[i] = rand() % ARRSIZE;

   printf("%4s", "");
   fprintf(fp, "%4s", "");
   for (i = 0; i < NUMALGO; i++) {
      printf("%15s", algorName[i]);
      fprintf(fp, "%15s", algorName[i]);
   }

   printf("\n");
   fprintf(fp, "\n");

   for (i = 0; i < 3; i++) {
      printf("%4d", inputSize[i]);
      fprintf(fp, "%4d", inputSize[i]);
      for (j = 0; j < NUMALGO; j++) {
         memcpy(intputArr, arr, sizeof(int) * ARRSIZE);

         gettimeofday(&start, NULL);
         sort[j](intputArr, inputSize[i]);
         gettimeofday(&end, NULL);
         
         printf("%15i", end.tv_usec - start.tv_usec);
         fprintf(fp, "%15i", end.tv_usec - start.tv_usec);
      }
      printf("\n");
      fprintf(fp, "\n");
      fflush(fp);
   }

   printf("\n");
   fprintf(fp, "\n");
   printf("%15s: ", "Initai Arr");
   fprintf(fp, "%15s: ", "Initai Arr");

   for (i = 0; i < 10; i++) {
      printf("%2d, ", arr[i]);
      fprintf(fp, "%2d, ", arr[i]);
   }
   printf("\n");
   fprintf(fp, "\n");


   for (i = 0; i < NUMALGO; i++) {
      printf("%15s: ", algorName[i]);
      fprintf(fp, "%15s: ", algorName[i]);
      memcpy(intputArr, arr, sizeof(int) * ARRSIZE);
      sort[i](intputArr, inputSize[0]);

      for (j = 0; j < 10; j++) {
         printf("%2d, ", intputArr[j]);
         fprintf(fp, "%2d, ", intputArr[j]);
      }
      printf("\n");
      fprintf(fp, "\n");
   }


   fclose(fp);

   return 0;
}

void bubbleSort(int arr[], int n) {
   int i, j, temp;
   for (i = 0; i < n - 1; i++) {
      for (j = 0; j < n - i - 1; j++) {
         if (arr[j] > arr[j + 1]) {
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
         }
      }
   }
}

void insertionSort(int arr[], int n) {
   int key, i, j;

   for (int i = 1; i < n; i++) {
      key = arr[i];
      j = i - 1;
      while (j >= 0 && key < arr[j]) {
         arr[j + 1] = arr[j];
         j--;
      }
      arr[j + 1] = key;
   }
}

void mergeSortStart(int arr[], int n) {
   int* tmp = (int*)malloc(sizeof(int) * n);
   mergeSort(arr, tmp, 0, n - 1);
   free(tmp);
}

void mergeSort(int arr[], int tmp[], int start, int end) {
   if (start < end) {
      int mid = (start + end) / 2;
      mergeSort(arr, tmp, start, mid);
      mergeSort(arr, tmp, mid + 1, end);
      merge(arr, tmp, start, mid, end);
   }
}

void merge(int arr[], int tmp[], int start, int mid, int end) {
   int index = start;
   int part1 = start;
   int part2 = mid + 1;

   memcpy(tmp + start, arr + start, sizeof(int) * (end - start + 1));

   while (part1 <= mid && part2 <= end)
      arr[index++] = (tmp[part1] < tmp[part2]) ? tmp[part1++] : tmp[part2++];

   if (part1 < mid + 1)
      memcpy(arr + index, tmp + part1, sizeof(int) * (mid - part1 + 1));
}

void selectionSort(int arr[], int n) {
   for (int i = 0; i < n; i++) {
      int min = i;
      for (int j = i + 1; j < n; j++) {
         if (arr[j] < arr[min])
            min = j;
      }
      int temp = arr[i];
      arr[i] = arr[min];
      arr[min] = temp;
   }
}

void quickSortStart(int arr[], int n) {
   quickSort(arr, 0, n - 1);
}

void quickSort(int arr[], int start, int end) {
   if (start < end) {
      int pivot = partition(arr, start, end);
      quickSort(arr, start, pivot - 1);
      quickSort(arr, pivot + 1, end);
   }
}

int partition(int arr[], int start, int end) {
   int key = arr[start];
   int i = start;
   int j;

   int temp;
   for (j = start + 1; j <= end; j++) {
      if (arr[j] < key) {
         i++;
         temp = arr[i];
         arr[i] = arr[j];
         arr[j] = temp;
      }
   }
   temp = arr[i];
   arr[i] = arr[start];
   arr[start] = temp;

   return i;
}

void countingSortStart(int arr[], int n) {
   countingSort(arr, n, 0);
}

void countingSort(int arr[], int n, int digit) {
   int accum[10] = { 0 };
   int* tmp = (int*)malloc(sizeof(int) * n);
   int i;
   memcpy(tmp, arr, sizeof(int) * n);

   for (i = 0; i < n; i++) accum[arr[i] / (int)pow(10, digit) % 10]++;
   for (i = 1; i < 10; i++) accum[i] += accum[i - 1];
   for (i = n-1; i >= 0; i--) arr[--accum[tmp[i] / (int)pow(10, digit) % 10]] = tmp[i];
}

void radixSort(int arr[], int n) {
   int i;
   int digit = 0;
   int maxVal = INT_MIN;
   for (i = 0; i < n; i++) (maxVal < arr[i]) ? maxVal = arr[i] : 0;
   for (i = maxVal; i > 0; i /= 10) digit++;
   for (int i = 0; i < digit; i++) countingSort(arr, n, i);
}

void bucketSort(int arr[], int n) {
   int i, j;
   int maxVal = INT_MIN;
   int numBucket = 5 * (int)log10(n);
   int* bucketIndex = (int*)calloc(numBucket, sizeof(int));
   int* bucketSize = (int*)calloc(numBucket, sizeof(int));
   int interval;
   int index;
   int **bucket = (int**)malloc(numBucket * sizeof(int*));

   for (i = 0; i < n; i++) (maxVal < arr[i]) ? maxVal = arr[i] : 0;
   interval = maxVal / numBucket + 1;

   for (i = 0; i < n; i++) bucketSize[arr[i] / interval]++;
   for (i = 0; i < numBucket; i++) bucket[i] = (int*)malloc(sizeof(int) * bucketSize[i]);

   for (i = 0, j = 0; i < n; i++) {
      bucket[arr[i] / interval][bucketIndex[arr[i] / interval]++] = arr[i];
   }

   for (i = 0; i < numBucket; i++) radixSort(bucket[i], bucketSize[i]);
 
   for (i = 0, index = 0; i < numBucket; i++) {
      for (j = 0; j < bucketSize[i]; j++) {
         arr[index] = bucket[i][j];
         index++;
      }
   }

   for (i = 0; i < numBucket; i++) free(bucket[i]);
   free(bucket);
   free(bucketSize);
   free(bucketIndex);
}