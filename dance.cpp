#include <iostream>
#include <string>
#include <unistd.h>
#include <stdlib.h>

std::string DANCE_STR[] = {
  [0] = "(>'-')>",
  [1] = "<('-'<)",
  [2] = "^('-')^",
  [3] = "v('-')v",
  [4] = "(>'-')>",
  [5] = " (^-^) "

}; 

unsigned int SLEEP_DURATION = 500000;

int main() {

  while (true) {
    for(int i = 0; i < 6; ++i) {
      usleep(SLEEP_DURATION);
      std::cerr << DANCE_STR[i] << '\r';
    }
  }

  return 0;
}
