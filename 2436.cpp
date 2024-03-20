#include <iostream>

#define ll long long 

using namespace std;


ll gcd(ll a, ll b){
		if(b ==0)return a;
		else return gcd(b, a%b);
}

int main(){
		cin.tie(0);
		ios_base::sync_with_stdio(0);
		
		ll a, b;
		ll y = -1;
		ll x = -1;

		cin >> a >> b;
				
		ll sum = 1e9;
		

		ll val = a*b;

		for(ll i = a; i <= b; i++){
				if(b%i != 0) continue;

				ll j = val / i;

				if(j%a != 0) continue;
				
				ll gcd_num = gcd(i,j);
				if(gcd_num != a) continue;
				ll lcm = i * (j / gcd_num);

				if(lcm != b) continue;

				if(sum > i + j){
						sum = i+j;		
						x = i;
						y = j;
				}
		}

		/*
		for(ll i = a; i <= b; i++){
				if(b%i != 0) continue;
				
				ll j = b/i;
				//if(j%a != 0) continue;

				ll gcd_num = gcd(i,j);
				if(gcd_num != a) continue;
				
				cout << i << " " << j << "\n";
				cout << "gcd : " << gcd_num << "\n";
				ll lcm = i * (j / gcd_num);
				
				cout << "lcm : " << gcd_num << "\n";
				if(lcm != b) continue;

				if(sum > i + j){
						sum = i+j;		
						x = i;
						y = j;
				}
		}
		*/
		cout << x  << " " << y;

		return 0;
}
