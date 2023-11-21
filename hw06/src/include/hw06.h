#include <stdlib.h>

class MyIntVector
{
private:
    int* _container;
    size_t _capacity;
    size_t _size;

public:
    MyIntVector();
    MyIntVector(size_t count);
    MyIntVector(size_t count, const int value);

    size_t size();
    size_t capacity();

    void push_back(const int value);

    void resize(size_t count);
    void resize(size_t count, const int value);
    void reserve(size_t count);
    void shrink_to_fit();

    int& operator[](int index);
    int* begin();
    int* end();
};
