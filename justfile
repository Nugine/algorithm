test name case:
	#!/bin/bash
	cd {{invocation_directory()}}
	set -ex
	g++ {{name}}.cpp -std=c++11 -o {{name}}
	cat {{name}}.{{case}}.in
	cat {{name}}.{{case}}.out
	./{{name}} < {{name}}.{{case}}.in > out
	diff out {{name}}.{{case}}.out

