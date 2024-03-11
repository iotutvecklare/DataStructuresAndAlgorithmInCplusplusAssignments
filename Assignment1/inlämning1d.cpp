#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

// Function to sort a vector of integers and measure the time taken
void sortAndMeasureTime(std::vector<int>& numbers) {
    // Measure start time
    auto start = std::chrono::high_resolution_clock::now();

    // Sort the vector using std::sort
    std::sort(numbers.begin(), numbers.end());

    // Measure end time
    auto end = std::chrono::high_resolution_clock::now();



    // Calculate the total time in nanoseconds
    std::chrono::duration<double, std::nano> duration = end - start;

    // Print the sorted vector
    std::cout << "Sorted vector: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Print the time taken to sort the vector in nanoseconds
    std::cout << "Time taken for sorting: " << duration.count() << " nanoseconds" << std::endl;
}

int main() {
    // Create a vector with random numbers
    std::vector<int> numbers = {5, 2, 9, 3, 7, 1, 8, 4, 6};

    // Call the function to sort the vector and measure time
    sortAndMeasureTime(numbers);

    return 0;
}

