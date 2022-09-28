NAME = libft.a
 
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isascii.c \
	ft_isalpha.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
	ft_memcmp.c ft_memcpy.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c \
	ft_striteri.c ft_strjoin.c ft_strrchr.c ft_strtrim.c ft_substr.c \
	ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
	ft_strnstr.c ft_tolower.c ft_toupper.c ft_memmove.c \
	GNL/get_next_line_bonus.c GNL/get_next_line_utils_bonus.c \
	PRINTF/ft_print_hexa_maj.c PRINTF/ft_print_hexa_min.c PRINTF/ft_printf.c \
	PRINTF/ft_putchar_fd.c PRINTF/ft_putnbr_fd.c PRINTF/ft_putnbr_fd_u.c PRINTF/ft_putstr_fd.c \

BONUSSRCS = ft_lstadd_front.c ft_lstdelone.c ft_lstiter.c ft_lstclear.c \
	ft_lstlast.c ft_lstmap.c ft_lstadd_back.c ft_lstnew.c ft_lstsize.c

OBJS = ${SRCS:.c=.o}

BONUS = ${BONUSSRCS:.c=.o} 

HEADER = libft.h

CMD=gcc
FLAGS=-Wall -Werror -Wextra

%.o: %.c ${HEADER} Makefile
	$(CMD) $(FLAGS) -c $< -o $@ 

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

all: ${NAME}

bonus: $(NAME) $(BONUS)
	ar rcs $(NAME) $(BONUS)

clean:
	rm -rf $(OBJS) $(BONUS)
 
fclean: clean
	rm -rf ${NAME}
 
re: fclean all
 
.PHONY: clean all re fclean