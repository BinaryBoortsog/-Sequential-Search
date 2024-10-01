#define DATACOUNT 5000001

#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

int sequential_search(const std::vector<int>& data, int target) {
    for (int i = 0; i < data.size(); i++) {  
        if (data[i] == target) {
            return i; 
        }
    }
    return -1;  // Return -1
}

int main() {
    clock_t start, stop;
    double best_case_time = 0, average_case_time = 0, worst_case_time = 0;
    
    // Create and write data to a file
    std::ofstream output_file("large_data.txt");
    if (!output_file.is_open()) {
        std::cerr << "Error creating file!" << std::endl;
        return -1;
    }
    
    for (int i = 1; i <= DATACOUNT; ++i) {
        output_file << i << "\n";
    }
    output_file.close();  // Close the file after writing
    
    // Read the data from the file 
    std::ifstream input_file("large_data.txt");
    if (!input_file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return -1;
    }
    
    std::vector<int> data;
    int temp;
    while (input_file >> temp) {
        data.push_back(temp);  // Read the file and store the values in the vector
    }
    input_file.close();  // Close the file after reading
    
    // Start the clock for the best case search (first element)
    start = clock();
    sequential_search(data, 1);  // Searching for the first element (best case)
    stop = clock();
    best_case_time = static_cast<double>(stop - start) / CLOCKS_PER_SEC;
    
    // Start the clock for the average case search (middle element)
    start = clock();
    sequential_search(data, DATACOUNT / 2);  // Searching for the middle element
    stop = clock();
    average_case_time = static_cast<double>(stop - start) / CLOCKS_PER_SEC;
    
    // Start the clock for the worst case search (last element)
    start = clock();
    sequential_search(data, DATACOUNT);  // Searching for the last element (worst case)
    stop = clock();
    worst_case_time = static_cast<double>(stop - start) / CLOCKS_PER_SEC;
    
    // Output the results
    std::cout << "Best case search time: " << best_case_time << " seconds" << std::endl;
    std::cout << "Average case search time: " << average_case_time << " seconds" << std::endl;
    std::cout << "Worst case search time: " << worst_case_time << " seconds" << std::endl;

    return 0;
}
