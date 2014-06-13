/*
	Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

	get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
	set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, 
				  it should invalidate the least recently used item before inserting a new item. 
	Problem link: https://oj.leetcode.com/problems/lru-cache/

	Author: Vincent Zhang
*/

#include <map>
using namespace std;

struct CacheNode {
	int key;
	int value;
	CacheNode* prev;
	CacheNode* next;
	CacheNode(int k,int v) : key(k), value(v), prev(NULL), next(NULL) {}
};

class LRUCache{
public:
	LRUCache(int capacity) {
		this->cache_capacity = capacity;
		head = NULL;
		tail = NULL;		
	}

	int get(int key) {
		map<int,CacheNode*>::iterator it = cache_map.find(key);
		if (it == cache_map.end())
			return -1;
		else
		{
			CacheNode *tp = it->second;
			moveToHead(tp);
			return tp->value;
		}
	}

	void set(int key, int value) {
		map<int,CacheNode*>::iterator it = cache_map.find(key);
		// new key and value
		if (it == cache_map.end())
		{	
			// cache is full, release the LRU one and add new
			if (cache_map.size() == cache_capacity)
			{
				cache_map.erase(tail->key);
				tail->key = key;
				tail->value = value;
				CacheNode *tp = tail;
				moveToHead(tp);

				cache_map.insert(map<int,CacheNode*>::value_type(key,tp));
			}
			else	// cache is not full, add new
			{
				CacheNode *newNode = new CacheNode(key,value);
				attachToHead(newNode);
				cache_map.insert(map<int,CacheNode*>::value_type(key,newNode));
			}
			
		}
		else	// has an exist node
		{
			CacheNode *tp = it->second;
			tp->value = value;

			isolateNode(tp);
			attachToHead(tp);
		}

	}
private:
	int cache_capacity;
	CacheNode *head,*tail;
	map<int,CacheNode*> cache_map;

	void moveToHead(CacheNode *node)
	{
		if (node == head)
			return;
		else
		{
			isolateNode(node);
			attachToHead(node);
		}
	}
	void isolateNode(CacheNode* node)
	{
		if (node->prev != NULL)		
			node->prev->next = node->next;
		else // node is head
			head = node->next;
		
		if (node->next !=NULL)
			node->next->prev = node->prev;
		else	// node is tail
			tail = node->prev;

		node->next = NULL;
		node->prev = NULL;		
	}
	void attachToHead(CacheNode* node)
	{
		// head is null, list is empty
		if (head == NULL)
		{
			head = node;
			tail = head;
		}
		else
		{
			node->next = head;
			head->prev = node;
			head = node;
		}
	}
};