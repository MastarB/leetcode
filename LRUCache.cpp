#include<list>
#include<map>
using namespace std;
class LRUCache{
public:
	int cap;
	int num;
	map<int,int>cathe;
	map<int,list<int>::iterator>f;
	list<int>prio;
    LRUCache(int capacity) 
	{
        cap = capacity;
		num = 0; 
    }
    
    int get(int key) 
	{
        if(cathe.find(key) == cathe.end())return -1;
        prio.erase(f[key]);
        prio.push_back(key);
        f[key] = --prio.end();
        return cathe[key];
    }
    
    void set(int key, int value) 
	{
        int a = get(key);
        if(a != -1)cathe[key] = value;
        else
        {
        	cathe[key] = value;
        	prio.push_back(key);
        	f[key] = --prio.end();
        	if(num == cap)
        	{
        		int k = prio.front();
        		f.erase(k);
        		cathe.erase(k);
        		prio.pop_front();
			}
			else num++;
		}
    }
};
