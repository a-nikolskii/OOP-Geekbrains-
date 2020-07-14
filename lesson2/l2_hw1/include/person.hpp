#include <iostream>

class Person {
protected:
        std::string name;
        std::string surname;
        std::string sex;
        float weight;
public:
        Person (std::string name,
                        std::string surname,
                        std::string sex,
                        float weight);

        Person& setName (std::string name_);

        Person& setSurname (std::string surname_ );

        Person& setSex (std::string sex_);

        Person& setWeight (float weight_);

        friend std::ostream& operator << (std::ostream& out, const Person& obj);

        void print ();

        std::string getName ()const;
        std::string getSurname () const;
        std::string getSex () const;
        float getWeight () const;

};




class Student : public Person {
        unsigned year;
        static int studentCount;
public:
        Student (std::string name,
                        std::string surname,
                        std::string sex,
                        float weight,
                        unsigned year);

        Student (const Student& obj);

        // оператор присваивания для студентов вроде как не имеет смысла)
        // поэтому не пеереопределяю

        ~Student();

        void setYear(unsigned year_);

        void increaseYear();

        unsigned getYear () const;

        friend std::ostream& operator << (std::ostream& out, const Student& obj);

        void print ();

        static int getStudentCount();

};
