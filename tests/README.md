# BCC Tests

_Stolen from [Write A C Compiler](https://github.com/nlsandler/write_a_c_compiler/blob/master/test_compiler.sh) by [Nora Sandler](https://norasandler.com)_

The passing tests are in this directory and the ones i haven't gotten to are in different stages.
The "tester" checks two directories, [valid](./valid/) and [invalid](./invalid/).
It check the return code of the compiler when it compiles each file. For files in [valid](./valid/), 
it should always be 0 and for files in [invalid](./invalid/) it never should be 0.

