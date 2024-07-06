// refer the picture
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>final;
        stack<int>temp;

        for(int  i = asteroids.size()-1; i>=0; i--){
            temp.push(asteroids[i]);
        }

        while(!temp.empty()){
            if(final.empty()){
                final.push(temp.top());
                temp.pop();
            }
            else if(final.top()<0 && temp.top()>0){
                final.push(temp.top());
                temp.pop();
            }
            else if(final.top()>0 && temp.top()>0){
                final.push(temp.top());
                temp.pop();
            }
            else if(final.top()<0 && temp.top()<0){
                final.push(temp.top());
                temp.pop();
            }
            else if(final.top()>0 && temp.top()<0){
                if(final.top()> abs( temp.top() ) ) {
                    temp.pop();
                }
                else if(final.top()<abs(temp.top()))
                {   
                    final.pop();
                }
                else if(final.top()==abs(temp.top())){
                    final.pop();
                    temp.pop();
                }
            }
        }

        vector<int>ans;
        while(!final.empty()){
            ans.push_back(final.top());
            final.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};