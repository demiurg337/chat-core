#g++ -I ./src -Wall -pedantic -std=iso9899:1999  src/main.c src/log.c -o res
#g++ -I ../src -Wall -pedantic -std=iso9899:1999  ../src/*.c -o res
g++ -I ../src  -Wall -pedantic -std=iso9899:1999  ../src/*.c -o res -lncurses
