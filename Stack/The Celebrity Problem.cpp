
/*
Brute Force:
Algo:
iterate over each row and check if that whole row is zero
    if whole row is zero its potential candidate for celebrity, mark it one in check row
iterate over each col and check if whole col is one exccept i=j element
    if whole col is 1 then it is potential cnadidate for celebrity, mark it one in check col

now find ele where check row and check col is 1, thats our ans 
TC: O(N^2)
SC: O(N)
*/
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        vector<int>checkRow(n,0);
        vector<int>checkCol(n,0);
        for(int i = 0; i<n; i++){
            
            bool rowZero= true;
            for(int j= 0; j<n; j++){
                if(M[i][j]==1)rowZero = false;
            }
            if(rowZero == true)
            {
                checkRow[i] = 1;
            }
            
            bool colOne = true;
            for(int j= 0; j<n; j++){
                
                if(i!=j && M[j][i]==0)colOne = false;
                
            }
            if(colOne == true){
                checkCol[i]=1;
            }
        }
        for(int j= 0; j<n; j++){
            if(checkRow[j]==1 && checkCol[j]==1)
            {
                return j;
            }
        }
        
        return -1;
    }
};

/*
Better:
Algo:
Find potential candidate for celebrity:
    While the size of the stack is at least 2:
        Pop the top two elements from the stack, p1 and p2.
        If p1 knows p2 (M[p1][p2] == 1), then p2 is a potential candidate for celebrity. Push p2 back to the stack.
        Else, p2 knows p1, so p1 is a potential candidate for celebrity. Push p1 back to the stack.
    
    Pop the last remaining element from the stack, which is the potential celebrity.
    Verify that element and return ans.
    
TC: O(n)
SC: O(n)
*/
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>>& M, int n) 
    {
        stack<int> st;
        
        // Step 1: Push all elements in stack
        for (int i = 0; i < n; i++) {
            st.push(i);
        }
        
        // Step 2: Find potential candidate for celebrity
        while (st.size() >= 2) {
            int p1 = st.top(); st.pop();
            int p2 = st.top(); st.pop();
            
            if (M[p1][p2] == 1) { // p1 knows p2
                st.push(p2);    // p2 is potential candidate for celebrity        
            } else {            // p2 knows p1
                st.push(p1);    // p1 is potential candidate for celebrity
            }
        }
        
        // Step 3: Verify potential candidate
        int potentialCelebrity = st.top(); st.pop();
        
        // Check row
        for (int i = 0; i < n; i++) {
            if (M[potentialCelebrity][i] == 1) {
                return -1;
            }
        }
        
        // Check column
        for (int i = 0; i < n; i++) {
            if (i != potentialCelebrity && M[i][potentialCelebrity] == 0) {
                return -1;
            }
        }
        
        return potentialCelebrity;
    }
};

