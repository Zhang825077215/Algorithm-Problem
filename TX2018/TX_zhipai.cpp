#include<bits/stdc++.h>
using namespace std;
int cmp(int a, int b){
	return a > b;
}
int main(){
	int n;
	int sum = 0;
	cin >> n;
	int *puke = new int [n];
	for(int i = 0; i < n; ++ i)
		cin >> puke[i];
	sort(puke, puke+n, cmp);
	for(int i = 0; i < n-1; i += 2){
		sum += puke[i] - puke[i+1];
	}
	if(n % 2 == 1)
		sum += puke[n-1];
	cout << sum << endl;
	delete [] puke;
}
