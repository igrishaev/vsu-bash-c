
include Definitions

.DEFAULT_GOAL = all

.PHONY: test
def-print:
	echo $(CMD1)
	echo $(CMD2)

.PHONY: build
build:
	cc program.c -o program -D CMD1='"$(CMD1)"' -D CMD2='"$(CMD2)"'

.PHONY: run
run:
	./program

.PHONY: prompt
prompt:
	./prompt.sh

.PHONY: all
all: prompt build run
