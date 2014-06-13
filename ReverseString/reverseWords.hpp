#include "Utils.h"

class Solution_v1 {
public:
	void reverseWords(string &s) {

		int s_len = s.length();
		vector<string> words;
		
		int index = 0;
		while (index<s_len&& (!isValidPartOfWord(s[index])))
			index++;
		
		string word;
		while (index<s_len)
		{
			if (isValidPartOfWord(s[index]))
			{
				word.push_back(s[index]);
				index++;
			}else
			{
				words.push_back(word);
				word.clear();

				while (index<s_len&& (!isValidPartOfWord(s[index])))
					index++;
			}
		}

		if (!word.empty()){
			words.push_back(word);
		}

		int wordCount = words.size();
		string reversed;
		for (int i=wordCount-1;i>=0;i--)
		{
			reversed = reversed + words[i];
			if(i>0)
				reversed.push_back(' ');
		}
		s = reversed;
		cout<<s;
		
	}
	bool isValidPartOfWord(char a){
		if (a!=' '&& a !='\t' && a!='\n')
			return true;
		else
			return false;
	} 	
};

/************************************************************************/
/*隆迪 version                                                                     */
/************************************************************************/
class SolutionLD {
public:
	void reverseWords(string &s) {
		int flag=0;
		stack<string> S;
		string word;
		istringstream orgStr(s);	//!!!!!!!!!istringstream 太好用！！！！
			while(orgStr>>word)     //!!!!!!!!!istringstream 太好用！！！！
				S.push(word);
		s.clear();
		while(!S.empty()){
			flag = 1;
			s+=S.top()+" ";// s.top() 加 s.pop()的操作！！！！
			S.pop();
		}
		if(flag)//【边界条件！】如果s为空，不能执行s.erase(s.end()-1),会向下溢出！！！！
			s.erase(s.end()-1);//删除最后一个元素！！！！！
	}
};