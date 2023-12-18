#include <fstream>
#include <iostream>
#include "CookingOrderProcessor.h"

using namespace std;

void CookingOrderProcessor::processIngredients(std::ifstream &file) {
    string recipe, ingredient;
    double quantity;
    // Fill the orderQuantities map with ingredient data
    while (file >> recipe >> ingredient >> quantity)
        ingredientQuantities[recipe.append(' ' + ingredient)] = quantity;
}

void CookingOrderProcessor::processOrders(std::ifstream &file) {
    string recipe;
    int quantity;
    // Fill the orderQuantities map with order data
    while (file >> recipe >> quantity)
        orderQuantities[recipe] += quantity;
    multiplyQuantities(); // Update the ingredient quantities
    processTotals(); // Produce the ingredient totals
}

void CookingOrderProcessor::printResults() const {
    // Iterate through the totalQuantities map
    for (const auto &entry: totalQuantities)
        // Print the ingredient name and total quantity required
        cout << entry.first << ' ' << entry.second << '\n';
}

void CookingOrderProcessor::multiplyQuantities() {
    // Iterate through the orderQuantities map
    for (const auto &ordEntry: orderQuantities) {
        // Iterate through the ingredientQuantities map
        for (auto &ingEntry : ingredientQuantities) {
            // Recipe and ingredient names are separated by a space in the key
            auto spaceIndex = ingEntry.first.find(' ');
            // Extract the recipe name from the key
            string recipe = ingEntry.first.substr(0, spaceIndex);
            // If the recipe matches the target recipe order
            if (recipe == ordEntry.first)
                ingEntry.second *= ordEntry.second; // Update the ingredient quantity
        }
    }
}

void CookingOrderProcessor::processTotals() {
    // Iterate though the ingredientQuantities map
    for (auto &entry: ingredientQuantities) {
        // Recipe and ingredient names are separated by a space in the key
        auto spaceIndex = entry.first.find(' ');
        // Extract the ingredient name from the key
        string ingredient = entry.first.substr(spaceIndex + 1);
        // Update the totalQuantities mpa, merging ingredient records with duplicate names
        totalQuantities[ingredient] += entry.second;
    }
}
