#include <iostream>
#include <cmath>
#include <chrono>

using std::cout, std::endl;

void radix(int *data, int count)
{
    int max = data[0];
    for (int i = 1; i < count; i++)
    {
        if (data[i] > max)
            max = data[i];
    }

    int powerOfTen{0};
    while (max > 0)
    {
        max /= 10;
        powerOfTen++;
    }

    int sorted[100] = {};
    int divisor = 1;

    for (int currPot{0}; currPot < powerOfTen; currPot++)
    {
        int i{0};

        for (int currDig{0}; currDig <= 9; currDig++)
        {
            for (int n{0}; n < count; n++)
            {
                int digit = (data[n] / divisor) % 10;
                if (digit == currDig)
                {
                    sorted[i] = data[n];
                    i++;
                }
            }
        }

        for (int k{0}; k < count; ++k)
        {
            data[k] = sorted[k];
        }

        divisor *= 10;
    }
}


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

    radix(data, countData);
    
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
