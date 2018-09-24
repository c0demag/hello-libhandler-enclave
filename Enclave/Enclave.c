#include "Enclave_t.h"

#include <stdio.h> 
#include <libhandler.h>

LH_DEFINE_EFFECT1(exn, raise)
LH_DEFINE_VOIDOP1(exn, raise, lh_string)

int divexn(int x, int y) {
  if(y != 0) {
    return x / y;
  }
  else {
    exn_raise("divide by zero");
  }
}

lh_value handle_exn_raise(lh_resume* r, lh_value local, lh_value arg) {
  char buffer[256];
  snprintf(buffer, 256, "exception raised: %s\n", lh_lh_string_value(arg));
  ocall_print(buffer);
  return lh_value_null;
}

const lh_operation _exn_ops[] = {
  {
    LH_OP_NORESUME, LH_OPTAG(exn,raise), &handle_exn_raise
  }
};
  
const lh_handlerdef _exn_def = {
  LH_EFFECT(exn), NULL, NULL, NULL, _exn_ops
};

lh_value my_exn_handle(lh_value(*action)(value), lh_value arg){
  return lh_handle(&_exn_def, lh_value_null, action, arg);
}

lh_value divide_by(lh_value x){
  return lh_value_long(divexn(42, lh_long_value(x)));
}

int enclave_main(){
  my_exn_handle(divide_by, lh_value_long(0));
  return 33;
}

int generate_random_number() {
    ocall_print("Processing random number generation...");
    return 42;
}
