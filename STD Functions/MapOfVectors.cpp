#include <iostream>
#include <vector>
#include <iterator>
#include <functional>
#include <map>

// #pragma once

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

    void RegisterCallback(std::function<int()> Function)
    {
        while (itrMap != MapFn.end())
        {
            itrMap->second.push_back(Function);
            itrMap++;
        }
    }

    void CallEveryone()
    {
        int i=0, j=0, arr[4][5];
        for (auto &mapItr : MapFn)
        {
            // std::cout << "Value Of The Key "<< mapItr.first << "Are : ";
            for (auto &vectorItr : mapItr.second)
            {
                arr[i][j++]= vectorItr();
            }
            j=0;
            i++;
        }

        // for (itrMap = MapFn.begin(); itrMap != MapFn.end(); itrMap++)
        // {
        //     std::cout << "Values of the Key \"" << itrMap->first << "\" : ";
        //     for (auto itrVector = itrMap->second.begin(); itrVector != itrMap->second.end(); itrVector++)
        //     {
        //         std::cout << (itrVector) << " ";
        //     }
        //     std::cout << std::endl;
        // }
    }
};


int Feed()
{
    int value;
    std::cin >> value;
    std::cout << "OK" << std::endl;
    return value;
}

int main()
{
    Map Obj;
    
    int n = 4;
    int size = 0;

    std::cout << "Enter The Size Of The Vector\n";
    std::cin >> size;
    std::cout << "Enter " << size << " Values Of The Vector\n";
    // while ((size--) != 0)
    // {
    //     Obj.RegisterCallback(Feed);
    //     Obj.CallEveryone();
    // }
    Obj.RegisterCallback(Feed);

    Obj.CallEveryone();
}