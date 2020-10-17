#include <iostream>
#include <cctype>

int CONST1 = 100;

class Ex {
private:
        int m_x;
public:
        Ex(int a) : m_x(a) {}
        int get_x() const{return m_x;}
};


class Bar{
private:
        int m_y;
public:
        Bar() : m_y(0) {}
        void set(int a) {
                if (a + m_y > CONST1) {
                        throw Ex (a + m_y);
                }
                else (m_y = a);
        }
};

int get_integer(){
    std::string input_str;
    bool is_digit;
    do {
        is_digit = true;
        std::cout << "Enter integer > ";
        getline(std::cin, input_str);
        for (auto it = input_str.begin(); it != input_str.end(); ++it) {
            if (!isdigit(*it)) is_digit = false;
        }
        if (!is_digit) continue;
        return std::stoi(input_str);
    } while (true);
}

int main(int argc, char *argv[])
{
    Bar bar;
    int input_number = 0;
    do {
        input_number = get_integer();
        std::cout << input_number << std::endl;
        try {
            bar.set(input_number);
        }
        catch(Ex ex){
            std::cout << "Error: a + y = " << ex.get_x() << std::endl;
        }
    } while (input_number != 0);

    return 0;
}
