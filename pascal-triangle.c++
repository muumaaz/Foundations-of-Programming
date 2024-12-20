#include <iostream>
#include <vector>

// Function to get a specific row of Pascal's triangle
std::vector<int> getRow(int rowIndex) {
    // Create a vector to store the row
    // Size will be rowIndex + 1 because row 0 has 1 number,
    // row 1 has 2 numbers, and so on
    std::vector<int> row(rowIndex + 1);
    
    // First number in any row is always 1
    row[0] = 1;
    
    // For row 0, we're done - it's just [1]
    if (rowIndex == 0) {
        return row;
    }
    
    // For each position in the row
    for (int i = 1; i <= rowIndex; i++) {
        // In Pascal's triangle, each number is the sum of the
        // two numbers above it. For a single row calculation,
        // we can use this formula:
        // C(n,r) = C(n,r-1) * (n-r+1) / r
        // where n is rowIndex and r is current position
        
        long long val = (long long)row[i-1] * (rowIndex - i + 1) / i;
        row[i] = (int)val;
    }
    
    return row;
}

int main() {
    // Get row index from user
    int rowIndex;
    std::cout << "Enter the row index (0 or positive number): ";
    std::cin >> rowIndex;
    
    // Input validation
    if (rowIndex < 0) {
        std::cout << "Please enter a non-negative number!" << std::endl;
        return 1;
    }
    
    // Get the requested row
    std::vector<int> result = getRow(rowIndex);
    
    // Print the result
    std::cout << "Row " << rowIndex << " of Pascal's triangle is: [";
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i];
        // Add comma if this is not the last number
        if (i < result.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;
    
    return 0;
}
