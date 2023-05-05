# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 22:58:27 by nsainton          #+#    #+#              #
#    Updated: 2023/05/05 17:13:48 by nsainton         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

PROG := $(NAME).c

SRCS_DIR := sources

SRCS_SUBDIRS := $(shell find $(SRCS_DIR) -type d)

SRCS_NAMES = $(subst $(SRCS_DIR)/,,$(foreach dir, $(SRCS_SUBDIRS), $(wildcard $(dir)/*.c)))

SRCS := $(addprefix $(SRCS_DIR)/, $(SRCS_NAMES))

OBJS_DIR := objects

OBJS_NAMES := $(SRCS_NAMES:.c=.o)

OBJS := $(addprefix $(OBJS_DIR)/, $(OBJS_NAMES))

INCS_DIR := includes

INCS_NAMES := $(wildcard $(INCS_DIR)/*)

LIBS_DIR ?= $(addprefix $(shell pwd)/, libs)

LFT_DIR := $(addprefix $(LIBS_DIR)/, libft)

LFT_URL := git@github.com:nsainton/libft.git

LFT_NAME := libft.a

LFT := $(addprefix $(LFT_DIR)/, $(LFT_NAME))

LIB := -lft

DIR := mkdir -p

CC := cc

CFLAGS := -Wall -Wextra -Werror

export C_INCLUDE_PATH=$(INCS_DIR):$(LFT_DIR)/$(INCS_DIR)
export LIBRARY_PATH=$(LFT_DIR)

all: | $(LFT_DIR)
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

$(LFT_DIR):
	git clone $(LFT_URL) $@

clean:
	$(MAKE) clean -C $(LFT_DIR)
	$(RM) -r $(OBJS_DIR)

oclean:
	$(MAKE) oclean -C $(LFT_DIR)
	$(RM) $(NAME)

lclean:
	$(RM) -f $(LIBS_DIR)

fclean:
	$(MAKE) clean
	$(MAKE) oclean
	$(MAKE) lclean

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
	echo $(SRCS_NAMES)

.PHONY: all clean fclean oclean re debug
.SILENT: test
