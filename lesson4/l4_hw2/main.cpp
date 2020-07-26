#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[])
{
    std::vector<int> vector {1,2,1,1,3,3,3,4,5,4};
    std::sort(vector.begin(), vector.end());
    auto last = std::unique(vector.begin(), vector.end());
    vector.erase(last, vector.end());

    std::cout << vector.size() << std::endl;

    return 0;
}
