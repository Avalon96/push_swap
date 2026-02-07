*This project has been created as part of the 42 curriculum by aunverdi.*

# **Description**

get_next_line reads the bytes in a file until it reaches a new line character or EOF, then returns the line.

# **Instructions**

Compile everything with -D BUFFER_SIZE=n flag, where n is any number you choose. Buffer size must be a positive number for the program to work.

```cc -Wall -Wextra -Werror -D BUFFER_SIZE=100 get_next_line.c get_next_line_utils.c main.c```
# **Resources**
Geeks For Geeks - https://www.geeksforgeeks.org/c/input-output-system-calls-c-create-open-close-read-write/

Geeks For Geeks - https://www.geeksforgeeks.org/c/static-variables-in-c/

AI was used to understand how to run and test get_next_line, as well as getting hints for the algorithm.

# **DSA**

Buffer holds BUFFER_SIZE characters from the file, then it will copy them to Stash. If stash has a new line character in it, string up until that part gets extracted and put into Line. The extracted line gets removed from the stash. The program continues until it reaches EOF.