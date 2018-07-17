

class ZigzagIterator {
public:
    queue<pair<vector<int>::iterator,vector<int>::iterator>> q;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if(v1.size()!=0)
          q.push(make_pair(v1.begin(),v1.end()));
          
         if(v2.size()!=0)
          q.push(make_pair(v2.begin(),v2.end()));
    }

    int next() {
        vector<int>::iterator it = q.front().first;
        vector<int>::iterator endit = q.front().second;
        q.pop();
        if(it+1 != endit)
            q.push(it+1,endit);
            
         return *it;
    }

    bool hasNext() {
        return !q.empty();
    }
};
