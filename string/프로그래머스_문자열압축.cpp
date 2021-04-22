#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) 
{
    int answer = s.size();
    for (int i = 1; i <= s.size() / 2; i++)
    {
        string str, temp;
        int cnt = 1;
        temp = s.substr(0, i);

        //앞에서 자른 문자열 다음부터 시작하는 문자열을 검사한다.
        for (int j = i; j < s.size(); j += i)
        {
            //자른 문자열이 검사하는 문자열이랑 일치하는 경우
            if (temp == s.substr(j, i))
            {
                cnt++;
            }
            else
            {
                if (cnt > 1)
                {
                    str += to_string(cnt);
                }

                str += temp;
                temp = s.substr(j, i);
                cnt = 1;
            }
        }

        if (cnt > 1)
        {
            str += to_string(cnt);
        }

        str += temp;
        answer = min(answer, (int)str.size());
    }

    return answer;
}