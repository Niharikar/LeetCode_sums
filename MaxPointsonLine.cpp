

struct Point 
{
  int x;
  int y;
  Point() : x(0), y(0) {}
  Point(int a, int b) : x(a), y(b) {}
};
 
 
 int GCD(int a,int b)
 {
    if(b==0)
      return a;
    return GCD(b,a%b);
 }
 
int maxPoints(vector<Point>& points)
{
    if(points.size() <= 2)
      return points.size();
      
      map<int, map<int,int> > m;
      
      for(int i =0 ;i<points.size()-1;i++)
      {
          m.clear();
          int overlap = 0,maxi = 0;
          for(int j = i+1;i<points.size();j++)
          {
              int x = points[j].x - points[i].x;
              int y = points[j].y - points[i].y;
              
              if(x == 0 && y == 0)
              {
                overlap++;
                continue;
              }
              
              int gcd = GCD(x,y);
              if(gcd!=0)
              {
                  x = x/gcd;
                  y = y/gcd;
              }
              
              if(m.find(x)!=m.end())
              {
                  if(m[x].find(y)!=m[x].end())
                    m[x][y]++;
                   else
                   {
                      m[x][y] = 1;
                   }
              }
              
              else
              {
                  map<int,int> mp;
                  mp[y] = 1;
                  m[x] = mp;
              }
              
              maxi = max(maxi,m[x][y]);   
          }
          ans = max(ans,maxi+overlap+1);
      }
      
      return ans;
      
}
