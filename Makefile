NAME = libasm.a
FLAGS = -Wall -Werror -Wextra
FLAGS_ASM = -felf64

SRCS = $(wildcard *.s)
SRCS_BONUS = $(wildcard bonus/*.s)
OBJS = $(SRCS:.s=.o)
OBJS_BONUS = $(SRCS_BONUS:.s=.o)

all: $(NAME)

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

fclean: clean
	rm -rf $(NAME)
	rm -rf tester
	rm -rf bonus_tester
	rm -rf ft_write.txt
	rm -rf write.txt

bonus: fclean $(OBJS) $(OBJS_BONUS)
	ar rc $(NAME) $(OBJS) $(OBJS_BONUS)
	ranlib $(NAME)

bonus_tester:	$(OBJS) $(OBJS_BONUS) $(NAME)
	clang $(FLAGS) main_bonus.c $(NAME) -o bonus_tester

re: fclean all

.PHONY : all clean fclean re
