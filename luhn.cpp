#include "luhn.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
namespace luhn {
    bool valid(string ID){
        // Preprocessing for valid inputs
        // Remove spaces
        ID.erase(remove(ID.begin(), ID.end(), ' '), ID.end());
        // Check if size >= 2
        if(ID.size() <= 1){
            return false;
        }
        
        unsigned int index_to_double = (((ID.size() % 2) == 0) ? 0 : 1);
        int sum = 0;
        for (unsigned int i = 0; i < ID.size(); i++) {
            // Check for invalid characters
            if (!(ID[i] >= 48 && ID[i] <= 57)) {
                return false;
            }
            // Luhn algorithm
            int value_of_char_at_i = (ID[i]-'0');
            if (i == index_to_double) {
                index_to_double = index_to_double + 2;
                 value_of_char_at_i = value_of_char_at_i * 2;
                int computed_value = (value_of_char_at_i > 9) ? value_of_char_at_i - 9 : value_of_char_at_i;
                sum = sum + computed_value;
            } else {
                sum = sum + value_of_char_at_i;
            }
        }
        return (sum % 10 == 0);
    }
}  // namespace luhn
