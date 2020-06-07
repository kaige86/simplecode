void test(void)
{
  long a = 0x123456;
  int b = 0x12345;
  *(long *)a = 0x4567890;
}

void sets(char *a, char b)
{
   *a = b;
   a++;
   *a = b;
   a++;
}

void asm11(void)
{
  asm("xchg %%eax,%%eax":::"eax");
}
