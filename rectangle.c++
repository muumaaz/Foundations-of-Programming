#include <iostream>
#include <vector>

bool isRectangleOverlap(std::vector<int>& rec1, std::vector<int>& rec2) {
    // For rectangles to overlap:
    // 1. Left edge of one rectangle must be less than right edge of other
    // 2. Bottom edge of one rectangle must be less than top edge of other
    
    // Check if either rectangle is actually a line
    if (rec1[0] == rec1[2] || rec1[1] == rec1[3] ||
        rec2[0] == rec2[2] || rec2[1] == rec2[3]) {
        return false;
    }
    
    // Check if rectangles don't overlap
    // If one rectangle is to the left of other's right edge
    // or if one rectangle is to the right of other's left edge
    // or if one rectangle is above other's top edge
    // or if one rectangle is below other's bottom edge
    
    // rec1's left edge >= rec2's right edge
    // OR rec1's right edge <= rec2's left edge
    // OR rec1's bottom edge >= rec2's top edge
    // OR rec1's top edge <= rec2's bottom edge
    if (rec1[0] >= rec2[2] ||    // rec1 is to the right of rec2
        rec1[2] <= rec2[0] ||    // rec1 is to the left of rec2
        rec1[1] >= rec2[3] ||    // rec1 is above rec2
        rec1[3] <= rec2[1]) {    // rec1 is below rec2
        return false;
    }
    
    return true;
}

int main() {
    // Get coordinates for first rectangle
    std::vector<int> rec1(4);
    std::cout << "Enter coordinates for first rectangle (x1 y1 x2 y2): ";
    for(int i = 0; i < 4; i++) {
        std::cin >> rec1[i];
    }
    
    // Get coordinates for second rectangle
    std::vector<int> rec2(4);
    std::cout << "Enter coordinates for second rectangle (x1 y1 x2 y2): ";
    for(int i = 0; i < 4; i++) {
        std::cin >> rec2[i];
    }
    
    // Check and display result
    bool result = isRectangleOverlap(rec1, rec2);
    std::cout << "Do rectangles overlap? " << (result ? "true" : "false") << std::endl;
    
    return 0;
}
