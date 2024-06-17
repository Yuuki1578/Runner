# Release
SOURCE := src/runner.c
TARGET := build/run
CC := gcc $(SOURCE)
FLAGS := --optimize=3 -Wall -Werror -Wc23-extensions -Wpedantic -std=gnu23 -o $(TARGET)

# Sample
SAMPLE_SOURCE := sample/sample.c
SAMPLE_TARGET := sample/path/to/exe/sample
SAMPLE_CC := gcc $(SAMPLE_SOURCE)
SAMPLE_FLAGS := -o $(SAMPLE_TARGET)

all: build/run sample/path/to/exe/sample

build/run: src/runner.c
	mkdir -p build
	$(CC) $(FLAGS)

sample/path/to/exe/sample: sample/sample.c
	mkdir -p sample/path/to/exe
	$(SAMPLE_CC) $(SAMPLE_FLAGS)
