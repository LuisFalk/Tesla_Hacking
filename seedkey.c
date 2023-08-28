#include <stdio.h>
#include <stdint.h>

typedef char byte;

void fillArray(byte seed[16]) {
  for (int i = 0; i < 16; i++) seed[i] = i;
}

/*
  Levels: [1, 3, 5]
  Tester-CAN ID: 0x064C
  ECU-CAN ID: 0x065C
  ECU: IC (Instrument Cluster)
*/
void calcSeedKey(const byte seed[16], byte key[16]) {
  for (int i = 0; i < 16; i++) key[i] = seed[i] ^ 0x35;
}

int main(void)
{
  byte seed[16];
  byte key[16];
  fillArray(seed);
  calcSeedKey(seed, key);
  printf("Seed: ");
  for (int i = 0; i < 16; i++) printf("%02x ", seed[i]);
  printf("\n");
  printf("Key: ");
  for (int i = 0; i < 16; i++) printf("%02x ", key[i]);
  /*
  Seed: 00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f 
  Key: 35 34 37 36 31 30 33 32 3d 3c 3f 3e 39 38 3b 3a
  */
  printf("\n");
}


// gcc seedkey.c
// ./a.out
