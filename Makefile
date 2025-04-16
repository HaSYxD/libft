NAME = libft.a
OBJDIR = build
SRC = char_manip/ft_isalpha.c char_manip/ft_isdigit.c char_manip/ft_isalnum.c\
      char_manip/ft_isascii.c char_manip/ft_isprint.c char_manip/ft_toupper.c\
      char_manip/ft_tolower.c\
      mem_manip/ft_bzero.c    mem_manip/ft_memset.c   mem_manip/ft_memcpy.c\
      mem_manip/ft_memmove.c  mem_manip/ft_memchr.c   mem_manip/ft_memcmp.c\
      str_manip/ft_strlen.c   str_manip/ft_strlcpy.c  str_manip/ft_strlcat.c\
      str_manip/ft_strchr.c   str_manip/ft_strrchr.c  str_manip/ft_strncmp.c\
      str_manip/ft_strnstr.c  str_manip/ft_atoi.c     str_manip/ft_strdup.c\
      str_manip/ft_substr.c   str_manip/ft_strjoin.c  str_manip/ft_strtrim.c\
      str_manip/ft_itoa.c     str_manip/ft_strmapi.c  str_manip/ft_split.c\
      str_manip/ft_striteri.c str_manip/ft_countw.c   str_manip/ft_domstr.c\
      str_manip/ft_nullify.c\
      ft_close.c 		gnl.c			     gnl_utils.c\
      garbage_collector.c       linked_list.c	             ft_gettime.c\
      ft_fprintf/ft_cprint_fd.c ft_fprintf/ft_cprinthex_fd.c ft_fprintf/ft_fprintf.c\

SRCEXT = .c
OBJEXT = .o
OBJS = $(addprefix $(OBJDIR)/,$(SRC:$(SRCEXT)=$(OBJEXT)))
OBJOUT = $(addprefix $(OBJDIR)/,$(notdir $(OBJ)))
CC        = gcc
RM        = rm -f
CFLAGS = -Wall -Wextra -Werror -g -I./

#=====================================
#===**DO NOT EDIT AFTER THIS LINE**===
#=====================================

all: directory ${NAME}
directory:
	@if ! test -d $(OBJDIR); then\
		mkdir $(OBJDIR);\
	fi

$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJOUT}

$(OBJDIR)/%$(OBJEXT): %$(SRCEXT)
	${CC} ${CFLAGS} -g -c $< -o $(addprefix $(OBJDIR)/,$(notdir $@))

clean:
	${RM} ${OBJOUT} 

fclean: clean
	${RM} ${NAME}
	@if test -d $(OBJDIR); then\
		rm -rf $(OBJDIR);\
	fi

re: fclean all
