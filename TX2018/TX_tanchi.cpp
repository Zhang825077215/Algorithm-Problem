#include<bits/stdc++.h>
using namespace std;
int pow(float a, int n){
	float sum = 1;
	while(n --)
		sum *= a;
	return sum;
}

int if_satisfy(int a, int m, int n){
	int temp = a, sum = a;
	for(int i = 1; i < n; ++ i){
		temp = temp / 2 + temp % 2;
		sum += temp;
	}
	//cout << "test :" << sum << endl; 
	if (sum == m)
		return 0;
	else if(sum < m)
		return 1;
	return -1;
}
int main(){
	int n, m;
	cin >> n >> m;
	int mid;
	int left = 1;
	int right = m;
	//cout << "test :" << if_satisfy(40, m, n) << endl; 
	while(left <= right){
		mid = (left + right)/ 2;
		int flag = if_satisfy(mid, m, n);
		if(flag == 0){
			cout << mid << endl;
			return 0;
		}
		else if(flag == 1)
			left = mid + 1;
		else
			right = mid - 1;		
	}
	cout << left - 1 << endl;
	return 0;
} 
