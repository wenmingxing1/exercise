#include<iostream>

using namespace std;

class if_then_else
{
    int operator()(bool b, int i, int j)
    {
        if (b)
            return i;
        else
            return j;
    }
};
