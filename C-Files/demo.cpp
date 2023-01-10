#include <iostream>

using namespace std;

void run(int value)
{
    value = value + 10;
    cout << value << "  a ";
}
void ran(int value)
{
    value = value + 10;
    cout << value << " b ";
}

int main()
{
    int value = 10;
    int *b = &value;

    run(value);
    cout << value << " c ";

    ran(*b);
    cout << value << " d ";
}