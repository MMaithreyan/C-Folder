#include <iostream>
#include <map>
#include <functional>
#include <iterator>

using std ::cin;
using std ::cout;
using std ::endl;
using std ::function;
using std ::iterator;
using std ::map;

int main();
void EnterValues();
int value1 = 0;
int value2 = 0;
int flag = 0;

void ReadInputValues()
{
    map<int, function<void()>> dataStore;
    map<int, function<void()>>::iterator itr;

    function<void()> enterValues = EnterValues;
    function<void()> Main = main;

    dataStore[0] = EnterValues;
    dataStore[1] = Main;

    int choice = 0;

    cout << "1.Enter values ." << endl
         << "2.Back" << endl;
    cout << "Enter operation to perform : ";
    cin >> choice;

    for (itr = dataStore.begin(); itr != dataStore.end(); itr++)
    {
        if (choice == itr->first)
        {
            itr->second();
            break;
        }
    }
}

void EnterValues()
{
    cout << "1. Enter value1 ." << endl
         << "2. Enter value2 ." << endl
         << "3. Back ." << endl;
    int choice = 0;

    cout << "Enter choice for operation : ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "Enter value1 = ";
        cin >> value1;
        EnterValues();
    }

    else if (choice == 2)
    {
        cout << "Enter value2 = ";
        cin >> value2;
        EnterValues();
    }

    else if (choice == 3)
    {
        EnterValues();
    }
}

void DisplayValues()
{
    cout << "Value 1 = " << value1 << "." << endl
         << "Value 2 = " << value2 << "." << endl
         << endl;
    main();
}

void ResetValues()
{
    value1 = 0;
    value2 = 0;
    main();
}

void ExitCode()
{
    flag = 1;
    main();
}

int main()
{
    static map<int, function<void()>> Menu;
    static map<int, function<void()>>::iterator itr;

    static function<void()> readData = ReadInputValues;
    static function<void()> ViewOutputValues = DisplayValues;
    static function<void()> resetValues = ResetValues;
    static function<void()> exit = ExitCode;

    Menu[1] = readData;
    Menu[2] = ViewOutputValues;
    Menu[3] = resetValues;
    Menu[4] = exit;

    int choice = 0;

    while (flag == 0)
    {
        cout << "1.Store data ." << endl
             << "2.Display data ." << endl
             << "3.Reset data ." << endl
             << "4.Exit ." << endl;

        cout << "Enter operation to perform : ";
        cin >> choice;

        for (itr = Menu.begin(); itr != Menu.end(); itr++)
        {
            if (choice == itr->first)
            {
                itr->second();
                break;
            }
        }
    }
}