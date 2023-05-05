# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 22:58:27 by nsainton          #+#    #+#              #
#    Updated: 2023/03/14 16:02:07 by nsainton         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

PROG := $(NAME).c

SRCS_DIR := sources

SRCS_NAMES = algorithms/turk.c  operations/basic_operations.c operations/do_ops.c \
			operations/operations.c operations/operations_both.c  stack/add.c \
			stack/algo_funcs.c stack/comparison.c stack/delete.c stack/getters.c \
			stack/helpers.c stack/init.c stack/print.c stack/searching.c stack/setters.c  \
			checking/infos.c checking/sorted.c  parsing/atoi_errors.c parsing/parsing.c  \
			debug/debug.c

SRCS := $(addprefix $(SRCS_DIR)/, $(SRCS_NAMES))

OBJS_DIR := objects

OBJS_NAMES := $(SRCS_NAMES:.c=.o)

OBJS := $(addprefix $(OBJS_DIR)/, $(OBJS_NAMES))

INCS_DIR := includes

INCS_NAMES := $(wildcard $(INCS_DIR)/*)

LFT_DIR := ../Libft

LFT_NAME := libft.a

LFT := $(addprefix $(LFT_DIR)/, $(LFT_NAME))

LIB := -lft

DIR := mkdir -p

CC := cc

CFLAGS := -Wall -Wextra -Werror

export C_INCLUDE_PATH=$(INCS_DIR):$(LFT_DIR)/$(INCS_DIR)
export LIBRARY_PATH=$(LFT_DIR)

all:
	$(MAKE) $(NAME)

names:
	echo $(OBJS)
	echo $(OBJS_NAMES)
	echo $(SRCS_NAMES)
	echo $(SRCS_DIR)

$(NAME): $(PROG) $(OBJS) $(LFT)
	$(CC) $(CFLAGS) $(GG) $(OPT) $< $(OBJS) $(LIB) -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCS_NAMES)
	if [ ! -d $(dir $@) ];\
	then $(DIR) $(dir $@);\
	fi
	$(CC) $(CFLAGS) $(GG) $(OPT) -c $< -o $@

$(LFT):
	$(MAKE) -C $(LFT_DIR)

clean:
	$(MAKE) clean -C $(LFT_DIR)
	$(RM) -r $(OBJS_DIR)

oclean:
	$(MAKE) oclean -C $(LFT_DIR)
	$(RM) $(NAME)

fclean:
	$(MAKE) clean
	$(MAKE) oclean

re:
	$(MAKE) fclean
	$(MAKE)

debug:
	$(MAKE) fclean
	$(MAKE) debug -C $(LFT_DIR)
	$(MAKE) GG=-g3 OPT=-O0

git:
	git add --all
	git commit
	git push

header:
	../Scripts/header.sh .

test:
	$(MAKE) && ./$(NAME) "1 2 3"

leaks:
	$(MAKE) debug && valgrind ./$(NAME) "2 1 3"

getsrcs:
	echo $(SOURCES_NAMES)
.PHONY: all clean fclean oclean re debug
.SILENT: test
