typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

class Solution {
    
 int find(vector<int> & hist){
     int n = hist.size();
    // Create an empty stack. The stack holds indexes of hist[] array
    // The bars stored in stack are always in increasing order of their
    // heights.
    stack<int> s;
 
    int max_area = 0; // Initalize max area
    int tp;  // To store top of stack
    int area_with_top; // To store area with top bar as the smallest bar
 
    // Run through all bars of given histogram
    int i = 0;
    while (i < n)
    {
        // If this bar is higher than the bar on top stack, push it to stack
        if (s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);
 
        // If this bar is lower than top of stack, then calculate area of rectangle 
        // with stack top as the smallest (or minimum height) bar. 'i' is 
        // 'right index' for the top and element before top in stack is 'left index'
        else
        {
            tp = s.top();  // store the top index
            s.pop();  // pop the top
 
            // Calculate the area with hist[tp] stack as smallest bar
            area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
 
            // update max area, if needed
            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }
 
    // Now pop the remaining bars from stack and calculate area with every
    // popped bar as the smallest bar
    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
 
        if (max_area < area_with_top)
            max_area = area_with_top;
    }
 
    return max_area;
}

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0)return 0;

        vector<int> hist(matrix[0].size());
    int ans =0;
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[0].size(); j++){
            if(i==0)hist[j] = matrix[i][j] == '1' ? 1:0;
            else{
                hist[j] = matrix[i][j] == '1'? hist[j]+1:0;
            }
        }
        ans = max(ans,find(hist));
    }
        return ans;
    }
};