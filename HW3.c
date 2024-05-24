#include <stdio.h>

void printArray(int a[], int aSize)
{
    for (int i = 0; i < aSize; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void BubbleSort(int a[], int aSize)
{
    int i, j, temp;
    for (i = 0; i < aSize; i++)
    {
        for (j = 0; j < aSize - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
            printArray(a, aSize);
        }
    }
}

void SelectionSort(int a[], int aSize)
{
    for (int i = 0; i < aSize - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < aSize; j++)
        {
            if (a[j] < a[min_idx])
            {
                min_idx = j;
            }
        }
        printArray(a, aSize);
        int temp;
        temp = a[min_idx];
        a[min_idx] = a[i];
        a[i] = temp;
    }
}
void QuickSort(int a[], int aSize, int first_index, int last_index)
{
    int pivotIndex, temp, index_a, index_b;

    if (first_index < last_index)
    {
        pivotIndex = first_index;
        index_a = first_index;
        index_b = last_index;
        printArray(a, aSize);
        while (index_a < index_b)
        {
            while (a[index_a] <= a[pivotIndex] && index_a < last_index)
            {
                index_a++;
            }
            while (a[index_b] > a[pivotIndex])
            {
                index_b--;
            }

            if (index_a < index_b)
            {
                temp = a[index_a];
                a[index_a] = a[index_b];
                a[index_b] = temp;
            }
        }
        temp = a[pivotIndex];
        a[pivotIndex] = a[index_b];
        a[index_b] = temp;
        QuickSort(a, aSize, first_index, index_b - 1);
        QuickSort(a, aSize, index_b + 1, last_index);
    }
}
int main()
{

    int n = 10;
    int array1[10] = {33, 67, 8, 13, 54, 119, 3, 84, 25, 41};
    printf("\nBubble Sort Process:\n");
    BubbleSort(array1, n);

    int array2[10] = {33, 67, 8, 13, 54, 119, 3, 84, 25, 41};
    printf("\nSelection Sort Process:\n");
    SelectionSort(array2, n);

    int array3[10] = {33, 67, 8, 13, 54, 119, 3, 84, 25, 41};
    printf("\nQuick Sort Process:\n");
    QuickSort(array3, n, 0, n - 1);
    return 0;
}