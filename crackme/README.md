# cracker

## How cracker works
* This is a simple script that attempts to crack an MD5 hash. 
* When run with an MD5 hash value in a directory with a file containing a list of potential passwords [wordlist.txt](./wordlist.txt), the script will:
1. Iterate through the list of passwords 
2. Compute the MD5 hash for each one, and 
3. Compare it to the original hash value. 
* If it finds a match, it will print the password and exit. 
* If it completes the list without finding a match, it will print a message indicating that the password was not found in the list.

## How to run cracker
* Run the following command in your terminal:
``` 
./cracker <hash>
```
## Current challenges
* wordlist.txt does not contain all the words in the world so may fail if passwords are more complicated
* wordlist.txt contains mostly English words and may fail for other languages
Still working on a way to get all words in an enlish dictionary into wordlist.txt
All collaborators are welcome!
