CLIENT	= client
SERVER = server
SRCS_CLIENT = client.c 
SRCS_SERVER = server.c utils.c
OBJS_CLIENT	= $(SRCS_CLIENT:.c=.o)
OBJS_SERVER	= $(SRCS_SERVER:.c=.o)

LFT = ./ft_printf/libftprintf.a
LIB = -L ./ft_printf -lftprintf

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra

.c.o:		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(LFT) $(SERVER) $(CLIENT)

$(LFT):
				make -s -C ./ft_printf/ all

$(CLIENT):	$(OBJS_CLIENT) Makefile
				$(CC) $(CFLAGS) $(OBJS_CLIENT) -o client $(LIB)

$(SERVER):	$(OBJS_SERVER) Makefile
				$(CC) $(CFLAGS) $(OBJS_SERVER) -o server $(LIB)

clean:
			rm -f $(OBJS_CLIENT) $(OBJS_SERVER)
			@make -s -C ./ft_printf/ clean

fclean:		clean
			rm -f $(CLIENT) $(SERVER)
			@make -s -C ./ft_printf/ fclean

re:			fclean all

.PHONY:		all clean fclean bonus re
