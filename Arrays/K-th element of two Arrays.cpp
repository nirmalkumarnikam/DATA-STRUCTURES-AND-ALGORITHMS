//TC : O(n)
//TC : O(1)
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        // code here
        int i=0,j=0;
        int cnt =1;
        while(i<arr1.size()&&j<arr2.size() && cnt<k){
            if(arr1[i]<=arr2[j]){
                i++;
            }else{
                j++;
            }
            cnt++;
        }
        
        if(cnt == k){
            if(i<arr1.size()&&arr1[i]<=arr2[j]){
                return arr1[i];
            }else{
               return arr2[j];
            }
        }else{
            if(i<arr1.size()){
                while(cnt<k){
                    i++,cnt++;
                }
                return arr1[i];
            }else{
                while(cnt<k){
                    j++,cnt++;
                }
                return arr1[j];
            }
        }
        return -1;
        
    }
};





//mergeSort
class Solution{
    public:    
    void mergesorted( vector<int>& ans, int arr1[], int arr2[], int n, int m )
    {
        int i = 0, j=0; 
        while(i < n && j < m)
        {
            if(arr1[i] < arr2[j])
            {
                ans.push_back(arr1[i]);
                i++;
            }
            else
            {
                ans.push_back(arr2[j]);
                j++;
            }
        }
        
        while(i < n)
        {
             ans.push_back(arr1[i]);
             i++;
        }
        
        while(j < m)
        {
             ans.push_back(arr2[j]);
             j++;
        }
    }
    
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        vector<int> ans;
        mergesorted(ans,arr1, arr2, n, m);
        
        return ans[k-1];
    }
};





//sorting
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        vector<int> answer;
        for(int i = 0 ; i<n; i++)
        {
            answer.push_back(arr1[i]);
        }
        for(int i = 0 ; i<m; i++)
        {
            answer.push_back(arr2[i]);
        }
        
        sort(answer.begin(),answer.end());
        return answer[k-1];
    }
};
