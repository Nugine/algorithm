// https://blog.csdn.net/qq_29169749/article/details/53223002

/*
translation:
	有一堵墙，往上面贴海报，每张海报有各自的范围，可以相互覆盖，求最后还能看见多少张海报？
solution:
	线段树,离散化
	每张海报的粘贴就是一个区间操作，所以可以考虑用线段树来解决。但是题目中所给的墙的长度数据量太大，都存下来
	肯定MLE，所以考虑利用离散化，将每张海报的端点存储下来。然后利用这些端点来建立一颗线段树。然后就是查询操作
	了，为了不让先后顺序相互影响，所以将逆序粘贴海报。这样每个节点中的covered信息就不会收到后来海报的影响。
note:
date:
	2016.11.18
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
 
using namespace std;
const int maxn = 20000 + 5;
 
int pl[maxn], pr[maxn], n;	//海报
 
int s[maxn*4], e[maxn*4];
bool covered[maxn*4];	//线段树节点保存信息
 
int port[maxn], cnt;	//保存离散后的端点
int id[10000000+5];		//保存离散后各个端点所在的位置编号
 
void build_tree(int l, int r, int rt)
{
	s[rt] = l;
	e[rt] = r;
	covered[rt] = false;
 
	if(l != r){
		build_tree(l, (l + r) / 2, rt << 1);
		build_tree((l + r) / 2 + 1, r, rt << 1 | 1);
	}
}
 
bool post(int l, int r, int rt)
{
	if(covered[rt] == true)	return false;
	if(s[rt] == l && e[rt] == r){
		covered[rt] = true;
		return true;
	}
 
	bool res;
	if(r <= (s[rt] + e[rt]) / 2)	res = post(l, r, rt << 1);
	else if(l > (s[rt] + e[rt]) / 2)	res = post(l, r, rt << 1 | 1);
	else {
		bool res1 = post(l, (s[rt] + e[rt]) / 2, rt << 1);
		bool res2 = post((s[rt] + e[rt]) / 2 + 1, r, rt << 1 | 1);
		res = res1 || res2;
	}
 
	if(covered[rt << 1] && covered[rt << 1 | 1])	covered[rt] = true;
 
	return res;
}
 
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out1.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		cnt = 0;
		for(int i = 0; i < n; i++){
			scanf("%d%d", &pl[i], &pr[i]);
			port[cnt++] = pl[i];
			port[cnt++] = pr[i];
		}
 
		sort(port, port + cnt);
		cnt = unique(port, port + cnt) - port;	//离散化
 
		build_tree(1, cnt, 1);	//建立线段树
 
		for(int i = 0; i < cnt; i++)	id[port[i]] = i + 1;
 
		int res = 0;
		for(int i = n-1; i >= 0; i--){
			if(post(id[pl[i]], id[pr[i]], 1)){
				res++;
				//printf("pl:%d pr:%d\n", pl[i], pr[i]);
			}
		}
		printf("%d\n", res);
	}
	return 0;
}