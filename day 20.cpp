#include <stdio.h>

int isPalindrome(int x) {
    // Negative numbers and numbers ending with 0 (but not 0 itself) can't be palindromes
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return 0;
    }
    
    int reversed = 0;
    int original = x;

    // Reversing half of the number
    while (x > reversed) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }

    // Check if original is equal to the reversed half (for even length)
    // Or original is equal to reversed/10 (for odd length)
    return x == reversed || x == reversed / 10;
}

int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);

    if (isPalindrome(num)) {
        printf("%d is a palindrome.\n", num);
    } else {
        printf("%d is not a palindrome.\n", num);
    }

    return 0;
}