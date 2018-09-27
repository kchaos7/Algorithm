///*이중 연결리스트로 deck구현하기!
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class DequeNode
{
private:
public:
	int data;
	DequeNode* rLink;
	DequeNode* lLink;
	DequeNode(int _data = 0)
		: data(_data), rLink(NULL), lLink(NULL)
	{}
	~DequeNode()
	{}
};


class Deque
{
private:
	DequeNode* head;
	DequeNode* tail;
public:
	Deque()
		: head(NULL), tail(NULL)
	{}
	~Deque()
	{}
	void push_front(int _element)
	{
		DequeNode* newNode = new DequeNode(_element);
		//if (head)//head != NULL
		if (isEmpty())
			head = tail = newNode;
		else
		{
			head->lLink = newNode;
			newNode->rLink = head;
			head = newNode;
		}
	}
	void push_back(int _element)
	{
		DequeNode* newNode = new DequeNode(_element);
		if (isEmpty())
			tail = head = newNode;
		else
		{
			tail->rLink = newNode;
			newNode->lLink = tail;
			tail = newNode;
		}
	}
	int pop_front()
	{
		if (isEmpty())
			return -1;
		int data = head->data;
		//요소가 2개 이상이면
		if (head != tail)
		{
			head = head->rLink;
			head->lLink = NULL;
			delete head->lLink;
		}
		//요소가 1개라면
		else{
			delete head;
			tail = head = NULL;
		}
		return data;
	}
	int pop_back()
	{
		if (isEmpty())
			return -1;
		int data = tail->data;
		
		//요소가 2개 이상이면
		if (head != tail){
			tail = tail->lLink;
			tail->rLink = NULL;
			delete tail->rLink;
		}
		//요소가 1개이면
		else
		{
			delete head;
			head = tail = NULL;
		}
		return data;
	}
	bool isEmpty()
	{
		//return (head == NULL) ? true : false;
		return (head == NULL) ? 1 : 0;
	}
	int front()
	{
		if (isEmpty())
			return -1;
		return head->data;
	}
	int back()
	{
		if (isEmpty())
			return -1;
		return tail->data;
	}
	int getSize()
	{
		if (isEmpty())
			return 0;
		int cnt = 1;
		DequeNode* node = head;
		while (node = node->rLink)
			cnt++; 
		return cnt;
	}
};
int main()
{
	int testcase;
	cin >> testcase;
	string cmnd;
	Deque deque;
	int element;
	for (int i = 0; i < testcase; i++)
	{
		cin >> cmnd;
		if (!cmnd.compare("push_front")){
			cin >> element;
			deque.push_front(element);
		}
		else if (!cmnd.compare("push_back")){
			cin >> element;
			deque.push_back(element);
		}
		else if (!cmnd.compare("pop_front"))
			cout << deque.pop_front() << endl;
		else if (!cmnd.compare("pop_back"))
			cout << deque.pop_back() << endl;
		else if (!cmnd.compare("size"))
			cout << deque.getSize() << endl;
		else if (!cmnd.compare("empty"))
			cout << deque.isEmpty() << endl;
		else if (!cmnd.compare("front"))
			cout << deque.front() << endl;
		else if (!cmnd.compare("back"))
			cout << deque.back() << endl;
	}
	return 0;
}
//*/