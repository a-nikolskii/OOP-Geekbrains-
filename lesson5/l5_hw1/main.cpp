#include <iostream>

template <class Type>
class Pair1 {
private:
    Type m_first;
    Type m_second;
public:
    Pair1 (const Type& first,
           const Type& second) : m_first(first), m_second(second) {}

    Pair1 (const Pair1& obj) : m_first(obj.first()), m_second(obj.second()) {}

    Type first() const {return m_first;}

    Type second() const {return m_second;}

    void swap (Pair1& obj) {
        std::swap(m_first, obj.first());
        std::swap(m_second, obj.second());
    }
};

template <class Type>
bool operator< (const Pair1<Type>& p1, const Pair1<Type>& p2) {
    if (p1.first() < p2.first()) {return true;}
    else if (p2.first() < p1.first()) {return false;}
    else if (p1.second() < p2.second()) {return true;}
    return false;
}

template <class Type>
bool operator> (const Pair1<Type>& p1, const Pair1<Type>& p2) {
    return p2 < p1;
}

template <class Type>
bool operator== (const Pair1<Type>& p1, const Pair1<Type>& p2) {
    if (p1.first() == p2.first() && p1.second() == p2.second())
        return true;
    return false;
}

template <class  Type>
bool operator!= (const Pair1<Type>& p1, const Pair1<Type>& p2) {
    return !(p1 == p2);
}

template <class Type>
bool operator<= (const Pair1<Type>& p1, const Pair1<Type>& p2) {
    return !(p1 > p2);
}

template <class Type>
bool operator>= (const Pair1<Type>& p1, const Pair1<Type>& p2) {
    return !(p1 < p2);
}



int main(int argc, char *argv[])
{
    Pair1<int> p1(6, 9);
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2(3.4, 7.8);
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
    return 0;

}
