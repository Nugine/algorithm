leetcode no problem name:
    #!/bin/bash -ex
    cd {{justfile_directory()}}
    mkdir -p "leetcode/{{no}} {{problem}}"
    F="leetcode/{{no}} {{problem}}/{{name}}.cpp"
    cat > "$F" << EOF
    // {{no}} {{problem}}
    // https://leetcode.cn/problems/{{problem}}
    #ifdef LEETCODE_LOCAL
    #include "leetcode.h"
    #endif
    EOF
    code "$F"

cpp name input:
    #!/bin/bash -ex
    cd "{{invocation_directory()}}"
    mkdir -p target
    g++ {{name}}.cpp -Wall -Wextra -o target/{{name}}
    ./target/{{name}} < {{input}}.in | tee target/{{name}}.out
    diff {{input}}.out target/{{name}}.out
