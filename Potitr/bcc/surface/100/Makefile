CC=gcc
CFLAGS=-O3
EXE=main
OBJS= main.o  create_bcc_100.o generate_datafile_for_lammps.o input_file.o
LDFLAGS=-lm


.PHONY: all run clean

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) -o $(EXE) $(OBJS) $(LDFLAGS)

run: clean $(EXE)
	./$(EXE)



clean:
	rm -f $(EXE) $(OBJS)

