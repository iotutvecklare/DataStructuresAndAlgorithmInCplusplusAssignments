#include <iostream>

template <typename T, int SIZE>
class Queue {
private:
    T data[SIZE];
    int start;
    int end;
    int count;

public:

    Queue() : start(0), end(0), count(0) {}


    bool enqueue(const T& item) {

        if (count >= SIZE) {
            std::cerr << "The queue is full. Unable to add elements." << std::endl;
            return false;
        }

        data[end] = item;
        end = (end + 1) % SIZE; // Manage circular buffer
        ++count;
        return true;
    }

    void dequeue() {
        if (count == 0) {
            std::cerr << "The queue is empty. Unable to remove elements." << std::endl;
            return;
        }

        start = (start + 1) % SIZE; // Manage circular buffer
        --count;
    }

    T& getFirst() {
        if (count == 0) {
            throw std::logic_error("Queue is empty. There are no elements to retrieve.");
        }
        return data[start];
    }

    T& getLast() {
        if (count == 0) {
            throw std::logic_error("Queue is empty. There are no elements to retrieve.");
        }
        // Since 'end' points to the next available position, the last element is at 'end - 1'
        return data[(end == 0) ? SIZE - 1 : end - 1];
    }


    [[nodiscard]] bool empty() const {
        return count == 0;
    }


    [[nodiscard]] bool full() const {
        return count == SIZE;
    }

    [[nodiscard]] int size() const {
        return count;
    }
};

int main() {
    Queue<int, 5> myQueue;

    myQueue.enqueue(5);
    myQueue.enqueue(6);
    myQueue.enqueue(7);
    myQueue.enqueue(8);
    myQueue.enqueue(9);

    myQueue.enqueue(10);

    myQueue.dequeue();

    myQueue.enqueue(10);

    std::cout << "The first element in the queue: " << myQueue.getFirst() << std::endl;
    std::cout << "The last element in the queue: " << myQueue.getLast() << std::endl;

    return 0;
}
