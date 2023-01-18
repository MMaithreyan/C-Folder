#include <pthread.h>
#include <iostream>
#include <mutex>

std::mutex Security;

void *ThreadFunction1(void *arguments)
{
    Security.lock();

    std::cout << "Thread  Running" << std::endl;
    static int amount = 0;
    amount++;
    std::cout << amount << std::endl;

    Security.unlock();
    return 0;
}

int main()
{
    pthread_t thread1;
    pthread_t thread2;

    std::cout << "Main() = Calling Thread" << std::endl;

    pthread_create(&thread1, NULL, ThreadFunction1, NULL);
    pthread_create(&thread2, NULL, ThreadFunction1, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
}