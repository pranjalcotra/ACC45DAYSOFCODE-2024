Here’s the full C++ implementation of pow(x, n) to calculate :

#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;
        
        long long N = n;  // Use long long to handle the case when n is INT_MIN
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        
        double result = 1;
        double current_product = x;
        
        while (N > 0) {
            if (N % 2 == 1)
                result *= current_product;
            current_product *= current_product;
            N /= 2;
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    double x;
    int n;
    
    cout << "Enter base (x): ";
    cin >> x;
    cout << "Enter exponent (n): ";
    cin >> n;
    
    double result = solution.myPow(x, n);
    cout << x << " raised to the power " << n << " is: " << result << endl;
    
    return 0;
}

Explanation:

myPow function implements the power calculation using exponentiation by squaring.

Handling of negative exponents: If n is negative, we convert the problem into calculating  and use a positive n.

Edge case handling: We use long long for N to avoid overflow when n is INT_MIN.


Time Complexity:

O(log n) because we reduce n by half at each iteration.