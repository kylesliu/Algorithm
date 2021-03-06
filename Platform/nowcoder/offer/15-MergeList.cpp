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

/*输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。*/
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

struct ListNode {
    int val;
    struct ListNode* next;
    // ListNode(int x);
};

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {

        // 极端情况
        if (!pHead1) {
            return pHead2;
        }
        if (!pHead2) {
            return pHead1;
        }

        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        ListNode* newList = new ListNode();
        ListNode* cur = newList;
        // 如果某个链表到结尾则结束
        while (p1 && p2) {
            //将最小的数放新链表
            if (p1->val <= p2->val) {
                cur->next = p1;
                p1 = p1->next;
                cur = cur->next;
            } else {
                cur->next = p2;
                p2 = p2->next;
                cur = cur->next;
            }
            // cur->next = NULL;
        }
        if (p1) {
            cur->next = p1;
        }
        if (p2) {
            cur->next = p2;
        }
        return newList->next;
    }

    // 在链表头部插入节点
    void InsertHead(ListNode* pListHead)
    {
    }

    // 在链尾部部插入节点
    void Insert(ListNode* pListHead)
    {
    }

    // 删除第几个节点
    void Remove(ListNode* pListHead, int index)
    {
        ListNode* p = new ListNode();
    }

    // 获取链表长度
    int getLength(ListNode* pListHead)
    {
        int len = 0;
        while (pListHead != NULL) {
            len++;
            pListHead = pListHead->next;
        }
        return len;
    }

    // 链表翻转
    ListNode* Reverse(ListNode* pListHead)
    {
        if (pListHead == NULL) {
            return NULL;
        }
        ListNode* pNode = pListHead;
        ListNode* pPrev = NULL;
        while (pNode != NULL) {
            ListNode* pNext = pNode->next;

            pNode->next = pPrev;
            pPrev = pNode;

            pNode = pNext;
        }
        return pPrev;
    }

    // 查找节点位置
    int Find(ListNode* pListHead, int val)
    {
        int index = 1;
        ListNode* p = pListHead;
        while (p != NULL) {
            if (p->val == val) {
                // cout << p->val << endl;
                return index;
            }
            p = p->next;
            index++;
        }
        return -1;
    }

    void Print(ListNode* pListHead)
    {
        if (pListHead == NULL) {
            cout << "LinkList is empty" << endl;
            return;
        }
        ListNode* temp = pListHead;
        while (temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ListNode* Init(int length)
    {
        ListNode* pListHead = new ListNode();
        ListNode* p = pListHead;

        while (--length > 0) {
            p->val = getRandom(1, 20);
            p->next = createNode(getRandom(1, 20));
            p = p->next;
        }
        return pListHead;
    }

private:
    ListNode* createNode(int val)
    {
        ListNode* p = new ListNode();
        p->val = val;
        p->next = NULL;
        return p;
    }
    int getRandom(int start, int end)
    {
        return rand() % (start - end + 1) + start;
    }
};
int main()
{
    Solution s;
    ListNode* Head1 = s.Init(10);
    ListNode* Head2 = s.Init(10);
    ListNode* Head3 = s.Init(10);
    cout << "Head1" << endl;
    s.Print(Head1);
    cout << "Head2" << endl;
    s.Print(Head2);

    Head3 = s.Merge(Head1, Head2);
    cout << "Head3" << endl;
    s.Print(Head3);
    cout << s.getLength(Head3) << endl;
}
