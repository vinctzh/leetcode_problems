/*
	Given an array of integers, find two numbers such that they add up to a specific target number.

	The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

	You may assume that each input would have exactly one solution.

	Input: numbers={2, 7, 11, 15}, target=9
	Output: index1=1, index2=2
	Copyright ©2014 Vincent Zhang 
	Blog: http://www.centvin.com 
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		inds.clear();
		size = numbers.size();
		this->numbers = numbers;
		for (int i=0;i<ceil(double(size)/2);i++) {
			if (twoSumFound(i,target))  break;
		}
		return inds;
	}

private:
	vector<int> inds; 
	vector<int> numbers;
	int size;
	bool twoSumFound(int cur_ind, int target){
		for (int i=cur_ind+1;i<size; i++) {
			if (numbers[i]+numbers[cur_ind] == target) {
				inds.push_back(cur_ind+1);
				inds.push_back(i+1);
				return true;
			}
		}
		return false;
	}
};