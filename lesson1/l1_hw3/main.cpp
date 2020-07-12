#include <iostream>
const int SIZE = 10;

class Stack {
    int* arr;
    int lenght = 0;
public:
    Stack() {
        arr = new int[SIZE];
    }

    explicit Stack(int a){
        arr = new int[SIZE];
        arr[lenght++] = a;
    }

    Stack (const Stack & obj) {
        this->arr = new int[SIZE];
        for (int i = 0; i < SIZE; ++i) {
            this->arr[i] = obj.arr[i];
        }
    }

    Stack& operator = (const Stack& obj){
        if (& obj == this ) return *this; // проверка на присваивание самому себе
        delete [] arr; // иначе произойдет утечка памяти, если объект уже существует
        for (int i = 0; i < SIZE; ++i) {
            this->arr[i] = obj.arr[i];
        }
        return *this;
    }

    ~Stack(){
        delete [] arr;
    }

    void reset () {
        lenght = 0;
        for (int i = 0; i < SIZE; ++i) {
            arr[i] = 0;
        }
    }

    bool push (int a) {
        if (lenght == SIZE) return false;
        arr[lenght++] = a;
        return true;
    }

    int pop() {
        if (lenght == 0 ) {
            std::cout << "Stack is empty!" << std::endl;
            return 0;
        }
        else return arr[lenght--];
    }

    void print() {
        std::cout << "{";
        for (int i = 0; i < lenght; ++i) {
            if (i == lenght - 1) std::cout << arr[i];
            else std::cout << arr[i] << ", ";
        }
        std::cout << "}";
        std::cout << std::endl;
    }
};



int main(int argc, char *argv[])
{
    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();


    return 0;
}
