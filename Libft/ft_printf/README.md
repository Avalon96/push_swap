*This project has been created as part of the 42 curriculum by aunverdi.*

# **Description**

This project is about re-implementing a part of the printf function.

# **Instructions**

In a terminal at the root of the project, type "make" or "make all" to create the *.o files and both of the libraries. Then you can type make clean to clear out the *.o files to reduce the clutter.

## Makefile commands

make all: creates the *.o files for both libft and libftprintf, compiles them, then creates the libraries.

make clean: deletes *.o files.

make fclean: deletes *.o files and the library.

make re: deletes *.o files and the library, then does make all.

# **Resources**

Geeks For Geeks - https://www.geeksforgeeks.org/c/variadic-functions-in-c/

AI is used for learning various printf flags and how to use multiple Makefiles from a single Makefile.

# **DSA**

There are 6 functions for the required flags. A flag checker decides which function to run and variadic functions count how many flags are used.