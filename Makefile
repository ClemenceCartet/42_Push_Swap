# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 11:44:19 by ccartet           #+#    #+#              #
#    Updated: 2022/04/06 14:31:51 by ccartet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT = libft/libft.a

SRCS = push_swap.c parsing.c sa_sb_ss.c pa_pb.c ra_rb_rr.c rra_rrb_rrr.c sort_small.c sort_big.c push_swap_utils.c
OBJS = ${addprefix ${OBJD}, ${SRCS:.c=.o}}

SRCD = srcs/
OBJD = obj/

CFLAGS = -Wall -Wextra -Werror

all: lib ${NAME}

${NAME}:	${OBJS} ${LIBFT}
	gcc ${CFLAGS} ${OBJS} ${LIBFT} -o ${NAME}

$(OBJD)%.o: $(SRCD)%.c push_swap.h libft/libft.h Makefile | ${OBJD}
	gcc ${CFLAGS} -I libft -c -o $@ $<
	
${OBJD}:
	mkdir -p $@
	
lib:
	$(MAKE) -C libft/
	
clean:
	rm -rf ${OBJD}
	$(MAKE) clean -C libft/

fclean:	clean
	rm -f ${NAME}
	$(MAKE) fclean -C libft/

re:	fclean all

.PHONY:	all lib clean fclean re
