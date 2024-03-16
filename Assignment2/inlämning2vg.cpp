#include <iostream>
#include <unordered_map>
#include <list>
#include <fstream>
#include <sstream>
#include <utility>

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

public:
    explicit LRUCache(int cap) : capacity(cap) {}

    HockeyPlayer* GetPlayer(int id) {
        auto it = cacheMap.find(id);
        if (it != cacheMap.end()) { // Player found in cache
            // Move the player to the front of the cache
            cache.splice(cache.begin(), cache, it->second);
            return &(*it->second);
        } else { // Player not found in cache
            HockeyPlayer* player = ReadFromFile(id);
            if (player) {
                // Add the player to the front of the cache
                cache.push_front(*player);
                cacheMap[id] = cache.begin();

                // If cache size exceeds capacity, remove the least recently used player
                if (cache.size() > capacity) {
                    cacheMap.erase(cache.back().id);
                    cache.pop_back();
                }
                return player;
            } else {
                return nullptr;
            }
        }
    }

private:
    static HockeyPlayer* ReadFromFile(int id) {
        std::ifstream file("hockey_players.txt");
        if (!file.is_open()) {
            std::cerr << "Error: Unable to open file." << std::endl;
            return nullptr;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            int playerId, jerseyNumber;
            std::string playerName, teamName;
            iss >> playerId >> playerName >> jerseyNumber >> teamName;

            if (playerId == id) {
                return new HockeyPlayer(playerId, playerName, jerseyNumber, teamName);
            }
        }
        std::cerr << "Error: Player not found in file." << std::endl;
        return nullptr;
    }
};

int main() {
    LRUCache cache(10);

    // Example usage:
    HockeyPlayer* player1 = cache.GetPlayer(1);
    HockeyPlayer* player2 = cache.GetPlayer(2);

    if (player1) {
        std::cout << "Player 1: " << player1->name << std::endl;
    } else {
        std::cout << "Player 1 not found." << std::endl;
    }

    if (player2) {
        std::cout << "Player 2: " << player2->name << std::endl;
    } else {
        std::cout << "Player 2 not found." << std::endl;
    }

    return 0;
}
