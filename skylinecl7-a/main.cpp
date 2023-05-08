#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct block{
    ll h , w;
    ll index;
    block(ll ha , ll wa , ll i){
        h = ha;
        w = wa;
        index = i;
    }
    bool operator<(block v2){
        return (h < v2.h);
    }
};

bool are_nearby(block v1 , block v2){
    if(v1.index == v2.index -1 || v1.index == v2.index+1){
        return true;
    }
    return false;
}
int main() {
	std::freopen("skyline.in" , "r", stdin);
	std::freopen("skyline.out" , "w", stdout);
	ll n; cin >> n;
	std::vector<block> skylines;
	for(ll i = 0 ; i < n ; ++i){
		ll h, l; cin >> h >> l;
		skylines.push_back(block(h , l , i));
	}
	std::vector<block> ordered_skylines = skylines;
	sort(skylines.begin(), skylines.end()); // skylines ordered by height
	std::vector<block> common;
	ll ans_w = 0;
	ll c = 0;
	for(int i = 0; i < skylines.size(); i++){
        if(skylines[i].h == ordered_skylines[i].h || skylines[i].h == ordered_skylines[i + 1].h || skylines[i].h == ordered_skylines[i + 2].h){
            c += skylines[i].w;
            if(c > ans_w){
                common.push_back(skylines[i]);
            }
            ans_w = max(c , ans_w);
        }
        else{
            c = skylines[i].w;
        }
	}
	ll min_h = LONG_MAX + LONG_MAX;
	for(auto c : common){
        min_h = min(c.h , min_h);
	}
	std::cout << (ans_w + 1) * min_h;


}
