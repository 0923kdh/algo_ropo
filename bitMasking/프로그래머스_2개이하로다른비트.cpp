#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) 
{
    vector<long long> answer;
    for(int i = 0; i < numbers.size(); i++)
    {
        bitset s = bitset<52>(numbers[i]);
        for(int j = 0; j < s.size(); j++)
        {
            if(s[j] == 0)
            {
                s[j] = 1;
                if(j != 0)
                {
                    s[j-1] = 0;
                }
                break;
            }   
        }
        answer.push_back(s.to_ulong());
    }
    
    return answer;
}