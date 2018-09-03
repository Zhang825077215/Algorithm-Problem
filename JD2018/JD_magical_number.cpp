#include<bits/stdc++.h>
using namespace std;
int judge2(int x){
	int a[10];
	memset(a, 0, sizeof(a));
	int count = 0;
	for(int i = 0; i < 10; ++ i){
		a[i] = x % 10;
		x /= 10;
		count += a[i];
	}
	if(count % 2 == 1)
		return 0;	
	count /= 2;
	int dp[45];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(int i = 0; i < 10; ++ i){
		for(int j = 44; j >= 0; -- j){
			if(dp[j] == 1 && j + a[i] < 45)
				dp[j + a[i]] = 1;
		}
	}
	return dp[count];
}
int judge(int x){
	int a[10];
	memset(a, 0, sizeof(a));
	int count = 0;
	for(int i = 0; i < 10; ++ i){
		a[i] = x % 10;
		x /= 10;
		count += a[i];
		//cout << "a: " << a[i] << endl; 
	}
	//cout <<"count = " << count << endl;
	if(count % 2 == 1)
		return 0;
	int help[10];
	memset(help, 0, sizeof(help));
	int n = 0;
	int temp = 0;
	while(n >= 0){
		while(help[n] < 2){
			++ help[n];
			temp = 0;
			for(int i = 0; i < n; ++ i){
				if(help[i] == 0)
					break;
				else if(help[i] == 2)
					temp += a[i];
			}
			if(temp == count / 2)
				return 1;
			else if(temp > count / 2){
				break;
			} 
			else {
				if(n < 9)
					++ n;
			}
		}
		help[n] = 0;
		-- n;
	}
	return 0;
}
int main(){
	int l, r;
	cin >> l >> r;
	int sum = 0;
	for(int i = l; i <= r; ++ i){
		if(judge2(i))
		{
			//cout << i << endl;
			sum += 1;
		}
			
	}
	//cout << judge(242) << endl;
	cout << sum << endl;
} 
