NAME = libmx.a

LIBMX = libmx

ULS = uls

SRC = src

OBJ = obj

INC = inc

FLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: $(ULS) clean

$(ULS) :
	@make -C ./libmx 
	@clang $(FLAGS) $(SRC)/*.c -L $(LIBMX) -lmx -o $@

uninstall: clean
	@rm -rf ./libmx/$(NAME)
	@rm -rf $(ULS)

clean:
	@rm -rf $(OBJ)

reinstall: uninstall all
