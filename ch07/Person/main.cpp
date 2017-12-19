#include <iostream>
#include "person.h"

using namespace std;

int main()
{
    Person person;
    cout << "Please input person's name and address:" << endl;
    read(cin, person);
    print(cout, person);

    return 0;
}
