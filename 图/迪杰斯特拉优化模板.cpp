#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#define Max 0x3f3f3f3f
using namespace std;
typedef struct {
	int point;//能够到达的点
	int value;//第一尺度
	int cost; //第二尺度
}node;
int N;
int num[1001];//第一尺度的最小值储存单位
int cost[1001];//第二尺度的最小值储存单位
int hashtable[2000] = { 0 };//哈希表，判断点是否访问过
vector<node>point[2000];//邻接表
void init(int start) {//初始化
	int i;
	for (i = 0; i < N; i++) {
		num[i] = Max;
		cost[i] = Max;
	}
	num[start] = 0;
	cost[start] = 0;
}
void djistra(int start) {
	init(start);
	int i;
	int min = 0;
	int min_num;
	int check;
	while (1) {
		min_num = Max;
		check = 0;
		for (i = 0; i < N; i++) {//找出当前离起点最近的且未访问过的节点
			if (hashtable[i] == 0 && num[i] != Max) {
				check = 1;
				if (num[i] < min_num) {
					min = i;
					min_num = num[i];
				}
			}
		}
		if (check == 0)//如果没有就说明优化距离结束
			return;
		hashtable[min] = 1;
		for (i = 0; i < point[min].size(); i++) {
			if (hashtable[point[min][i].point] == 0) {
				if (num[point[min][i].point] > point[min][i].value + num[min]) {//以第一尺度为标准，先计算出第一尺度的最小值下的第二尺度的值
					num[point[min][i].point] = point[min][i].value + num[min];
					cost[point[min][i].point] = point[min][i].cost + cost[min];
				}
				else if (num[point[min][i].point] == point[min][i].value + num[min]) {//以计算出的第二尺度值为标准，计算出第二尺度的最小值
					if (cost[point[min][i].point] > point[min][i].cost + cost[min])
						cost[point[min][i].point] = point[min][i].cost + cost[min];
				}
			}
		}

	}
}
int main() {//点标号0开头
	int M, start, end;
	int x, y, value,cost_value;
	while (scanf("%d%d", &N, &M) && (N != 0 || M != 0) ) {
		while (M--) {
			scanf("%d%d%d%d", &x, &y, &value, &cost_value);
			node new_node = { y,value,cost_value };
			point[x].push_back(new_node);//无向边
			new_node.point = x;
			point[y].push_back(new_node);
		}
		scanf("%d%d", &start, &end);
		djistra(start);
		printf("%d %d\n", num[end], cost[end]);
	}
}