#include <iostream>
#include <string>
#include <vector>

/**
 * Searches string for occurrence of pattern.
 * @param {std::string} search - The string in which the pattern is searched
 * @param {std::string} pattern - The pattern that is search
 * @param {int} maxNumberOfMismatches - Number of mismatched characters allowed to still be a match
 * @param {int} startPosition - Position from which we search
 * @return {int} Index of first character of occurrence
 */
int boyerMooreMismatch(std::string search, std::string pattern, int maxNumberOfMismatches = 0, int startPosition = 0) {
    int patternLength = pattern.size();
    int searchLength  = search.size();
    int shift         = startPosition;
    int mismatches    = 0;
    int firstMismatch = -1;
    // Vector to store how much we want to shift if we have a mismatch.
    std::vector<int> badChars(256, 1);
    // Initialize values.
    for (int i = 0; i < patternLength; i++) {
        badChars.at(static_cast<int>(pattern.at(i))) = patternLength - i - 1;
    }

    // Search for as long as pattern fits in search string
    while (shift < searchLength - patternLength + 1) {
        // Keep track of current character of pattern to compare
        int j = patternLength - 1;

        // As long as pattern has characters left
        while (j >= 0) {
            if (pattern.at(j) == search.at(shift + j)) {
                // If match, continue
                j--;
            } else if (mismatches < maxNumberOfMismatches) {
                // If not match, keep track of the first mismatch because this is the number we have to use for
                // shifting afterwards
                if (firstMismatch == -1) {
                    firstMismatch = j;
                }
                mismatches++; // Count mismatches
                j--;
            } else {
                // No match or number of mismatches exceeded
                break;
            }
        }

        if (j < 0) {
            // Found occurrence
            return shift;
        } else if (firstMismatch > -1) {
            // There were to many mismatches.
            // Shift by the value of the character at which the first mismatch happened and reset mismatch variables.
            shift += badChars.at(static_cast<int>(search.at(shift + firstMismatch)));
            firstMismatch = -1;
            mismatches    = 0;
        } else {
            // We only land here if no mismatches are allowed and we have not found an occurrence.
            // Shift by the value of the character that mismatched.
            shift += badChars.at(static_cast<int>(search.at(shift + j)));
        }
    }

    return -1;
}

int main() {
    std::string pattern = "0123Hund89Hund11";
//    std::string pattern = "GDFGHJDFFGJJGHJTYREYWERWETYDSGF";
    std::string search  = "FFKJJ";
    std::string text    = "Hund";

    std::cout << boyerMooreMismatch(pattern, text);

    return 0;
}