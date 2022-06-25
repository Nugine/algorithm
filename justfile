leetcode problem name url:
    #!/bin/bash -ex
    cd {{justfile_directory()}}
    mkdir -p leetcode/{{problem}}
    F=leetcode/{{problem}}/{{name}}.cpp
    cat > $F << EOF
    // {{url}}
    #ifdef LEETCODE_LOCAL
    #include "leetcode.h"
    #endif
    EOF
    code $F
