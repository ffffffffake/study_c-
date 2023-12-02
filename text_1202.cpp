#define _CRT_SECURE_NO_WARNINGS 1
//内存超限
//#include<iostream>
//#include<vector>
//#include<set>
//#include<algorithm>
//using namespace std;
////vector<int> enjine[100000];
//int enjine[100000][10000] = { 0 };
//int main()
//{
//    int n, m, q; cin >> n >> m >> q;//引擎数，宝石种类数，开采宝石数量
//    //vector<int>type;//宝石种类对应的能量
//    int* type = (int*)malloc(sizeof(int) * m);
//    int tmp = m;
//    //int** enjine = (int**)malloc(sizeof(int*) * n);//引擎的能量
//    //for(int i=0;i<n;i++) enjine[i]= (int*)malloc(sizeof(int) * m);
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//            enjine[i][j] = 0;
//    }
//    while (tmp--)
//    {
//        int mm; cin >> mm;
//        //type.push_back(mm);
//        type[m - tmp-1] = mm;
//    }
//    while (q--)
//    {
//        int jewel,location;      cin >> jewel>>location;//宝石和位置
//        for (int i = location-1; i < min(location + type[jewel-1]-1, n); i++)
//        {
//            enjine[i][jewel-1] = 1;
//        }
//    }
//    int re = 0;
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//            re += enjine[i][j];
//        printf("%d ", re);
//        re = 0;
//    }
//    system("pause");
//    return 0;
//}

//int n, m, q;
//int s[100005];
//int h[200005];
//int dh[200005];
//vector <int> G[100005];
//int main() {
//    cin >> n >> m >> q;
//    for (int i = 1; i <= m; i++) {
//        cin >> s[i];
//    }
//    while (q--) {
//        int x, pos;
//        cin >> x >> pos;
//        G[x].push_back(pos);
//    }
//    for (int i = 1; i <= m; i++) {
//        sort(G[i].begin(), G[i].end());
//    }
//    for (int i = 1; i <= m; i++) {
//        int pos = -10000000;
//        for (int j = 0; j < G[i].size(); j++) {
//            if (G[i][j] >= pos + s[i]) {
//                dh[G[i][j]]++;
//                dh[G[i][j] + s[i]]--;
//                pos = G[i][j];
//                continue;
//            }
//            if (G[i][j] == pos) continue;
//            dh[pos + s[i]]++;
//            dh[G[i][j] + s[i]]--;
//            pos = G[i][j];
//        }
//    }
//    for (int i = 1; i <= n; i++) {
//        h[i] = h[i - 1] + dh[i];
//    }
//    for (int i = 1; i <= n; i++) {
//        cout << h[i] << ' ';
//    }
//    return 0;
//}
#include<iostream>
#include<algorithm>
//long long pow1(int x, int y)
//{
//	if (y == 0)
//		return 1;
//	return x * pow1(x, y - 1);
//}
//using namespace std;
//int main()
//{
//	ios::sync_with_stdio(), cin.tie(0), cout.tie(0);
//	/*long long x = pow1(2, 2023) % 1000;
//	int m = pow1(2, 3);
//	cout << x<<' ' << m;*/
//	int i = 23;
//	int x = 0;
//	while (i)
//	{
//		x++;
//		int tmp = x;
//		int tmp_er = 0, tmp_eight = 0;
//		while (tmp != 0)
//		{
//			if (tmp % 2 == 1)  tmp_er++;
//			tmp /= 2;
//		}
//		tmp = x;
//		while (tmp != 0)
//		{
//			if (tmp % 8 != 0)  tmp_eight+=tmp%8;
//			tmp /= 8;
//		}
//		if (tmp_er == tmp_eight)  i--;
//
//	}
//	cout << x<<endl;
//	system("pause");
//}
////
//using namespace std;
//int main()
//{
//	ios::sync_with_stdio(), cin.tie(0), cout.tie(0);
//	int m[36] = { 393353, 901440 ,123481, 850930, 423154, 240461,
//	373746, 232926, 396677 ,486579, 744860, 468782
//, 941389 ,777714, 992588, 343292, 385198, 876426
//,  483857, 241899 ,544851, 647930, 772403, 109929
//,  882745, 372491, 877710, 340000, 659788, 658675
//,  296521, 491295, 609764 ,718967, 842000, 670302 };
//	int s[36] = { 0 };
//	for (int i = 0; i < 36; i++)
//	{
//		int tmp = m[i]/2+1;
//		while (tmp!=1)
//		{
//			if (m[i] % tmp == 0) s[i]+=1;
//			tmp--;
//		}
//	}
//	int tmp = 0;
//	for (int i = 0; i < 35; i++)
//	{
//		if (s[tmp] > s[i + 1])
//			tmp++;
//	}
//	cout << s[tmp] << ' ' << m[tmp];
//	system("pause");
//}

