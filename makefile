CFLAGS := -O0
LDFLAGS := -O0 -g

AR ?= ar

CFLAGS += -Iinclude `pkg-config --cflags raylib` \
	-Iwren/src/include
LDFLAGS += `pkg-config --libs --static raylib` \
	-Lwren/lib -L. -lwren

SRC := src/wray.c src/wray_funcs.c src/wray_core.c
OBJ := $(SRC:.c=.o)

all: tools/bin2c libwren.a libwray.a wray_standalone

libwren.a: wren
	$(MAKE) -C wren static

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

tools/bin2c: tools/bin2c.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.wren.c: %.wren
	tools/bin2c $< $@ $<

libwray.a: $(OBJ)
	ar rcu $@ $^

wray_standalone: src/wray_standalone.o
	$(CC) -o $@ $^ $(LDFLAGS) -lwray

clean:
	rm -rf wray_standalone libwray.a tools/bin2c tools/bin2c.o $(OBJ)
	$(MAKE) -C wren clean

.PHONY: libwray.a wray_standalone
