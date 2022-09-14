#include "SORT.H"
void Swap(Type *x, Type *y)
{
  Type tmp;
  tmp = *x;
  *x = *y;
  *y = tmp;
}

void Display(Type *a, int n)
{
  int i;
  for (i = 0; i < n; i++)
    printf("%f ", a[i]);
  printf("\n");
}
void FillRandom(Type *a, int n)
{
  int i;
  for (i= 0; i < n; i++)
    a[i] = rand() % 31;
}

Type mem[MAXN];

void Merge(Type *a, int l, int r)
{
  int i = l, m = (l + r) / 2, j = m + 1, k = 0;
  for (k = l; k <= r; k++)
  if(j > r || i <= m && a[i] <= a[j])
    mem[k] = a[i++];
  else
    mem[k] = a[j++];
  for (k = l; k <= r; k++)
    a[k] = mem[k];
}

void MergeSortR(Type *a, int l, int r)
{
  int m = (l + r)/2;
  if (l == r)
    return;
  MergeSortR(a, l, m);
  MergeSortR(a, m + 1, r);
  Merge(a, l, r);
}

void MergeSort(Type *a, int n)
{
  MergeSortR(a, 0, n-1);
}

int SimpleCntInv(Type *a, int n)
{
  int i, j, s = 0;
  for (i = 0; i < n - 1; i++)
    for (j = 0; j < n - i - 1; j++)
      if (a[j] > a[j + 1])
      {
        s++;
        Swap(&a[j], &a[j + 1]);
      }
  printf("%i\n", s);
  return s;
}

int CntInv1(Type *a, int l, int r, int s)
{
  int i = l, m = (l + r) / 2, j = m + 1, k = 0;
  for (k = l; k <= r; k++)
  if(j > r || i <= m && a[i] <= a[j])
    mem[k] = a[i++];
  else
  {
    mem[k] = a[j++];
  }
  for (k = l; k <= r; k++)
  {
    a[k] = mem[k];
  }
  printf("%i", s);
  return s;
}

void CntInvdop(Type *a, int l, int r)
{
  int s = 0;
  int m = (l + r)/2;
  if (l == r)
    return;
  CntInvdop(a, l, m);
  CntInvdop(a, m + 1, r);
  CntInv1(a, l, r, s);
}

void CntInv(Type *a, int n)
{
  CntInvdop(a, 0, n-1);
}

void FillRandom1(Type *a, int n)
{
  int i;
  int k = 1;
  for (i = 0; i < n; i++)
  {
    a[i] = k;
    k++;
  }
}
/*void FillAntiquick(Type *a, int n)
{
  int i;

}*/

void FillRandom2(Type *a, int n)
{
  int i;
  int k = n;
  for (i = n; i > 0; i--)
  {
    a[i] = k;
    k++;
  }
}

int Check(Type *a, int n)
{
  int i;
  for (i = 0; i < n - 1; i++)
    if (a[i] > a[i + 1])
      return 0;
  return 1;
}

void(*Sort[4/*3*/])(Type *a, int n)=
{
 SelectionSort,
 BubbleSort,
 InsertionSort,
 CallQuickSort,
};

void(*Fill[3])(Type *a, int n)=
{
  FillRandom,
  FillRandom1,
  FillRandom2,
};

void Table(Type *a, int n)
{
  int i, j;
  long stt;
  printf("FillType  Selection   Bubble     Insertion    QuickSort\n");
  for (i = 0; i < 3 ;i++)
  {
      if (i == 0)
        printf("Random     ");
      else
      {
        if (i == 1)
           printf("MinMax     ");
        else
          if (i == 2)
            printf("MaxMin     ");
      }
    for (j = 0; j < 4/*3*/; j++)
    {
      stt = clock();
      Fill[i](a, n);
      Sort[j](a, n);
      if (Check(a, n))
        printf("%.4f      ", (double)(clock() - stt) / CLOCKS_PER_SEC);
      else
        printf("Error     ");
    }
    printf("\n");
  }



}

void BubbleSort(Type *a, int n)
{
  int i, j;
  for (i = 0; i < n - 1; i++)
    for (j = 0; j < n - 1 - i; j++)
      if (a[j] > a[j + 1])
        Swap(&a[j], &a[j + 1]);
}

void SelectionSort(Type *a, int n)
{
  int i, j;
  for (i = 0; i < n - 1; i++)
    for (j = i + 1; j < n ; j++)
      if(a[j] < a[i])
        Swap(&a[i], &a[j]);
}

void InsertionSort(Type *a, int n)
{
  int i, j;
  Type x;
  for (i = 1; i < n ; i++)
  {
    x = a[i];
    for (j = i - 1; j >= 0 && x < a[j]; j--)
      a[j + 1] = a[j];
    a[j + 1] = x;
  }
}

void Heapify(Type *a, int n, int v)
{
  int l = 2 * v + 1;
  int r = l + 1;
  if (r < n && a[l] < a[r])
    l = r;
  if (l < n && a[v] < a[l])
  {
    Swap(&a[v], &a[l]);
    Heapify(a, n, l);
  }
}

void BuildHeap(Type *a, int n)
{
  int v;
  for (v = (n / 2) - 1; v >= 0; v--)
    Heapify(a, n, v);
}

void HeapSort(Type *a, int n)
{
  BuildHeap(a, n);
  while (n >= 1)
  {
    Swap(&a[0], &a[n - 1]);
    n--;
    Heapify(a, n, 0);
  }
}

void QuickSort(Type *a, int l, int r)
{
  int i = l, j = r;
  Type x;
  if (l >= r)
    return;

  x = a[(l + r) / 2];
  while (i <= j)
  {
    if (a[i] < x)
      i++;
    else if (a[j] > x)
      j--;
    else
      Swap(&a[i++], &a[j--]);
  }
  QuickSort(a, l, j);
  QuickSort(a, i, r);
}

void CallQuickSort(Type *a, int n)
{
   QuickSort(a, 0 , n - 1);
}

/*int Partition(Type *a, int l, int r)
{
  int i = l;
  int j = r;
  Type x = a[(l + r) / 2];
  while (i <= j)
  {
    if (a[i] < x)
      i++;
    else if (a[j] > x)
      j--;
    else
      Swap(&a[i++], &a[j--]);
  }
  return i - 1;
}
 */