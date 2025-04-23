#include "sort.hpp"
#include <cstddef>
// #include <utility>

void quicksort(int *data, int left, int right)
{
    if (left >= right)
        return;

    int pivot = data[right];
    int i = left - 1;

    for (int j = left; j < right; j++)
    {
        if (data[j] < pivot)
        {
            i++;
            int temp = data[i];
            data[i] = data[j];
            data[j] = temp;
            // alternatively, std::swap(data[i], data[j]) with include utility should work just as well
        }
    }

    int temp = data[i + 1];
    data[i + 1] = data[right];
    data[right] = temp;

    quicksort(data, left, i);
    quicksort(data, i + 2, right);
}

void sort(int *data, std::size_t count)
{
    if (count <= 1)
        return;
    quicksort(data, 0, count - 1);
}