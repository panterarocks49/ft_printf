# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbrown <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/20 15:42:35 by jbrown            #+#    #+#              #
#    Updated: 2018/04/22 15:03:49 by jbrown           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
RM := /bin/rm -f

FLAGS := -Wall -Wextra -Werror
INCLUDE := -I ./include/
SRC_DIR := ./src/
OBJ_DIR := ./obj/

PRF_UTIL := buffer pf_itoa pf_uitoa_base pf_ftoa
PRF_HND := char str ptr percent int uint float wildcard int_ptr
PRF_MAIN := ft_printf parse_arg handle_arg

PRF_FUNCTS := $(PRF_MAIN) $(patsubst %, handlers/%, $(PRF_HND)) $(patsubst %, util/%, $(PRF_UTIL))

LFT_PRF := $(PRF_MAIN) $(PRF_HND) $(PRF_UTIL)
LFT_MEM := ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove ft_memchr ft_memcmp ft_memalloc ft_memdel
LFT_STR := ft_strlen ft_strdup ft_strcpy ft_strncpy ft_strcat ft_strncat ft_strlcat ft_strchr ft_strrchr \
		ft_strstr ft_strnstr ft_strcmp ft_strncmp ft_atoi ft_countwords ft_wordlen ft_tabledel ft_strnew \
		ft_strdel ft_strclr ft_striter ft_striteri ft_strmap ft_strmapi ft_strequ ft_strnequ ft_strsub \
		ft_strjoin ft_strtrim ft_strsplit ft_itoa
LFT_CHAR := ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper ft_tolower
LFT_WCHAR := ft_wclen ft_wstrlen
LFT_PUT := ft_putchar ft_putstr ft_putendl ft_putnbr ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd
LFT_LST := ft_lstnew ft_lstdelone ft_lstdel ft_lstadd ft_lstiter ft_lstmap ft_lstappend ft_lstsize ft_lstat ft_lstrev ft_lstdup
LFT_READ := get_next_line
LFT_MATH := ft_pow

FUNCTS := $(patsubst %, mem/%, $(LFT_MEM)) $(patsubst %, str/%, $(LFT_STR)) \
$(patsubst %, char/%, $(LFT_CHAR)) $(patsubst %, wchar/%, $(LFT_WCHAR)) $(patsubst %, put/%, $(LFT_PUT)) \
$(patsubst %, list/%, $(LFT_LST)) $(patsubst %, read/%, $(LFT_READ)) $(patsubst %, math/%, $(LFT_MATH)) \
$(patsubst %, ft_printf/%, $(PRF_FUNCTS))

CFILES := $(patsubst %, $(SRC_DIR)%.c, $(FUNCTS))
OFILES := $(patsubst %, $(OBJ_DIR)%.o, $(FUNCTS))

.PHONY: all clean fclean re

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)mem
	@mkdir -p $(OBJ_DIR)str
	@mkdir -p $(OBJ_DIR)char
	@mkdir -p $(OBJ_DIR)wchar
	@mkdir -p $(OBJ_DIR)put
	@mkdir -p $(OBJ_DIR)list
	@mkdir -p $(OBJ_DIR)read
	@mkdir -p $(OBJ_DIR)math
	@mkdir -p $(OBJ_DIR)ft_printf/handlers
	@mkdir -p $(OBJ_DIR)ft_printf/util
	@echo [INFO] Libftprintf Object Files Directory Created

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@gcc $(FLAGS) $(INCLUDE) -o $@ -c $<
	@echo [INFO] Compiling $@ into $<

$(NAME): $(OBJ_DIR) $(OFILES)
	@ar rc $(NAME) $(OFILES)
	@echo [INFO] $(NAME) Created
	@ranlib $(NAME)
	@echo [INFO] ranlib $(NAME)


clean:
	@rm -rf $(OBJ_DIR)
	@echo [INFO] Libftprintf Object Files Directory Destroyed

fclean: clean
	@$(RM) $(NAME)
	@echo [INFO] $(NAME) Destroyed

re: fclean all
