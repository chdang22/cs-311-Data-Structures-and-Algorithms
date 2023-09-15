#include "graph.h"
#include <limits>    // Add this include for numeric_limits
#include <algorithm> // Add this include for std::reverse
#include <iostream>

Graph::Graph(const std::unordered_map<std::string, City>& citiesData) : cities(citiesData) {
    numCities = citiesData.size(); // Use citiesData.size() instead of cities.size()
    adjacencyMatrix.resize(numCities, std::vector<int>(numCities, -1)); // Initialize with -1
    // Populate indexToCode map
    for (const auto& cityPair : citiesData) { // Use citiesData instead of cities
        indexToCode[cityPair.second.id] = cityPair.first;
    }
}


void Graph::addRoad(int fromCityId, int toCityId, int distance) {
    if (fromCityId >= 0 && fromCityId < numCities && toCityId >= 0 && toCityId < numCities) {
        adjacencyMatrix[fromCityId][toCityId] = distance;
    }
}






bool Graph::findShortestRoute(const std::string& fromCityCode, const std::string& toCityCode,
                              std::vector<std::string>& shortestRoute, int& shortestDistance) {
    int fromIndex = cities[fromCityCode].id;
    int toIndex = cities[toCityCode].id;

    std::vector<int> distances(numCities, std::numeric_limits<int>::max());
    std::vector<int> previous(numCities, -1);
    std::vector<bool> visited(numCities, false);

    distances[fromIndex] = 0;

    while (true) {
        int currentCityIndex = -1;
        int shortestDist = std::numeric_limits<int>::max();

        // Find the unvisited city with the shortest distance
        for (int v = 0; v < numCities; ++v) {
            if (!visited[v] && distances[v] < shortestDist) {
                shortestDist = distances[v];
                currentCityIndex = v;
            }
        }

        if (currentCityIndex == -1) {
            break; // No more progress can be made
        }

        visited[currentCityIndex] = true;

        for (int v = 0; v < numCities; ++v) {
            if (!visited[v] && adjacencyMatrix[currentCityIndex][v] != -1) {
                int newDistance = distances[currentCityIndex] + adjacencyMatrix[currentCityIndex][v];
                if (newDistance < distances[v]) {
                    distances[v] = newDistance;
                    previous[v] = currentCityIndex;
                }
            }
        }
    }

    if (previous[toIndex] == -1) {
        return false; // No route found
    }

    shortestDistance = distances[toIndex];

    shortestRoute.clear();
    int cityIndex = toIndex;
    while (cityIndex != fromIndex) {
        shortestRoute.push_back(indexToCode[cityIndex]);
        cityIndex = previous[cityIndex];
    }
    shortestRoute.push_back(fromCityCode);
    std::reverse(shortestRoute.begin(), shortestRoute.end());

    return true;
}

std::string Graph::getCityName(const std::string &cityCode) {
    if (cities.find(cityCode) != cities.end()) {
        return cities.at(cityCode).name;
    }
    return "";
}

int Graph::getCityElevation(const std::string &cityCode) const {
    return cities.at(cityCode).elevation;
}

int Graph::getCityPopulation(const std::string &cityCode) const {
    return cities.at(cityCode).population;
}
