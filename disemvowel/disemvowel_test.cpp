#include <gtest/gtest.h>

#include "disemvowel.h"

TEST(Disemvowel, HandleEmptyString) 
{
  char *testCase= disemvowel((char*) "");
  ASSERT_STREQ("", testCase);
  free(testCase);
}

TEST(Disemvowel, HandleNoVowels) {
  char *testCase = disemvowel((char*) "pqrst");
  ASSERT_STREQ("pqrst", testCase);
  free(testCase);
}

TEST(Disemvowel, HandleOnlyVowels) {
  char *testCase =  disemvowel((char*) "aeiouAEIOUOIEAuoiea");
  ASSERT_STREQ("", testCase);
  free(testCase);
}

TEST(Disemvowel, HandleMorrisMinnesota) {
  char *testCase =  disemvowel((char*) "Morris, Minnesota");
  ASSERT_STREQ("Mrrs, Mnnst", testCase);
  free(testCase);
}

TEST(Disemvowel, HandlePunctuation) {
  char *testCase =  disemvowel((char*) "An (Unexplained) Elephant!");
  ASSERT_STREQ("n (nxplnd) lphnt!",testCase);
  free(testCase);
}

TEST(Disemvowel, HandleLongString) {
  char *str;
  int size;
  int i;

  size = 50000;
  str = (char*) calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';
  
  char *testCase = disemvowel(str);
  ASSERT_STREQ("xyz", testCase);
  free(testCase);

  free(str);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
