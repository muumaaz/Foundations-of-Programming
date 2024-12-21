#include <iostream>
#include <vector>

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    // Constructor to make node creation easier
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    std::vector<std::vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        // Create m x n matrix filled with -1
        std::vector<std::vector<int>> matrix(m, std::vector<int>(n, -1));
        
        // If list is empty, return matrix filled with -1
        if (!head) return matrix;
        
        // Define boundaries
        int top = 0;          // Top row
        int bottom = m - 1;   // Bottom row
        int left = 0;         // Leftmost column
        int right = n - 1;    // Rightmost column
        
        // Current node in linked list
        ListNode* current = head;
        
        // Continue until we run out of elements or space
        while (current && top <= bottom && left <= right) {
            // Fill top row (left to right)
            for (int j = left; j <= right && current; j++) {
                matrix[top][j] = current->val;
                current = current->next;
            }
            top++;
            
            // Fill right column (top to bottom)
            for (int i = top; i <= bottom && current; i++) {
                matrix[i][right] = current->val;
                current = current->next;
            }
            right--;
            
            // Fill bottom row (right to left)
            if (top <= bottom) {
                for (int j = right; j >= left && current; j--) {
                    matrix[bottom][j] = current->val;
                    current = current->next;
                }
                bottom--;
            }
            
            // Fill left column (bottom to top)
            if (left <= right) {
                for (int i = bottom; i >= top && current; i--) {
                    matrix[i][left] = current->val;
                    current = current->next;
                }
                left++;
            }
        }
        
        return matrix;
    }
};

// Helper function to create linked list from array
ListNode* createList(std::vector<int>& arr) {
    if (arr.empty()) return nullptr;
    
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    
    for (int i = 1; i < arr.size(); i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    
    return head;
}

// Helper function to print matrix
void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << "\t";
        }
        std::cout << std::endl;
    }
}

int main() {
    Solution solution;
    
    // Get matrix dimensions from user
    int m, n;
    std::cout << "Enter number of rows (m): ";
    std::cin >> m;
    std::cout << "Enter number of columns (n): ";
    std::cin >> n;
    
    // Get list elements from user
    std::cout << "Enter number of elements in linked list: ";
    int size;
    std::cin >> size;
    
    std::vector<int> arr;
    std::cout << "Enter " << size << " elements:" << std::endl;
    for (int i = 0; i < size; i++) {
        int val;
        std::cin >> val;
        arr.push_back(val);
    }
    
    // Create linked list
    ListNode* head = createList(arr);
    
    // Generate and print spiral matrix
    std::vector<std::vector<int>> result = solution.spiralMatrix(m, n, head);
    
    std::cout << "\nResulting Matrix:" << std::endl;
    printMatrix(result);
    
    // Clean up memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    
    return 0;
}
