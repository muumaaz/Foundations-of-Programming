#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

// Function to find the kth distinct string in an array
std::string findKthDistinct(std::vector<std::string>& arr, int k) {
    // Create a map to count how many times each string appears
    std::unordered_map<std::string, int> stringCount;
    
    // Count occurrences of each string
    for(const std::string& str : arr) {
        stringCount[str]++;
    }
    
    // Keep track of how many distinct strings we've found
    int distinctCount = 0;
    
    // Go through the array in original order
    for(const std::string& str : arr) {
        // If this string appears only once, it's distinct
        if(stringCount[str] == 1) {
            distinctCount++;
            
            // If this is the kth distinct string we've found, return it
            if(distinctCount == k) {
                return str;
            }
        }
    }
    
    // If we didn't find k distinct strings, return empty string
    return "";
}

int main() {
    // Get array size from user
    int size;
    std::cout << "Enter how many strings you want to input: ";
    std::cin >> size;
    
    // Input validation
    if(size <= 0) {
        std::cout << "Please enter a positive number" << std::endl;
        return 1;
    }
    
    // Create vector to store strings
    std::vector<std::string> arr;
    std::string temp;
    
    // Clear input buffer
    std::cin.ignore();
    
    // Get strings from user
    std::cout << "Enter " << size << " strings (press Enter after each string):" << std::endl;
    for(int i = 0; i < size; i++) {
        std::cout << "String " << (i + 1) << ": ";
        std::getline(std::cin, temp);
        arr.push_back(temp);
    }
    
    // Get k from user
    int k;
    std::cout << "Enter k (which distinct string to find): ";
    std::cin >> k;
    
    // Input validation for k
    if(k <= 0) {
        std::cout << "Please enter a positive number for k" << std::endl;
        return 1;
    }
    
    // Find and display result
    std::string result = findKthDistinct(arr, k);
    
    if(result.empty()) {
        std::cout << "There are fewer than " << k << " distinct strings in the array." << std::endl;
    } else {
        std::cout << "The " << k << "th distinct string is: \"" << result << "\"" << std::endl;
    }
    
    return 0;
}
