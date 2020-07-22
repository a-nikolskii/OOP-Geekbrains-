#include <iostream>

class Fraction {
private:
    int32_t m_numerator;
    uint32_t m_denomenator;

    // Функция для нахождения наибольшего общего делителя
    // Нужна для сокращения дроби
    int NOD (uint32_t a, uint32_t b) const {
        while (a != 0 && b!=0) {
            if (a > b)  a = a % b;
            else b = b % a;
        }
        return a + b;
    };

public:
    explicit Fraction (uint32_t numerator,
              uint32_t denomenator) : m_numerator(numerator), m_denomenator(denomenator) {
        if (m_denomenator == 0) {
            std::cout << "Знаменатель должен быть отличен от 0" << std::endl;
            this->~Fraction();
        }
    }

    const Fraction operator+ (const Fraction& obj) const {
        int32_t numerator;
        uint32_t denomenator;
        numerator = m_numerator * obj.m_denomenator + obj.m_numerator * m_denomenator;
        denomenator = m_denomenator * obj.m_denomenator;
        int nod = NOD (abs(numerator), denomenator);
        Fraction sum (numerator / nod, denomenator / nod); // тут получили несократимую дробь
        return sum;
    }

    const Fraction operator- (const Fraction& obj) const {
        int32_t numerator;
        uint32_t denomenator;
        numerator = m_numerator * obj.m_denomenator - obj.m_numerator * m_denomenator;
        denomenator = m_denomenator * obj.m_denomenator;
        int nod = NOD (abs(numerator), denomenator);
        Fraction diff (numerator / nod, denomenator / nod); // тут получили несократимую дробь
        return diff;
    }

    const Fraction operator* (const Fraction& obj) const {
        int32_t numerator;
        uint32_t denomenator;
        numerator = m_numerator * obj.m_numerator;
        denomenator = m_denomenator * obj.m_denomenator;
        int nod = NOD (abs(numerator), denomenator);
        Fraction mult (numerator / nod, denomenator / nod); // тут получили несократимую дробь
        return mult;
    }

    const Fraction operator/ (const Fraction& obj) const {
        int32_t numerator;
        uint32_t denomenator;
        numerator = m_numerator * obj.m_denomenator;
        denomenator = m_denomenator * obj.m_numerator;
        int nod = NOD (abs(numerator), denomenator);
        Fraction div (numerator / nod, denomenator / nod); // тут получили несократимую дробь
        return div;
    }

    bool operator< (const Fraction& obj) const {
        return (m_numerator * obj.m_denomenator < obj.m_numerator * m_denomenator);
    }

    bool operator> (const Fraction& obj) const {
        return obj < (*this);
    }

    bool operator== (const Fraction& obj) const {
        return !((*this < obj) || (obj < *this));
    }

    bool operator!= (const Fraction& obj) const {
        return ((*this < obj) || (obj < *this));
    }

    bool operator<= (const Fraction& obj) const {
        return !(*this > obj);
    }

    bool operator>= (const Fraction& obj) const {
        return !(*this < obj);
    }

    friend const Fraction operator- (const Fraction& obj);

    friend std::ostream& operator<< (std::ostream& out, const Fraction& obj);
};

const Fraction operator- (const Fraction& obj) {
    Fraction negative (-obj.m_numerator, obj.m_denomenator);
    return negative;
}

std::ostream& operator<< (std::ostream& out, const Fraction& obj) {
    out << obj.m_numerator << "/" << obj.m_denomenator;
    return out;
}




int main(int argc, char *argv[])
{
    Fraction a (3,4);
    const Fraction b (1,2);

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << std::endl;

    std::cout << "a+b: " << a + b << std::endl;
    std::cout << "b-a: " << b - a << std::endl;
    std::cout << "a*b: " << a * b << std::endl;
    std::cout << "a/b: "<< a / b << std::endl;
    std::cout << "a<b: "<< (a < b) << std::endl;
    std::cout << "a>b: "<< (a > b) << std::endl;
    std::cout << "a=b: "<< (a == b) << std::endl;
    std::cout << "a!=b: "<< (a != b) << std::endl;
    std::cout << "a>=b: "<< (a >= b) << std::endl;
    std::cout << "a<=b: "<< (a <= b) << std::endl;
    std::cout << "-a: "<< (-a) << std::endl;
    return 0;
}
