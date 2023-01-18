#include <iostream>
#include <array>

int main()
{
    const int size = 5;

    std::array<int, size> Test;

    std::cout << "`````````````````````````````````" << std::endl;
    std::cout << "        Give The Input Data" << std::endl;
    std::cout << "`````````````````````````````````" << std::endl;

    for (int i = 0; i < size; i++)
    {
        std::cin >> Test.at(i);
    }
    std::cout << "`````````````````````````````````" << std::endl;
    std::cout << "        Print The Given Data" << std::endl;
    std::cout << "`````````````````````````````````" << std::endl;

    for (auto i = Test.begin(); i < Test.end(); i++)
    {
        std::cout << *i << std::endl;
    }
    std::cout << "`````````````````````````````````" << std::endl;

    std::cout << "Data At Begin =   " << Test.begin() << std::endl;
    std::cout << "Data At End   =   " << Test.end() << std::endl;
    std::cout << "Data At Front =   " << Test.front() << std::endl;
    std::cout << "Data At End   =   " << Test.end() << std::endl;
    std::cout << "Data Size     =   " << Test.size() << std::endl;
    std::cout << "Size Of Data  =   " << sizeof(Test) << std::endl;

    Test.fill(10);
    std::cout << "`````````````````````````````````" << std::endl;
    std::cout << " Print The Given Data Afer Fill" << std::endl;
    std::cout << "`````````````````````````````````" << std::endl;

    for (auto i = Test.begin(); i < Test.end(); i++)
    {
        std::cout << *i << std::endl;
    }
}