#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
    int id;
    double amount;
} FinancialData;

void generateRandomData(FinancialData *data, int size)
{
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        data[i].id = i + 1;
        data[i].amount = (double)(rand() % 10000) / 100;
    }
}

void merge(FinancialData arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    FinancialData *L = (FinancialData *)malloc(n1 * sizeof(FinancialData));
    FinancialData *R = (FinancialData *)malloc(n2 * sizeof(FinancialData));

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i].amount <= R[j].amount)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(FinancialData arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int partition(FinancialData arr[], int low, int high)
{
    double pivot = arr[high].amount;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j].amount <= pivot)
        {
            i++;
            FinancialData temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    FinancialData temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(FinancialData arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void writeToFile(FinancialData *data, int size, const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
    for (int i = 0; i < size; i++)
    {
        fprintf(file, "ID: %d, Amount: %.2f\n", data[i].id, data[i].amount);
    }
    fclose(file);
}

void readFromFile(FinancialData *data, int size, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
    for (int i = 0; i < size; i++)
    {
        fscanf(file, "ID: %d, Amount: %lf\n", &data[i].id, &data[i].amount);
    }
    fclose(file);
}

int main()
{
    int size = 100;
    FinancialData *data = (FinancialData *)malloc(size * sizeof(FinancialData));

    generateRandomData(data, size);
    printf("Random financial data has been generated.\n");

    writeToFile(data, size, "unsorted_data.txt");
    printf("Unsorted data has been written to 'unsorted_data.txt'.\n");

    FinancialData *dataForMergeSort = (FinancialData *)malloc(size * sizeof(FinancialData));
    FinancialData *dataForQuickSort = (FinancialData *)malloc(size * sizeof(FinancialData));
    memcpy(dataForMergeSort, data, size * sizeof(FinancialData));
    memcpy(dataForQuickSort, data, size * sizeof(FinancialData));

    mergeSort(dataForMergeSort, 0, size - 1);
    quickSort(dataForQuickSort, 0, size - 1);

    writeToFile(dataForMergeSort, size, "sorted_data_merge.txt");
    printf("Data sorted using merge sort has been written to 'sorted_data_merge.txt'.\n");

    writeToFile(dataForQuickSort, size, "sorted_data_quick.txt");
    printf("Data sorted using quick sort has been written to 'sorted_data_quick.txt'.\n");

    free(data);
    free(dataForMergeSort);
    free(dataForQuickSort);

    return 0;
}