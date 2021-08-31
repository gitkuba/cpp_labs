// Zaprojektować program, który pozwoli przekonwertować wartość liczbową z postaci dziesiętnej
// do postaci zapisu rzymskiego oraz odwrotnie wartość liczbową w postaci zapisu rzymskich
// cyfr do postaci dziesiętnej. Program powinien sprawdzać poprawność wprowadzanych znaków
// alfanumerycznych.

#include <iostream>
#include <map>
#include <regex>

using namespace std;

class NumberConverter {
private:
    const map<string, int> SYMBOLS_TO_NUMBERS = {
            {"M",  1000},
            {"CM", 900},
            {"D",  500},
            {"CD", 400},
            {"C",  100},
            {"XC", 90},
            {"L",  50},
            {"XL", 40},
            {"X",  10},
            {"IX", 9},
            {"V",  5},
            {"IV", 4},
            {"I",  1},
    };

    const map<int, string> NUMBERS_TO_SYMBOLS = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"},
    };

    bool isNumber(const string &s) {
        return find_if(s.begin(), s.end(), [](unsigned char c) { return !isdigit(c); }) == s.end();
    }

    void validateInput(string &input) {
        if (input.empty()) {
            throw invalid_argument("value required");
        }

        if (this->isNumber(input)) {
            this->validateDecimalNumber(input);
        } else {
            this->validateRomanNumeral(input);
        }
    }

    void validateDecimalNumber(string &input){
        int number = stoi(input);
        if (number < 1 || number > 3999) {
            throw invalid_argument(
                    "input must be a decimal number between 1 and 3999 or a valid roman numeral"
            );
        }
    }

    void validateRomanNumeral(string &input) {
        regex pattern("^M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$");
        if (!regex_match(input, pattern)) {
            throw invalid_argument("invalid roman numeral");
        }
    }

    int convertToDecimal(string input) {
        int output = 0;
        for (int i = 0; i < input.size(); i++) {
            // check if it's a double-letter sign.
            string doubleLetter = input.substr(i , 2);
            if (this->SYMBOLS_TO_NUMBERS.find(doubleLetter) != this->SYMBOLS_TO_NUMBERS.end()) {
                output += this->SYMBOLS_TO_NUMBERS.at(doubleLetter);
                i++;
                continue;
            }
            // orherwise go for a single-letter sign.
            string singleLetter = input.substr(i, 1);
            output += this->SYMBOLS_TO_NUMBERS.at(singleLetter);
        }

        return output;
    }

    string convertToRoman(int input) {
        string output = "";
        int elements[] = {};
        int zeros = to_string(input).size() - 1;
        // split the number into units, tens, hundreads...
        for (char num : to_string(input)) {
            elements.push(num + "0".repeat(zeros--));
        }
//        // concatenate the numeral
//        for (let element of elements) {
//            // zero doesn't need to be converted
//            if (element === "0") continue;
//
//            // if the value exists in the map just add it e.g. 1000 -> M
//            if (map.hasOwnProperty(element)) {
//                output += map[element];
//                continue;
//            }
//
//            // now let's handle more complex components like LXXX
//            let remaining = parseInt(element);
//            while (remaining > 0) {
//                let key = Object.keys(map)
//                                  .reverse()
//                                  .find((value) => value <= remaining);
//                output += map[key];
//                remaining -= parseInt(key);
//            }
//        }

        return output;
    }

public:
    int decimal;
    string roman;

    explicit NumberConverter(string &input) {
        this->validateInput(input);
        if (this->isNumber(input)){
            int number = stoi(input);
            this->decimal = number;
            this->roman = this->convertToRoman(number);
        } else {
            this->decimal = this->convertToDecimal(input);
            this->roman = input;
        }
    }

};

int main() {
    string input;

    cout << "Wprowadź liczbę rzymską lub dziesiętną: ";
    cin >> input;

    NumberConverter romanNumber(input);

    cout << "Postać rzymska: " << romanNumber.roman << endl;
    cout << "Postać dziesiętna: " << romanNumber.decimal << endl;

    return 0;
}
