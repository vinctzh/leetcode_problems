#include "Utils.h"

// Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		if (inorder.empty() || inorder.size() != postorder.size())
			return NULL;

		return buildTreeInAndPost_rec(inorder,0,postorder,0,inorder.size());
	}
	TreeNode *buildTreeInAndPost_rec(vector<int> &inorder, int i_begin, 
										vector<int> &postorder,int p_begin,
										int len)
	{
		if (len == 0) return NULL;
		
		TreeNode* temp = new TreeNode(postorder[p_begin+len-1]);
		
		int root_index = i_begin;
		if(len != 1){

			while ((root_index<i_begin+len) && (inorder[root_index] != postorder[p_begin+len-1]))
			{
				root_index++;
			}
			
			int next_left_len = root_index - i_begin;
			
			if (root_index != i_begin)
			{
				temp->left = buildTreeInAndPost_rec(inorder,i_begin,postorder,p_begin,next_left_len);
			}

			if (root_index != i_begin+len-1)
			{
				temp->right = buildTreeInAndPost_rec(inorder,i_begin+next_left_len+1,postorder,p_begin+next_left_len,len-next_left_len-1);
			}
		}
		return temp;
	}
};