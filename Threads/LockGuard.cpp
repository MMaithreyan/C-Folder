#include <iostream>
#include <mutex>
#include <thread>

std::mutex security;
int Value = 0;

void AddMoney(const char* Number, int loop)
{
    std::lock_guard<std::mutex> lock(security);

    for (int i = 0; i < loop; i++)
    {
        Value++;
        std::cout << Number << " = " << Value << std::endl;
    }
}

int main()
{
    std::thread ThreadOne(AddMoney, "T1", 10);
    std::thread ThreadTwo(AddMoney, "T2", 10);

    ThreadOne.join();
    ThreadTwo.join();
}