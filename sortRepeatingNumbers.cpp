#include <iostream>

using namespace std;


void swap(int& val1, int& val2)
{
    int tmp = val1;
    val1 = val2;
    val2 = tmp;
}

void sortRepeatingArray(int* arr, int size)
{
    int begin = 0;
    int end = begin + size - 1;

    while (end >= begin)
    {
        swap(arr[end], arr[begin]);

        if (arr[end] == 2)
            --end;
        
        if (arr[begin] != 2)
            ++begin;
    }
}

int main(int argc, char* argv[])
{
    int arr[19] = {1, 2, 1, 2, 2, 1, 2, 1, 2, 2, 2, 1, 1, 2, 1, 2, 2, 1, 2};
    int size = 19;

    sortRepeatingArray(arr, size);

    return 0;
}
