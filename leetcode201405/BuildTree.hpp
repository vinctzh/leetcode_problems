// Definition for binary tree
#include "Utils.h"
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		if (preorder.size() != inorder.size())
			return NULL;		

		return buildTree_rec(preorder, 0,inorder,0,preorder.size());

	}

	TreeNode *buildTree_rec(vector<int> &preorder,int p_begin,vector<int> &inorder,int i_begin,int len){
		if (preorder.size() == 0 || preorder.size() != inorder.size())
			return NULL;		
		
		TreeNode *tmp = new TreeNode(preorder[p_begin]);
		cout<<tmp->val<<endl;
		if (len != 1)
		{		
			int in_root = i_begin;
			while ((in_root<i_begin+len) && (preorder[p_begin]!= inorder[in_root]))	in_root++;	// find the index of root in inorder vector      

			int leftlen = in_root-i_begin;
			int rightlen = len-leftlen-1;
			if (in_root != i_begin)
				tmp->left = buildTree_rec(preorder,p_begin+1,inorder,i_begin,leftlen);
			if (in_root != i_begin+len-1){
				
				tmp->right = buildTree_rec(preorder,p_begin+leftlen+1,inorder,i_begin+leftlen+1,len-leftlen-1);
			}
		}

		return tmp;
	}
};