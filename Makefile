OBJ      = main.o date.o graph.o neighbours.o predecessors.o search.o stack.o paths.o dataloader.o
LINKOBJ  = main.o date.o graph.o neighbours.o predecessors.o search.o stack.o paths.o dataloader.o
BIN      = dfs.exe
CXXFLAGS = $(CXXINCS) -g3
CFLAGS   = $(INCS) -g3
RM       = rm.exe -f

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CC) $(LINKOBJ) -o $(BIN) $(LIBS)

main.o: main.c
	$(CC) -c main.c -o main.o $(CFLAGS)

date.o: date.c
	$(CC) -c date.c -o date.o $(CFLAGS)

graph.o: graph.c
	$(CC) -c graph.c -o graph.o $(CFLAGS)

neighbours.o: neighbours.c
	$(CC) -c neighbours.c -o neighbours.o $(CFLAGS)

predecessors.o: predecessors.c
	$(CC) -c predecessors.c -o predecessors.o $(CFLAGS)

search.o: search.c
	$(CC) -c search.c -o search.o $(CFLAGS)

stack.o: stack.c
	$(CC) -c stack.c -o stack.o $(CFLAGS)

paths.o: paths.c
	$(CC) -c paths.c -o paths.o $(CFLAGS)

dataloader.o: dataloader.c
	$(CC) -c dataloader.c -o dataloader.o $(CFLAGS)
