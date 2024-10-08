//double with 6 decimal places 

int main() {
	// your code goes here
	double p=0;
	double r = 0;
	double t=0;
	cin>>p;
	cin>>t;
	cin>>r;
	double ans = (p*r*t)/100; 
	printf("%.6f",ans); 
	return 0;
}

Q) find prime
METHOD 1) Normal for loop gives tle... so we iterate till sqrt of N as num above it will not divide that number.

    int isPrime(int N){
        // code here
        if(N==2)return 1;
        if(N==1)return 0;
        for(int i =2; i<=sqrt(N); i++){
            if(N%i == 0)return 0;
        }
        return 1;
        
    }
METHOD 2) //Sieve of Eratosthenes
   	long long int prime_Sum(int n){
   	    
   	    // initialize a vector with n+1 size
   	    vector<int>sieve(n+1,1);
   	    
   	    long long int sum=0;	//sum of all the primes till n
   	    
   	    
   	    for(int i = 2; i<=n; i++){
   	        if(sieve[i]==1)sum = sum+i;   
   	    
   	        // find a prime number and mark its all multiples as 0
   	        
   	        for(int j = i*i; i*j<=n; j++){  //as till i*i everythinf+g will be marked already
   	            sieve[i*j]=0;
   	        }
   	    }
   	    return sum;
   	}




floating point error... caused due to division by zero... refer this chat: https://chatgpt.com/share/9e4f8cf5-4e0e-43a6-8312-efb4c2fda17c
class Solution{
public:
    int evenlyDivides(int N){
        //code here
        int num = N;
        int count=0;
        while(num){
            int check = num%10;
            if(check!=0 && N%check == 0){    //here the error is caused as we divide N by check and check can be zero... so we apply if case that check is not zero. 
                count++;
            }
            num=num/10;
        }
        return count;
    }
};


Q) reversing an equation 50+32-1/21*22
here we push digits in a string and then push that string into stack. 
all the symbols( +-*/) are converted to strings of single digits using "string op(1, s[i]);"

string reverseEqn(string s) {
        string ans = "";
        stack<string> st;
        int n = s.size();

        for (int i = 0; i < n; ) {
            if (isdigit(s[i])) {    // isdigit() function to determine whether the char is digit
                string num = "";  
                while (i < n && isdigit(s[i])) {
                    num.push_back(s[i]);
                    i++;
                }
                st.push(num);
            } else {
                string op(1, s[i]); // Convert char to string
                st.push(op);
                i++;
            }
        }

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }


Q)Given an integer N, print all the divisors of N in the ascending order.

void print_divisors(int n) {
        // Code here.
        vector<int> ans;
        
        //to satisfy corner case of 1.
        if(n==1){
            cout<<1;
            return;
        }
        
        for(int i=1; i<=sqrt(n); i++){
            if(n%i==0){
                ans.push_back(i);
                if(i!=n/i){                 //take case of 4... when i=2.. n/i=2..   
                    ans.push_back(n/i);     //so i will be placed 2 time in vector.. so we put if case
                }
                
            }
        }
        
        sort(ans.begin(),ans.end());
        
        for(int i=0; i<ans.size(); i++){
                cout<<ans[i]<<" ";
        }
    }


Q)Find element in unorderd_map. 
->

if (um.find(sum) == um.end()) 
    um[sum] = i;

/*
um.find(sum):
If the key sum is found, find returns an iterator pointing to the element.
If the key sum is not found, find returns an iterator to the end of the unordered map (um.end()).

um.end():
This is a special iterator that points to the position just past the last element of the unordered map.
It is used to indicate the end of the unordered map and to signify that a searched key was not found.

um.find(sum) == um.end():
This condition checks if the result of um.find(sum) is equal to um.end().
If this condition is true, it means that the key sum is not present in the unordered map.
Then it enters if condtion othervise leaves it.
*/


Q) How to convert string to integer?
-> string str2 = "3.14159";
   int myint2 = stoi(str2);


Q) How to convert integer to String?
-> int i_val = 20;
   string stri = to_string(i_val);

Q) How to initialize 2d vector?
-> vector<vector<int>>newmatrix(n,vector<int>(m,0));






Q) Find LCM and GCD.
class Solution {
  public:
    long long gcd(long long A , long long B){
        if(A ==0){
            return B;
        }
        return gcd(B%A, A);
    }
  
    vector<long long> lcmAndGcd(long long A , long long B) {
        long long  g;
        long long  l;
        g = gcd(A,B);
        l = (A*B)/g;
        return {l,g};
    }
};
