#include "test.h"
#include "date_conv.h"
#include <stdio.h>

int main(){

  testi("test1", 59, day_of_year(2001, 2, 28));

  testresult();

  return 0;
}