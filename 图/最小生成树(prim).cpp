#include <stdio.h>
#include <vector>
#include <algorithm>
#define inf 0x3f3f3f3f
using namespace std;
typedef struct {
	int point;
	int value;
}node;
int N;
int sum;
vector<node>point[1000];
int hashtable[1000] = {0};
int num[1000];
void init() {
	int i;
	for (i = 0; i < N; i++)
		num[i] = inf;
	num[0] = 0;
	sum = 0;
}
void prim() {
	int n = N;
	int i;
	int k;
	int min;
	int min_num;
	while (n--) {
		min = -1;
		min_num = inf;
		for (i = 0; i < N; i++) {
			if (hashtable[i] == 0 && num[i] != inf) {
				if (num[i] < min_num) {
					min = i;
					min_num = num[i];
				}
			}
		}
		sum += num[min];
		hashtable[min] = 1;
		if (min == -1)
			return;
		for (k = 0; k < point[min].size(); k++) {
			int v = point[min][k].point;
			int value = point[min][k].value;
			if (num[v] > value && hashtable[v] == 0)
				num[v] = value;
		}
	}
	
}
int main() {
	int M;
	scanf("%d", &N);
	scanf("%d", &M);
	int i;
	int x, y, value;
	int check;
	for (i = 0; i < M; i++) {
		scanf("%d%d%d", &x, &y, &value);
		node new_node = { y,value };
		point[x].push_back(new_node);
		new_node.point = x;
		point[y].push_back(new_node);
	}
	init();
	prim();
	printf("%d",sum);
	scanf("%d", &check);
}
