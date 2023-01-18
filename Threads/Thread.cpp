#include <iostream>
#include <chrono>
#include <thread>

int evensum = 0;
int oddsum = 0;

void odd(int start, int end)
{

    for (int i = start; i <= end; i++)

    {
        if ((i & 1) == 1)
        {
            oddsum += i;
        }
    }
}

void even(int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if ((i & 1) == 0)
        {
            evensum += i;
        }
    }
}
int main()
{ 

    int start = 0, end = 1000000000;

    auto StartTime = std::chrono::high_resolution_clock::now();

    std::thread t1(odd, start, end);
    std::thread t2(even, start, end);

    t1.join();
    t2.join();
    
    // odd(start, end);
    // even(start, end);

    auto EndTime = std::chrono::high_resolution_clock::now();
    auto total = std::chrono::duration_cast<std::chrono::seconds>(EndTime - StartTime);

    std::cout << "Odd : " << oddsum << std::endl;
    std::cout << "Even : " << evensum << std::endl;
    std::cout << "Sec :" << total.count() << std::endl;
}