#include <iostream>
#include <fstream>
#include <chrono>
#include "CookingOrderProcessor.h"

using namespace std;
using namespace std::chrono;

int main() {
    auto start = high_resolution_clock::now();

    // Open and read ingredients.txt
    ifstream ingredientsFile("ingredients.txt");
    if (!ingredientsFile.is_open()) { // Test the file
        cerr << "Error opening ingredients.txt\n";
        return 1; // Failed to open
    }

    // Open and read orders.txt
    ifstream ordersFile("orders.txt");
    if (!ordersFile.is_open()) { // Test the file
        cerr << "Error opening orders.txt\n";
        return 1; // Failed to open
    }

    // Instantiate the CookingOrderProcessor
    CookingOrderProcessor processor;

    // Read  and process data from ingredients.txt
    processor.processIngredients(ingredientsFile);

    // Read and process data from orders.txt
    processor.processOrders(ordersFile);

    // Print the results to standard output
    processor.printResults();

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds >(stop - start);
    cout << "\nTime elapsed: " << duration.count() << "μs" << endl;

    return 0;
}
