//<cstring>(string.h)
#include <assert.h>
char *strcpy(char *strDest, const char *strSrc) //(1)const
{
  assert((strDest!=NULL)&&(strSrc!=NULL)); //(2)assert
  char *address=strDest;    //(3)address保存
  while ((*strDest++=*strSrc++)!='\0')  //(4)\0判断,付过了'/0'再判断
  NULL;
  return address;  //(5)return char* 可以实现链式表达式
}

//注意strcpy没有空间判断
