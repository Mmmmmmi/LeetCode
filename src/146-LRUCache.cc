/*
运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。
获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
写入数据 put(key, value) - 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值留出空间。

进阶:
    你是否可以在 O(1) 时间复杂度内完成这两种操作？


 */

#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
private:
    int _capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> dict;
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        //map 中找 找到了 就说明链表中有
        //把链表中的拿出来 返回回去 然后 重新插入到链表的头 更新map的迭代器        
        auto mappos = dict.find(key);//map 中找到
        //map 中没有 直接返回 
        if (mappos == dict.end())
        {
            //not found
            return -1;
        }
        //从链表里面拿出来 放到链表尾 
        pair<int, int> tmp  = *(dict[key]);
        //放到链表尾部
        cache.erase(dict[key]);
        cache.push_front(tmp);
        //更新map
        dict[key] = cache.begin();  
        //返回value
        return tmp.second;
    }
    
    void put(int key, int value) {
        auto mappos = dict.find(key);
        if (mappos != dict.end())   //map 中 找到
        {
            //更新位置
            pair<int ,int> tmp = *(dict[key]);
            cache.erase(dict[key]);
        }
        else  //map中没有找到
        {
            if (cache.size() == _capacity)  //需要淘汰
            {
                auto del = cache.back();
                dict.erase(del.first);   //删除map 中数据
                cache.pop_back();        //从链表中删除数据
            }
        }
        //添加新数据    
        cache.push_front({key, value});
        dict[key] = cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */



int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

