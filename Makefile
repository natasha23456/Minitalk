SERVER = server
CLIENT = client
PRINTF = ft_printf

CFLAGS = -Wall -Werror -Wextra
CC = gcc
FLAGS = -Wall -Wextra -Werror -I$(PRINTF)/includes -L$(PRINTF) -1ftprintf

all:
		@make -s -C $(PRINTF)
		@echo $(PRINTF)
		$(CC) server.c $(FLAGS) -o $(SERVER)
		$(CC) client.c $(FLAGS) -o $(CLIENT)
		@echo "Server And Client Are Ready!"

clean:
		@make clean -s -C $(PRINTF)

fclean:	clean
		@make fclean -s -C $(PRINTF)
		@rm -f $(SERVER) $(CLIENT)
		@echo "Server and Client Have Been Cleaned Successfully"

re: fclean all