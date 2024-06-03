#include <cmath>
#include <algorithm>
using namespace std;

namespace isbn_verifier {
    bool is_valid(string isbn){
        //first remove dashes
        isbn.erase(remove(isbn.begin(), isbn.end(), '-'), isbn.end()); 
        
        if(isbn.size() != 10){return false;} // checks correct size

        //now check if contains X
        if(isbn[isbn.size() - 1] == 'X'){
            isbn[isbn.size() - 1] = 10; // converts X to 10 (this is arbitrary)
        }

        int myInteger = stoi(isbn); // converts string to int

        //now insert all digits of the integer into a vector
        vector<int> digits;
        while(myInteger){
            digits.push_back(myInteger % 10);
            myInteger /= 10;
        }

        //account for X being converted to 1 and 0
        if(digits[digits.size() - 1] == 0 && digits[digits.size() - 2] == 1 &&             digits.size() != 10){
            digits.pop_back();
            digits.pop_back();
            digits.push_back(10);
        }

        //now apply formula
        if((digits[0] * 10 + digits[1] * 9 + digits[2] * 8 + digits[3] * 7 +               digits[4] * 6 + digits[5] * 5 + digits[6] * 4 + digits[7] * 3 + digits[8]          * 2 + digits[9] * 1) % 11 == 0){
            return true;
        }
        
        return false;
    }
}  // namespace isbn_verifier