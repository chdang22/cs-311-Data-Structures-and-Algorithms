// graph.h
#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
#include <limits> // Include limits for initialization of distances

struct City {
    int id;
    std::string code;
    std::string name;
    int population;
    int elevation;
    bool visited;

    City(int _id, const std::string& _code, const std::string& _name, int _population, int _elevation)
            : id(_id), code(_code), name(_name), population(_population), elevation(_elevation), visited(false) {}

    City() : id(0), code(""), name(""), population(0), elevation(0), visited(false) {}
};

class Graph {
private:
    std::unordered_map<std::string, City> cities;
    std::vector<std::vector<int>> adjacencyMatrix;
    std::unordered_map<int, std::string> indexToCode;
    int numCities;

public:
    Graph(const std::unordered_map<std::string, City>& cities);

    void addRoad(int fromCityId, int toCityId, int distance);

    bool findShortestRoute(const std::string& fromCityCode, const std::string& toCityCode,
                           std::vector<std::string>& shortestRoute, int& shortestDistance);
    int getNumCities() const {
        return numCities;
    }

    void printAdjacencyMatrix() const {
        for (const auto& row : adjacencyMatrix) {
            for (int value : row) {
                std::cout << value << " ";
            }
            std::cout << std::endl;
        }
    }

    std::string getCityName(const std::string& cityCode);
    int getCityElevation(const std::string& cityCode) const;
    int getCityPopulation(const std::string& cityCode) const;

};



#endif
