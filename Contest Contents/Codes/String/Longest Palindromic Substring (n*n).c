#include <stdio.h>
#define MX_SIZE 1000

char *longestPalindrome(char *inputString) {
  int oddLengthPalindrome[MX_SIZE], evenLengthPalindrome[MX_SIZE];
  int SIZE = 0, maxLength = 0, indexOfPalindrome = -1;

  for (int i = 0; inputString[i]; i++) {
    oddLengthPalindrome[i] = evenLengthPalindrome[i] = 0;
    SIZE++;
  }

  for (int i = 0; inputString[i]; i++) {
    
    oddLengthPalindrome[i] = 1;
    // Calculating the number of odd length palindrome consider 'i' as a center
    while ((0 <= (i - oddLengthPalindrome[i])) && ((i + oddLengthPalindrome[i]) < SIZE) &&
    (inputString[i - oddLengthPalindrome[i]] == inputString[i + oddLengthPalindrome[i]])) {
      oddLengthPalindrome[i]++;
    }

    // checking center 'i' making longest palindrome for odd length
    if (maxLength < oddLengthPalindrome[i] * 2 - 1) {
      maxLength = oddLengthPalindrome[i] * 2 - 1;
      indexOfPalindrome = i;
    }

    evenLengthPalindrome[i] = 0;
    // Calculating the number of even length palindrome consider 'i' as a center
    while ((0 <= i - evenLengthPalindrome[i] - 1) && (i + evenLengthPalindrome[i] < SIZE) &&
    (inputString[i - evenLengthPalindrome[i] - 1] == inputString[i + evenLengthPalindrome[i]])) {
      evenLengthPalindrome[i]++;
    }

    // checking center 'i' making longest palindrome for even length
    if (maxLength < evenLengthPalindrome[i] * 2) {
      maxLength = evenLengthPalindrome[i] * 2;
      indexOfPalindrome = i;
    }
  }

/**
 * * Storing Longest palindrome starting
 * 
 * 0-indexing calculation
 * 
 * Allocating memory for palindromic string as returnString
 * 
 * Legnth of Longest palindromic string is maxLength
 * maxLength can be odd or even
 * 
 * If length is odd, starting position will be "(center index of palindrome) - maxLength/2),
 * End position will be "(center index of palindrome) - maxLength/2)"
 * 
 * For even length,
 * start position => "(center index of palindrome) - maxLength/2),
 * end position => "(center index of palindrome) - maxLength/2-1)"
 * 
 * Center index of Palindrome => 'indexOfPalindrome' (second position consider as a center for even length)
 */
  char *returnString = (char *)malloc(sizeof(char) * (maxLength + 1));
  int index = 0;

  if (maxLength & 1) {
    for (int i = indexOfPalindrome - maxLength / 2; i <= indexOfPalindrome + maxLength / 2; i++) {
      returnString[index++] = inputString[i];
    }
  } 
  else {
    for (int i = indexOfPalindrome - maxLength / 2; i <= indexOfPalindrome + maxLength / 2 - 1; i++) {
      returnString[index++] = inputString[i];
    }
  }

  returnString[index] = '\0';
  return returnString;
}

int main() {
  char inputString[MX_SIZE];
  scanf("%s", inputString);
  char *longestPalindromeString = longestPalindrome(inputString);
  puts(longestPalindromeString);
  return 0;
}
