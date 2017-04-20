CC = cc
LIBS = -lpthread -l SDL2 -l SDL2_ttf
CFLAGS = -O2 -w
SRCS = SDL2BounceApp.c BouncingBall.c SDL2BounceCfg_cfg.c Timer.c runtime.c
OBJS = SDL2BounceApp.o BouncingBall.o SDL2BounceCfg_cfg.o Timer.o runtime.o

all : SDL2BounceCfg

.c.o :
	${CC} ${CFLAGS} -c $< 

.cpp.o :
	${CC} ${CFLAGS} -c $< 

SDL2BounceCfg : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS) -lm

clean:
	rm -f *.o *~ SDL2BounceCfg
