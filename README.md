# 42Fillit
42 school's Fillit project (2nd real project)

The goal is to form the smallest square possible using up-to 26 trtriminos
(provided in a file), in the shortest time possible.

# The pogram should be able to:

- Analyse it's args (and err out if needed)
- Read the provided file
- Analyse the provided file (and err out if needed)
- Create the smallest square possible
- Do it before year 3000 :D

# The provided Makefile does:

- Compile the program
- Avoids relinking if no changes have been made
- Recompiles if changes have been made

	The rules are:

- all: Builds the binary (rebuilds if the srcs change)
- clean: clean the object files
- fclean: same as clean + removes binary
- re: fclean + all
