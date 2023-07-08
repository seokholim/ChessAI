XX = g++
CXXFLAGS = -std=c++17 -Wall -g -MMD
EXEC = chess
OBJECTS = chess.o ./engine/engine.o ./engine/scenario.o ./engine/move.o ./board/board.o ./board/chess_board.o ./board/cell.o ./utility/info.o ./player/player.o ./pieces/piece.o ./pieces/chess_piece.o ./pieces/king.o ./pieces/queen.o ./pieces/bishop.o ./pieces/knight.o ./pieces/rook.o ./pieces/pawn.o ./pieces/observer.o ./pieces/subject.o main.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean