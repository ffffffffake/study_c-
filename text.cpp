#include<iostream>
#include<vector>

using namespace std;
void print(vector<int>m)
{
	for (vector<int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void text1()//练习1
{
	vector<int>m;
	for (int i = 0; i < 10; i++)
		m.push_back(i);
	print(m);
	vector<int>m2;
	print(m2);
	vector<int>mm = m;
	
	m2.assign(m.begin(),m.end());
	print(m2);
	m2.assign(5,20);
	print(m2);
	cout<<m2.capacity()<<endl;
	m.reserve(100);
	cout << m.capacity()<<endl;
	m.swap(m2);
	cout << endl;
	print(m);
	print(m2);
	vector<int>(m).swap(m);
	cout << m.capacity() << endl;
	vector<int>(m2).swap(m2);

	cout << m2.capacity()<<endl;
	print(m);
	print(m2);
	vector<int>m3(m);
	cout << m3.capacity() << endl;
	print(m3);
	system("pause");
}
void text2()//练习2
{
	vector<int>m;
	int j = m.capacity();
	for (int i = 0; i < 100; i++)
	{
		if (j != m.capacity())
		{
			cout << j<<"   ";
			j = m.capacity();
		}
		m.push_back(i);
	}
	cout << j;
	system("pause");
}
void text3()//初始化1
{
	vector<int>m1 = { 1,2,3,4,5 };
	vector<int>m2 = m1;
	auto it = m1;
	cout <<"m1的地址为："<< & m1 << '\n' << "m2的地址为: "<< & m2 << '\n'<<"it的地址为：" << &it << endl;
	vector<int>m3(10, 1);
	vector<int>m4(m3.begin(), m3.end());
	vector<int>::iterator i1 = m3.begin();
	vector<int>::iterator i2 = m3.end();
	vector<int>m5(i1, i2);
	vector<int>(5, 1);
	print(m3);
	print(m4);
	print(m5);
	print(vector<int>(5, 1));
}
void text4()//初始化测试
{
	vector<int>m1;
	vector<int>m2 = { 1,2,3,4,5 };
	vector<int>m3=m2;
	vector<int>m4(5,6);
	vector<int>m5(m4.begin(),m4.end());

	print(m1);
	print(m2);
	print(m3);
	print(m4);
	print(m5);
}
void text5()//赋值测试
{
	vector<int>m1;
	vector<int>m2;
	vector<int>m3;
	vector<int>m4;

	m1 = { 1,2,3,4,5 };
	m2 = m1;
	m3.assign(5, 6);
	m4.assign(m3.begin(), m4.end());
}
void text6()
{
	vector<int>m1 = { 1,2,3,4,5 };
	vector<int>m2 = { 8,8,8,8,8 };
	m1.push_back(6);
	m1.insert(m1.begin(), 0);
	m1.insert(m1.begin(), m1.begin(), m1.end());
	print(m1);

	m1.pop_back();
	m1.erase(m1.begin(),m1.begin()+2);
	print(m1);

	auto it = find(m1.begin(), m1.end(), 5);
	cout << *it <<endl;

	m1.at(0) = 0;
	m1[1] = 0;
	print(m1);
}
void text7()
{
	vector<int>m1(100,1);
	m1.push_back(1);
	cout << m1.capacity()<<endl;
	m1.reserve(5);
	cout << m1.capacity() << endl;

}
void text8()
{
	vector<int>m;
	for (int i = 0; i < 1000; i++)
		m.push_back(1);
	for (int i = 0; i < 990; i++)
		m.pop_back();
	cout << "m的有效元素个数为：" << m.size() << '\n' << "m的容量为：" << m.capacity() << endl;
	vector<int>(m).swap(m);
	cout << "m的有效元素个数为：" << m.size() << '\n' << "m的容量为：" << m.capacity() << endl;
}
int main()
{
	//text1();
	//text3();
	text8();
	system("pause");
	return 0;
}