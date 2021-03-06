#include <cstdio>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

void find_lis(vector<int> &a, vector<int> &b)
{
	vector<int> p(a.size());
	int u, v;

	if (a.empty()) return;

	b.push_back(0);

	for (size_t i = 1; i < a.size(); i++)
        {

		if (a[b.back()] < a[i])
                {
			p[i] = b.back();
			b.push_back(i);
			continue;
		}


		for (u = 0, v = b.size()-1; u < v;)
        {
			int c = (u + v) / 2;
			if (a[b[c]] < a[i]) u=c+1; else v=c;
		}


		if (a[i] < a[b[u]])
                {
			if (u > 0) p[i] = b[u-1];
			b[u] = i;
		}
	}

	for (u = b.size(), v = b.back(); u--; v = p[v]) b[u] = v;
}


int main()
{
    int cases;
    scanf("%d",&cases);
    getchar();
    getchar();
    string str;

    while (cases--)
    {
        int in;
        vector<int> seq;

        while (getline(cin,str) && str!="")
        {
            istringstream sstr(str);
            sstr>>in;
            seq.push_back(in);
        }

        vector<int> lis;
        find_lis(seq, lis);

        printf("Max hits: %d\n",lis.size());
        for (size_t i = 0; i < lis.size(); i++)
            printf("%d\n", seq[lis[i]]);

        if (cases)printf("\n");
    }



	return 0;
}
