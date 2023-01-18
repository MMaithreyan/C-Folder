#include <iostream>
int main()
{
    int a = 10;
    auto display = [=]()
    {
        // a = 15;
        std::cout << a << std::endl;
    };
    display();
    std::cout << a;
}