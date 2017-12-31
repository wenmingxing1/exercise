#include<iostream>
#include<memory>
#include<vector>
#include<fstream>

using namespace std;

shared_ptr<vector<int>> dynamic_vector_generator_sptr()
{
    return make_shared<vector<int>>();
}

void dynamic_vector_processor_sptr(shared_ptr<vector<int>> sptr_vi, ifstream& ifs)
{
    int i;
    while (ifs >> i) sptr_vi->push_back(i);
}

void dynamic_vector_printer_sptr(shared_ptr<vector<int>> sptr_vi)
{
    for (const auto& vi : *sptr_vi) cout << vi << " ";
    cout << endl;
}

int main()
{
    ifstream ifs("./data/input.txt");
    shared_ptr<vector<int>> vec = dynamic_vector_generator_sptr();
    dynamic_vector_processor_sptr(vec, ifs);
    dynamic_vector_printer_sptr(vec);

    return 0;
}
