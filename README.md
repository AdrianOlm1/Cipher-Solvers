# Cipher-Solvers
C files meant to solve ciphers from Math-134 Cryptography

Ceaser:
To use Ceaser, first input encrypting(E) or decrypting(D), then input shift and lastly the string. The encrypted or decrypted string will ouput then exit.

Subsitution Solver:
The SubSolver function will solve for create the key given the intial word in the code then solve for the whole string that is written in the code.
The AlphaCounter function will output the total of each letter in the given string.
The AlphaSolver function will first take a char that will be replaced in the given string and then take a char that the intial char will be replaced with. After the whole string will be outputted with changed letters in lowercase and green and unchanged in uppercase and red. This will continue until the string contains no more uppercase chars or hopefully the substitution is solved.

Vigenere:
The Decrypt Function will decrypt a given string text and key using the Vigenere cipher.
The Encrypt Function will encrypt a given string text and key using the Vigenere cipher.
