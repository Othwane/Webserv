CC			=	c++

CPPFLAGS	=	-Wall -Wextra -fsanitize=address -g

SRCS		=	main.cpp\
				server/Server.cpp\
				parsing/Config.cpp\
				utils.cpp\
				client/Client.cpp\
				client/clientHandler.cpp\
				server/Response.cpp\
				server/Default.cpp\
				parsing/Mime.cpp\
				parsing/Parser.cpp\
				Cgi/Cgi.cpp\

OBJS		=	$(SRCS:.cpp=.o)

NAME		=	webserv

%.o:		%.cpp *.hpp
			$(CC) $(CPPFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(OBJS) $(CPPFLAGS) -o $(NAME)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all