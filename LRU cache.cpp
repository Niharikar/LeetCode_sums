

class LRUCache{

deque<int> dq;
unordered_map<int,pair<int,deque<int>::iterator>> cache;
int cap;

LRUCache(int capacity): cap(capacity)
{}

int get(int key)
{
    auto it = cache.find(key);
    if(it!=cache.end())
    {
        dq.erase(it->second.second);
        dq.push_front(key);
        it->second.seond = dq.begin();
        return it->second.first;
    }
    
    else
      return -1;
}

int put(int key,int value)
{
   auto it = cache.find(key);
  if(it!=cache.end())
  {
      dq.erase(it->second.second);
      dq.push_front(key);
      it->second.second = dq.begin();
  }
  
  else
  {
      if(cache.size() == cap)
      {
          cache.erase(dq.back());
          dq.pop_back();
      }
      dq.push_front(key);
      cache[key] = {value,dq.begin()};
  }
}
