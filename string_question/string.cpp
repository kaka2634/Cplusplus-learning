class String{
public:
  String(const char *str = NULL);
  String(const String &other);
  ~String(void);
  String & operate = (const String &other);
private:
  char * m_data;//save string
};

String::~String(void)
{
  delete [] m_data;
}

String::String(const char *str=NULL) //"hello"就是const char *
{
  if(str=NULL)
  {
    m_data = new char [1];
    *m_data='\0';
  }
  else
  {
    int length = strlen(str);//不包括结束字符,需要len+1
    m_data = new char [length+1];
    strcpy(m_data,str);
  }
}

String::String(const String &other) //复制构造函数
{
  if(other=NULL)
  {
    m_data = new char [1];
    *m_data='\0';
  }
  else
  {
    int length = strlen(other.m_data);//不包括结束字符,需要len+1
    m_data = new char [length+1];
    strcpy(m_data,other.m_data);
  }
}

String & String::operate =(const String &other)
{
  //自己检查
  if(this==&other)
  return this;
  //delete之前的空间,不像构造函数,之前是没有内纯空间分配的
  delete [] m_data;
  int length = strlen(other.m_data);//不包括结束字符,需要len+1
  m_data = new char [length+1];
  strcpy(m_data,other.m_data);
  //最后还要返回 this
  return *this;
}
