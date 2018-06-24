
// Optimal solution, O(n) time complexity, O(1) space complexity
int trap(vector<int>& height)
{
    int left = 0,right = height.size()-1,leftmax = 0,rightmax = 0;
    int ans = 0;
    
    while(left<right)
    {
        if(height[left] < height[right])
        {
            if(height[left] > leftmax)
              leftmax = height[left];
            else
              ans += leftmax - height[left];
            left++;
        }
        
        else
        {
            if(height[right] > rightmax)
                rightmax = height[right];
            else
                ans += rightmax - height[right];
                
            right--;
        }
    }
    
    return ans;
}

// other method with O(n) time and space complexity

int trap(vector<int>& height)
{
    int n = height.size();
    vector<int> leftmax(n,0),rightmax(n,0);
    
    leftmax[0] =height[0];rightmax[0] = height[n-1];
    
    for(int i = 1;i<n;i++)
      leftmax[i] = max(height[i],leftmax[i-1]);
    
    for(int j = n-2;j>=0;j--)
       rightmax[i] = max(height[i],rightmax[i+1]);
       
    int ans = 0;
    for(int i = 1;i<n-1;i++)
        ans += min(leftmax[i],rightmax[i]) - height[i];
    
    
    return ans;
    
    
}


//  another method with O(n) time ans space complexity

in trap(vector<int>& height)
{
    stack<int> st;
    int c = 0,n = height.size(), ans = 0;
    st.push(c++);
    
    while(c<n)
    {
        while(!st.empty() && height[c] > st.top())
        {
            int t = st.top();
            st.pop();
            
            if(st.empty())
              break;
              
            int dis =  c - st.top() - 1;
            ans += (min(height[c],height[st.top()]) - height[t])*dis;
        }
        st.push(height[c++]);
    }
    
    return ans;
    
}
