# ish makefile
# 2021-07-27 19:21
# by Ian D Brunton <iandbrunton at gmail dot com>

APPNAME = hlt2lb
VERSION = 0.1a
CC = gcc

CFLAGS = -DVERSION=\"$(VERSION)\" -DAPPNAME=\"$(APPNAME)\" -I.

SRCS = main.c
OBJS = $(SRCS:.c=.o)
DEPS = 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(APPNAME): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -rf *.o $(APPNAME)