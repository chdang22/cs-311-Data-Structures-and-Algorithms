#include "graph.h"
#include <limits>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <source_city_code> <destination_city_code>" << std::endl;
        return 1;
    }

    std::cout << "Author: Caroline Dang" << std::endl;
    std::cout << "Date: 08/07/2023" << std::endl;
    std::cout << "Course: CS311 (Data structures and Algorithms)" << std::endl;
    std::cout << "Description: Program to find the shortest route between cities" << std::endl;
    std::cout << "----------------------------------------------------------------" << std::endl;

    std::string sourceCityCode = argv[1];
    std::string destinationCityCode = argv[2];

    // Create the graph and read city data from a file
    std::unordered_map<std::string, City> citiesData;
    std::ifstream cityFile("city.txt");

    if (!cityFile) {
        std::cerr << "Error opening cities file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(cityFile, line)) {
        std::istringstream iss(line);
        int id, population, elevation;
        std::string code, name;

        if (iss >> id >> code >> name >> population >> elevation) {
            citiesData[code] = City(id, code, name, population, elevation);
        } else {
            std::cerr << "Error parsing line: " << line << std::endl;
        }
    }

    //std::cout << "Number of cities in the map: " << citiesData.size() << std::endl;

    Graph graph(citiesData);

    // Read road data from a file and add roads to the graph
    std::ifstream roadFile("road.txt");

    if (!roadFile) {
        std::cerr << "Error opening road file." << std::endl;
        return 1;
    }


    while (std::getline(roadFile, line)) {
        std::istringstream iss(line);
        int fromCityId, toCityId, distance;

        if (!(iss >> fromCityId >> toCityId >> distance)) {
            std::cerr << "Error reading road data from file." << std::endl;
            return 1;
        }

        graph.addRoad(fromCityId, toCityId, distance);
    }
    if (citiesData.find(sourceCityCode) == citiesData.end() || citiesData.find(destinationCityCode) == citiesData.end()) {
        std::cout << "Invalid city code" << std::endl;
        return 1; // Exit with an error code
    }
    // Print the adjacency matrix
    //graph.printAdjacencyMatrix();
    std::vector<std::string> shortestRoute;
    int shortestDistance = 0;

    if (graph.findShortestRoute(sourceCityCode, destinationCityCode, shortestRoute, shortestDistance)) {
        std::cout << "From City: " << graph.getCityName(sourceCityCode) << ", population " << graph.getCityPopulation(sourceCityCode)
                  << ", elevation " << graph.getCityElevation(sourceCityCode) << std::endl;
        std::cout << "To City: " << graph.getCityName(destinationCityCode) << ", population " << graph.getCityPopulation(destinationCityCode)
                  << ", elevation " << graph.getCityElevation(destinationCityCode) << std::endl;

        std::cout << "The shortest distance from " << graph.getCityName(sourceCityCode) << " to " << graph.getCityName(destinationCityCode)
                  << " is " << shortestDistance << std::endl;

        std::cout << "Through the route: ";
        for (size_t i = 0; i < shortestRoute.size(); ++i) {
            std::cout << graph.getCityName(shortestRoute[i]);
            if (i < shortestRoute.size() - 1) {
                std::cout << "->";
            }
        }
        std::cout << std::endl;
    } else {
        std::cout << "From City: " << graph.getCityName(sourceCityCode) << ", population " << graph.getCityPopulation(sourceCityCode)
                  << ", elevation " << graph.getCityElevation(sourceCityCode) << std::endl;
        std::cout << "To City: " << graph.getCityName(destinationCityCode) << ", population " << graph.getCityPopulation(destinationCityCode)
                  << ", elevation " << graph.getCityElevation(destinationCityCode) << std::endl;

        std::cout << "No route found from " << graph.getCityName(sourceCityCode) << " to " << graph.getCityName(destinationCityCode) << "." << std::endl;
    }
    return 0;
}
