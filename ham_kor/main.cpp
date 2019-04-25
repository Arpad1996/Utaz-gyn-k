#include<iostream>

using namespace std;

int ary[10][10], fin[10], n, cost = 0;

int gover(int c)
{
	int i, nc = 999;
	int min = 999, kmin;

	for (i = 0; i < n; i++)
	{
		if ((ary[c][i] != 0) && (fin[i] == 0))
		if (ary[c][i] + ary[i][c] < min)
		{
			min = ary[i][0] + ary[c][i];
			kmin = ary[c][i];
			nc = i;
		}
	}

	if (min != 999)
		cost += kmin;

	return nc;
}

void takeInput()
{
	int i, j;

	cout << "Number of rows: ";
	cin >> n;

	cout << "\nEnter the Cost Matrix\n";

	for (i = 0; i < n; i++)
	{
		cout << "\nEnter Elements of Row: " << i + 1 << "\n";

		for (j = 0; j < n; j++)
			cin >> ary[i][j];

		fin[i] = 0;
	}

	cout << "\n\nThe cost list is:";

	for (i = 0; i < n; i++)
	{
		cout << "\n";

		for (j = 0; j < n; j++)
			cout << "\t" << ary[i][j];
	}
}



void mincost(int node)
{
	int i, nnode;

	fin[node] = 1;

	cout << node + 1 << "--->";
	nnode = gover(node);

	if (nnode == 999)
	{
		nnode = 0;
		cout << nnode + 1;
		cost += ary[node][nnode];

		return;
	}

	mincost(nnode);
}

int main()
{
	takeInput();

	cout << "\n\nThe Path is:\n";
	mincost(0); 

	cout << "\n\nMinimum cost is " << cost;

	return 0;
}