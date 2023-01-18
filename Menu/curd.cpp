#include <iostream>
#include <map>
#include <vector>
using namespace std;
std::map<int, std::vector<int>> student;

int main()
{
    while (1)
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

        student.insert(pair<int,> choice);
    }
}