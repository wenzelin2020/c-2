#include <bits/stdc++.h>//��ѧ��״̬ѹ����!!!
using namespace std;
int n, m, x[101], p, g[21][21], a, b, c, dp[2000001][21];
long long ans;
bitset<100> bit;

int dfs(bitset<100> bit, int u) {
	if (dp[bit.to_ulong()][u] != -1)//������
		return dp[bit.to_ulong()][u];
	if (bit.count() == m) //����
		return dp[bit.to_ulong()][u] = 0;
	int maxx;//���˼max
	for (int i = 1; i <= n; i++) {
		if (bit[i - 1] == 0) { //ûȡ��
			bit.flip(i - 1); //ȥ����������������
			maxx = max(maxx, dfs(bit, i) + x[i] + g[u][i]);
			bit.flip(i - 1);
		}
	}
	dp[bit.to_ulong()][u] = maxx;
	return maxx;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++)
		cin >> x[i];
	cin >> p;
	for (int i = 1; i <= p; i++) {
		cin >> a >> b >> c;
		g[a][b] = c;
	}
	bitset<100> t;
	for (int i = 1; i <= n; i++) {
		bit.set(i - 1);
		ans = max(int(ans), int(dfs(bit, i) + x[i])); //dfs(bit,i)��˼��ǰ״̬Ϊbit,ǰi�����
		bit.reset(i - 1); //����
	}
	cout << ans << endl;
	return 0;
}
