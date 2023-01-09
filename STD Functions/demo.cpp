#include <iostream>
#include <map>
#include <vector>
#include <functional>
#include <iterator>

class MapOfVectorFunctions
{
private:
    std::map<int, std::vector<std::function<int()>>> student;

public:
    MapOfVectorFunctions()
    {
        student[1] = vec1;
        student[2] = vec2;
    }

    std::vector<std::function<int()>> vec1;
    std::vector<std::function<int()>> vec2;

    std::map<int, std::vector<std::function<int()>>>::iterator MapItr;
    std::vector<std::function<int()>>::iterator VectorItr;
};

int Read()
{
    int value;
    std::cin >> value;
    return value;
}

int main()
{

    MapOfVectorFunctions MapObject;

    int VectorSize;
    std::cin >> VectorSize;


}
