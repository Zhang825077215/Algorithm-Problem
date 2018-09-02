#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<char> > block;
	for(int i = 0; i < n; ++ i){
		vector<char> temp(m);
		for(int j=0; j < m; ++ j)
			cin >> temp[j];
		block.push_back(temp);
	}
	vector<int> dp(n+1, 0);
	for(int i = 0; i < n; ++ i){
		dp[i+1] = dp[i];
		for(int j = 0; j < m; ++ j){			
			switch(block[i][j]){
				case 'B':{
					if(! (i-1 >= 0 && j + 1 <m && (block[i-1][j+1] == 'B' || block[i-1][j+1] == 'G')))
						dp[i+1] ++;
					break;
				}
				case 'Y':{
					if(! (i-1 >= 0 && j - 1 >= 0 && (block[i-1][j-1] == 'Y' || block[i-1][j-1] == 'G')))
						dp[i+1] ++;
					break;
				}
				case 'G':{
					dp[i+1] +=  2;
					if(i-1 >= 0&& j + 1 < m && (block[i-1][j+1] == 'B' || block[i-1][j+1] == 'G'))
						-- dp[i+1];
					if(i-1 >= 0 && j - 1 >= 0 && (block[i-1][j-1] == 'Y' || block[i-1][j-1] == 'G'))
						-- dp[i+1];
					break;
				}
				default:break;				
			}
		}
	}
	cout << dp[n] << endl;
}
