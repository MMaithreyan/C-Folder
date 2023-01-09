#include <iostream>
#include <vector>
#include <iterator>
#include <functional>
#include <map>

// #pragma once

int arr[4][5] = {{0}, {0}};

class Map
{
private:
    std::map<int, std::vector<std::function<int()>>> MapFn;

public:
    Map()
    {
        // MapFn.insert(pair<int ,vector<std::function<int()>>>(1,{1,2,3,4}));
        MapFn[1] = Vector1;
        MapFn[2] = Vector2;
        MapFn[3] = Vector3;
        MapFn[4] = Vector4;

        itrMap = MapFn.begin();
    }

    std::map<int, std::vector<std::function<int()>>>::iterator itrMap;

    std::vector<std::function<int()>> Vector1;
    std::vector<std::function<int()>> Vector2;
    std::vector<std::function<int()>> Vector3;
    std::vector<std::function<int()>> Vector4;

    std::vector<std::function<int()>>::iterator itrVector;
 

    void RegisterCallback(std::function<int()> Function)
    {
        while (itrMap != MapFn.end())
        {
            itrMap->second.push_back(Function);
            itrMap++;
        }
    }

    void CallEveryone(int VectorSize)
    {
        // std::cout << itrMap->
        static int i = 0;
        std::cout << "Enter " << VectorSize << " Vector Values \n";
        int j = 0;
        for (auto &mapItr : MapFn)
        {
            for (auto &vectorItr : mapItr.second)
            {
                vectorItr();
            }
        }
        i++;
    }

    void GetValues(int VectorSize)
    {
        std::cout << "The Vector Values are : \n";

        for (int itr1 = 0; itr1 < 4; itr1++)
        {
            for (int itr2 = 0; itr2 < VectorSize; itr2++)
            {
                std::cout << arr[itr1][itr2] << " ";
            }
            std::cout << std::endl;
        }
    }
};
// for (itrMap = MapFn.begin(); itrMap != MapFn.end(); itrMap++)
// {
//     std::cout << "Values of the Key \"" << itrMap->first << "\" : ";
//     for (auto itrVector = itrMap->second.begin(); itrVector != itrMap->second.end(); itrVector++)
//     {
//         std::cout << (itrVector) << " ";
//     }
//     std::cout << std::endl;
// }

int Feed()
{
    int value;
    std::cin >> value;
    return value;
}

int main()
{
    Map Obj;

    int VectorSize = 0, VectorCount = 4;

    std::cout << "Enter The size of the Vector Values\n";
    std::cin >> VectorSize;

    while ((VectorCount--) != 0)
    {
        Obj.RegisterCallback(Feed);
        Obj.CallEveryone(VectorSize);
    }
    Obj.GetValues(VectorSize);
}