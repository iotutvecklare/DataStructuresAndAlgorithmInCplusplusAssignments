#include <iostream>
#include <queue>
#include <string>
#include <chrono>
#include <thread>
#include <utility>

// Class to represent a customer
template<typename T>
class Customer {
private:
    int queueNumber;
    T name;
    // This clock is designed to be monotonic and steady, meaning it does not adjust or jump due to system time adjustments, such as clock synchronization.
    // It guarantees a steady tick rate that moves forward at a uniform rate.
    std::chrono::time_point<std::chrono::steady_clock> arrivalTime;

public:
    Customer(int _queueNumber, T  _name)
            : queueNumber(_queueNumber), name(std::move(_name)), arrivalTime(std::chrono::steady_clock::now()) {}

    [[nodiscard]] int getQueueNumber() const { return queueNumber; }
    [[nodiscard]] const T& getName() const { return name; }
    [[nodiscard]] std::chrono::time_point<std::chrono::steady_clock> getArrivalTime() const { return arrivalTime; }
};

// Clinic simulator
template<typename T>
class ClinicSimulator {
private:
    std::queue<Customer<T>> waitingQueue;

public:

    // Method to add a new customer to the waiting queue
    void addCustomer(const Customer<T>& customer) {
        waitingQueue.push(customer);
        std::cout << "Customer " << customer.getQueueNumber() << " with name " << customer.getName() << " has arrived." << std::endl;
    }

    // Method to call the next customer
    void callNextCustomer() {
        if (!waitingQueue.empty()) {
            Customer<T> nextCustomer = waitingQueue.front();
            waitingQueue.pop();

            std::chrono::duration<double> waitingTime = std::chrono::steady_clock::now() - nextCustomer.getArrivalTime();
            std::cout << "Customer " << nextCustomer.getQueueNumber() << " with name " << nextCustomer.getName()
                      << " has waited for " << waitingTime.count() << " seconds." << std::endl;
        } else {
            std::cout << "No more customers waiting." << std::endl;
        }
    }
};

int main() {
    ClinicSimulator<std::string> clinic;

    // Main loop for the clinic simulator
    while (true) {
        std::cout << "Welcome to the clinic simulator." << std::endl;
        std::cout << "Choose an option:" << std::endl;
        std::cout << "1. Add a new customer to the waiting queue." << std::endl;
        std::cout << "2. Call the next customer." << std::endl;
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string name;
                std::cout << "Enter the customer's name: ";
                std::cin >> name;
                static int queueNumber = 1;
                clinic.addCustomer(Customer<std::string>(queueNumber++, name));
                break;
            }
            case 2:
                clinic.callNextCustomer();
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
