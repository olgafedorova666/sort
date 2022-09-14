#include "SORT.H"

void main(void)
{
  int quit = 0;
  int c, n = 3;
  static Type arr[MAXN] = {1, 3, 2};
  Display(arr, n);
  while (!quit)
  {
    printf("\n0-Выход"
           "\n1-Изменить размер"
           "\n2-BubbleSort"
           "\n3-SelectionSort"
           "\n4-InsertionSort"
           "\n5-Table"
           "\n6-MergeSort"
           "\n7-HeapSort"
           "\n8-QuickSort"
           "\n9-SimpleCntInv,CntInv\n\n");
    c = _getch();
    switch (c)
    {
      case '0':
        quit = 1;
        break;
      case '1':
        printf("Введите размер n\n");
        scanf_s("%i", &n);
        FillRandom(arr, n);
        break;

      case '2':
        BubbleSort(arr, n);
        Display(arr, n);
        break;

      case '3':
        SelectionSort(arr, n);
        Display(arr, n);
        break;
      case '4':
        InsertionSort(arr, n);
        Display(arr, n);
        break;
      case '5':
        Table(arr, n);
        break;
      case '6':
        MergeSort(arr, n);
        Display(arr, n);
        break;
      case '7':
        HeapSort(arr, n);
        Display(arr, n);
        break;
      case '8':
        CallQuickSort(arr, n);
        Display(arr, n);
        break;
      case '9':
        Display(arr, n);
        SimpleCntInv(arr, n);
        CntInv(arr, n);
        break;
     }
  }
}