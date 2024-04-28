#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <random>

class PasswordGenerator {
public:
    PasswordGenerator();
    PasswordGenerator(int length, bool useDigits, bool useLowercase, bool useSpecialChars, bool useUppercase)
    : length(length), useDigits(useDigits), useLowercase(useLowercase), useSpecialChars(useSpecialChars), useUppercase(useUppercase) {
        std::srand(std::time(NULL));
    }

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
        if(i > 0 && i % 4 == 0) {
            password += "-";
        }
        password += genRandomChar();
    }
    return password;
}

char PasswordGenerator::genRandomChar() {
    std::string chars;
    if(useDigits) chars += "0123456789";
    if(useSpecialChars) chars += "!@#$%^&*()-_=+[]{}|;:,.<>?";
    if(useLowercase) chars += "abcdefghijklmnopqrstuvwxyz";
    if(useUppercase) chars += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int randomIndex = rand() % chars.size();
    return chars[randomIndex];
}

int main() 
{

    PasswordGenerator pw(16, true, true, false, true);
    std::string password = pw.generatePassword();
    std::cout << password << '\n';

    return 0;

}