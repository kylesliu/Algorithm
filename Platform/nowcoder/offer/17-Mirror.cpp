#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <malloc.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string.h>
#include <string>
#include <utility>
#include <vector>
#define TIME std::ios::sync_with_stdio(false)
#define LL long long
#define MAX 233
#define INF 0x3f3f3f3f

using namespace std;

/*输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）*/
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    struct TreeNode* next;
    TreeNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL)
    {
    }
};

class Solution {
public:
    // 递归
    void Mirror(TreeNode* pTreeRoot)
    {
        if (pTreeRoot == NULL
            && pTreeRoot->left == NULL
            && pTreeRoot->right == NULL) {
            return;
        }
        // 递归左右交换
        TreeNode* pTemp = pTreeRoot->left;
        pTreeRoot->left = pTreeRoot->right;
        pTreeRoot->right = pTemp;
        if (pTreeRoot->left) {
            Mirror(pTreeRoot->left);
        }
        if (pTreeRoot->right) {
            Mirror(pTreeRoot->right);
        }
    }
    // 非递归
    void Mirror1(TreeNode* pRoot)
    {
        if (pRoot == NULL
            && pRoot->left == NULL
            && pRoot->right == NULL) {
            return;
        }
        stack<TreeNode*> stackNode;
        stackNode.push(pRoot);
        while (stackNode.size()) {
            TreeNode* tree = stackNode.top();
            stackNode.pop();
            if (tree->left != NULL || tree->right != NULL) {
                TreeNode* ptemp = tree->left;
                tree->left = tree->right;
                tree->right = ptemp;
            }
            if (tree->left)
                stackNode.push(tree->left);
            if (tree->right)
                stackNode.push(tree->right);
        }
    }
    // 先序遍历
    void PreorderTraverse(TreeNode* pTreeRoot)
    {
        if (pTreeRoot != NULL) {
            cout << pTreeRoot->val << " ";
            PreorderTraverse(pTreeRoot->left);
            PreorderTraverse(pTreeRoot->right);
        }
    }
    // 非递归先序遍历
    void PreorderTraverseNoRecursion(TreeNode* pTreeRoot)
    {
        if (pTreeRoot == NULL) {
            cout << "The Tree is Empty" << endl;
        }
        stack<TreeNode*> stack;
        while (pTreeRoot || !stack.empty()) {
            while (pTreeRoot) {
                cout << pTreeRoot->val << " ";
                stack.push(pTreeRoot);
                pTreeRoot = pTreeRoot->left;
            }
            pTreeRoot = stack.top();
            stack.pop();
            pTreeRoot = pTreeRoot->right;
        }
    }
    // 递归中序遍历
    void MidorderTraverse(TreeNode* pTreeRoot)
    {
        if (pTreeRoot) {
            MidorderTraverse(pTreeRoot->left);
            cout << pTreeRoot->val << " ";
            MidorderTraverse(pTreeRoot->right);
        }
    }
    // 非递归中序遍历
    void MidorderTraverseNoRecursion(TreeNode* pTreeRoot)
    {
        if (pTreeRoot == NULL) {
            cout << "The Tree is Empty" << endl;
        }
        stack<TreeNode*> stack;
        while (pTreeRoot || !stack.empty()) {
            while (pTreeRoot) {
                stack.push(pTreeRoot);
                pTreeRoot = pTreeRoot->left;
            }
            pTreeRoot = stack.top();
            stack.pop();
            cout << pTreeRoot->val << " ";
            pTreeRoot = pTreeRoot->right;
        }
    }
    // 递归后序遍历
    void PostorderTraversal(TreeNode* pTreeRoot)
    {
        if (pTreeRoot) {
            PostorderTraversal(pTreeRoot->left);
            PostorderTraversal(pTreeRoot->right);
            cout << pTreeRoot->val << " ";
        }
    }

    // 非递归后序遍历
    void PostorderTraversalNoRecursion(TreeNode* pTreeRoot)
    {
        if (pTreeRoot == NULL) {
            cout << "The Tree is Empty" << endl;
        }
        stack<TreeNode*> stack;
        while (pTreeRoot || !stack.empty()) {
            while (pTreeRoot) {
                stack.push(pTreeRoot);
                pTreeRoot = pTreeRoot->left;
            }
            pTreeRoot = stack.top();
            stack.pop();
            cout << pTreeRoot->val << " ";
            pTreeRoot = pTreeRoot->right;
        }
    }

    // 根据数组初始化树
    TreeNode* Init(vector<int> arr)
    {
        TreeNode* tree = new TreeNode(0);
        tree = CreateBinaryTree(tree, arr, 0);
        return tree;
    }

private:
    // 递归创建树
    /*
        params 
            TreeNode* tree      当前节点
            vector<int> arr     数据
            int index           数据下标

    */

    void CreatBiTree(TreeNode*& T, vector<int> arr, int index)
    { // 先序递归创建二叉树
        // 先按顺序驶入二叉树中节点的值(一个字符),空格字符代表空树
        char ch;
        for (int j = 0; j < arr.size(); ++j) {
            if (arr[index] == -1) // getchar() 为逐个读入标准库函数
                T = NULL;
            else {
                T = new TreeNode(0); // 产生新的子树
                T->val = ch; // 由getchar()逐个读进来
                CreatBiTree(T->left, arr, --index); // 递归创建左子树
                CreatBiTree(T->right, arr, --index); // 递归创建右子树
            }
        }
    }
    TreeNode* CreateBinaryTree(TreeNode* root, vector<int> arr, int index)
    {
        cout << "index:" << index << " arr[index]:" << arr[index] << endl;
        if (arr[index] == -1) {
            return NULL;
        }

        if (index < arr.size()) {
            root = new TreeNode(arr[index]);
            root->left = CreateBinaryTree(root, arr, ++index);
            root->right = CreateBinaryTree(root, arr, ++index);
        }
        return root;
    }

    int getRandom(int start, int end)
    {
        return rand() % (start - end + 1) + start;
    }
};
int main()
{
    Solution s;
    vector<int> data = { 1, 2, 4, -1, -1, -1, 3, 5, -1, -1 };
    // TreeNode* pTreeRoot = s.Init(data);
    // cout << pTreeRoot->right->left->val << endl;

    TreeNode* pTreeRoot = new TreeNode(8);

    pTreeRoot->left = new TreeNode(6);
    pTreeRoot->right = new TreeNode(10);

    pTreeRoot->left->left = new TreeNode(5);
    pTreeRoot->left->right = new TreeNode(7);

    pTreeRoot->right->left = new TreeNode(9);
    pTreeRoot->right->right = new TreeNode(11);

    cout << "Source: " << endl;
    s.PreorderTraverse(pTreeRoot);
    s.Mirror1(pTreeRoot);
    cout << "\nMirror: " << endl;
    s.PreorderTraverse(pTreeRoot);

    return 0;
}
