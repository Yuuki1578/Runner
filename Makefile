SOURCE := src/runner.c
TARGET := build/run
CC := gcc $(SOURCE)
FLAGS := --optimize=3 -Wall -Werror -Wc23-extensions -std=gnu23 -o $(TARGET)

build/run: src/runner.c
	mkdir -p build
	$(CC) $(FLAGS)
