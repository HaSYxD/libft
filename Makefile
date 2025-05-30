NAME = libft.a
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
      arena/arena.c		linked_list.c	             ft_gettime.c\
      ft_fprintf/ft_cprint_fd.c ft_fprintf/ft_cprinthex_fd.c ft_fprintf/ft_fprintf.c\
      alloc_api.c garbage_collector.c

SRCEXT = .c
OBJEXT = .o
OBJS = $(SRC:$(SRCEXT)=$(OBJEXT))
CC        = clang
AR	  = ar
RM        = rm -f
CFLAGS = -Wall -Wextra -Werror -g -I./ -I./arena -I./ft_fprintf

#=====================================
#===**DO NOT EDIT AFTER THIS LINE**===
#=====================================

all: ${NAME}

$(NAME): $(OBJS)
	$(AR) rcs $(NAME) ${OBJS}

%$(OBJEXT): %$(SRCEXT)
	${CC} ${CFLAGS} -g -c $< -o $@

clean:
	${RM} ${OBJS} 

fclean: clean
	${RM} ${NAME}
	$(RM) libft-desktop.a libft-web.a

re: fclean all
