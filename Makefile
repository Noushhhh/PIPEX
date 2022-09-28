NAME = pipex

LIBFT = ./libft/libft.a \

SRCS =  pipex.c \
		parse.c \
		exec.c \
		lst_fts.c \

OBJS = ${SRCS:.c=.o}

HEADER = pipex.h \

CMD = gcc
FLAGS = -Wall -Werror -Wextra -I mlx

%.o: %.c $(HEADER)
		$(CMD) $(FLAGS) -c $< -o $@ 

all: libft $(NAME)

libft:
			 make -C ./libft

$(NAME): $(OBJS) $(LIBFT) Makefile
		$(CMD) $(OBJS) $(LIBFT) -o $(NAME)

clean:
		rm -rf $(OBJS) 
		make clean -C ./libft
 
fclean: clean
		rm -rf $(NAME)
 
re: fclean all
 
.PHONY: libft mlx clean all re fclean
