#include <iostream>

class RGBA {
  std::uint8_t m_red;
  std::uint8_t m_green;
  std::uint8_t m_blue;
  std::uint8_t m_alfa;
public:
  explicit RGBA (std::uint8_t m_red = 0,
                 std::uint8_t m_green = 0,
                 std::uint8_t m_blue = 0,
                 std::uint8_t m_alfa = 255) :
      m_red(m_red), m_green(m_green), m_blue(m_blue), m_alfa(m_alfa){}

  void print() {
      std::cout << "m_red: " << (unsigned) m_red << std::endl;
      std::cout << "m_green: " << (unsigned) m_green << std::endl;
      std::cout << "m_blue: " << (unsigned) m_blue << std::endl;
      std::cout << "m_alfa: " << (unsigned) m_alfa << std::endl;
      std::cout << std::endl;
  }
};


int main(int argc, char *argv[])
{
    RGBA obj1, obj2(2,3,4,254);
    obj1.print();
    obj2.print();

    return 0;
}
