#include "delay.h"

void Delayms(u16 ms)
{
  u16 i,j;
  u8 k;
  for(i=0;i<ms;i++)
    for(j=0;j<0x0500;j++) k++;
}
