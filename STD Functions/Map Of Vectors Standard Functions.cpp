#include <iostream>
#include <vector>
#include <iterator>
#include <functional>
#include <map>

int Feed()
{
    int value = 0;
    std::cin >> value;
    // std::cout << "OK" << std::endl;
    return value;
}

int main()
{
    Map Obj;

    int vectorSize = 0, vectorCount = 4;

    std::cout << "Enter The size of the Vector Values\n";
    std::cin >> vectorSize;

    Obj.RegisterCallback(Feed, 1);
    Obj.RegisterCallback(Feed, 2);
    Obj.RegisterCallback(Feed, 1);
    Obj.RegisterCallback(Feed, 1);

    //Obj.CallEveryone(2);

    // Obj.GetValues(vectorSize);
}



class Map
{
private:
    std::map<int, std::vector<std::function<int()>>> MapFn;

public:
    Map()
    {
        MapFn[1] = Vector1;
        MapFn[2] = Vector2;
        MapFn[3] = Vector3;
        MapFn[4] = Vector4;
    }

    std::map<int, std::vector<std::function<int()>>>::iterator itrMap;

    std::vector<std::function<int()>> Vector1;
    std::vector<std::function<int()>> Vector2;
    std::vector<std::function<int()>> Vector3;
    std::vector<std::function<int()>> Vector4;

    std::vector<std::function<int()>>::iterator itrVector;

    void RegisterCallback(std::function<int()> Function, int key)
    {
        for (itrMap = MapFn.begin(); itrMap != MapFn.end(); itrMap++)
        {
            if (itrMap->first == key)
            {
                itrMap->second.push_back(Function);
            }
        }

       
    }

    void CallEveryone(int key)
    {
        for (auto &mapItr : MapFn)
        {
            if (mapItr.first == key)
            {
                for (auto &vectorItr : mapItr.second)
                {
                    vectorItr();
                }
            }
        }
    }
};