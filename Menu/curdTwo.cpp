#include <iostream>
#include <map>
#include <vector>

void function1()
{
    std::cout << "Function 1 called." << std::endl;
}

void function2()
{
    std::cout << "Function 2 called." << std::endl;
}

void function3()
{
    std::cout << "Function 3 called." << std::endl;
}

int main()
{
    std::string key;

    std::map<std::string, std::vector<void (*)()>> function_map;
    function_map["1"].push_back(function1);
    function_map["2"].push_back(function2);
    function_map["3"].push_back(function3);

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
        std::cin >> key;

        // Check if the key exists in the map
        if (function_map.count(key) > 0)
        {
            // Call the functions associated with the key
            for (auto func : function_map[key])
                func();
        }
        else
        {
            std::cout << "Invalid key." << std::endl;
        }

        return 0;
    }
}
