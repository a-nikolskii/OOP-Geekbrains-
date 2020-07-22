#include <iostream>

class Car {
private:
    std::string m_company;
    std::string m_model;
public:
    Car (std::string company,
         std::string model) : m_company(company), m_model(model) {
        std::cout << "Конструктор класса Car" << std::endl;
        std::cout << "Компания: " << m_company << std::endl;
        std::cout << "Модель: " << m_model << std::endl;
    }

    //virtual ~Car();
};


class PassengerCar : virtual public Car {
public:
    PassengerCar (std::string company, std::string model) : Car(company, model) {
        std::cout << "Конструктор класса PassengerCar" << std::endl;
    }
};


class Bus : virtual public Car {
public:
    Bus (std::string company, std::string model) : Car (company, model) {
        std::cout << "Конструктор класса Bus" << std::endl;
    }
};


class Minivan : public PassengerCar,  public Bus {
public:
    Minivan (std::string company, std::string model) :
        Car (company, model),
        PassengerCar(company, model),
        Bus (company, model)
    {
        std::cout << "Конструктор класса Minivan" << std::endl;
    }
};




int main(int argc, char *argv[])
{

    Car car ("ford", "focus");
    std::cout << std::endl;

    PassengerCar pas_car ("volkswagen", "golf");
    std::cout << std::endl;

    Bus bus ("hundai", "universe");
    std::cout << std::endl;

    Minivan ("hundai", "h350");
    std::cout << std::endl;

    return 0;
}
