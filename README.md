# Recipe Database Simulation

This project is a simulation of a simple database operation, developed as part of the IN2029 Programming in C++ coursework. It calculates the required quantities of ingredients based on cooking orders, demonstrating the application of data structures in managing and processing data efficiently.

## Coursework Details

- **Course**: IN2029 Programming in C++
- **Institution**: City, University of London
- **Term**: Autumn 2023

## Learning Outcomes

- **Applied Theoretical Knowledge:** Leveraged knowledge from Java/Python to implement concepts in C++.
- **File Manipulation:** Utilized `std::cin` to read data from files, mimicking database operations.
- **Data Handling:** Employed maps to efficiently sort and merge data from multiple sources.
- **Formatted Output:** Mastered the use of `std::cout` to produce outputs in a specified format, suitable for integration with other software.

## Project Structure

```
/RecipeDatabaseSimulation
|-- src/
| |-- main.cpp
| |-- RecipeDatabaseManager.cpp
| |-- RecipeDatabaseManager.h
|-- ingredients.txt
|-- orders.txt
|-- CMakeLists.txt
|-- README.md
```

## Setup and Compilation

Ensure you have a C++ compiler and CMake installed. This project is set up to use the Ninja build system. Follow these steps to compile and run the project:

1. Clone the repository.
2. Run CMake to generate the build system:
   ```bash
   cmake -B build -G "Ninja"
   ```
3. Build the project:
   ```bash
   cmake --build build
   ```
4. Run the simulation:
   ```bash
   ./build/RecipeDatabaseSimulation
   ```

## Usage

To run the simulation, make sure the `ingredients.txt` and `orders.txt` files are in the same directory as your executable. These files should be formatted as follows:

- `ingredients.txt`: Contains the ingredients for each recipe.
  ```
  cake eggs 6
  cake flour 2.5
  cake sugar 2
  ```
- `orders.txt`: Contains the orders with required quantities.
  ```
  cake 3
  cookies 6
  ```

After running the simulation, it reads the input files and calculates the total amount of each ingredient needed.

## Expected Output

After processing the input files, the program outputs the total quantities of each ingredient required. Here’s an example of the expected output when using the provided input files:

```cpp
eggs 18
flour 7.5
sugar 6
```

This output represents the total quantities of ingredients needed to fulfill the orders specified in the `orders.txt` file.
