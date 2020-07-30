#include <iostream>

template <class Type1, class Type2 >
class Pair {
private:
    Type1 m_first;
    Type2 m_second;
public:
    Pair (const Type1& first,
           const Type2& second) : m_first(first), m_second(second) {}

    Pair (const Pair& obj) : m_first(obj.first()), m_second(obj.second()) {}

    Type1 first() const {return m_first;}

    Type2 second() const {return m_second;}

    void swap (Pair& obj) {
        Pair tmp(obj);
        obj = *this;
        *this = tmp;
    }
};

template <class Type1, class Type2>
bool operator< (const Pair<Type1, Type2>& p1, const Pair<Type1, Type2>& p2) {
    if (p1.first() < p2.first()) {return true;}
    else if (p2.first() < p1.first()) {return false;}
    else if (p1.second() < p2.second()) {return true;}
    return false;
}

template <class Type1, class Type2>
bool operator> (const Pair<Type1, Type2>& p1, const Pair<Type1, Type2>& p2) {
    return p2 < p1;
}

template <class Type1, class Type2>
bool operator== (const Pair<Type1, Type2>& p1, const Pair<Type1, Type2>& p2) {
    if (p1.first() == p2.first() && p1.second() == p2.second())
        return true;
    return false;
}

template <class  Type1, class Type2>
bool operator!= (const Pair<Type1, Type2>& p1, const Pair<Type1, Type2>& p2) {
    return !(p1 == p2);
}

template <class Type1, class Type2>
bool operator<= (const Pair<Type1, Type2>& p1, const Pair<Type1, Type2>& p2) {
    return !(p1 > p2);
}

template <class Type1, class Type2>
bool operator>= (const Pair<Type1, Type2>& p1, const Pair<Type1, Type2>& p2) {
    return !(p1 < p2);
}



int main(int argc, char *argv[])
{

    Pair<int, double> p1(6, 7.8);
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair<double, int> p2(3.4, 5);
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    return 0;
}
