#include <iostream>
#include <math.h>
#include "uint64.h"

class int64
{
    private:
        char sign = 1;
        uint64 num;
    public:
        int64()
        {
            num = 0;
        }
        int64(char _sign, uint64 _num)
        {
            sign = _sign;
            num = _num;
        }
        int64(long long _num)
        {
            if (_num < 0) sign = -1;
            num = abs(_num);
        }
        int64(uint64 _num)
        {
            num = _num;
        }
        int64 operator=(int64 &other)
        {
            sign = other.sign;
            num = other.num;
            return other;
        }
        int64 operator+(int64 &other)
        {
            uint64 r;
            char sign_r;
            if (this->sign == other.sign)
            {
                r = this->num + other.num;
                sign_r = this->sign;  
            }
            else
            {
                if (this->num > other.num)
                {
                    r = this->num - other.num;
                    sign_r = this->sign;
                }
                if (this->num < other.num)
                {
                    r = other.num - this->num;
                    sign_r = other.sign;
                }
                if (this->num == other.num)
                {
                    r = 0;
                    sign_r = 1;
                }
            }
            return int64(sign_r, r);
        }
        int64 operator+=(int64 &other)
        {
            *this = *this + other;
            return (*this)
        }
        int64 operator-(int64 &other)
        {
            int64 _other((-1) * other.sign,other.num);
            return *this + other;
        }
        int64 operator-=(int64 &other)
        {
            *this = *this - other;
            return (*this)
        }
        int64 operator*(int64 &other)
        {
            return int64(this->sign * other.sign, this->num * other.num);
        }
        int64 operator*=(int64 &other)
        {
            *this = *this * other;
            return (*this)
        }
        int64 operator/(int64 &other)
        {
            return int64(this->sign / other.sign, this->num / other.num);
        }
        int64 operator/=(int64 &other)
        {
            *this = *this / other;
            return (*this)
        }
        int64 operator%(int64 &other)
        {
            if (this->sign != other.sign)
                return int64(1, other.num - (this->num % other.num));
            else
                return int64(1, this->num % other.num);
        }
        int64 operator%=(int64 &other)
        {
            *this = *this % other;
            return (*this)
        }
        friend std::ostream& operator<<(std::ostream &out, const int64 &n)
        {
            if (n.sign == -1) out << "-";
            out << n.num;
            return out;
        }
        bool operator==(int64 &other)
        {
            return ((this->sign == other.sign) && (this->num == other.num));
        }
        bool operator!=(const uint64 &other)
        {
            return !(*this == other);
        }
        bool operator<(int64 &other)
        {
            if (this->sign != other.sign)
                return this->sign == -1;
            else
            {
                if (this->sign == 1) return (this->num < other.num);
                else return (this->num > other.num);
            }
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