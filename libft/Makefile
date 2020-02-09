NAME = libft.a
SRC_1 =	ft_bzero.c			ft_memccpy.c		ft_memchr.c\
		ft_memcmp.c			ft_memcpy.c			ft_memset.c\
		ft_strdup.c			ft_strlen.c			ft_putchar.c\
		ft_putstr.c			ft_strcpy.c			ft_strcat.c\
		ft_atoi.c			ft_isalnum.c		ft_isalpha.c\
		ft_isascii.c		ft_isdigit.c		ft_memalloc.c\
		ft_isprint.c		ft_strchr.c			ft_strncpy.c\
		ft_strnstr.c		ft_strrchr.c		ft_strstr.c\
		ft_tolower.c		ft_toupper.c\
		ft_putnbr.c\
		ft_strcmp.c			ft_memmove.c		ft_strncmp.c\
		ft_strncat.c		ft_strlcat.c		ft_memdel.c\
		ft_strnew.c			ft_strclr.c			ft_striter.c\
		ft_striteri.c		ft_strequ.c			ft_strnequ.c\
		ft_strsub.c			ft_strjoin.c		ft_strtrim.c\
		ft_strsplit.c		ft_itoa.c			ft_putendl.c\
		ft_putchar_fd.c		ft_putstr_fd.c		ft_putendl_fd.c\
		ft_putnbr_fd.c		ft_strmap.c			ft_strmapi.c\
		ft_lstnew.c			ft_lstadd.c			ft_lstdelone.c\
		ft_lstdel.c			ft_lstiter.c		ft_lstmap.c\
		ft_strdel.c			get_next_line.c
SRCCD1 = ./srcs/
SRC_2 =	ft_printf.c checker.c colors.c display.c\
		flags.c ld_1.c ld_2.c ld_3.c ld_4.c\
		libft_modf.c libft_modf2.c ft_itoa_bpf.c\
		long_doudle.c maxnbr.c num_str.c num_str2.c\
		take_str.c take_str2.c
SRCCD2 = ./printf/


SRC = $(addprefix $(SRCCD1),$(SRC_1))
SRC += $(addprefix $(SRCCD2),$(SRC_2))
OFILES = $(SRC_1:.c=.o)
OFILES += $(SRC_2:.c=.o)
OBJCD = ./obj/
OBJ_CLEAN = $(addprefix $(OBJ_CD),$(OFILES)) 

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@mkdir $(OBJCD)
	@echo "\033[1;33mStarting compilation..."
	@gcc -Wall -Werror -Wextra -g -c $(SRC)
	@echo "\033[0;31mCreating library..."
	@ar rc $(NAME) $(OFILES)
	@echo "\033[0;31mGenerating index..."
	@ranlib $(NAME)
	@mv $(OFILES) $(OBJCD)

clean:
	@rm -rf $(OBJCD)
	@echo "Deleting:\n\033[33m $(OFILES)\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "Deleting:\n\033[33m $(NAME)\033[0m"

re : fclean all

.PHONY: all clean fclean re