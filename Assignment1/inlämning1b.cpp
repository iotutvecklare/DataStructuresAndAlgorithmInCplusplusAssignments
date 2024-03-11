//b) Lös find med en vektor och binärsökning (BinarySearchStorage)
//Skriv egen binary search! Inte använda befintlig algorithm
//Mät i nanosekunder

#include <iostream>
#include <vector>
#include <chrono>

class BinarySearchStorage {
private:
    std::vector<int> data;

public:
    explicit BinarySearchStorage(const std::vector<int>& sortedData) {
        data = sortedData;
    }

    int binarySearch(int target) {
        int left = 0;
        std::vector<int>::size_type right = data.size()- 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (data[mid] == target) {
                return mid;
            } else if (data[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1; // Return -1 if target not found
    }
};

int main() {
    std::vector<int> sortedData; // Assume you have sorted data here

    // Initialize the sorted data vector
    sortedData.reserve(7897655);
    for (int i = 0; i < 7897655; ++i) {
            sortedData.push_back(i);
        }

    // Target element to search
    int target = 124;

    // Create an instance of BinarySearchStorage
    BinarySearchStorage binarySearchStorage(sortedData);

    // Measure time for binary search
    auto start = std::chrono::high_resolution_clock::now();
    int index = binarySearchStorage.binarySearch(target);
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate duration in nanoseconds
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

    if (index != -1) {
        std::cout << "Element found at index: " << index << std::endl;
    } else {
        std::cout << "Element not found" << std::endl;
    }

    std::cout << "Binary search took " << duration << " nanoseconds" << std::endl;

    return 0;
}
