#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities)
{
    if (cacheSize == 0)
        return 5 * cities.size();

    vector<string> cache;
    int answer = 0;
    for (int i = 0; i < cities.size(); i++)
    {
        //소문자 변환
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);

        auto iter = find(cache.begin(), cache.end(), cities[i]);

        //cache miss
        if (iter == cache.end())
        {
            if (cache.size() == cacheSize)
                cache.erase(cache.begin());

            answer += 5;
        }
        //cache hit
        else
        {
            cache.erase(iter);
            answer += 1;
        }

        cache.push_back(cities[i]);
    }

    return answer;
}