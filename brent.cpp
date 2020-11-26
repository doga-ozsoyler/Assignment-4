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

int Brent::find_moving_cost(int h1, int h2) const{

    int cost = 1;
    int i = h1;
    int noLoop = 0;
    while(data_vec[i].valid != false && noLoop <= data_vec.size())
    {
        i = i + h2;
        cost++;
        noLoop++;
    }
    if(noLoop > data_vec.size())
    {
        cout << "List is full!!!" << endl;
        return 0;
    }

    return cost;

}


void Brent::insert(int new_data){


}



int Brent::find_num_probes(int key) const{

}



double Brent::find_average_num_probes() const{

}