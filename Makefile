NAME = libasm.a
FLAGS = -Wall -Werror -Wextra
FLAGS_ASM = -felf64

SRCS_PATH=src
SRCS_BONUS_PATH=src_bonus

SRCS = $(wildcard $(SRCS_PATH)/*.s)
SRCS_BONUS = $(wildcard $(SRCS_BONUS_PATH)/*.s)
OBJS = $(SRCS:.s=.o)
OBJS_BONUS = $(SRCS_BONUS:.s=.o)

NC=\033[0;0m
GREEN=\033[3;32m
BLINK=\e[5m

all: $(NAME)
	@echo "\n\n\t\t	${GREEN}${NAME} ready !${NC}\n\n"

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

tester:	$(OBJS) $(NAME)
	clang $(FLAGS) main.c $(NAME) -o tester

%.o: %.s
	nasm $(FLAGS_ASM) $<

clean:
	rm -rf *.o
	rm -rf bonus/*.o
	rm -rf ft_write.txt
	rm -rf write.txt

fclean: clean
	rm -rf $(NAME)
	rm -rf tester
	rm -rf bonus_tester

bonus: fclean $(OBJS) $(OBJS_BONUS)
	ar rc $(NAME) $(OBJS) $(OBJS_BONUS)
	ranlib $(NAME)

bonus_tester:	$(OBJS) $(OBJS_BONUS) $(NAME)
	clang $(FLAGS) main_bonus.c $(NAME) -o bonus_tester

re: fclean all

.PHONY : all clean fclean re
