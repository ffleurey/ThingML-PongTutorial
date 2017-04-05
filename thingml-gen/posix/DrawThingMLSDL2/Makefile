CC = cc
LIBS = -lpthread -l SDL2
CFLAGS = -O2 -w
SRCS = DrawThingML.c SDL2Display.c DrawThingMLSDL2_cfg.c runtime.c
OBJS = DrawThingML.o SDL2Display.o DrawThingMLSDL2_cfg.o runtime.o

all : DrawThingMLSDL2

.c.o :
	${CC} ${CFLAGS} -c $< 

.cpp.o :
	${CC} ${CFLAGS} -c $< 

DrawThingMLSDL2 : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS) -lm

clean:
	rm -f *.o *~ DrawThingMLSDL2
