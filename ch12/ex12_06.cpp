#include<iostream>
#include<vector>
#include<string>
#include<new>
#include<memory>
#include<fstream>

using namespace std;

//Éú³Évector<int>
vector<int>* dynamic_vector_generator()
{
    vector<int>* ptr_v = new vector<int> ();
    return ptr_v;
}

void dynamic_vector_processor(vector<int>* ptr_v, ifstream& ifs)
{
    int i;
    cout << "plz enter:" << endl;
    while (ifs >> i) ptr_v->push_back(i);
}

void dynamic_vector_printer(vector<int>* ptr_v)
{
    for (const auto& e : *ptr_v) cout << e << " ";
    cout << endl;
}

int main()
{
    ifstream ifs("./data/input.txt");
    vector<int>* vec = dynamic_vector_generator();
    dynamic_vector_processor(vec, ifs);
    dynamic_vector_printer(vec);

    delete vec;     //ÊÍ·Åvec

    return 0;
}
