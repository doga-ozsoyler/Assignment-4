#include "brent.h"

using namespace std;


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