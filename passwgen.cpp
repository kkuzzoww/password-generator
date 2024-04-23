#include <iostream>
#include <algorithm>
#include <random>

class PasswordGenerator {
public:
    PasswordGenerator();
    PasswordGenerator(int length, bool useDigits, bool useLowercase, bool useSpecialChars, bool useUppercase)
    : length(length), useDigits(useDigits), useLowercase(useLowercase), useSpecialChars(useSpecialChars), useUppercase(useUppercase) {}
    std::string generatePassword();

private:
    int length;
    bool useDigits;
    bool useSpecialChars;
    bool useUppercase;
    bool useLowercase;

    char genRandomChar();

};

std::string PasswordGenerator::generatePassword() {
    std::string password;
    for(int i = 0; i < length; ++i) {
        password += genRandomChar();
    }
    return password;
}

char PasswordGenerator::genRandomChar() {
    char ch;
    for(int i = 0; i < length; ++i) {
        
    }
}

int main() 
{



return 0;

}