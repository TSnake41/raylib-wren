CFLAGS := -O2 -s
LDFLAGS := -O2 -s

AR ?= ar
LUA ?= luajit

PKG_CONFIG_PATH := raylib

CFLAGS += -Iinclude -Iraylib/src -Iwren/src/include
LDFLAGS += -Lraylib/src -lraylib -Lwren/lib -L. -lwren

ifeq ($(OS),Windows_NT)
	LDFLAGS += -lopengl32 -lgdi32 -lwinmm
endif

WRAY_API := api/Raylib.wren api/RlColor.wren api/RlKey.wren api/RlVector.wren \
	api/RlRectangle.wren api/RlImage.wren

SRC := src/wray.c src/wray_funcs.c src/wray_api.c src/wray_typecheck.c \
	src/wray_core.c src/wray_color.c src/wray_vector.c src/wray_draw.c \
	src/wray_rectangle.c src/wray_image.c

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
		libwray.a $(OBJ)

	$(MAKE) -C wren clean

.PHONY: libwray.a wray_standalone
