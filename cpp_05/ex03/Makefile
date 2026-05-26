# Program name
NAME = intern

# Directories
OBJDIR = objs

SRCS_MAIN = main.cpp
BUREAUDIR = Bureaucrat
FORMDIR = Form
INTERNDIR = Intern

SRCS_BUREAU = $(addprefix $(BUREAUDIR)/, \
	Bureaucrat.cpp)

SRCS_FORM = $(addprefix $(FORMDIR)/, \
	AForm.cpp ShrubberyCreationForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp)

SRCS_INTERN = $(addprefix $(INTERNDIR)/, \
	Intern.cpp)

# Source files
SRCS = $(SRCS_MAIN) $(SRCS_BUREAU) $(SRCS_FORM) $(SRCS_INTERN)

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
	@rm -f $(NAME) Default\ Target_shrubbery 
	@echo "$(CYAN)✓ $(NAME) removed$(RESET)"

re: fclean all

run: all
	@echo "$(GREEN)🚀 Running $(NAME)...$(RESET)"
	@./$(NAME)

.PHONY: all clean fclean re run
