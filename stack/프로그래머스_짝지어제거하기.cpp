#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    stack<char> stk;
    for(int i = 0; i < s.size(); i++)
    {
        if(stk.size() && (stk.top() == s[i]))
            stk.pop();            
        else if((i < s.size() - 1) && s[i] == s[i+1])
            i += 1;
        else
            stk.push(s[i]);        
    }
    
    return !stk.size();
}