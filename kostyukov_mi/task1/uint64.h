#include <iostream>
#include <math.h>

class uint64
{
    private:
        unsigned int fnum;
        unsigned int snum;
    public:
        uint64()
        {
            snum = 0;
            fnum = 0;
        }
        uint64(unsigned long num)
        {
            fnum = num >> 32;
            snum = num & 0xFFFFFFFF;
        }
        uint64(unsigned int _fnum, unsigned int _snum)
        {
            fnum = _fnum;
            snum = _snum;
        }
        uint64 operator+(uint64 &other)
        {
            uint64 result(this->fnum + other.fnum, this->snum + other.snum);
            if (result.snum < this->snum) return uint64(result.fnum + 1, result.snum);
            return result;
        }
        uint64 operator-(uint64 &other)
        {
            uint64 result(this->fnum - other.fnum, this->snum - other.snum);
            if (this->snum < other.snum) return uint64(result.fnum - 1, result.snum);
            return result;
        }
        uint64 operator+=(uint64 &other)
        {
            *this = *this + other;
            return (*this);
        }
        uint64 operator-=(uint64 &other)
        {
            *this = *this - other;
            return (*this);
        }
        uint64 operator<<(int amount)
        {
            if (amount < 32)
                if (amount != 0)
                    return uint64((this->fnum << amount) | (this->snum >> (32 - amount)), this->snum << amount);
            return (*this);
        }
        uint64 operator>>(int amount)
        {
            if (amount < 32)
                if (amount != 0)
                    return uint64((this->fnum >> amount), (this->snum >> amount) | this->fnum >> (32 - amount));
            return (*this);
        }
        uint64 operator|(uint64 &other)
        {
            uint64 result(this->fnum | other.fnum, this->snum | other.snum);
            return result;
        }
        uint64 operator*(uint64 &other)
        {
            unsigned int a16 = this->snum >> 16;
            unsigned int a00 = this->snum & 0xFFFF;
            unsigned int b16 = other.snum >> 16;
            unsigned int b00 = other.snum & 0xFFFF;

            uint64 result(this->fnum * other.snum + this->snum * other.fnum + a16 * b16, a00 * b00);
            result += (uint64(a16 * b00) << 16);
            result += (uint64(a00 * b16) << 16);
            return result;
        }
        uint64 operator*=(uint64 &other)
        {
            *this = *this * other;
            return (*this);
        }
        void DivMod(uint64 a, uint64 b, uint64* _q, uint64* _r);
        uint64 operator/(uint64 &other)
        {
            uint64 q = 0;
            uint64 r = 0;
            DivMod(*this, other, &q, &r);
            return q;
        }
        uint64 operator/=(uint64 &other)
        {
            *this = *this / other;
            return (*this);
        }
        uint64 operator%(uint64 &other)
        {
            uint64 q = 0;
            uint64 r = 0;
            DivMod(*this, other, &q, &r);
            return r;
        }
        uint64 operator%=(uint64 &other)
        {
            *this = *this % other;
            return (*this);
        }
        friend std::ostream& operator<<(std::ostream &out, const uint64 &n)
        {
            out << n.fnum * 4294967296 + n.snum;
            return out;
        }
        bool operator==(const uint64 &other)
        {
            return (this->fnum == other.fnum) && (this->snum == other.snum);
        }
        bool operator!=(const uint64 &other)
        {
            return !(*this == other);
        }
        bool operator<(const uint64 &other)
        {
            if (this->fnum < other.fnum) return 1;
            if (this->snum < other.snum) return 1;
            return 0;            
        }
        bool operator<=(const uint64 &other)
        {
            return ((*this < other) || (*this == other));
        }
        bool operator>(const uint64 &other)
        {
            return !(*this <= other);
        }
        bool operator>=(const uint64 &other)
        {
            return !(*this < other);
        } 
};

void uint64::DivMod(uint64 a, uint64 b, uint64* _q, uint64* _r)
{
    if (b == 0)
    {
        *_q = 0;
        *_r = 0;
        return;
    }
    if (a < b)
    {
        *_q = 0;
        *_r = a;
        return;
    }
    if (a == b)
    {
        *_q = 1;
        *_r = 0;
        return;
    }
    uint64 d = b;
    uint64 q = 0;
    uint64 curr = 1;

    while (d<a)
    {
        d = d << 1;
        curr = curr << 1;
    }

    while (curr != 0)
    {
        if (d < a)
        {
            a = a - d;
            q = q + curr;
        }
        curr = curr >> 1;
        d = d >> 1;
    }
    *_q = q;
    *_r = a;
}