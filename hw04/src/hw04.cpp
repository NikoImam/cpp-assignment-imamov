#include <hw04.h>

std::size_t hw04(const int* input_array, std::size_t elem_count)
{
    int *out_data = new int[1];

    std::size_t sum = 0;
    std::size_t count = 0;

    int *temp = new int[1];

    for(std::size_t i = 0; i < elem_count; i++)
    {
        auto elem = *(input_array + i);
        if(elem < 0) break;

        delete[] out_data;
        out_data = new int[i + 1];

        for(std::size_t j = 0; j < i; j++)
        {
            *(out_data + j) = *(temp + j);
        }

        *(out_data + i) = elem;

        delete[] temp;
        temp = new int[i + 1];

        for(std::size_t j = 0; j < i + 1; j++)
        {
            *(temp + j) = *(out_data + j);
        }

        count++;
    }
    
    for(std::size_t i = 0; i < count; i++)
    {
        sum += *(out_data + i);
    }

    delete[] out_data;
    delete[] temp;
    out_data = nullptr;
    temp = nullptr;

    return sum;
}
