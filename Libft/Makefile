# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmaria <lmaria@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/28 13:25:14 by lmaria            #+#    #+#              #
#    Updated: 2025/01/16 16:21:53 by lmaria           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re

# Nom de l'exécutable
NAME = libft.a

# Répertoires
OBJS_DIR = objs/
SRCS_DIR = srcs/

CHARACTERS_DIR = characters/
LISTS_DIR = lists/
MEMORIES_DIR = memories/
NUMBERS_DIR = numbers/
PRINTS_DIR = prints/
STRINGS_DIR = strings/

#Options de compilation
CC = cc
CFLAGS = -Wall -Werror -Wextra

# Source Files
LST_CHARACTERS 	= 		ft_isalnum.c 		ft_isalpha.c 			\
						ft_isascii.c 		ft_isdigit.c 			\
						ft_isprint.c		ft_tolower.c			\
						ft_toupper.c

LST_LISTS 		= 		ft_lstadd_back.c 	ft_lstadd_front.c		\
						ft_lstclear.c 		ft_lstdelone.c 			\
						ft_lstiter.c 		ft_lstlast.c 			\
						ft_lstmap.c 		ft_lstnew.c 			\
						ft_lstsize.c			
									
LST_MEMORIES	= 		ft_bzero.c 			ft_calloc.c 			\
						ft_free_and_null.c	ft_memchr.c 			\
						ft_memcmp.c 		ft_memcpy.c				\
						ft_memmove.c 		ft_memset.c
						
LST_NUMBERS		=		ft_atoi.c			ft_itoa.c
					
LST_PRINTS 		= 		ft_printf.c			ft_putchar_fd.c 		\
						ft_putendl_fd.c 	ft_putnbr_base_fd.c		\
						ft_putnbr_fd.c 		ft_putnbr_unsigned_fd.c	\
						ft_putstr_fd.c		get_next_line.c
						
LST_STRINGS		=		ft_split.c 			ft_strchr.c				\
						ft_strdup.c			ft_striteri.c			\
						ft_strjoin.c		ft_strlcat.c 			\
						ft_strlcpy.c		ft_strlen.c 			\
						ft_strmapi.c		ft_strncmp.c			\
						ft_strnstr.c		ft_strrchr.c			\
						ft_strtrim.c		ft_substr.c
									

	


# Fichiers objets
SRCS	=	$(addprefix $(SRCS_DIR)$(CHARACTERS_DIR), $(LST_CHARACTERS))	\
			$(addprefix $(SRCS_DIR)$(LISTS_DIR), $(LST_LISTS))				\
			$(addprefix $(SRCS_DIR)$(MEMORIES_DIR), $(LST_MEMORIES))		\
			$(addprefix $(SRCS_DIR)$(NUMBERS_DIR), $(LST_NUMBERS))			\
			$(addprefix $(SRCS_DIR)$(PRINTS_DIR), $(LST_PRINTS))			\
			$(addprefix $(SRCS_DIR)$(STRINGS_DIR), $(LST_STRINGS))
OBJS	=	$(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.o))

# Règles
all : $(NAME)

$(NAME) : $(OBJS)
	@ar rcs $@ $^
	@echo "Library $(NAME) created."

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c Makefile libft.h | $(OBJS_DIR)
	@$(CC) -o $@ -c $< $(CFLAGS)

$(OBJS_DIR):
	@mkdir -p	$(OBJS_DIR)					$(OBJS_DIR)$(CHARACTERS_DIR)	\
				$(OBJS_DIR)$(LISTS_DIR)		$(OBJS_DIR)$(MEMORIES_DIR)		\
				$(OBJS_DIR)$(NUMBERS_DIR)	$(OBJS_DIR)$(PRINTS_DIR)		\
				$(OBJS_DIR)$(STRINGS_DIR)

print-nameexec:
	@echo $(NAME)

clean :
	@rm -rf $(OBJS_DIR)

fclean : clean
	@rm -f $(NAME)

re : fclean all
