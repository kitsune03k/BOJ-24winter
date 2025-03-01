#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m; // n개의 수에서 m개만큼 출력
vector<int> v;
vector<int> comb;

bool checked[9];

void backtrack(int level, int start){
    // level == m이면, 출력
    if(level == m){
        for(int i=0; i<m; i++){
            cout << v[comb[i]] << ' ';
        }
        cout << '\n';
        return;
    }
    else{
        for(int i=start; i<n; i++){
            // 중복 방지 - 아직 사용하지 않은 경우만 vector에 push
            if(!checked[i]){
                comb.push_back(i);
                checked[i] = true;
                
                backtrack(level+1, 0);
                
                comb.pop_back();
                checked[i] = false;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m;
    
    int tmp;
    
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }
    
    sort(v.begin(), v.end());
    
    backtrack(0,0);
}