#include <iostream>
using namespace std;

class Animal
{
public:
    void ate()
    {
        cout << "Eating...";
    }
};

class Dog : public Animal
{
public:
    void eat()
    {
        cout << "Eating bread...";
    }
};

int main(void)
{
    Dog obj;
    obj.ate();
    return 0;
}