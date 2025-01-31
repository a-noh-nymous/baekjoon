#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    // 연결된 컴퓨터 정보를 저장하는 인접 리스트
    vector<vector<int>> adj(N + 1); // 1번 컴퓨터부터 사용하기 위해 크기 N+1로 설정
    
    // M개의 연결 정보를 입력받아 인접 리스트에 추가
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    // BFS 또는 DFS를 위한 방문 여부 체크 배열
    vector<bool> visited(N + 1, false);
    int infectedCount = 0;
    
    // 1번 컴퓨터에서 시작
    queue<int> q;
    q.push(1);
    visited[1] = true;
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        // 현재 컴퓨터와 연결된 모든 컴퓨터를 확인
        for (int neighbor : adj[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
                infectedCount++;
            }
        }
    }
    
    // 1번 컴퓨터를 제외한 감염된 컴퓨터 수를 출력
    cout << infectedCount << endl;
    
    return 0;
}
