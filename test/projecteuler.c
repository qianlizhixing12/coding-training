#include "projecteuler.h"
#include "test.h"

static void llt_getSum(void) {
  TEST_CASE_TRUE(getSum(3, 5, 10) == 23);
  TEST_CASE_TRUE(getSum(3, 5, 1000) == 233168);
}

void projecteuler(void) { TEST_CASE_ADD(llt_getSum); }