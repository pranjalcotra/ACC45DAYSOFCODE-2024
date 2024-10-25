#include <stdio.h>
#include <string.h>

// Function to remove the first occurrence of `part` in `s`
void removeFirstOccurrence(char *s, const char *part) {
    int lenS = strlen(s);
    int lenPart = strlen(part);
    char *pos = strstr(s, part);  // Find the first occurrence of `part` in `s`

    if (pos != NULL) {
        // Shift all characters after `part` to the left
        memmove(pos, pos + lenPart, lenS - (pos - s) - lenPart + 1);
    }
}

// Function to remove all occurrences of `part` from `s`
void removeAllOccurrences(char *s, const char *part) {
    while (strstr(s, part) != NULL) {
        removeFirstOccurrence(s, part);
    }
}

int main() {
    char s[100] = "daabcbaabcbc";
    char part[] = "abc";

    removeAllOccurrences(s, part);

    printf("Resulting string: %s\n", s);

    return 0;
}