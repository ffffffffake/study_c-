#if 0
#include<string>
#include<iostream>

using namespace std;

int main()
{
string s1;
cout << "s1:" << ' ' << s1 << endl;

string s2("hello world");
cout << "s2:" << ' ' << s2 << endl;


string s3(s2);
cout << "s3:" << ' ' << s3 << endl;

string s4(10, 'a');
cout << "s4:" << ' ' << s4 << endl;
string s1;
char m[] = "hello world";//栈区
s1.assign(m, 5);
cout << s1 << ' ' << s1.size() << endl;
s1.assign(m, 20);
cout << s1 << ' ' << s1.size() << endl;
for (int i = 0; i < s1.size(); i++)
	cout << s1[i];
cout << endl;
for (int i = 0; i < s1.size(); i++)
	cout << m[i];
cout << endl;
string str1;
string str2;
string str3;
string str4;
string str5;
string str6;
string str7;

str1 = "hello world";			cout << "str1 = " << str1 << endl;
str2 = str1;					cout << "str2 = " << str2 << endl;
str3 = 'c';						cout << "str3 = " << str3 << endl;
str4.assign("hello world");		cout << "str4 = " << str4 << endl;
str5.assign("hello world", 5);	cout << "str5 = " << str5 << endl;
str6.assign(str1);				cout << "str6 = " << str6 << endl;
str7.assign(10, 'a');			cout << "str7 = " << str7 << endl;
str1 = "hello ";
str2 = " worldxxxxxxxx";
str1.append(str2, 1, 20);
cout << "str1 = " << str1 << endl;

str3 = "abcdefabcdef";
int pos2 = str3.rfind("bc", 5);
cout << pos2 << endl;

str4 = "hello world";
str4.replace(0, 0, "xxxxxxxxxxx");
cout << "str4 = " << str4 << endl;

str5 = "hello world";
str5.at(6) = 'x';
cout << "str5 = " << str5 << endl;

str6 = "hello world";
str6.insert(6, "xxxxxx");
cout << "str6 = " << str6 << endl;

str7 = "hello world";
str7 = str7.erase(5, 6);
cout << "str7 = " << str7 << endl;

str8 = "hello world";
str8 = str8.substr(0, 5);
cout << "str8 = " << str8 << endl;
cout << "str的地址为                ：" << (void*)&str << endl;
cout << "str中字符串的首元素地址为  ：" << (void*)&str[0] << endl;
cout << "str.c_str的返回地址为      ：" << (void*)str.c_str() << endl;
system("pause");
return 0;
}
#endif
#if 0
#include<string>
#include<iostream>

using namespace std;

int main()
{
	string str = "hello world";
	int num = atoi(str.c_str());
	cout << num << endl;
	
	
	system("pause");
	return 0;
}
#endif
