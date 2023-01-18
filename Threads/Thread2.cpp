#include <iostream>
#include <chrono>
#include <thread>

void fun1(int val)
{

    while (val --> 0)
    {
        std::cout << val << " = Fun_One" << std::endl;
    }
}

void fun2()
{

    std::cout << "Fun_Two" << std::endl;
}

int main()
{
    std::thread t1(fun1, 10);
    std::thread t2(fun2);

    t1.join();
    t2.join();

    std::cout << "Fun" << std::endl;
}