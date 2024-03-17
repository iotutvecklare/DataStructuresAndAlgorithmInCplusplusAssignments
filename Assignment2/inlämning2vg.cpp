/*
LRU Cache (Combination of Hash table and Linked list):
LRU caches typically use a combination of a hash table and a linked list to provide fast access to cached items and efficient eviction of least recently used items.
The hash table allows fast lookup of cached items by key, while the linked list keeps track of the access order.
This combination enables constant-time access to cached items and efficient removal and reinsertion of items based on their access patterns.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <list>
#include <unordered_map>

struct HockeyPlayer {
    int id;
    std::string name;
    int jersey;
    std::string teamName;

    HockeyPlayer(int _id, std::string  _name, int _jersey, std::string  _teamName)
            : id(_id), name(std::move(_name)), jersey(_jersey), teamName(std::move(_teamName)) {}
};


class LRUCache {
private:
    int capacity;
    std::list<HockeyPlayer> cache;
    std::unordered_map<int, std::list<HockeyPlayer>::iterator> cacheMap;

    static HockeyPlayer *ReadFromFile(int id) {
        std::ifstream file("hockey_players.txt");
        if (!file.is_open()) {
            std::cerr << "Error: Unable to open file." << std::endl;
            return nullptr;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            int playerId, jersey;
            std::string playerName, teamName;

            iss >> playerId;
            iss.ignore();  // Ignore the comma
            // Read the data using getline with ',' as a delimiter for all fields
            std::getline(iss, playerName, ',');
            iss >> jersey;
            iss.ignore();  // Ignore the comma
            // Read the data using getline with ',' as a delimiter for all fields
            std::getline(iss, teamName, ',');

            iss >> playerId >> playerName >> jersey >> teamName;

            if (playerId == id) {
                //std::cout << playerId << std::endl;
                //std::cout << playerName << std::endl;
                //std::cout << jersey << std::endl;
                //std::cout << teamName << std::endl;
                return new HockeyPlayer(playerId, playerName, jersey, teamName);
            }
        }
        //std::cerr << "Error: Player not found in file." << std::endl;
        return nullptr;
    }

public:
    LRUCache(int _capacity) {
        capacity = _capacity;
    }

    // Function to print the contents of the cache
    void printCache() const {
        std::cout << "Cache contents:" << std::endl;
        for (const auto& player : cache) {
            std::cout << "Player ID: " << player.id << ", Name: " << player.name << ", Jersey: " << player.jersey << ", Team: " << player.teamName << std::endl;
        }
    }

    HockeyPlayer* getPlayer(int id) {
        auto it = cacheMap.find(id);
        if (it == cacheMap.end()) {
            HockeyPlayer* hockeyPlayer = ReadFromFile(id);
            if (hockeyPlayer) {
                // Add the player to the front of the cache
                cache.push_front(*hockeyPlayer);

                // If cache size exceeds capacity, remove the least recently used player
                if (cache.size() > capacity) {
                    //cacheMap.erase(cache.back().id);
                    cache.pop_back();
                }
                return hockeyPlayer;
            } else {
                return nullptr;
            }
        } else {
            // Retrieve the iterator from the cacheMap
            auto listIterator = it->second;

            // Move the player to the front of the list
            cache.splice(cache.begin(), cache, listIterator);

            // If cache size exceeds capacity, remove the least recently used player
            if (cache.size() > capacity) {
                //cacheMap.erase(cache.back().id);
                cache.pop_back();
            }

            // Return the pointer to the accessed player
            return &(*listIterator);
        }
    }

};

int main() {
//    IOStream writer("hockey_players.txt"); // Just for generating 10000 players in the file
//    writer.writeToFile(); // Just for generating 10000 players in the file

    LRUCache cache(2);
    while (true) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Get player information" << std::endl;
        std::cout << "2. View cache contents" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int id;
                std::cout << "Enter player ID: ";
                std::cin >> id;

                HockeyPlayer* player = cache.getPlayer(id);
                if (player) {
                    std::cout << "Player information:" << std::endl;
                    std::cout << "ID: " << player->id << std::endl;
                    std::cout << "Name: " << player->name << std::endl;
                    std::cout << "Jersey: " << player->jersey << std::endl;
                    std::cout << "Team: " << player->teamName << std::endl;
                } else {
                    std::cout << "Player with ID " << id << " not found." << std::endl;
                }
                break;
            }
            case 2: {
                std::cout << "Cache contents:" << std::endl;
                cache.printCache();
            }
            case 3: {
                std::cout << "Exiting program." << std::endl;
                return 0;
            }
            default:
                std::cout << "Invalid choice. Please enter a valid option." << std::endl;
        }
    }
    return 0;
}


class IOStream {
private:
    std::string fileName;
public:
    IOStream(std::string _fileName) : fileName(_fileName) {}

    void writeToFile() {
        std::ofstream outFile(fileName);
        if (!outFile.is_open()) {
            std::cerr << "Error: Unable to open file " << fileName << std::endl;
            return;
        }

        std::vector<std::string> names = {"Matthew", "Mark", "Luke", "John", "Mildred", "Maribel", "Pikot", "Charmagne", "Rhea", "Jelly"};
        std::vector<std::string> teams = {"Team A", "Team B", "Team C", "Team D", "Team E", "Team F", "Team G", "Team H", "Team I", "Team J"};

        std::srand(static_cast<unsigned>(std::time(nullptr))); // vs srand(time(nullptr)); // Seed the random number generator
        for (int i = 0; i < 100000; ++i) {
            int id = i + 1; // Assuming IDs start from 1
            std::string name = names[rand() % names.size()];
            int jersey = rand() % 100; // Random jersey number between 0 and 99
            std::string teamName = teams[rand() % teams.size()]; // Random team name

            outFile << id << "," << name << "," << jersey << "," << teamName << std::endl;
        }

        outFile.close();
        std::cout << "File " << fileName << " has been created with 100000 random hockey players." << std::endl;
    }

    void readFromFile() {
        std::ifstream readFile(fileName);
        if (!readFile.is_open()) {
            std::cerr << "Cannot open the file for reading.\n";
            return;
        }
    }
};


/*
The function srand() is used to seed the random number generator in C++.
A seed is essentially a starting point for generating a sequence of random numbers.
In C++, if you don't explicitly seed the random number generator using srand(),
it will generate the same sequence of random numbers every time the program runs.
This is because the random number generator uses a deterministic algorithm that produces the same sequence of numbers for a given seed.
By seeding the random number generator with srand(time(nullptr)), you are initializing it with a different seed each time the program runs,
based on the current time (represented as the number of seconds since the epoch).
This ensures that the sequence of random numbers generated by rand() will be different each time you run the program,
which is usually desirable for generating random data.*/
