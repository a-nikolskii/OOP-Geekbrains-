#include <iostream>
#include "person.hpp"


int main(int argc, char *argv[])
{
    Student ivanov {"Ivan", "Ivanov", "men", 72.7, 1};
    std::cout << ivanov << std::endl;
    std::cout << Student::getStudentCount() << std::endl;

    {
        Student petrov {"Petr", "Petrov", "men", 72.1, 2};
        std::cout << petrov << std::endl;
        std::cout << Student::getStudentCount() << std::endl;
    }


    std::cout << Student::getStudentCount() << std::endl;

    {
        Student petrov = ivanov;
        std::cout << Student::getStudentCount() << std::endl;

    }

    return 0;
}
