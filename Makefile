##############################################################################
# Makefile for A1
# CMP_SC 4050
# Fall 2023
# By Jim Ries (RiesJ@missouri.edu)
##############################################################################
CC = gcc
CPP = g++
CFLAGS = -Wall -Werror -c -g -std=c11 -I.
CPPFLAGS = -Wall -Werror -c -g -I.
LDFLAGS = -lm -lcs4050 -L.

default: test testcc

%.o : %.c 
	@echo Compiling $^ 
	@$(CC) $(CFLAGS) $^

%.o : %.cc
	@echo Compiling $^ 
	@$(CPP) $(CPPFLAGS) $^

test : main.o BFS.o DFS.o libcs4050.a Queue.o
	@echo Linking $@ 
	@$(CC) $^ $(LDFLAGS) -o $@

testcc : maincc.o BFS.o DFS.o libcs4050.a Queue.o
	@echo Linking $@
	@$(CC) $^ $(LDFLAGS) -o $@

clean : 
	@rm -rf *.o
	@rm -rf test
	@rm -rf testcc
	@echo All Clean!
