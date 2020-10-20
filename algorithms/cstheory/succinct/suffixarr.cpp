
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int **arr;
int numcp =0;
const int INVALID = 0;

int compare(const void* arg_i, const void* arg_j, void* arg_str)
{
  int i = *(int*)arg_i;
  int j = *(int*)arg_j;
  char* str = (char*)arg_str;

  if ((str[i] == str[j]) && (arr[i+1][j+1] != INVALID))
  {
    arr[i][j] = arr[i+1][j+1];
    printf("saved cmp at pos=%d : %d\n", i, j);
  }
  else
  {
    numcp ++;
    arr[i][j] = strcmp(str + i, str + j);
    printf("cmp at pos=%d:%d = %d\n", i, j, arr[i][j]);
  }
  return arr[i][j];
}

int main()
{
  char str[] = "abeferethsi";
  size_t len = strlen(str);

  arr = (int**)malloc(sizeof(int*) * len);
  arr[0] = (int*) malloc(sizeof(int) * len * len);
  memset(arr[0], INVALID, sizeof(int) * len * len);

  for (int i = 1; i < len; i++)
  {
    arr[i] = (*arr + len * i);
  }

  int* sa = (int*)malloc(strlen(str));
  for (int i = 0; i < strlen(str); i++)
  {
    sa[i] = i;
  }

  qsort_r(sa, strlen(str), sizeof(int), compare, str);

  for (int i = 0; i < strlen(str); i++)
  {
    printf("%s\n", str + sa[i]);
  }
  printf("numcp=%d\n", numcp);
}
