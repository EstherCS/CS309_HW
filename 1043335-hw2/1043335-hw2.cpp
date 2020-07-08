#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct Element
{
	int Eu;
	int Ev;
	int Ew;
}ele[25004];

bool operator<(const Element &ele1, const Element &ele2)
{
	return ele1.Ew < ele2.Ew;
}

int integer[1004]{};

int find(int x)                       // find the root
{
	if (x == integer[x])
		return x;
	return integer[x] = find(integer[x]);
}

int main()
{
	int m, n;
	int u, v, w;
	vector <int> out;
	// input nodes (n), and edges ( m ), n + m > 0, n > 0
	while (cin >> n >> m && m + n && n)
	{
		for (int i = 0; i < m; i++)
		{
			cin >> u >> v >> w;
			ele[i].Eu = u;              // input u, v, w to structure
			ele[i].Ev = v;
			ele[i].Ew = w;
		}
		sort(ele, ele + m);             // sort ele[]'s weight, then ele[] is small to big

		bool check = true;              // check if cycle is exist
		for (int i = 0; i < n; i++)
		{
			integer[i] = i;
		}
		for (int i = 0; i < m; i++)
		{
			u = find(ele[i].Eu);        // find the start node
			v = find(ele[i].Ev);        // find the end node
			if (u == v)                 // cout the edge's weight that we want to delete
			{
				out.push_back(ele[i].Ew);
				//cout << ele[i].Ew << " ";
				check = false;
			}
			integer[u] = v;             // node u's end node is v
		}
		if (check)
			out.push_back('f');
		//cout << "forest";
		cout << endl;
		out.push_back('N');
	}
	for (int i = 0; i < out.size(); i++)
	{
		if (out[i] == 'N')
			cout << endl;
		else if (out[i] == 'f')
			cout << "forest";
		else
			cout << out[i] << " ";
	}
	system("pause");
}