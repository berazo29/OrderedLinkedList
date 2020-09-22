all : main

main : main.c
	gcc -Wall -Werror -fsanitize=address main.c -o main
clean :
	rm main
