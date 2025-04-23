#include <iostream>
#include <cmath>

using std::cout, std::endl;

void printSorted(int *sorted, int countSorted)
{
    for (int s{0}; s < countSorted; s++)
    {
        cout << sorted[s];

        if (s != countSorted - 1)
        {
            cout << ", ";
        }

        if (s % 25 == 0)
        {
            cout << endl;
        }
    }
}

void radix(int *data, int count)
{
    int max = data[0];
    for (std::size_t i = 0; i < count; i++)
    {
        if (data[i] > max)
            max = data[i];
    }
    int powerOfTens = 0;
    while (max > 0)
    {
        max /= 10;
        powerOfTens++;
    }

    int sorted[100] = {};
    int n{0};

    while (n <= 100)
    {
        for (int t{0}; t <= powerOfTens; t++) // cycles through each power of ten
        {
            for (int i{0}; i <= 9; i++) // cycles through each digit through base 10
            {
                if (data[n] % (i * pow(10, t) == 0)) // sorts from lowest to highest
                {
                    sorted[n] = data[n];
                    n++;
                }
            }
        }
    }

    int countSorted = sizeof(sorted) / sizeof(int);
    printSorted(sorted, countSorted);
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

    for (int d{0}; d < countData; d++)
    {
        cout << data[d];

        if (d != countData - 1)
        {
            cout << ", ";
        }

        if (d > 1 &&
            d % 25 == 0)
        {
            cout << endl;
        }
    }

    radix(data, countData);

    return 0;
}
