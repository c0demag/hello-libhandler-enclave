# Introduction

libhandler inside enclaves "hello, world"

## Compiling

use the make and pass in the argument LIBHANDLER_DIR. For example:

    $ make LIBHANDLER_DIR=../libhandler 

This doesn't compile for two reasons. 

1. First, FILE objects cannot be referred to inside the enclave. And
   libhandler.h has two API calls which use FILE.
2. Second, the libhandler lib makes many references to functions like fprintf
   which can't be used inside the enclave.
