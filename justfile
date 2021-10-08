test name case:
	#!/bin/bash
	cd {{invocation_directory()}}
	set -ex
	g++ {{name}}.cpp -std=c++11 -o {{name}} -Wall
	cat {{name}}.{{case}}.in
	cat {{name}}.{{case}}.out
	./{{name}} < {{name}}.{{case}}.in > out
	diff out {{name}}.{{case}}.out

leetcode no name url:
	#!/bin/bash
	set -ex
	cd {{justfile_directory()}}
	mkdir leetcode/{{no}}
	cat > leetcode/{{no}}/{{name}}.cpp << EOF
	// {{url}}
	EOF
