#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
using namespace std;

// 照上課的 pseudo code
/*
For I = 1 to |A| (第一個字串長度)
	For j = 1 to |B|
		LCS(I,0) <- 0;
		LCS(0,j) <- 0;

For I = 1 to |A|
	For j = 1 to |B|
		根據已算好的 LCS(i-1,j)、LCS(I,j-1) 和 LCS(i-1, j-1)，算出 LCS(I,j)    [這裡為常數時間可完成，從MAX{}可得知]

輸出LCS(|A||B|)
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
				if (str1[i - 1] == str2[j - 1])                    // 相等，則以左上方的 LCS 長度 + 1 為長度
				{
					LCS[i][j] = max(LCS[i - 1][j - 1] + 1, LCS[i][j-1]);
					LCS[i][j] = max(LCS[i][j], LCS[i - 1][j]);     // LCS = max{ LCS(i-1, j), LCS(i, j-1), LCS(i-1, j-1) +1 }
				}
				else                                               // 不相等，則以左方或上方的 LCS 長度為長度
					LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
			}
		}
		cout << LCS[str1.length()][str2.length()] << endl;
	}
	system("pause");
	return 0;
}