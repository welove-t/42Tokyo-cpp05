
NAME		= main
CXX 		= c++
CXXFLAGS 	= -Wall -Werror -Wextra -std=c++98
FILES		= main AForm Bureaucrat ShrubberyCreationForm PresidentialPardonForm RobotomyRequestForm Intern
SRCS		= $(FILES:=.cpp)
OBJS_DIR	= .objs
OBJS		= $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: %.cpp
	mkdir -p $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@
clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
