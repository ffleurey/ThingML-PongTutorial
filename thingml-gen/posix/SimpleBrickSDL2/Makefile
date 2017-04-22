CC = cc
LIBS = -lpthread -l SDL2
CFLAGS = -O2 -w
SRCS = SimpleBrick.c SDL2Display.c SimpleBrickSDL2_cfg.c Timer.c runtime.c
OBJS = SimpleBrick.o SDL2Display.o SimpleBrickSDL2_cfg.o Timer.o runtime.o

all : SimpleBrickSDL2

.c.o :
	${CC} ${CFLAGS} -c $< 

.cpp.o :
	${CC} ${CFLAGS} -c $< 

SimpleBrickSDL2 : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS) -lm

clean:
	rm -f *.o *~ SimpleBrickSDL2
