#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

typedef pair<int, int> pii;
const int MAXN = 5e4 + 5;
const int INF = 1e9;

vector<pii> adj[MAXN];
vector<pii> haybales;
int dist[MAXN];
int N, M, K;

void dijkstra(int start) {
    fill(dist, dist + N + 1, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int cur_dist = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (cur_dist > dist[cur]) continue;

        for (auto &edge : adj[cur]) {
            int next = edge.first;
            int weight = edge.second;
            if (cur_dist + weight < dist[next]) {
                dist[next] = cur_dist + weight;
                pq.push({dist[next], next});
            }
        }
    }
}

int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < M; ++i) {
        int a, b, t;
        cin >> a >> b >> t;
        adj[a].push_back({b, t});
        adj[b].push_back({a, t});
    }
    for (int i = 0; i < K; ++i) {
        int loc, y;
        cin >> loc >> y;
        haybales.push_back({loc, y});
    }

    dijkstra(N);

    for (int i = 1; i < N; ++i) {
        bool can_eat = false;
        for (auto &hay : haybales) {
            int loc = hay.first;
            int y = hay.second;
            if (dist[loc] + y >= dist[i]) {
                can_eat = true;
                break;
            }
        }
        cout << (can_eat ? 1 : 0) << endl;
    }

    return 0;
}
