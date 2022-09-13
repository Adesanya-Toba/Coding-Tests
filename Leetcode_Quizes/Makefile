# Make is all about rules and dependencies

# Using a variable to specify the compiler I would be using
CC=g++

# Creating an all task that will run whenever I just call 'make'
all: palindrome

# Here, I am creating a rule called palindrome that depends on palindrome_num.cpp.
# Whenever that file changes, it runs this rule, which essentially just compiles the program
palindrome: palindrome_num.cpp
	g++ -o palindrome palindrome_num.cpp

palindrome2: palindrome_num.cpp
	$(CC) -o palindrome palindrome_num.cpp # Using a variable here
	./palindrome
	clean

# It makes sense to add a clean rule to clean up the build after you're done
clean:
	rm palindrome