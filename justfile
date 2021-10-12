test name case:
	#!/bin/bash -ex
	cd {{invocation_directory()}}
	g++ {{name}}.cpp -std=c++11 -o {{name}} -Wall
	cat {{name}}.{{case}}.in
	cat {{name}}.{{case}}.out
	./{{name}} < {{name}}.{{case}}.in > out
	ojcmp normal -u out -s {{name}}.{{case}}.out
	diff --strip-trailing-cr out {{name}}.{{case}}.out
	echo "AC"

leetcode no name url:
	#!/bin/bash -ex
	cd {{justfile_directory()}}
	mkdir -p leetcode/{{no}}
	F=leetcode/{{no}}/{{name}}.cpp
	cat > $F << EOF
	// {{url}}
	EOF
	code $F

luogu no:
	#!/bin/bash -ex
	cd {{justfile_directory()}}
	mkdir -p luogu/{{no}}
	A=luogu/{{no}}/{{no}}.cpp
	cp templates/common.h $A
	B=luogu/{{no}}/{{no}}.1.in
	C=luogu/{{no}}/{{no}}.1.out
	code $A $B $C
