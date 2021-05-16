#include <bits/stdc++.h>

// 우큐 문제를 풀때는
// 수많은 학생들이 있고, 입출구가 하나씩 있는 방을 생각해보자.
// 학생들을 어떤 기준으로 정렬(=한 줄로 세우기)시켜서 입구로 통과 시킨 다음에
// 방에서 어떤 작업? 이 이루어지고
// 이 작업을 기준으로 다시 출구로 학생들을 통과시켜야 한다.
// 이를 우선순위 큐에 대입해보면
// 입구가 하나인 방에 아이들을 정렬 시킨 다음에 입구를 통과 시킨다 == 문제에서 주어진 데이터를 어떤 기준으로 정렬 시킨 다음에 우선순위 큐에 담는다.
// 방에서 어떤 작업이 이루어진다 == 우선순위 큐에 담긴 데이터를 하나씩 pop할때 어떻게 빼야하는지 문제에서 요구하는 사항이 있으면 적용시킨다. (없으면 안해도됨)
// 출구로 학생들을 통과시킨다 == 우선순위 큐에서 하나씩 뺀다.

// 우선순위 큐 문제는 대체적으로 주어진 데이터들의 순서가 절대 뒤로 밀리지 않거나, (그러니까 입력으로 들어온 데이터들의 출력 순서가 보장이되고, 데이터의 가중치가
// 같을 경우에만 순서가 변경되는 뜻? 이다.) 
// 무질서한 데이터를 어떤 기준으로 한줄 정렬 시킬 수 있으면 우선순위 큐로 문제를 해결할 수 있는 것 같다.

// 무질서하게 주어지는 인풋값을 머리속에서 한줄로 그려보는 연습을 해보자.

using namespace std;

struct Customer
{
    int id, weight, cacherID;
};

struct compare1
{
    bool operator()(const Customer& a, const Customer& b)
    {
        if (a.weight == b.weight)
            return a.cacherID > b.cacherID;

        return a.weight > b.weight;
    }
};

bool compare2(const Customer& a, const Customer& b)
{
    if (a.weight == b.weight)
        return a.cacherID > b.cacherID;
    
    return a.weight < b.weight;
}

priority_queue<Customer, vector<Customer>, compare1> pq;
int n, k, id, goodsCount;
long long answer;
vector<Customer> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //처음에 이 문제를 풀때 우선순위 큐를 이용하면 될거라 생각했음.
    //근데 우선순위큐를 쓰면 순서보장이 안되서 우선순위큐로 어떻게 해결해야할지 힌트를 못찾음. => 이럴땐 다른 자료형도 섞어서 써볼 생각을 해보자.

    //pq는 캐셔줄을 세우기 위한 용도이고
    //v는 계산 끝나고 나가기전에 다시 정렬시키기위해 대기 시키는 줄 정도로 생각하면 될 것 같다.

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> id >> goodsCount;
        if (i < k)
            pq.push({ id, goodsCount, i + 1 });
        else
        {
            pq.push({ id, goodsCount + pq.top().weight, pq.top().cacherID });
            v.push_back(pq.top());
            pq.pop();
        }
    }

    while (pq.size())
    {
        v.push_back(pq.top());
        pq.pop();
    }

    //마트를 동시에 빠져나가는 인원이 2명이상일 경우에는 cacherID가 큰 순서대로 나가야하므로
    //다시 한번 정렬해준다.
    sort(v.begin(), v.end(), compare2);

    for(int i = 0; i < v.size(); i++)
    {
        answer += 1LL * ((long long)i + 1) * v[i].id;
    }

    cout << answer << '\n';

    return 0;
}