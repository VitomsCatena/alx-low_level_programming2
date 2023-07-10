#!/bin/bash

# Compile each .c file into a corresponding .o object file
for file in *.c
do
  gcc -c "$file" -o "${file%.c}.o"
done

# Create the static library liball.a from the object files
ar rcs liball.a *.o

# Clean up the object files
rm *.o

# Print the contents of the created static library
ar -t liball.a

