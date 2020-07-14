#include "person.hpp"

Person::Person (std::string name,
                std::string surname,
                std::string sex,
                float weight) : name (name), surname (surname), sex (sex), weight (weight) {}

Person& Person::setName (std::string name_) {
        name = name_;
        return *this;
}

Person& Person::setSurname (std::string surname_ ) {
        surname = surname_;
        return *this;
}

Person& Person::setSex (std::string sex_) {
        sex = sex_;
        return *this;
}

Person& Person::setWeight (float weight_) {
        weight = weight_;
        return *this;
}

void Person::print () {std::cout << *this;}

std::string Person::getName () const {return name;}

std::string Person::getSurname () const {return surname;}

std::string Person::getSex () const {return sex;}

float Person::getWeight () const {return weight;}

/////////////////////////////////////////////////////////////////////////////////////////

Student::Student (std::string name,
                std::string surname,
                std::string sex,
                float weight,
                unsigned year) : Person (name, surname, sex, weight), year(year) {++studentCount; }

Student::Student (const Student& obj) : Person(obj.name, obj.surname, obj.sex, obj.weight){++studentCount;}

Student::~Student() {--studentCount;}

void Student::setYear(unsigned year_) {year = year_;}

void Student::increaseYear() { ++year;};

unsigned Student::getYear () const {return year;}

void Student::print () {std::cout << *this;}

int Student::getStudentCount () {return studentCount;}



int Student::studentCount = 0;



std::ostream& operator << (std::ostream& out, const Student& obj) {
    out << "name: " << obj.name << std::endl;
    out << "surname: " << obj.surname << std::endl;
    out << "sex: " << obj.sex << std::endl;
    out << "weight: " << obj.weight << std::endl;
    out << "year: " << obj.year << std::endl;
    return out;
}

std::ostream& operator << (std::ostream& out, const Person& obj) {
    out << "name: " << obj.name << std::endl;
    out << "surname: " << obj.surname << std::endl;
    out << "sex: " << obj.sex << std::endl;
    out << "weight: " << obj.weight << std::endl;
    return out;
}
