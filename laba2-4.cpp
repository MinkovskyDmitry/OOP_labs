#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

class String
{
public:
	String()
	{
		str = NULL;
		length = 0;
	}
	String (char *str1)
	{
		length=strlen(str1)+1;
		str = new char [length];
		strcpy(str,str1);
	}
	String (String *obj)
	{
		length=obj->getLength();
		str = new char [length];
		for (int i=0;i<length; i++)
		{
			str[i]=obj->getChar(i);
		}
	}

	~String() { delete []str; cout<<"Дасвидули"<<endl; }

	int getLength()
	{
		return strlen(str);
	}
	void Init(char *str1)
	{
		delete []str;
		length=strlen(str1)+1;
		str = new char [length];
		strcpy(str,str1);
	}
	char getChar(int i)
	{
			return str[i];
	}
	void  Concat(const char * str1)
	{		
		char* kopia = new char [length];
		strcpy(kopia,str);

		delete [] str;
				
		length+=strlen(str1);
		str = new char [length];
		strcpy(str,kopia);
		strcat(str,str1);
		delete []kopia;
	}
	


	void operator=(const char *c)
	{ 
		 int i;
		 delete[] this->str;
		 length = strlen(c)+1;
		 this->str = new char [length];
		 for(i = 0; i < length-1; i++) str[i] = c[i];
		 this->str[i]=NULL;
	}
	void operator=(const String &obj)
	{
	   if(this != &obj ) 
	  {              
		 delete[] this->str;
		 this->str = new char[this->length = strlen(obj.str)+1];
		 for(int i = 0; i < this->length; i++) this->str[i] = obj.str[i];
	  }
	}
	void operator+= (const char *c)
	{
		this->Concat(c);
	}
	void operator+= (const String &obj)
	{
		this->Concat(obj.str);
	}
	char& operator[] (int i)
	{
		return this->str[i];
	}
	
	friend ostream &operator<<(ostream &a,const String &c)
	{
		a<<c.str;
		return a;
	}
	friend void operator>>(istream &a, String &c)
	{	
		char *str1 = new char [100];
		a>>str1;
		c.length=strlen(str1)+1;
		c.str = new char [c.length];
		strcpy(c.str,str1);	
		delete []str1;
	}

	friend void print (String *);

private:
	char *str;
	int length;
};

void print (String *object)
{
	cout<<object->str<<endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	String s,s1;
	cin>>s;
	s+="123";
	s1=s;
	cout<<s1<<endl;

	getch();
	return 0;
}