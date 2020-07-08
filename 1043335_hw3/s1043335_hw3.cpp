#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
using namespace std;

// �ӤW�Ҫ� pseudo code
/*
For I = 1 to |A| (�Ĥ@�Ӧr�����)
	For j = 1 to |B|
		LCS(I,0) <- 0;
		LCS(0,j) <- 0;

For I = 1 to |A|
	For j = 1 to |B|
		�ھڤw��n�� LCS(i-1,j)�BLCS(I,j-1) �M LCS(i-1, j-1)�A��X LCS(I,j)    [�o�̬��`�Ʈɶ��i�����A�qMAX{}�i�o��]

��XLCS(|A||B|)
*/
int main()
{
	string str1, str2;
	while (getline(cin, str1))
	{
		getline(cin, str2);
		vector < vector<int> > LCS(1004, vector<int>(1004, 0));
		for (int i = 1; i <= str1.length(); i++)
		{
			for (int j = 1; j <= str2.length(); j++)               
			{
				if (str1[i - 1] == str2[j - 1])                    // �۵��A�h�H���W�誺 LCS ���� + 1 ������
				{
					LCS[i][j] = max(LCS[i - 1][j - 1] + 1, LCS[i][j-1]);
					LCS[i][j] = max(LCS[i][j], LCS[i - 1][j]);     // LCS = max{ LCS(i-1, j), LCS(i, j-1), LCS(i-1, j-1) +1 }
				}
				else                                               // ���۵��A�h�H����ΤW�誺 LCS ���׬�����
					LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
			}
		}
		cout << LCS[str1.length()][str2.length()] << endl;
	}
	system("pause");
	return 0;
}