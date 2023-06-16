XX = g++
CXXFLAGS = -std=c++17 -Wall -g -MMD
EXEC = chess
OBJECTS = chess_game.o board.o cell.o info.o player.o move.o piece.o king.o queen.o bishop.o knight.o rook.o pawn.o observer.o subject.o main.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
