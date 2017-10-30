// хэдер для задания
#ifndef HSE_VECTOR_HPP
#define HSE_VECTOR_HPP
#include<ostream>
#include<iostream>
// ... другие include директивы ...

// рассматривается упрощенный шаблон класса Vector< >
// как "обёртка" вокруг динамического массива произвольной
// длины
template<typename T>
class Vector
{
public:
    enum { CAPACITY = 8 };

    explicit Vector(std::size_t init_size = 0) : VSize(init_size), VCapacity(init_size + CAPACITY)
    {
        std::cout << "Ctor\n";
        vec = new T[VCapacity];
    }

    // конструктор копирования
    Vector(const Vector& right) : vec(nullptr)
    {
        std::cout << "CCtor\n";
        VSize = right.size();
        VCapacity = right.capacity();

        vec = new T[VCapacity];

        for (int i = 0; i < VSize; ++i)
            vec[i] = right.vec[i];
    }

    // конструктор перемещения
    Vector(Vector&& right) noexcept : vec(nullptr)
    {
        std::cout << "CtorMove\n";

        operator=(std::move(right));
    }

    ~Vector()
    {
        std::cout << "Dtor\n";
        delete[] vec;
    }

    Vector& operator=(const Vector& right)
    {
        Vector tmp(right);
        *this = std::move(tmp);

        return *this;
    }

    Vector& operator=(Vector&& right) noexcept {
        delete[] vec;

        vec = right.vec;
        right.vec = nullptr;
        return *this;
    }

    void resize(std::size_t newSize)
    {
        if(newSize > VCapacity)
            reserve(newSize*2 + 1);

        VSize = newSize;
    }

    void reserve(size_t newCapacity)
    {
        if (newCapacity > VCapacity)
        {
            T* tmp = new T[newCapacity];
            std::copy(vec, vec + VSize, tmp);

            delete vec;
            vec = tmp;
            VCapacity = newCapacity;
        }
    }

    T& operator[](int index)
    {
        if (index < 0 || index >= VCapacity)
            throw std::invalid_argument("Error: index is out of bounds.");

        return vec[index];
    }

    const T& operator[](int index) const
    {
        return vec[index];
    }

    bool empty() const
    {
        return VSize == 0;
    }

    std::size_t size() const
    {
        return VSize;
    }

    std::size_t capacity() const
    {
        return VCapacity;
    }

    T& front()
    {
        return vec[0];
    }

    const T& front() const
    {
        return vec[0];
    }

    T& back()
    {
        return vec[VSize - 1];
    }

    const T &back() const
    {
        return vec[0];
    }

    void push_back(const T &val)
    {
        if (VSize == VCapacity)
            reserve(VSize * 2 + 1);

        vec[VSize] = val;
        VSize += 1;
    };

    void push_back(T&& val)
    {
        if (VSize == VCapacity)
            reserve(VSize * 2 + 1);

        vec[VSize] = val;
        VSize += 1;
        val = nullptr;
    };

    void pop_back()
    {
        if (!empty())
            VSize -= 1;
    };

    // ... ОСТАВШАЯСЯ ЧАСТЬ - см. текст задания ...

    typedef T* viterator;
    viterator begin( ) const
    {
       return vec;
    }
    viterator end( ) const
    {
        return vec + VSize;
    }

    template<typename T1>
    friend std::ostream& operator<<(std::ostream& out, const Vector<T1>& obj);

private:
    std::size_t VSize;
    std::size_t VCapacity;
    T* vec;
};

template<typename T1>
std::ostream& operator<<(std::ostream& out, const Vector<T1>& obj)
{
    // вывод по 10 элементов в одной строке
    int num = 0;
    for(auto& i : obj)
    {
        out << i << " ";
        ++num;
        if(num/11)
        {
            std::cout << std::endl;
            num = 0;
        }
    }
    std::cout << std::endl;
    return out;
}

#endif