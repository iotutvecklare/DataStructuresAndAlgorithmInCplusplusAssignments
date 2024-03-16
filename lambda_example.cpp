/*
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::transform(vec.begin(), vec.end(), vec.begin(), [](int n){ return n * n; });
    for (int n : vec) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    return 0;
}*/

/*#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

int main() {
    std::vector<std::string> vec = {"apple", "banana", "cherry", "date"};
    std::sort(vec.begin(), vec.end(), [](const std::string& a, const std::string& b) {
        return a.size() < b.size();
    });
    for (const std::string& str : vec) {
        std::cout << str << " ";
    }
    std::cout << std::endl;
    return 0;
}*/

/*#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> vec = {1, 3, 5, 7, 8, 9};
    auto even = std::find_if(vec.begin(), vec.end(), [](int n){ return n % 2 == 0; });
    if (even != vec.end()) {
        std::cout << "The first even number is: " << *even << std::endl;
    } else {
        std::cout << "No even numbers found." << std::endl;
    }

    return 0;
}*/

/*#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> numbers{1, 2, 3, 4, 5, 6};

    std::vector<int> even_numbers;
    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(even_numbers),
                 [](int x) { return x % 2 == 0; });

   // Print the even numbers
    for (int x : even_numbers) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}*/

#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> numbers{1, 2, 3, 2, 4, 2};

    int num_twos = std::count_if(numbers.begin(), numbers.end(),
                                 [](int x) { return x == 2; });

    std::cout << "Number of twos: " << num_twos << std::endl;
}
