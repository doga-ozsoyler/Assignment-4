#include <iostream>
#include <fstream>
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
    int noLoop = 0;
    while(data_vec[h1].valid != false && noLoop <= data_vec.size())
    {
        h1 = (h1 + h2) % data_vec.size();
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

    if(data_vec[h1(new_data)].valid == false)
    {
        data_vec[h1(new_data)].data = new_data;
        data_vec[h1(new_data)].valid = true;
    }
    else
    {
        int new_dataCost = find_moving_cost( h1(new_data), h2(new_data) );

        if(new_dataCost != 0)
        {
            int newCost = 0;
            int oldCost = data_vec.size() + 5;
            int switchNum = -1;

            for(int i = 0, address = h1(new_data); i < new_dataCost; i++, address = address + h2(new_data))
            {
                newCost = find_moving_cost( h1(data_vec[address].data), h2(data_vec[address].data) ) + i;

                if(newCost < new_dataCost && newCost < oldCost)
                {
                    switchNum = data_vec[address].data;
                    oldCost = newCost;
                }
            }

            if(switchNum == -1)
            {
                int address = h1(new_data);
                int inc = h2(new_data);

                while(data_vec[address].valid != false)
                {
                    address = (address + inc) % data_vec.size();
                }

                data_vec[address].data = new_data;
                data_vec[address].valid = true;
            }
            else
            {
                data_vec[h1(switchNum)].data = new_data;

                int address = h1(switchNum);
                int inc = h2(switchNum);

                while(data_vec[address].valid != false)
                {
                    address = (address + inc) % data_vec.size();
                }

                data_vec[address].data = switchNum;
                data_vec[address].valid = true;
            }
        }
        else
        {
            cout << "List is full!!!" << endl;
        }
    }
    
}



int Brent::find_num_probes(int key) const{

    int probe = 1;

    int i = h1(key);
    int noLoop = 0;

    while(data_vec[i].data != key && noLoop <= data_vec.size())
    {
        i = (i + h2(key)) % data_vec.size();
        probe++;
        noLoop++;
    }

    if(noLoop > data_vec.size())
    {
        cout << key << " doesn't exit!!!" << endl;
        return 0;
    }

    return probe;
}



double Brent::find_average_num_probes() const{

    double probe_sum = 0;
    double data_num = 0;

    for(int i = 0; i < data_vec.size(); i++)
    {
        if(data_vec[i].valid != false)
        {
            probe_sum = probe_sum + find_num_probes(data_vec[i].data);
            data_num++;
        }
    }

    return probe_sum / data_num;

}