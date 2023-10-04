#include <hw04.h>
#include <new>
#include <iostream>

std::size_t hw04(const int* input_array, std::size_t elem_count)
{
    int *out_data = new int[1];
    std::size_t sum = 0;
    std::size_t c = 0;
    int *temp = new int[1];
    for(std::size_t i = 0; i < elem_count; i++)
    {
        auto elem = *(input_array + i);
        if(elem < 0) break;
        out_data = (int*)realloc(out_data, i + 1);
        *(out_data + i) = elem;
        c++;
    }
    
    for(std::size_t i = 0; i < c; i++)
    {
        sum += *(out_data + i);
    }
    delete[] out_data;
    //delete[] temp;
    out_data = nullptr;
    return sum;
}
