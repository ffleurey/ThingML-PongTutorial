CC = cc
LIBS = -lpthread 
CFLAGS = -O2 -w
SRCS = BrowserCanvasDisplay.c VelocityController.c TimerBrowser.c SimpleBrick.c SimpleBrickBrowserCanvas_cfg.c runtime.c
OBJS = BrowserCanvasDisplay.o VelocityController.o TimerBrowser.o SimpleBrick.o SimpleBrickBrowserCanvas_cfg.o runtime.o

all : SimpleBrickBrowserCanvas

.c.o :
	${CC} ${CFLAGS} -c $< 

.cpp.o :
	${CC} ${CFLAGS} -c $< 

SimpleBrickBrowserCanvas : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS) -lm

clean:
	rm -f *.o *~ SimpleBrickBrowserCanvas