#include<stdio.h>
//int main()
//{
//    int x;
//    scanf("%d", &x);
//    int s[6];
//    for (int i = 0; i < 6; i++)
//    {
//        s[i] = x % 10;
//        x /= 10;
//    }
//    int tmp = 10;
//    int re = s[5];
//    for (int i = 0; i < 5; i++)
//    {
//        re += s[i] * tmp;
//        tmp *= 10;
//    }
//    printf("%d\n", re);
//    system("pause");
//    return 0;
////}/*
//#include<stdio.h>
//int main()
//{
//
//    char str[10000];
//    scanf("%s", str);
//    int len = strlen(str);
//    for (int i = len - 1; i > 0; i--)
//    {
//        if (str[i] == 'a' ||
//            str[i] == 'e' ||
//            str[i] == 'i' ||
//            str[i] == 'o' ||
//            str[i] == 'u' )
//        {
//            printf("%c", str[i]);
//           system("pause");
//
//            return 0;
//        }
//    }
//
//    return 0;
//}*/
//#include<stdio.h>
//int tmp(int x)
//{
//    if (x == 0) return 1;
//    if (x % 10 == 0) return tmp(x / 10);
//    else   return x % 10 * tmp(x/10);
//}
//int main()
//{
//    long long x;
//    scanf("%lld", &x);
//    if (x < 10)
//    {
//        printf("%lld", x);
//        return 0;
//    }
//    while (x > 10)
//    {
//        x = tmp(x);
//        printf("%lld\n", x);
//    }
//    system("pause");
//    return 0;
//}


//
//#include<stdio.h>
//#include<stdlib.h>
//#include<stdbool.h>
//int n, m;
//long long** mode;
//bool** check;
//enum {
//    no,
//    on,
//    down,
//    left,
//    right
//};
//int text(int x, int y)//如果互指则为假
//{
//    if (x % y == 1) return 0;
//    if (x % y == 0) return 1;
//    return text(y, x % y);
//}
////              1 2
//void text_2(int x, int y, int* re)
//{
//    //查重
//    if (check[y][x] == true) return;
//    check[y][x] = true;
//    (*re)++;
//    if (y > 0)//像上走
//    {
//        if (text(mode[y][x], mode[y-1][x]) == 1)
//            text_2(x, y - 1, re);
//    }
//    if (y<n-1)//像下走
//    {
//        if (text(mode[y][x], mode[y+1][x]) == 1)
//            text_2(x, y +1, re);
//    }if (x>0)//像左走
//    {
//        if (text(mode[y][x-1], mode[y][x]) == 1)
//            text_2(x-1, y, re);
//    }if (x<m-1)//像右走
//    {
//        if (text(mode[y][x+1], mode[y][x]) == 1)
//            text_2(x+1, y, re);
//    }
//}
//
//
//int main()
//{
//    scanf("%d %d", &n, &m);
//    mode = (long long**)malloc(sizeof(long long*) * n);
//    for (int i = 0; i < n; i++)
//        mode[i] = (long long*)malloc(sizeof(long long) * m);
//    
//    check = (bool**)malloc(sizeof(bool*) * n);
//    for (int i = 0; i < n; i++)
//        check[i] = (bool*)malloc(sizeof(bool) * m);
//    
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//        {
//            scanf("%lld", &mode[i][j]);
//            check[i][j] = false;
//        }
//    }
//    int len, cow;
//    int re = 0;
//    scanf("%d %d", &len, &cow); len--; cow--;
//    text_2(cow, len, &re);
//    printf("%d\n", re);
//    system("pause");
//
//    return 0;
//}
#include<stdlib.h>
#include<stdio.h>
int main()
{
    int n, k; scanf("%d %d", &n, &k);
    int* num = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        scanf("%d", &num[i]);
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += num[i];
    }
    int len = n - k + 1;
    int* tmp = (int*)malloc(sizeof(int) * (len));
    tmp[0] = sum;
    for (int i = 1; i < len; i++)
    {
        tmp[i] = tmp[i - 1] - num[i - 1] + num[i + k - 1];
        if (tmp[i] > sum)
            sum = tmp[i];
    }
    printf("\n%d\n", sum);
    system("pause");
    return 0;
}
