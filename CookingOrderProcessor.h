#ifndef RECIPEDATABASESIMULATION_COOKINGORDERPROCESSOR_H
#define RECIPEDATABASESIMULATION_COOKINGORDERPROCESSOR_H


#include <string>
#include <unordered_map>

// Calculates the total ingredients required from a set of orders and ingredients
class CookingOrderProcessor {
    std::unordered_map<std::string, double> ingredientQuantities; // Quantity of each recipe ingredient
    std::unordered_map<std::string, int> orderQuantities; // Quantity of each ordered recipe
    std::unordered_map<std::string, double> totalQuantities; // Quantity required of each ingredient

public:
    // Process ingredient data and update the ingredientQuantities map
    void processIngredients(std::ifstream &file);

    // Process order data and update the orderQuantities map
    void processOrders(std::ifstream &file);

    // Print the totalQuantities map to standard output
    void printResults() const;

private:
    // Update the ingredientQuantities map based on the order quantities
    void multiplyQuantities();

    // Process updated ingredient data and update the totalQuantities map
    void processTotals();
};


#endif //RECIPEDATABASESIMULATION_COOKINGORDERPROCESSOR_H
