#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

struct people
{
	char id[19];   /* ����֤���� */
	int social;	   /* �籣�������� */
	int area;	   /* ����ס����� */
	char date[11]; /* �걨���� */
	bool operator<(const people &b) const
	{
		if (area == 0 && social <= 24)
			return 0;
		if (b.area == 0 && b.social <= 24)
			return 1;
		if (area != b.area)
			return area < b.area;
		if (area == 0 && social != b.social)
			return social > b.social;
		for (int i = 6; i < 10; ++i)
			if (date[i] != b.date[i])
				return date[i] < b.date[i];
		for (int i = 0; i < 2; ++i)
			if (date[i] != b.date[i])
				return date[i] < b.date[i];
		for (int i = 3; i < 5; ++i)
			if (date[i] != b.date[i])
				return date[i] < b.date[i];
		return 0;
	}
};

people *getMess(int &n);

int main()

{
	people *person; /* ָ�����б����˵Ļ��������׵�ַ��ͨ�����ú���getMess��ȡ */
	int n;			/* nΪ����������ͨ�����ú���getMess��ȡ */
	person = getMess(n);
	sort(person, person + n);
	map<string, int> mp;
	for (int i = 0; i < n; i++)
		mp[person[i].id] = i;
	int t, m;
	cin >> m >> t;
	while (t--)
	{
		char c[19];
		scanf("%s", c);
		string s = c;
		int id = mp[s];
		int l = lower_bound(person, person + n, person[id]) - person + 1;
		int r = upper_bound(person, person + n, person[id]) - person;
		if ((person[id].area == 0 && person[id].social <= 24) || l > m)
			printf("Sorry\n");
		else if (l == r)
			printf("%d\n", l);
		else
			r > m ? printf("%d/%d\n", m - l + 1, r - l + 1) : printf("%d %d\n", l, r);
	}
	return 0;
}

people *getMess(int &n) 
{
	FILE *fp;
	fp = fopen("house.bin", "rb");
	fseek(fp, -1 * (long)sizeof(int), SEEK_END);
	fread(&n, sizeof(int), 1, fp);
	rewind(fp);
	people *tmp = new people[n];
	fread(tmp, sizeof(people), n, fp);
	fclose(fp);
	return tmp;
}