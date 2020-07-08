#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
using namespace std;

vector<int> randomized(vector<int>, int ,int );

int main()
{
	int n;
	do
	{
		cin >> n;
	} while (n > 100000 || n < 1);
	vector<int> Array(n, 0);                     // �Ы� n �j�p�� vector �B����J 0
	for (int i = 0; i < n; i++)
		cin >> Array[i];

	vector<int> print = randomized(Array, 0, n); // �ǤJ�}�C

	for (int i = 0; i < n; i++)
		cout << print[i] << endl;

	system("pause");
	return 0;
}

vector<int> randomized(vector<int> a, int first, int last)
{
	if (last - first <= 1)
	{
		return a;
	}
	srand(time(NULL));
	vector<int> left, right, Final;
	int pivotIndex = rand() % (last - first) + first;  // ���n��z���q�� pivot
	int pivot = a[pivotIndex];

	for (int i = first; i < last; i++)
	{
		if (a[i] < pivot)
		{
			left.push_back(a[i]);                      // �� pivot �p������
		}
		else if (a[i] > pivot)
		{
			right.push_back(a[i]);                     // �� pivot �j����k��
		}
	}
	left = randomized(left, 0, left.size());
	right = randomized(right, 0, right.size());
	for (int i = 0; i < left.size(); i++)
		Final.push_back(left[i]);
	for (int i = 0; i < a.size() - (left.size() + right.size()); i++) // �i�঳�h�Ӹ� pivot ���ƪ��Ʀr
		Final.push_back(pivot);
	for (int i = 0; i < right.size(); i++)
		Final.push_back(right[i]);

	return Final;
}
