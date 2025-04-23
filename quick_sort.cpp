#include "quick_sort.hpp"
#include <iostream>
#include <cstddef>
#include <chrono>
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

using std::size_t, std::cout, std::endl;
int main()
{
    int data[100] = {
        834, 120, 932, 74, 543, 681, 217, 301, 64, 989,
        110, 745, 502, 229, 361, 785, 156, 480, 27, 901,
        329, 708, 36, 973, 812, 633, 509, 440, 678, 553,
        91, 381, 205, 703, 643, 150, 226, 494, 603, 88,
        915, 218, 577, 444, 142, 328, 830, 472, 12, 59,
        431, 342, 249, 780, 678, 90, 11, 999, 64, 300,
        438, 169, 350, 513, 236, 222, 600, 300, 512, 33,
        134, 177, 466, 478, 821, 303, 2, 703, 155, 451,
        739, 900, 84, 690, 411, 688, 207, 511, 315, 424,
        689, 271, 65, 30, 750, 601, 521, 990, 77, 399};

    int countData = sizeof(data) / sizeof(int);

    cout << "Input: " << endl;

    for (int d{0}; d < countData; d++)
    {
        cout << data[d];

        if (d < countData - 1)
        {
            cout << ", ";
        }

        if (d > 1 &&
            d % 25 == 0)
        {
            cout << endl;
        }
    }

    auto start = std::chrono::high_resolution_clock::now();

    sort(data, countData);
    
    auto end = std::chrono::high_resolution_clock::now();

    
    cout << endl << "Output: " << endl;
    
    for (int d{0}; d < countData; d++)
    {
        cout << data[d];
        
        if (d < countData - 1)
        {
            cout << ", ";
        }
        
        if (d > 1 &&
            d % 25 == 0)
        {
            cout << endl;
        }
    }
        std::chrono::duration<double, std::micro> duration = end - start;
        std::cout << endl << "Execution time: " << duration.count() << " microseconds ("
        << duration.count() / 1000 << "ms)" << std::endl;
            
            return 0;
}
