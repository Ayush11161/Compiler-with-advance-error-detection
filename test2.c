int main() {
    // Test variable declaration and initialization
    int x = 5;
    float y = 3.14;
    
    // Test type mismatch
    x = y;  // Should generate error
    
    // Test undefined variable
    z = 10;  // Should generate error
    
    // Test control structures
    if (x > 3) {
        while (y > 0) {
            y = y - 1.0;
        }
    }
    
    return 0;
} 