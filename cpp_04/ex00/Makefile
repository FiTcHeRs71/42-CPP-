# Program name
NAME = polymorph
 
# Directories
OBJDIR = objs

SRCS_MAIN = main.cpp
ANIDIR = Animal
DOGDIR = Dog
CATDIR = Cat
WRONGDIR = WrongAnimal

SRCS_WRONG = $(addprefix $(WRONGDIR)/, \
	Wrong.cpp)

SRCS_ANI = $(addprefix $(ANIDIR)/, \
	Animal.cpp)

SRCS_CAT = $(addprefix $(CATDIR)/, \
	Cat.cpp)

SRCS_DOG= $(addprefix $(DOGDIR)/, \
	Dog.cpp)

# Source files
SRCS = $(SRCS_MAIN) $(SRCS_ANI) $(SRCS_CAT) $(SRCS_DOG) $(SRCS_WRONG)
 
# Object files
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)
 
# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
 
# Colors
GREEN = \033[0;32m
CYAN = \033[0;36m
YELLOW = \033[0;33m
RESET = \033[0m
 
# Rules
all: $(NAME)
	@echo "$(GREEN)🎉 $(NAME) ready! 🎉$(RESET)"
 
$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@printf "$(CYAN)Compiling $(notdir $<)...$(RESET)\r"
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@printf "$(GREEN)✓ Compiled $(notdir $<)   $(RESET)\n"
 
$(NAME): $(OBJS)
	@echo "$(YELLOW)🔗 Linking $(NAME)...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) created successfully!$(RESET)"
 
clean:
	@rm -rf $(OBJDIR)
	@echo "$(CYAN)✓ Object files removed$(RESET)"
 
fclean: clean
	@rm -f $(NAME)
	@echo "$(CYAN)✓ $(NAME) removed$(RESET)"
 
re: fclean all
 
run: all
	@echo "$(GREEN)🚀 Running $(NAME)...$(RESET)"
	@./$(NAME)
 
.PHONY: all clean fclean re run