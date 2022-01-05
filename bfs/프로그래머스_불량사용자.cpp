#include <bits/stdc++.h>

using namespace std;

int check[9];
set<string> id;

void dfs(vector<string> userId, vector<string> bannedId, int index){
    if(index == bannedId.size()){
        string str="";
        for(int i = 0; i < userId.size(); i++){
            if(check[i])
                str += (i+'0');
        }
        id.insert(str);
        return;
    }

    for(int i = 0; i < userId.size(); i++){
        if(check[i] || bannedId[index].size() != userId[i].size())
            continue;

        bool isMatching = true;
        for(int j = 0; j < userId[i].size(); j++){
            if(bannedId[index][j] != '*' && bannedId[index][j] != userId[i][j]){
                isMatching = false;
                break;
            }
        }

        if(isMatching){
            check[i] = 1;
            dfs(userId, bannedId, index+1);
            check[i] = 0;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    dfs(user_id, banned_id, 0);

    return id.size();
}
