#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    queue<int> q;
    int time = 0;
    int tempTotalWeight = 0;
    int truckIndex = 0;

    while (true)
    {
        time++;

        if (q.size() == bridge_length)
        {
            tempTotalWeight -= q.front();
            q.pop();
        }

        if (tempTotalWeight + truck_weights[truckIndex] <= weight)
        {
            if (truckIndex == truck_weights.size() - 1)
            {
                time += bridge_length;
                break;
            }

            q.push(truck_weights[truckIndex]);
            tempTotalWeight += truck_weights[truckIndex];
            truckIndex++;
        }
        else
        {
            q.push(0);
        }
    }

    return time;
}