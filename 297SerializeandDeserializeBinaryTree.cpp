/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string str;
		serial(root,str);
		return str.substr(1);
	}
	void serial(TreeNode *root,string &s){
		if(root==nullptr) {
			s += ",#";
		}else{
			s = s + "," + to_string(root->val);
			serial(root->left,s);
			serial(root->right,s);
		}
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		deque<string> dq;
		int pre = 0;
		for (int i=0;i<data.size();++i) {
			if (data[i]==','){
				dq.push_back(data.substr(pre,i-pre));
				pre = i+1;
			}
		}
		dq.push_back(data.substr(pre));
		return deserial(dq);
	}
	TreeNode* deserial(deque<string>& dq){
		string s = dq.front();
		dq.pop_front();
		if (s=="#"){
			return nullptr;
		}else{
			TreeNode *node = new TreeNode(stoi(s));
			node->left = deserial(dq);
			node->right = deserial(dq);
			return node;
		}
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));