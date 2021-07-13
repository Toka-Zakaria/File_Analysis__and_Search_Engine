# File_Analysis__and_Search_Engine
### To implement a tool that analyzes a text file and returns information about its content. It also allows a simple search for words in the file.
**Overview:**
- Code uses an in-order linked list to build a file indexing
and (simple) search engine service.
- The program is passed a text file name and a file containing commands.
- Code is expected to read the input file. Separators such as , ; : ' ` & . [ ] { }
( ) should be discarded
- Each word is then inserted into the in-order list, along with the line number
in which it exists in the file. 
- First line in the file is line #1. **Note**: book,
Book and BOOK are the same word (Case insensitive).
- The following actions will then be performed by the program. 
The file containing the commands, have a set of commands. Each command is written in
a separate line. The programs reads the commands line-by-line and executes
them.
1. command: **wordCount** -> Prints the number of words in the file
2. command: **distWords** -> Prints the number of distinct words in the file
3. command: **charCount** -> Prints the number of characters in the file (in-
cluding spaces and newlines/carriage return)
4. command: **frequentWord** -> Prints the word(s) that had occurred the most
in the input file excluding common language constructs like (a, an, the,
in, on, of, and, is , are). If two or more words have the same number of
repetitions, one should print all of them sorting them in an alphabetical
order
5. command: **countWord** myword -> prints the number of myword occurrence
in the file
6. command: **starting** mysub -> Prints all words that start with "mysub"
followed by their number of occurrences. For example, if the command
is "starting Te", it shall print all words starting with "Te", for example
"Temperature" "Temperament".
7. command : **containing** mystr -> Prints all words that contain the string
"mystr" followed by their number of occurrences. E.g. if the program is
passed a command "containing al", it shall print words such as "shall" "all"
in a table format
8. command: **search** mystr -> Prints all words that contain the string "mystr"
along with the line numbers in which they exist.
- **Error Handling**:
program checks for the correctness of every command (e.g. number of argu-
ments).
it uses the following error messages to reflect the reason of not performing
the command
- "File not found"
- "Undefined command"
- "Incorrect number of arguments"
