all: analyse


analyse: lexer.o symbole.o etats.o automate.o main.o
	g++ -o analyse lexer.o symbole.o etats.o automate.o main.o

lexer.o: lexer.cpp lexer.h
	g++ -o lexer.o -c lexer.cpp

symbole.o: symbole.cpp symbole.h
	g++ -o symbole.o -c symbole.cpp

etats.o: Etats.cpp Etats.h
	g++ -o etats.o -c Etats.cpp

automate.o: Automate.cpp Automate.h
	g++ -o automate.o -c Automate.cpp

main.o: main.cpp symbole.h lexer.h Etats.h
	g++ -o main.o -c main.cpp

clean:
	del *.o

