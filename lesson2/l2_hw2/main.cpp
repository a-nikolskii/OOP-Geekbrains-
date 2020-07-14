#include <iostream>

class Fruit {
protected:
    std::string name;
    std::string color;
public:
    Fruit (std::string name,
           std::string color) : name(name), color(color) {}

    std::string getName () const {return name;}
    std::string getColor () const {return color;}
};


class Apple : public Fruit {
public:
    Apple () : Fruit ("apple", "red") {}
    Apple (std::string color) : Fruit ("apple", color) {}
    Apple (std::string name, std::string color) : Fruit (name + " apple", color) {}

};


class Banana : public Fruit {
public:
    Banana () : Fruit ("banana", "yellow") {}
    Banana (std::string color) : Fruit ("banana", color) {}
    Banana (std::string name, std::string color) : Fruit (name + " banana", color) {}
};


class GrannySmith : public Apple {
public:
    GrannySmith () : Apple ("Granny Smith", "green") {}
    GrannySmith (std::string color) : Apple ("Granny Smith", color) {}
};


int main()
{
Apple a("red");
Banana b;
GrannySmith c;

std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

return 0;
}
