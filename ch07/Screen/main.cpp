#include <iostream>
#include "Screen.h"

using namespace std;

int main()
{
    Screen myScreen(5,10,'X');
    myScreen.move(4,0).set('#').display(cout);
    cout << endl;

    myScreen.display(cout);
    cout << endl;

    return 0;
}
