#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) 
{
    vector<int> answer;
    int sum = brown + yellow;
    for (int height = 3; height <= sqrt(sum); height++)
    {
        if ((sum % height) == 0)
        {
            int width = sum / height;
            if (sum - (width - 2) * (height - 2) == brown)
            {
                answer.push_back(width);
                answer.push_back(height);

                break;
            }
        }
    }

    return answer;
}