CFLAGS := -O2 -s
LDFLAGS := -O2 -s -lm

AR ?= ar
LUA ?= luajit

CFLAGS += -Iinclude -Iwren/src/include -Iraylib/src
LDFLAGS += -Lwren/lib -L. -lwren -Lraylib/src -lraylib

ifeq ($(OS),Windows_NT)
	LDFLAGS += -lopengl32 -lgdi32 -lwinmm -static
else ifeq ($(shell uname),Darwin)
	LDFLAGS += -framework CoreVideo -framework IOKit -framework Cocoa \
		-framework GLUT -framework OpenGL \
		-Wl,-pagezero_size,10000,-image_base,100000000
else
	LDFLAGS += -ldl -lX11 -lpthread
endif

WRAY_API := api/Raylib.wren api/Color.wren api/Key.wren api/Math.wren \
	api/Image.wren

SRC := src/wray.c src/wray_funcs.c src/wray_api.c src/wray_typecheck.c \
	src/wray_core.c src/wray_class.c src/wray_color.c src/wray_vector.c \
	src/wray_draw.c src/wray_rectangle.c src/wray_image.c

OBJ := $(SRC:.c=.o)

all: libraylib.a libwren.a libwray.a wray_standalone wray_embedded

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

libwren.a: wren
	$(MAKE) -C wren static

libraylib.a:
	$(MAKE) CFLAGS="$(CFLAGS)" LDFLAGS="$(LDFLAGS)" -C raylib/src

libwray.a: $(OBJ)
	$(AR) rcu $@ $^

src/wray_api.c: $(WRAY_API)
	$(LUA) tools/wren2str.lua $@ wray_api $^

wray_standalone: libwray.a src/wray_standalone.o
	$(CC) -o $@ $^ -lwray $(LDFLAGS)

wray_embedded: libwray.a src/lib/miniz.o src/wray_builder.o src/wray_embedded.o
	$(CC) -o $@ $^ -lwray $(LDFLAGS)

clean:
	rm -rf src/wray_api.c wray_embedded src/wray_builder.o \
		wray_standalone src/wray_standalone.o src/lib/miniz.o \
		libwray.a $(OBJ) src/wray_embedded.o

	$(MAKE) -C wren clean
	$(MAKE) -C raylib/src clean

.PHONY: libwray.a wray_standalone
