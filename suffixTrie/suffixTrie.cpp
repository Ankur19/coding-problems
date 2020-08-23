#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct Trie{
	char c;
	bool isValid;
	vector<Trie*> next;
	Trie(char val) : c(val), isValid(false), next(vector<Trie*>(26, nullptr)) {}
};

class SuffixTrie{
	public:
		Trie* root;
		SuffixTrie(){
			root = new Trie('*');
		}
		void insert(string s){
			reverse(s.begin(), s.end());
			Trie* current = root;
			for(char c: s){
				current->next[c-'a'] = new Trie(c);
				current = current->next[c-'a'];
			}
			current->isValid = true;
		}
		bool find(string s){
			reverse(s.begin(), s.end());
			Trie* current = root;
			for(char c: s){
				if(!current->next[c-'a'])
					return false;
				current = current->next[c-'a'];
			}
			return current->isValid;
		}
};

int main(){
	SuffixTrie* st = new SuffixTrie();
	
	st->insert("welcome");

	cout << "For welcome, Expected found: true, Actual: " << st->find("welcome") << endl;
	
	cout << "For welcmoe, Expected found: false, Actual: " << st->find("welcmoe") << endl;

	return 0;
}
