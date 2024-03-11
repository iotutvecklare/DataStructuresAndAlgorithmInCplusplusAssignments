#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

// Funktion för att generera slumpmässiga kundnummer
std::vector<int> generateRandomCustomerNumbers(int count) {
    std::vector<int> numbers;
    std::random_device rd;
    std::mt19937 gen(rd());

    // Lägg till slumpmässiga kundnummer i vektorn
    for (int i = 0; i < count; ++i) {
        // Anta att kundnumret är mellan 1 och 1000000 (eller valfri gräns)
        std::uniform_int_distribution<int> dis(1, 1000000);
        numbers.push_back(dis(gen));
    }

    return numbers;
}

int main() {
    // Antalet slumpmässiga kundnummer att generera
    int count = 1;
    std::vector<int> customerNumbers = generateRandomCustomerNumbers(count);

    // Skriv ut de slumpmässiga kundnumren
    std::cout << "Slumpmässiga kundnummer:" << std::endl;
    for (int number : customerNumbers) {
        std::cout << number << std::endl;
    }

    return 0;
}
