XX = g++
CXXFLAGS = -std=c++17 -Wall -g -MMD
EXEC = chess
OBJECTS = piece.o chess_game.o board.o cell.o info.o player.o move.o rook.o observer.o subject.o main.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
