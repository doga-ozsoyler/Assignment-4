#include <iostream>
#include <fstream>
#include "brent.cpp"

using namespace std;

int main(){

    Brent list(11);

    for(int i = 0; i < list.data_vec.size(); i++)
    {
        cout << i << "d=" << list.data_vec[i].data <<
        "v=" << list.data_vec[i].valid << " ";
    }

    cout << endl;


    return 0;
}