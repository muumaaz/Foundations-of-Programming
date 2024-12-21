#include <iostream>
#include <string>
#include <algorithm> // For reverse() function

std::string addBinary(std::string a, std::string b) {
    std::string result = "";    // Store the final result
    int carry = 0;             // Store the carry during addition
    
    // Start from rightmost bit (end of strings)
    int i = a.length() - 1;
    int j = b.length() - 1;
    
    // Continue while we have bits in either number or carry
    while (i >= 0 || j >= 0 || carry > 0) {
        // Get current bits from both numbers
        // If we've run out of digits, use 0
        int bit1 = (i >= 0) ? a[i] - '0' : 0;
        int bit2 = (j >= 0) ? b[j] - '0' : 0;
        
        // Add both bits and the carry
        int sum = bit1 + bit2 + carry;
        
        // Calculate new carry and result bit
        carry = sum / 2;        // Carry is 1 if sum >= 2
        sum = sum % 2;          // Result bit is 0 if sum = 2
        
        // Add current bit to result string
        result.push_back(sum + '0');
        
        // Move to next bits
        i--;
        j--;
    }
    
    // Reverse the result string since we built it backwards
    std::reverse(result.begin(), result.end());
    
    return result;
}

int main() {
    std::string num1, num2;
    
    // Get first binary number
    std::cout << "Enter first binary number: ";
    std::cin >> num1;
    
    // Get second binary number
    std::cout << "Enter second binary number: ";
    std::cin >> num2;
    
    // Check if input contains only 0s and 1s
    bool isValid = true;
    for(char c : num1) {
        if(c != '0' && c != '1') {
            isValid = false;
            break;
        }
    }
    for(char c : num2) {
        if(c != '0' && c != '1') {
            isValid = false;
            break;
        }
    }
    
    if(!isValid) {
        std::cout << "Error: Please enter valid binary numbers (only 0s and 1s)" << std::endl;
        return 1;
    }
    
    // Calculate and display result
    std::string result = addBinary(num1, num2);
    std::cout << "Sum of binary numbers is: " << result << std::endl;
    
    return 0;
}
