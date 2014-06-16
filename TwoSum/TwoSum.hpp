/*
	Given an array of integers, find two numbers such that they add up to a specific target number.

	The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

	You may assume that each input would have exactly one solution.

	Input: numbers={2, 7, 11, 15}, target=9
	Output: index1=1, index2=2
	Copyright © 2014 Vincent Zhang 
	Blog: http://www.centvin.com 
*/
#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		return twoSum_map(numbers,target);
	}

private:
	// O(n*n)  rejec for "time limit exceed"
	vector<int> twoSumOn2(vector<int> &numbers, int target) {
		vector<int> inds;
		int countNums = numbers.size();
		for (int i=0; i<countNums-1;i++) {
			int curFirst = numbers[i];
			for (int j=i+1;j<countNums;j++) {
				if ((curFirst + numbers[j] == target)) {
					inds.push_back(i+1);
					inds.push_back(j+1);
					return inds;
				}
			}
		}
		return inds;
	}

	// O(nlog(n)) with map<K,V>
	vector<int> twoSum_map(vector<int> &numbers, int target) {
		int countNums = numbers.size();
		vector<int> inds;

		map<int, int> numbers_map;
		for (int i=0;i<countNums;i++) 
			numbers_map[numbers[i]] = i;	// use the value of the number as key, and the index as the value of the map.

		map<int,int>::iterator it;
		for (int i=0; i<countNums;i++) {
			it = numbers_map.find(target-numbers[i]);
			if (it != numbers_map.end() && it->second != i ) {
				inds.push_back(i+1);
				inds.push_back(it->second+1);
				return inds;
			}
		}
		return inds;
	}
};