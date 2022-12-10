# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 17:54:37 by mabbas            #+#    #+#              #
#    Updated: 2022/11/12 01:35:41 by mabbas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
#define compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
#Source Functions for the library
source = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		 ft_strlen.c ft_memcpy.c ft_memset.c ft_bzero.c  \
		 ft_atoi.c ft_memmove.c ft_toupper.c \
		 ft_tolower.c ft_strlcpy.c ft_strlcat.c   \
		 ft_memchr.c ft_strchr.c ft_memcmp.c ft_strrchr.c ft_strncmp.c ft_strnstr.c \
		 ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c \
    	 ft_split.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
    	 ft_putendl_fd.c ft_putnbr_fd.c

bonus_src = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
       	    ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

# The object files after compiling
objects = $(source:%.c=%.o)
objbonus = $(bonus_src:%.c=%.o)

all: $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(objects)
	@echo "$$HEADER"
	@$(CC) $(CFLAGS) -c $(source)
	@ar rcs $(NAME) $(objects)

clean:
	@rm -rf $(objects) $(objbonus)

fclean: clean
	@echo "$$HEADER3"
	@rm -rf $(NAME)


re: fclean all	

bonus: 
	@echo "$$HEADER4"
	@$(CC) $(CFLAGS) -c $(bonus_src)
	@ar rcs $(NAME) $(objbonus)


.PHONY: all clean fclean re bonus





define HEADER

		>>>>>>>--<<<<<Beware!! We are now Compiling <<<<<-->>>> !_!
			“Fool! Nothing but black ink runs through my veins!”
							― Hiromu Arakawa      
endef
export HEADER

define HEADER3


	░█████╗░░█████╗░██╗░░░██╗████████╗██╗░█████╗░███╗░░██╗██╗██╗                           
	██╔══██╗██╔══██╗██║░░░██║╚══██╔══╝██║██╔══██╗████╗░██║██║██║                    
	██║░░╚═╝███████║██║░░░██║░░░██║░░░██║██║░░██║██╔██╗██║██║██║                    
	██║░░██╗██╔══██║██║░░░██║░░░██║░░░██║██║░░██║██║╚████║╚═╝╚═╝                    
	╚█████╔╝██║░░██║╚██████╔╝░░░██║░░░██║╚█████╔╝██║░╚███║██╗██╗                    
	░╚════╝░╚═╝░░╚═╝░╚═════╝░░░░╚═╝░░░╚═╝░╚════╝░╚═╝░░╚══╝╚═╝╚═╝
endef
export HEADER3

define HEADER4

		█▓▒▒░░░<<-- 🅛 🅘 🅝 🅚 🅔 🅓    🅛 🅘 🅢 🅣   🅜 🅐 🅓 🅝 🅔 🅢 🅢 -->>░░░▒▒▓█
endef
export HEADER4
