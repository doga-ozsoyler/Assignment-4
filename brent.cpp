#include "brent.h"

using namespace std;

int Brent::h1(int key) const{

    return key % data_vec.size();

}

int Brent::h2(int key) const{

    int inc = (key / data_vec.size()) % data_vec.size();
    
    if(inc == 0)
    {
        return 1;
    }
    else
    {
        return inc;
    }
}

Brent::Brent(int table_size){

    for(int i = 0; i < table_size; i++){
        auto anyEntry = entry();
        anyEntry.data = -1;
        data_vec.push_back(anyEntry);
    }

}


void Brent::insert(int new_data){

}



int Brent::find_num_probes(int key) const{

}



double Brent::find_average_num_probes() const{

}