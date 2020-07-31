#include <iostream>

std::ostream& endll(std::ostream& stream) {
    stream << "\n\n";
    stream.flush();
    return stream;
}

int main()
{
    std::cout << "+++++++++++" <<endll << "+++++++++++" << std::endl;
    return 0;
}
