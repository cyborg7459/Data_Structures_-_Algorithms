// Explanation : Usage of optimal merge pattern, we create a merging tree, then in this tree if we move to left child, we add '0' and vice-versa for encoding
// Detailed Explanation here -> https://www.youtube.com/watch?v=co4_ahEDCho

#include <bits/stdc++.h>
using namespace std;

class CharacterGroup {
public:
	int freq;
	vector<char> v;
	bool operator>(CharacterGroup a) {
		return freq > a.freq;
	}
};

struct compare {
	bool operator()(CharacterGroup a, CharacterGroup b) {
		return a.freq > b.freq;
	}
};

int main() {
	priority_queue<CharacterGroup, vector<CharacterGroup>, compare > pq;
	string s = "abcdefghijkl";
	vector<int> frequency = {12, 4, 3, 85, 14, 2, 1, 65, 2, 45, 1, 23};
	map<char, string> mp;
	int n = s.size();
	for(int i=0; i<n; i++) {
		CharacterGroup k;
		k.freq = frequency[i];
		k.v = {s[i]};
		pq.push(k);
		mp.insert({s[i], ""});
	}
	while(pq.size() != 1) {
		CharacterGroup a = pq.top();
		pq.pop();
		CharacterGroup b = pq.top();
		pq.pop();
		vector<char> temp;
		for(char c : a.v) {
			mp[c].push_back('0');
			temp.push_back(c);
		}
		for(char c : b.v) {
			mp[c].push_back('1');
			temp.push_back(c);
		}
		CharacterGroup newGroup;
		newGroup.freq = a.freq + b.freq;
		newGroup.v = temp;
		pq.push(newGroup);
	}

	vector<string> res;

	for(map<char, string>::iterator it = mp.begin(); it != mp.end(); it++) {
		reverse(it->second.begin(), it->second.end());
		res.push_back(it->second);
	}

	sort(res.begin(), res.end());
	for(auto s : res)
		cout << s << " ";
}
