#include <iostream>
using namespace std;

class Pass
{
public:
    void run()
    {
        cout << "This is class A : no values"<< std::endl;
    }
     void run(int par)
    {
        cout << "This is class B with value : " << par << std::endl;
    }
};

int main()
{
    Pass obj;
    obj.run(55);
    obj.run();
}
