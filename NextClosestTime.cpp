

string nextClosestTime(string time)
{
     int given = 60*stoi(time.substr(0,2));
     given = given + stoi(time.substr(3));
     
     int elapsed = 60*24;
     set<int> allowed;
     
     for(char c: time)
     {
        if(c!=':')
            allowed.insert(c-'0');
     }
     int ans;
     for(int h1 : allowed)
     {
        for(int h2 : allowed)
        {
        
            if(h1*10 + h2 < 24)
            {
                for(int m1 : allowed)
                {
                    for(int m2: allowed)
                    {
                          if(m1*10+m2 < 60)
                          {
                              int cur = 60*(h1*10+h2) + m1*10+m2;
                              int cal = cur-given <0 ? cur-given + 24*60 : cur-given;
                              if(cal > 0 && cal < elapsed)
                              {
                                ans = cur;
                                cal = elapsed;
                              }
                          }
                    }
                }
             }
        }
     }
     
     return string foo("02%d:02%d",ans/60,ans%60);
     
}
