#include <iostream>
#include <cmath>

class Figure {
public:
    virtual float area () const = 0;
};


class Parallelogram : public Figure {
protected:
    float m_side_a;
    float m_side_b;
    float m_angle;
public:
    Parallelogram(float side_a,
                  float side_b,
                  float angle) : m_side_a(side_a), m_side_b(side_b), m_angle(angle) {}

    float area () const override {
        return m_side_a * m_side_b * sin(m_angle * M_PI / 180);
    }

    void set_side_a (float side_a) {m_side_a = side_a;}
    void set_side_b (float side_b) {m_side_b = side_b;}
    void set_angle (float angle) {m_angle = angle;}
    float get_side_a () const {return m_side_a;}
    float get_side_b () const {return m_side_b;}
    float get_angle () const {return m_angle;}
    virtual ~Parallelogram();
};


class Circle : public Figure {
private:
    float m_radius;
public:
    Circle (float radius) : m_radius(radius) {}

    float area() const override {
        return M_PI * pow(m_radius, 2);
    }

    void set_radius (float radius) {m_radius = radius;}
    float get_radius () const {return m_radius;}
};


class Rectangle : public Parallelogram {
public:
    Rectangle (float side_a,
               float side_b) : Parallelogram (side_a, side_b, 90) {}

    float area() const override {return m_side_a * m_side_b;}
private:
    void set_angle (float angle) {m_angle = angle;}
    // нужно запретить функцию set_angle()
    // но тут конечно нарушается критерий Барабары Лисков
    ~Rectangle();
};


class Square : Parallelogram {
public:
    Square (float side) : Parallelogram (side, side, 90) {}
    float area() const override {return pow(m_side_a, 2);}
private:
    void set_angle (float angle) {m_angle = angle;}
    void set_side_b (float side_b) {m_side_b = side_b;}
    float get_side_b () const {return m_side_b;}
    // нужно запретить функцию set_angle()
    // нужно запретить функцию set_side_b()
    // нужно запретить функцию get_side_b()
    ~Square();

};


class Rhombus : public Parallelogram {
public:
    Rhombus (float side_a,
               float angle) : Parallelogram (side_a, side_a, angle) {}

    float area() const override {return pow(m_side_a, 2) * sin(m_angle * M_PI / 180);}
private:
    void set_side_b (float side_b) {m_side_b = side_b;}
    float get_side_b () const {return m_side_b;}
    // нужно запретить функцию set_side_b()
    // нужно запретить функцию get_side_b()
    ~Rhombus();

};



int main(int argc, char *argv[])
{


    return 0;
}
