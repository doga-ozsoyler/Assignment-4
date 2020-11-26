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

    list.insert(27);
    list.insert(18);
    list.insert(29);
    list.insert(28);
    list.insert(39);
    list.insert(13);
    list.insert(16);
    list.insert(42);
    list.insert(17);

    for(int i = 0; i < list.data_vec.size(); i++)
    {
        cout << i << "d=" << list.data_vec[i].data <<
        "v=" << list.data_vec[i].valid << " ";
    }
    cout << endl;

    cout << "27 probe= " << list.find_num_probes(27) << endl;
    cout << "18 probe= " << list.find_num_probes(18) << endl;
    cout << "29 probe= " << list.find_num_probes(29) << endl;
    cout << "28 probe= " << list.find_num_probes(28) << endl;
    cout << "39 probe= " << list.find_num_probes(39) << endl;
    cout << "13 probe= " << list.find_num_probes(13) << endl;
    cout << "16 probe= " << list.find_num_probes(16) << endl;
    cout << "42 probe= " << list.find_num_probes(42) << endl;
    cout << "17 probe= " << list.find_num_probes(17) << endl;

    cout << "Average number of probes= " << list.find_average_num_probes() << endl;

    return 0;
}