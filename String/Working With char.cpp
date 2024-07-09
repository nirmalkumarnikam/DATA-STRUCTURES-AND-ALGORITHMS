//return the address of the string
char* reverse(char *S, int len)
{
    //code here
    stack <char> num;
    
    for(int i =0; i<len;i++)
    {
        char str=S[i];
        num.push(str);
    }
    
    for(int i=0; i<len; i++)
    {
        char push= num.top();
        S[i]=push;
        num.pop();
    }
    return S;
}
