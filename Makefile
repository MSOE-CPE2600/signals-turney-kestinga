CFLAGS=-c -g -Wall -Werror
CC=gcc

all: recv_signal send_signal signal_alarm signal_handler signal_segfault signal_sigaction

recv_signal: recv_signal.o
	$(CC) -o recv_signal.out recv_signal.o

send_signal: send_signal.o
	$(CC) -o send_signal.out send_signal.o

signal_alarm: signal_alarm.o
	$(CC) -o signal_alarm.out signal_alarm.o

signal_handler: signal_handler.o
	$(CC) -o signal_handler.out signal_handler.o

signal_segfault: signal_segfault.o
	$(CC) -o signal_segfault.out signal_segfault.o

signal_sigaction: signal_sigaction.o
	$(CC) -o signal_sigaction.out signal_sigaction.o

clean:
	rm -f *.o *.out

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<

