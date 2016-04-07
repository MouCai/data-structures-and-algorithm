#include <stdio.h>
#include "ohtbl.h"

static int _match (const void *key1, const void *key2) {
  return (* (int *)key1) == (* (int *)key2);
}

int main(int argc, char **argv) {
  return 0;
}
