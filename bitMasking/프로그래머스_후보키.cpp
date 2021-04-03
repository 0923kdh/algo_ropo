#include <string>
#include <vector>
#include <set>

using namespace std;

bool minimalityDuplicationCheck(vector<int> v, int now)
{
	for (int i = 0; i < v.size(); i++)
	{
		if ((v[i] & now) == v[i])
			return false;
	}

	return true;
}

int solution(vector<vector<string>> relation)
{
	int rowSize = relation.size();
	int colSize = relation[0].size();
	vector<int> ans;

	//(1 << colSize) == 2^colSize == 2^4 == 16
	for (int i = 1; i < (1 << colSize); i++)
	{
		if (minimalityDuplicationCheck(ans, i) == false)
			continue;

		set<string> s;
		for (int j = 0; j < rowSize; j++)
		{
			string cur;
			for (int k = 0; k < colSize; k++)
			{
				//k < 4,
				// (1 << 0) == 2^0 = 1
				// (1 << 1) == 2^1 = 2
				// (1 << 2) == 2^2 = 4
				// (1 << 3) == 2^3 = 8
				if (i & (1 << k))
					cur += relation[j][k];
			}
			//이미 담긴 string은 중복으로 담지않기 위해 set 자료구조 사용
			s.insert(cur);
		}

		//s.size가 rowSize 와 다르면 식별가능하지 않다는 뜻임
		if (s.size() == rowSize)
			ans.push_back(i);
	}

	return ans.size();
}