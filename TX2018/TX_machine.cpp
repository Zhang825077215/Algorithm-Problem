 #include<bits/stdc++.h>
using namespace std;
/*
1 2
100 3
100 2
100 1
*/
class task{
public:
	int time;
	int rank;
};

int mycmp(const task &a, const task &b){
	if(a.time == b.time)
		return a.rank > b.rank;
	return a.time > b.time;
}
int main(){
	int n, m;
	cin >> n >> m;
	int cnt[105] ;
	task * machine = new task[n];
	task * project = new task[m];
	for(int i = 0; i < n; ++ i){
		cin >> machine[i].time >>  machine[i].rank;
	}
	for(int i = 0; i < m; ++ i){
		cin >> project[i].time >> project[i].rank;
	}
	sort(machine, machine+n, mycmp);
	sort(project, project+m, mycmp);
	memset(cnt, 0, sizeof(cnt));
	long long profit = 0;
	int count = 0;
	int i, j, k;
	for(i = 0, j = 0; i < m; ++ i){
		while(j < n && machine[j].time >= project[i].time){
			++ cnt[machine[j].rank];
			++ j;
		}
		for(k=project[i].rank; k <= 100; ++ k){
			if(cnt[k]){
				++ count;
				-- cnt[k];
				profit += 200 * project[i].time + 3 * project[i].rank;
				break;
			}
		}
	}
	cout << count << " " << profit << endl;
	delete [] machine;
	delete [] project;
}
