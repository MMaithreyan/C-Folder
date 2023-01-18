#include <iostream>
#include <mutex>
#include <thread>

std::mutex security;

void AddMoney(int *Amount)
{
    (*Amount)++;
    security.unlock();
}

int main()
{
    int value = 0;
    int *Amount = &value;

    std::thread ThreadOne(AddMoney, Amount);
    std::thread ThreadTwo(AddMoney, Amount);

    ThreadOne.join();
    ThreadTwo.join();

    std::cout << "main = " << *Amount << std::endl;
}