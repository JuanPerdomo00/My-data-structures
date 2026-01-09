#include <stdio.h>
#include <string.h>

int is_luhn(char *nums) {
  int sum = 0;
  for (int i = strlen(nums) - 1; i >= 0; i--) {
    int digit = nums[i] - '0';
    if ((strlen(nums) - 1) % 2 == 0) {
      digit *= 2;
    }

    if (digit > 9) {
      digit /= 10 + digit % 10;
    }

    sum += digit;
  }

  return sum % 10 == 0;
}

int main(void) {
  char *nums[4] = {
      "4111111111111111",
      "4012888888881881",
      "5555555555554444",
      "5105105105105100",
  };

  for (int i = 0; i < 4; i++) {
    if (is_luhn(nums[i])) {
      printf("%s is luhn\n", nums[i]);
    } else {

      printf("%s no is luhn\n", nums[i]);
    }
  }

  return 0;
}
