# Introduction

"hello, world" for libhandler inside enclaves

## Compiling

First ensure the SGX SDK is installed. Instructions here: https://github.com/intel/linux-sgx

Then make sure the SGX environment variables are set:

    $ source ${sgx-sdk-install-path}/environment

Finally use make and pass in the location of LIBHANDLER_DIR. libhandler must already have been built. For example:

    $ make LIBHANDLER_DIR=../libhandler 

This doesn't compile for two reasons. 

1. First, FILE objects cannot be referred to inside the enclave. And
   libhandler.h has two API calls which use FILE.
2. Second, the libhandler lib makes many references to functions like fprintf
   which can't be used inside the enclave.
