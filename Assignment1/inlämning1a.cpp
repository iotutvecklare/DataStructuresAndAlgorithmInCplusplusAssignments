
//a) Gör så att kundnummer är "paddat", dvs alltid 10 tecken och 0-utfyllt i början
//"0000000001"
//"0000000002"

#include <iostream>
#include <string>

std::string paddingNumber(int number) {
    std::string paddedNumber = std::to_string(number);
    while (paddedNumber.length() < 10) {
        paddedNumber = "0" + paddedNumber;
    }
    return paddedNumber;
}

int main() {
    std::cout << paddingNumber(1) << std::endl;
    std::cout << paddingNumber(776) << std::endl;
    return 0;
}







