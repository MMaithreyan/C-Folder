#include <iostream>
#include <map>
#include <functional>
#include <iterator>

using namespace std;
int main();
int valueOne, valueTwo = 0;
int dummy = 0;
int StoreData()
{
    int choice = 0;
    std::cout << "~~~~~~StoreData~~~~~~" << std::endl;
    std::cout << "1.Store data" << std::endl;
    std::cout << "2.Back" << std::endl;
    std::cout << "Enter Operation" << std::endl;
    std::cin >> choice;

    if (choice == 1)
    {
        std::cout << "Enter value one" << std::endl;
        std::cin >> valueOne;
        std::cout << "Enter value Two" << std::endl;
        std::cin >> valueTwo;
        StoreData();
    }
    else if (choice == 2)
    {
        main();
    }
    return 0;
}

int DisplayData()
{
    std::cout << "Value->1 = " << valueOne << std::endl;
    std::cout << "Value->2 = " << valueTwo << std::endl;
    return 0;
}
int ResetData()
{
    valueOne = 0, valueTwo = 0;
    std::cout << "value Resetted" << std::endl;
    return 0;
}
int Exit()
{
    std::cout << "exit" << std::endl;
    dummy = 1;
    return 0;
}

int main()
{
    std::map<int, std::function<int()>> Menu;
    std::map<int, std::function<int()>>::iterator Itr;

    while (dummy == 0)
    {
        std::cout << "`````Select Operations`````" << std::endl
                  << "1. Store Values" << std::endl
                  << "2. View Values" << std::endl
                  << "3. Reset Values" << std::endl
                  << "4. Exit " << std::endl
                  << "```````````````````````````" << std::endl;

        int choice = 0;

        std::cout << "`````Enter Choice`````" << std::endl;
        std::cin >> choice;

        function<int()> storeData = StoreData;
        function<int()> displayData = DisplayData;
        function<int()> resetData = ResetData;
        function<int()> exit = Exit;

        Menu[1] = storeData;
        Menu[2] = displayData;
        Menu[3] = resetData;
        Menu[4] = exit;

        int flag = Menu.count(choice);
        if (flag == 0)
        {
            std::cout << "INVALID KEY\n ENTER VALID KEY : ";
        }
        else
        {
            for (Itr = Menu.begin(); Itr != Menu.end(); Itr++)
            {
                if (Itr->first == choice)
                {
                    std::cout << Itr->second();
                    break;
                }
            }
        }
    }
}