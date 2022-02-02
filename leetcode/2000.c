char* reversePrefix(char* word, char ch) {
  int left = 0;
  int right = 0;
  char tmp;

  while (word[right] != '\0' && word[right] != ch) {
    ++right;
  }

  if (word[right] == '\0') {
    return word;
  }

  while (left < right) {
    tmp = word[left];
    word[left] = word[right];
    word[right] = tmp;
    ++left;
    --right;
  }

  return word;
}