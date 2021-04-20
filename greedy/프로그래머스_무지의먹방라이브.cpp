#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int solution(vector<int> food_times, long long k)
{
    long long totalTime = 0;
    int foodCount = food_times.size();
    priority_queue <pair<int, int>> pq;
    for (int i = 0; i < foodCount; i++)
    {
        pq.push({ -food_times[i], i + 1 });
        totalTime += food_times[i];
    }

    if (totalTime <= k)
        return -1;

    long long previous = 0;
    totalTime = 0;
    while (totalTime + (-pq.top().first - previous) * foodCount <= k)
    {
        long long now = -pq.top().first;
        pq.pop();
        totalTime += (now - previous) * foodCount;
        foodCount--;
        previous = now;
    }

    vector<pair<int, int>> result;
    while (!pq.empty())
    {
        int foodTime = -pq.top().first;
        int index = pq.top().second;
        result.push_back({ foodTime, index });
        pq.pop();
    }

    sort(result.begin(), result.end(), compare);
    return result[(k - totalTime) % foodCount].second;
}