FT_TARGET	= ft_tester
STL_TARGET	= stl_tester
CFLAGS		= -Wall -Wextra -Werror --std=c++98
FT			= -D FT
TESTER		= -D TESTER
CHECKER		= -D CHECKER

all: test check

test: main.cpp

	clang++ ${CFLAGS} ${FT} ${TESTER} $< -o ${FT_TARGET}
	clang++ ${CFLAGS} ${TESTER} $< -o ${STL_TARGET}
	./ft_tester ; ./stl_tester

check: main.cpp

	clang++ ${CFLAGS} ${CHECKER} $< -o checker
	./checker

clean:

	rm -f *.out *.time
	rm -f ${FT_TARGET} ${STL_TARGET}
	rm -f ./checker

re: clean all
