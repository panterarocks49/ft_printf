# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbrown <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/20 15:42:35 by jbrown            #+#    #+#              #
#    Updated: 2018/03/06 12:02:56 by jbrown           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
RM := /bin/rm -f

FLAGS := -Wall -Wextra -Werror
INCLUDE := -I ./include/

#PRF_HND :=

LFT_PRF := ft_printf
LFT_MEM := ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove ft_memchr ft_memcmp ft_memalloc ft_memdel
LFT_STR := ft_strlen ft_strdup ft_strcpy ft_strncpy ft_strcat ft_strncat ft_strlcat ft_strchr ft_strrchr \
		ft_strstr ft_strnstr ft_strcmp ft_strncmp ft_atoi ft_countwords ft_wordlen ft_tabledel ft_strnew \
		ft_strdel ft_strclr ft_striter ft_striteri ft_strmap ft_strmapi ft_strequ ft_strnequ ft_strsub \
		ft_strjoin ft_strtrim ft_strsplit ft_itoa
LFT_CHAR := ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper ft_tolower
LFT_PUT := ft_putchar ft_putstr ft_putendl ft_putnbr ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd
LFT_LST := ft_lstnew ft_lstdelone ft_lstdel ft_lstadd ft_lstiter ft_lstmap ft_lstappend ft_lstsize ft_lstat ft_lstrev ft_lstdup
LFT_READ := get_next_line

FILES := $(LFT_MEM) $(LFT_STR) $(LFT_CHAR) $(LFT_PUT) $(LFT_LST) $(LFT_READ) $(LFT_PRF)

FUNCTS := $(patsubst %, mem/%, $(LFT_MEM)) $(patsubst %, str/%, $(LFT_STR)) \
$(patsubst %, char/%, $(LFT_CHAR)) $(patsubst %, put/%, $(LFT_PUT)) \
$(patsubst %, list/%, $(LFT_LST)) $(patsubst %, read/%, $(LFT_READ)) \
$(patsubst %, ft_printf/%, $(LFT_PRF))

CFILES := $(patsubst %, ./src/%.c, $(FUNCTS))
OFILES := $(patsubst %, %.o, $(FILES))

.PHONY: all clean fclean re

all: $(NAME)

$(OFILES):
	@gcc $(FLAGS) $(INCLUDE) -c $(CFILES)

$(NAME): $(OFILES)
	@ar rc $(NAME) $(OFILES)
	@ranlib $(NAME)

clean:
	@$(RM) $(OFILES)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
