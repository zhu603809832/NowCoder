#pragma once
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		bool bResult = false;
		stack<int> tempStack;
		if (pushV.size() == 0)
			return bResult;

		int j = 0;
		for (int i = 0 ; i < pushV.size(); ++i)
		{
			tempStack.push(pushV[i]);
			while (j < popV.size() && tempStack.top() == popV[j])
			{
				tempStack.pop();
				++j;
			}
		}
		bResult = tempStack.size() == 0;
		return bResult;
	}
	bool TestSolution() {
		bool bResult = false;
		int PushA[] = { 1,2,3,4,5 };
		int PopA[] = { 4,5,3,1,2 };
		vector<int> PushVec(PushA, PushA + 5);
		vector<int> PopVec(PopA, PopA + 5);
		bool bRet = IsPopOrder(PushVec, PopVec);
		bResult = true;
		return bResult;
	}
};

/*
链接：https://www.nowcoder.com/questionTerminal/d77d11405cc7470d82554cb392585106?f=discussion
来源：牛客网

class Solution {
public:
bool IsPopOrder(vector<int> pushV,vector<int> popV) {
if(pushV.size() == 0) return false;
vector<int> stack;
for(int i = 0,j = 0 ;i < pushV.size();){
stack.push_back(pushV[i++]);
while(j < popV.size() && stack.back() == popV[j]){
stack.pop_back();
j++;
}
}
return stack.empty();
}
};

*/