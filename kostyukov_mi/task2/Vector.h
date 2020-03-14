#include <iostream>
#include <string.h>
#include <math.h>

template <typename Type>
class Vector
{
    private:
        Type *data;
        size_t size;
    public:
        Vector()
        {
            size = 2;
            data = new Type[2];
        }
        Vector(size_t _size)
        {
            size = _size;
            data = new Type[size];
        }

        Vector(const Type* _data, size_t _size)
        {
            size = _size;
            data = new Type[size];
            std::copy(data, data + size, _data);
        }
        Vector(const Vector &v)
        {
            size = v.size;
            data = new Type[size];
            std::copy(data, data + size, v.data);
            //memcpy(data, v.data, sizeof(Type)*size);
        }
        ~Vector()
        {
            delete[] data;
        }
        Vector& operator=(const Vector &v)
        {
            size = v.size;
            data = new Type[size];
            std::copy(data, data + size, v.data);
            return *this;
        }
        void setSize(size_t _size)
        {
            Type *buff = new Type[_size];
            std::copy(buff, buff + size, data);
            delete[] data;
            data = buff;
            size = _size;
        }
        size_t getSize()
        {
            return size;
        }
        Type getLength()
        {
            Type len = 0;
            for (size_t i = 0; i < size; i++)
            {
                len += data[i] * data[i];
            }
            return sqrt(len);
        }
        Type& operator[](size_t i)
        {
            return data[i];
        }
        Vector operator+(const Vector &other)
        {
            if ((*this).size != other.size)
                throw std::invalid_argument("Adding vectors of different sizes!");
            Vector<Type> res(other.size);
            for (size_t i = 0; i<other.size; i++)
            {
                res[i] = this->data[i] + other.data[i];
            }
            return res;
        }
        Type operator*(const Vector &other)
        {
            if ((*this).size != other.size)
                throw std::invalid_argument("Inner product of vectors of different sizes!");
            Type res = 0;
            for (size_t i = 0; i < size; i++)
            {
                res += data[i] * other.data[i];
            }
            return res;
        }
        friend std::ostream& operator<<(std::ostream &out, const Vector &v)
        {
            for (size_t i = 0; i < v.size - 1; i++)
            {
                out << v.data[i] << " ";
            }
            out << v.data[v.size-1];
        }
};
