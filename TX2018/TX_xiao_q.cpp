/*
#include<iostream>
using namespace std;
int mods = 1000000007;
long long c[105][105];

5
2 3 3 3

void init(){
	c[0][0] = 1;
	for(int i = 1; i <= 100; ++ i){
		c[i][0] = 1;
		for(int j = 0; j <= 100; ++ j)
			c[i][j] = (c[i-1][j-1] + c[i-1][j]) % mods;
	}
}
long long  c_m_n(int m, int n){
	long long  count = 1;
	long long  fenmu = 1;
	while(n --){
		count *= m --;
		fenmu *= n + 1;
		if(count % fenmu == 0){
			count /= fenmu;
			fenmu =  1;
		}
	}
	count = count / fenmu % mods;
	return count;
}
int main(){
	int k, x, a, y, b;
	cin >> k >> a >> x >> b >> y;
	init();
	long long output = 0;
	for(int i = 0; i <= k / a && i <= x; ++ i){
		if((k - i * a) % b == 0){
			//cout << " i = " << i <<endl;					
			//
			int temp = (k - i * a) / b;
			if(temp <= y){
			//output += c_m_n(x, i) * c_m_n(y, (k - i * a) / b) % mods;
			output += c[x][i] * c[y][temp] % mods;
			output %= mods;
			}

		}

	}
	cout <<output << endl;
	//cout << c_m_n(92, 55) << endl;
	//cout << c_m_n(92, 55)<< " " << fact(55, 55)<< " "  << fact(92, 55) / fact(55, 55);
	//cout << c[92][55] <<endl;
	
} */
//解法二：动态规划，真是厉害 
#include <iostream>
 
#include <cstring>
 
using namespace std;
 
  
 
int K, A, X, B, Y;
 
int dp[201][1001];
 
int p[201];
 
  
 
int main()
 
{
 
    while(cin >> K)
 
    {
 
        cin >> A >> X >> B >> Y;
 
        memset(dp, 0, sizeof(dp));
 
        dp[0][0] = 1;
 
        for(int i = 1; i <= X; i++)
 
            p[i] = A;
 
        for(int j = X + 1; j <= X + Y; j++)
 
            p[j] = B;
 
        for(int i = 1; i <= X + Y; i++)
 
            for(int j = 0; j <= K; j++)
 
            {
 
                if(j >= p[i])
 
                    dp[i][j] = (dp[i - 1][j] % 1000000007 + dp[i - 1][j - p[i]] % 1000000007) % 1000000007;
 
                else
 
                    dp[i][j] = dp[i - 1][j] % 1000000007;
 
            }
 
        cout << dp[X + Y][K] % 1000000007 << endl;
 
    }
 
}
