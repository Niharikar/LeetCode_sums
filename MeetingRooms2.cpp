
struct Interval
{
  int start;
  int end;
  Interval(): start(0),end(0) {}
  Interval(int s, int e): start(s), end(e) {}
};

struct compare
{
    bool operator<>(const Interval& l,const Interval& r)
    {
      return l.start > r.start;
    }
};

bool fun(Interval& l, Interval& r)
{
    return l.start < r.start;
} 

int minMeetingRooms(vector<int> Intervals)
{
    sort(Intervals.begin(),Intervals.end(),fun);
    
    priority_queue<int,vector<int>,compare> pq;
    pq.push(Intervals[0].end());
    
    for(int i = 1;i<Intervals.size();i++)
    {
        if(Intervals[i].start >= pq.top())
          pq.pop();
         
        pq.push(intervals[i].end()); 
    }
    
    return pq.size();
    
}
