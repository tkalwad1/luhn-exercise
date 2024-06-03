#include "luhn.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

namespace luhn {
    bool valid(string ID){
        //remove whitespace
        ID.erase(remove(ID.begin(), ID.end(), ' '), ID.end());

        for(long unsigned int i = 0; i < ID.size(); ++i){
            if(!(ID[i] >= 48 && ID[i] <= 57)){return false;}
        }

        if(ID.size() <= 1){
            return false;
        }

        //separate the second digit into "doubles"
        string doubles;
        if(ID.size() % 2 == 0){
            for(long unsigned int i = 0; i < ID.size(); i = i + 2){
                doubles += ID[i];
            }
        }else if(ID.size() % 2 != 0){
            for(long unsigned int i = 1; i < ID.size(); i = i + 2){
                doubles += ID[i];
            }
        }
        //put all "doubles" into a vector of ints to begin doubling
        vector<int> doubleVector;
        for(long unsigned int i = 0; i < doubles.size(); ++i){
            int x = doubles[i] - '0';
            doubleVector.push_back(x);
        }

        //double
        for(long unsigned int i = 0; i < doubleVector.size(); ++i){
            doubleVector[i] = doubleVector[i] * 2;
            if(doubleVector[i] > 9){
                doubleVector[i] = doubleVector[i] - 9;
            }
        }

        //convert original ID to a vector of ints
        vector<int> IDvector; 
        for(long unsigned int i = 0; i < ID.size(); ++i){
            int y = ID[i] - '0';
            IDvector.push_back(y);
        }

        //now we have a vector of all digits of the ID and a vector of doubles
        //insert all doubles into the alternate positions of ID vector
        long unsigned int j = 0;
        while(j < doubleVector.size() - 1){
            if(ID.size() % 2 == 0){
                for(long unsigned int i = 0; i < IDvector.size(); i = i + 2){
                    IDvector[i] = doubleVector[j];
                    ++j;
                }
            }else if(ID.size() % 2 != 0){
                for(long unsigned int i = 1; i < IDvector.size(); i = i + 2){
                    IDvector[i] = doubleVector[j];
                    ++j;
                }
            }
        }
        //if(IDvector.size() <= 3){
          //  return true;
        //}

        int sum = accumulate(IDvector.begin(), IDvector.end(), 0);
        return (sum % 10 == 0);

        
    }
}  // namespace luhn
