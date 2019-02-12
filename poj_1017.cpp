#include<stdio.h>
#include<stdlib.h>
#include<map>

using namespace std;

map<unsigned, unsigned> three_to_two;


void fill_ones(unsigned * p, unsigned space_used) {
  if (p[1] >= (36 - space_used)) {
    p[1] -= (36- space_used);
  }
  else {
    p[1] = 0;
  }
}


unsigned num_packages(unsigned * p) {
  // Defines how many threes allow a mapped number of twos
  unsigned packages = p[6]; // 6th ones must always be in their own
  unsigned spaceUsed;
  while (true) {
    if (p[5]) {
      p[5]--;
      fill_ones(p, 5 * 5);
    }
    else if (p[4]) {
      // Fill in extra space with twos first, then ones
      if (p[2] >= 5) p[2] -= 5;
      else {
        fill_ones(p, p[2] * 4);
        p[2] = 0;
      }
    }
    else if (p[3]) {
      if (p[3] >= 4) p[3] -= 4;
      else {
        spaceUsed = p[3] * (3 * 3);
        if (p[2] >= three_to_two[p[3]]) {
          p[2] -= three_to_two[p[3]];
          spaceUsed += three_to_two[p[3]] * 2 * 2;
        } else {
          // packet is less than full with twos and threes
          spaceUsed -= p[2] * 2 * 2;
          p[2] = 0;
        }
        p[3] = 0;
        fill_ones(p, spaceUsed);
      }
    }
    else if (p[2]) {
      if (p[2] >= 9) p[2] -= 9;
      else {
        spaceUsed = p[2] * 2 * 2;
        fill_ones(p, spaceUsed);
        p[2] = 0;
      }
    }
    else if (p[1]) fill_ones(p, 0);
    else break;
    packages++;
  }
  return packages;
}


int main() {
  three_to_two[4] = 0;
  three_to_two[3] = 1;
  three_to_two[2] = 3;
  three_to_two[1] = 5;
  three_to_two[0] = 9;
  unsigned p[7]; // 0th idx is not used
  while (true) {
    scanf("%d%d%d%d%d%d", p+1, p+2, p+3, p+4, p+5, p+6);
    if (p[1] ==0 && p[2] ==0 && p[3] == 0 && p[4] == 0 && p[5] == 0 && p[6] == 0) break;
    printf("%d\n", num_packages(p));
  }
}
