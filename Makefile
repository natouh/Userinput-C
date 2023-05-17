CC = gcc
CFLAGS = -Wall -Wextra -pedantic

all: letters numbers firstname userinput newshell

letters: letters.c
	$(CC) $(CFLAGS) letters.c -o letters

numbers: numbers.c
	$(CC) $(CFLAGS) numbers.c -o numbers

firstname: firstname.c
	$(CC) $(CFLAGS) firstname.c -o firstname

userinput: userinput.c
	$(CC) $(CFLAGS) userinput.c -o userinput

newshell: newshell.c
	$(CC) $(CFLAGS) newshell.c -o newshell

clean:
	rm -f letters numbers firstname userinput newshell


	

















	


























