#g++ -I ./src -Wall -pedantic -std=iso9899:1999  src/main.c src/log.c -o res
# gcc - for compiling c and c++ code
# g++ - for compiling only c++
gcc -I ../src -Wall -pedantic -std=iso9899:1999  ../src/*.c -o res
