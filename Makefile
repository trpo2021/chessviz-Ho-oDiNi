all: bin/chess

bin/chess: obj/src/chess/main.o obj/src/libchess/libchess.a
		g++ -Wall -Werror -I src -o bin/chess obj/src/chess/main.o obj/src/libchess/libchess.a

obj/src/libchess/libchess.a: obj/src/libchess/func.o 
		ar rcs obj/src/libchess/libchess.a obj/src/libchess/func.o

obj/src/chess/main.o: src/chess/main.cpp
		g++ -Wall -Werror -c -I src -o obj/src/chess/main.o src/chess/main.cpp

obj/src/libchess/func.o: src/libchess/func.cpp
		g++ -Wall -Werror -c -I src -o obj/src/libchess/func.o src/libchess/func.cpp
