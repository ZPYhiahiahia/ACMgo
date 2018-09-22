#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#define Max 0x3f3f3f3f
using namespace std;
typedef struct {
	int point;//�ܹ�����ĵ�
	int value;//��һ�߶�
	int cost; //�ڶ��߶�
}node;
int N;
int num[1001];//��һ�߶ȵ���Сֵ���浥λ
int cost[1001];//�ڶ��߶ȵ���Сֵ���浥λ
int hashtable[2000] = { 0 };//��ϣ���жϵ��Ƿ���ʹ�
vector<node>point[2000];//�ڽӱ�
void init(int start) {//��ʼ��
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
		for (i = 0; i < N; i++) {//�ҳ���ǰ������������δ���ʹ��Ľڵ�
			if (hashtable[i] == 0 && num[i] != Max) {
				check = 1;
				if (num[i] < min_num) {
					min = i;
					min_num = num[i];
				}
			}
		}
		if (check == 0)//���û�о�˵���Ż��������
			return;
		hashtable[min] = 1;
		for (i = 0; i < point[min].size(); i++) {
			if (hashtable[point[min][i].point] == 0) {
				if (num[point[min][i].point] > point[min][i].value + num[min]) {//�Ե�һ�߶�Ϊ��׼���ȼ������һ�߶ȵ���Сֵ�µĵڶ��߶ȵ�ֵ
					num[point[min][i].point] = point[min][i].value + num[min];
					cost[point[min][i].point] = point[min][i].cost + cost[min];
				}
				else if (num[point[min][i].point] == point[min][i].value + num[min]) {//�Լ�����ĵڶ��߶�ֵΪ��׼��������ڶ��߶ȵ���Сֵ
					if (cost[point[min][i].point] > point[min][i].cost + cost[min])
						cost[point[min][i].point] = point[min][i].cost + cost[min];
				}
			}
		}

	}
}
int main() {//����0��ͷ
	int M, start, end;
	int x, y, value,cost_value;
	while (scanf("%d%d", &N, &M) && (N != 0 || M != 0) ) {
		while (M--) {
			scanf("%d%d%d%d", &x, &y, &value, &cost_value);
			node new_node = { y,value,cost_value };
			point[x].push_back(new_node);//�����
			new_node.point = x;
			point[y].push_back(new_node);
		}
		scanf("%d%d", &start, &end);
		djistra(start);
		printf("%d %d\n", num[end], cost[end]);
	}
}