#include <hw06.h>
#include <exception>

MyIntVector::MyIntVector(): _size{0}, _capacity{0}
{
    _container = new int[0];
}

MyIntVector::MyIntVector(size_t count): _size{0}, _capacity{count}
{
    _container = new int[count]{};
}

MyIntVector::MyIntVector(size_t count, int value): _size{count}, _capacity{count}
{
    _container = new int[count];
    for(auto i = 0; i < _size; i++)
    {
        _container[i] = value;
    }
}

size_t MyIntVector::size()
{
    return _size;
}

size_t MyIntVector::capacity()
{
    return _capacity;
}

void MyIntVector::push_back(const int value)
{
    if(_size == _capacity)
    {
        _capacity *= 2;
    }
    auto temp = new int[_capacity];
    for(auto i = 0; i < _size; i++)
    {
        temp[i] = *(_container + i);
    }
    temp[_size] = value;

    delete[] _container;
    _container = temp;
    _size++;
}

void MyIntVector::resize(size_t count)
{
    if((int)count < 0) throw std::exception();

    auto temp = new int[count]{};
    
    if(count <= _size)
    {
        for(auto i = 0; i < count; i++)
        {
            temp[i] = _container[i];
        }
    }
    else{
        for(auto i = 0; i < _size; i++)
        {
            temp[i] = _container[i];
        }
    }

    

    delete[] _container;
    _container = temp;
    _size = count;
    if(_capacity < _size)
    {
        _capacity = _size;
    }
}

void MyIntVector::resize(size_t count, const int value)
{
    if((int)count < 0) throw std::exception();

    auto temp = new int[count]{};
    
    if(count <= _size)
    {
        for(auto i = 0; i < count; i++)
        {
            temp[i] = _container[i];
        }
    }
    else{
        for(auto i = 0; i < _size; i++)
        {
            temp[i] = _container[i];
        }
        for(auto i = _size; i < count; i++)
        {
            temp[i] = value;
        }
    }

    delete[] _container;
    _container = temp;
    _size = count;
    
    if(_capacity < _size)
    {
        _capacity = _size;
    }
}

void MyIntVector::reserve(size_t count)
{
    if(count < _size) return;

    auto temp = new int[count];

    for(auto i = 0; i < _size; i++)
    {
        temp[i] = *(_container + i);
    }

    delete[] _container;
    _container = temp;

    _capacity = count;
}

void MyIntVector::shrink_to_fit()
{
    _capacity = _size;
}

int& MyIntVector::operator[](int index)
{
    if(index < _size)
    {
        return _container[index];
    }
    throw std::exception();
}

int* MyIntVector::begin()
{
    return &_container[0];
}

int* MyIntVector::end()
{
    return &_container[_size];
}
