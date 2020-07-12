#include <iostream>
#include <cmath>

class Power {
    float base = 1;
    float exponent = 0;
public:
    Power(){};
    Power(const float& base, const float& exponent) : base(base), exponent(exponent){}
    void set (float base_, float exponent_){
        base = base_;
        exponent = exponent_;
    }
    double calculate () {
        return pow(base, exponent);
    }
};




int main(int argc, char *argv[])
{
    Power y;
    Power x(2, 2.3);
    std::cout << y.calculate() << std::endl;
    return 0;
}
