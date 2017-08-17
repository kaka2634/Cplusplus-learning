#include <assert.h>
int strlen(const char *str)
{
  assert(str!=NULL);
  int len=0;
  while((*str++)!='/0') //strlen,不包括末尾的/0
  {
    len++;
  }
  return len;
}

//source code;
size_t strlen_b(const char * str)

{
     const char *cp =  str;
     while (*cp++ );
     return (cp - str - 1 );
}
