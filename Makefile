
include Definitions

test:
	echo $(CMD1)
	echo $(CMD2)

build:
	cc program.c -o program -D CMD1='"$(CMD1)"' -D CMD2='"$(CMD2)"'
