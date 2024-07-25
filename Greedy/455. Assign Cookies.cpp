// Function to find the maximum number of content children
// g: vector containing the greed factor of each child
// s: vector containing the size of each cookie

// Sort the greed factor of children in ascending order
// Sort the size of cookies in ascending order
// Initialize pointers for children (l) and cookies (r)
// Loop until we have either no more children or no more cookies left
    // If the current cookie can satisfy the current child
        // Move to the next child
    // Move to the next cookie
// The number of content children is the value of l

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int l =0,r=0;

        while(l<g.size() && r<s.size()){
            if(g[l]<=s[r]){
                l++;
            }
            r++;
        }
        return l;
    }
};