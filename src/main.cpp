#include <stdio.h>
#include <queue>
#include <vector>



//use two stack implement que

//1 3 5
//push 4
//pop 5


#include <list>
#include  <iostream>
using namespace std;
void listTest()
{
	list<int> list1;
	list<int> list2;
	list1.push_back(1);
	list1.push_back(2);
	list1.push_back(3);
	list2.push_back(4);
	list2.push_back(8);
	list2.push_back(6);
	auto iter = list1.begin();
	++iter;

	list1.splice(list1.begin(),
		list1, iter);       //list1 = list1 + [list2++, list2.end), list2 = list2.begin();
	for (auto iter1 : list1) {
		printf("%d\n", iter1);
	}
}
struct List {
	int value;
	List *next;
};


struct ListNode {
	int value;
	ListNode*left;
	ListNode*right;
};
void qsort(int *array, int start, int end, int length)
{
	if (array == nullptr)return;
	if (start >= end)return;
	if (length == 0)return;
	int indexData = array[end];
	int smart = start;
	for (int i = start; i < end; ++i)
	{
			if (indexData > array[i])
			{
				if (smart != i)
				{
					std::swap(array[i], array[smart]);
				}
				smart++;
			}
	}
	swap(array[smart], array[end]);
	if (smart > start)
	{
		qsort(array, start, smart - 1, length);
	}
	if (smart < end)
	{
		qsort(array, smart + 1, end, length);
	}
}

bool isValidBalanceTree(ListNode *root, int MIN, int MAX) {
	if (root == nullptr)return true;
	if (root->left != nullptr && root->left->value > MIN) {
		return false;
	}
	if (root->right != nullptr && root->right->value < MAX) {
		return false;
	}
	return isValidBalanceTree(root->left, root->value, MAX) && isValidBalanceTree(root->right, MIN, root->value);
}
#include<algorithm>
int getMaxSum(int *data, int len)
{
	if (data == nullptr)return 0;
	int maxSum = 0;
	int maxMaxSum = 0;
	for (int i = 0; i < len; ++i)
	{
		maxSum = std::max(data[i] + maxSum, data[i]);
		maxMaxSum = std::max(maxMaxSum, maxSum);
	}
	return maxMaxSum;
}

int getMaxStep(int *data, int len)
{
	if (nullptr == data)return 0 ;
	int left = 0, right = data[0];
	int step = 0;
	
	
	for (int i = left; i < len; )
	{
		int round = -1;
		if (i + data[i] >= len)return step;
		for (int j = left + 1; j <= right; ++j)
		{
			if (round < data[j] + j)
			{
				i = left = j;
				round = data[j] + j;
			}
		}
		step++;
		printf("round = %u\n", i);

		left = right;
		right = round;
	}
	return step;
}

bool match(char *src, char *pattern)
{
	if (src == nullptr)return false;
	int srcLen = strlen(src);
	int patternLen = strlen(pattern);

	vector<vector<bool> >dp;
	dp[0][0] = src[0] == pattern[0] || pattern[0] == '.';

	for (int i = 1; i < patternLen; ++i)
	{
		if (pattern[i-1] == '*')
		{
			if (i == 1)dp[0][1] = dp[0][0];
			else
			dp[0][i] = dp[0][i - 2];
		}
	}
	for (int i = 1; i < srcLen; ++i)
	{
		for (int j = 1; i < patternLen; ++j)
		{
			if (pattern[j - 1] == '*')
			{
				dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && (src[i - 1] == pattern[j - 2] || pattern[j - 2] == '.'));
			}
			else
			{
				dp[i][j] = dp[i - 1][j - 1] && src[i-1] == pattern[j -1] || pattern[j - 1] == '.';
			}
		}
	}
	return dp[srcLen][patternLen];
}
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <windows.data.json.h>

typedef void(*regHandle)(const std::string &str);
std::unordered_map<const char *, regHandle> strHandle;

struct Filter {

	bool match(void *value);
	void setFilterData(const std::string &str);
	std::vector<std::string>_filterStrList;
};
void Filter::setFilterData(const std::string &str)
{
	if (str.length() == 0)return;
	int num = count(str.begin(), str.end(), '&');
	std::string::size_type iterPos = 0;
	printf("num =%d\n", num);
	if (num > 0)
	{
		while (num)
		{
			std::string::size_type pos = str.find('&', iterPos);
			if (std::string::npos != pos)
			{
				string newStr(str.substr(iterPos, pos));
				if(pos > iterPos)
				   newStr[pos - iterPos] = '\0';
				_filterStrList.push_back(newStr);
				iterPos = pos + 1;
				--num;
			}
			else {
				break;
			}
		}
	}
	_filterStrList.push_back(str.substr(iterPos));
	for (auto iter : _filterStrList)
	{
		printf("%s\n", iter.c_str());
	}
}

bool Filter::match(void *json)
{
	for (auto &filterIter : _filterStrList)
	{
	    ///判断是否是只有字母和数字的
		for (auto & strIter : strHandle)
		{
			//
			if (std::string::npos != filterIter.find(strIter.first()))
			{

			}
		}
	}
	return false;
}

int main()
{
	Filter filter;
	string str("1222dffd&dfasdd&ddfffd&1222");
	filter.setFilterData(str);
	std::cin.get();
	return 0;
}