/*

KTH NUMBER  BINARY REPRESENTAION    AMUSING NUMBER                      value of i (1<<i)
1                0                         5					1
2                1                         6					"
3               00                        55					2
4               01                        56
5               10                        65
6               11                        66					"
7              000                       555					3
8              001                       556
9              010                       565
10             011                       566
11             100                       655					"
12             101                       656
13             110                       665
14             111                       666					"
15            0000                      5555					4
16            0001                      5556
17            0010                      5565
18            0011                      5566					"
19            0100                      5655
20            0101                      5656
21            0110                      5665
22            0111                      5666					"
23            1000                      6555
24            1001                      6556
25            1010                      6565					"
26            1011                      6566
27            1100                      6655
28            1101                      6656					"
29            1110                      6665
30            1111                      6666					"
31	     00000		       55555					5



0 <=> 5
1 <=> 6

we can spot a G.P (each term represents the number of Amusing numbers formed for each value of 'i') here  :
  2 + 2^2 + 2^3 +2^4 + 2^5 + .....

*/



#include<iostream>
#include<bitset>
using namespace std;
#define ll long long
const int N = 10000;

//used binary search here
ll search(ll n , ll count, ll k) {
	ll s = 0;
	ll e = n;
	while (s <= e) {
		ll mid = (s + e) / 2;
		if (((mid) + count) == k) {
			return mid;
		}
		else if ((mid + count) < k) {
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}

}
int main() {


	int t; cin >> t;
	bitset<N>b;
	b.reset(); 		// setting the initial vaue of bitset to 0


	while (t--) {
		ll k;
		cin >> k;
		ll count = 0;
		for (int i = 1; i < 64; i++) {
			ll p = (1ll << i);
			if (count < k && (count + p) >= k) {
				b.reset();
				b = search((count + (1ll << i)) , count , k) - 1;
				int cnt = i;
				while (cnt--) {
					if (b[cnt] != 0) {
						cout << 6;
					}
					else {
						cout << 5;
					}
				}
				break;
			}
			else {
				count += p;
			}
		}
		cout << endl ;
	}
}
