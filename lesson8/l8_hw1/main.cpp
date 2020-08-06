#include <iostream>

int my_div (int numerator, int denominator) {
        if (denominator == 0) {
                throw "Division by zero";
        }
        else {
                int sign_num = 1;
                int sign_denom = 1;

                if (numerator < 0) {
                        sign_num = -1;
                        numerator = abs(numerator);
                }
                if (denominator < 0) {
                        sign_denom = -1;
                        denominator = abs(denominator);
                }

                int i = 0;
                while (numerator >= denominator) {
                        numerator -= denominator;
                        ++i;
                }
                return (i * sign_num * sign_denom);
        }

}


int main(int argc, char *argv[])
{

    try {
        std::cout << my_div(5, -3) << std::endl;
    }
    catch (const char* ex) {
        std::cout << ex << std::endl;
    }

    try {
        std::cout << my_div(-5, 0) << std::endl;
    }
    catch (const char* ex) {
        std::cout << ex << std::endl;
    }



    return 0;
}
