#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int minCostToMoveChips1(vector<int>& chips)
{//自己的烂算法，用了hash  还用了n^2的复杂度
	unordered_map<int, int> temp;
	for (auto i : chips)
	{
		if (temp.find(i) != temp.end())
			temp[i]++;
		else
			temp[i] = 1;
	}
	int res = INT_MAX, count = 0;
	for (auto i = temp.begin(); i != temp.end(); i++)
	{
		count = 0;
		for (auto j = temp.begin(); j != temp.end(); j++)
			count += abs(j->first - i->first) % 2 * j->second;
		res = min(res, count);
	}
	return res;
}

int minCostToMoveChips(vector<int>& chips)
{//大神的算法
	int pos0 = 0, pos1 = 0;
	for (auto i : chips)
	{
		if (i % 2)
			pos1++;
		else
			pos0++;
	}
	return min(pos0, pos1);
}

int main()
{
	vector<int>chips({ 1,2,3 });
	cout << minCostToMoveChips(chips) << endl;
	system("pause");
	return 0;
}