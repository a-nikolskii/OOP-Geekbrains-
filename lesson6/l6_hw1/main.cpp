#include <iostream>

int main()
{
    int number = 0;
    bool validate = true;

    do {
        validate = true;
        std::string inputStr;
        std::cout << "Enter integer> ";
        getline(std::cin, inputStr);
        for (auto it = inputStr.begin(); it != inputStr.end(); ++it ){
            if (!std::isdigit(*it)){
                validate =  false;
                std::cout << "Input Error! ";
                break;
            }
        }
        if (validate){
            number = std::stoi(inputStr);
        } else continue;
    } while (!validate);

    std::cout << "Your entred number is " << number << std::endl;

    return 0;
}
