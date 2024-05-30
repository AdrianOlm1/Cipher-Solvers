# Cipher-Solvers

### Name: Adrian Olmos

## Overview

C files meant to solve ciphers from Math-134 Cryptography

## Files Included
- **Ceaser.c**
- **SubsitutionSolver.c**
- **Vigenere.c**
- **README.md**

## Descriptions

### Ceaser:
To use Caesar, first input whether you want to encrypt (E) or decrypt (D). Then input the shift value and lastly the string. The encrypted or decrypted string will be outputted, and then the program will exit.

### Substitution Solver:
- **SubSolver**: This function will create the key given the initial word in the code, then solve for the whole string written in the code.
- **AlphaCounter**: Outputs the total count of each letter in the given string.
- **AlphaSolver**: This function will first take a character that will be replaced in the given string and then take a character that the initial character will be replaced with. Afterward, the whole string will be outputted with changed letters in lowercase and green and unchanged letters in uppercase and red. This process will continue until the string contains no more uppercase characters or hopefully the substitution is solved.

### Vigenere:
- **Decrypt**: Decrypts a given string text and key using the Vigenere cipher.
- **Encrypt**: Encrypts a given string text and key using the Vigenere cipher.
