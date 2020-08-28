#include <iostream>
#include <vector>

using namespace std;

struct Trie{
	bool isWord;
	string word;
	vector<Trie*> small;
	vector<Trie*> capital;
	Trie() : isWord(false), word(""), small(vector<Trie*>(26, nullptr)), capital(vector<Trie*>(26, nullptr)) {}
};


void constructTrie(string& s, Trie* root){
	Trie* cur = root;
	for(char c: s){
		if(c==tolower(c)){
			if(cur->small[c-'a']==nullptr)
				cur->small[c-'a'] = new Trie();
			cur = cur->small[c-'a'];
		}
		else{
			if(cur->capital[c='A']==nullptr)
				cur->capital[c-'A'] = new Trie();
			cur = cur->capital[c-'A'];
		}
	}
	cur->word = string(s.begin(), s.end());
	cur->isWord = true;
	return;
}

void boggleRec(vector<vector<char>>& board, int i, int j, Trie* root, vector<string>& data){	
	if(root==nullptr || i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
		return;
	bool isSmall = false;
	if(board[i][j]== tolower(board[i][j]))
		isSmall = true;
	Trie* cur = root;
	if(cur->isWord){
		data.push_back(cur->word);
		cur->isWord = false;
	}
	if(isSmall)
		cur = cur->small[board[i][j]-'a'];
	else
		cur = cur->capital[board[i][j]-'A'];
	if(cur==nullptr)
		return;
	boggleRec(board, i+1, j, cur, data);
	boggleRec(board, i-1, j, cur, data);
	boggleRec(board, i, j+1, cur, data);
	boggleRec(board, i, j-1, cur, data);
	boggleRec(board, i-1, j-1, cur, data);
	boggleRec(board, i-1, j+1, cur, data);
	boggleRec(board, i+1, j-1, cur, data);
	boggleRec(board, i+1, j+1, cur, data);
	return;
}


vector<string> boggleBoard(vector<vector<char>>& board, vector<string>& words){
	vector<string> data;
	Trie* root = new Trie();
	for(string s: words){
		constructTrie(s, root);
	}

	Trie* cur = root;
	for(char c: words[0]){
		cur = cur->small[c-'a'];
	}
	cout << "Validate trie: " <<words[0] << ", Actual: " << cur->word << endl;
	for(int i=0;i<board.size();i++){
		for(int j = 0;j<board[0].size();j++){
			boggleRec(board, i, j, root, data);
		}
	}
	return data;
}

int main(){
	vector<string> words{
		    "frozen",
			        "rotten",
				    "teleport",
				        "city",
					    "zutgatz",
					        "kappa",
						    "before",
						        "rope",
							    "obligate",
							        "annoying",
	};

	vector<vector<char>> board{
		    {'f', 't', 'r', 'o', 'p', 'i', 'k', 'b', 'o'},
			        {'r', 'w', 'l', 'p', 'e', 'u', 'e', 'a', 'b'},
				    {'j', 'o', 't', 's', 'e', 'l', 'f', 'l', 'p'},
				        {'s', 'z', 'u', 't', 'h', 'u', 'o', 'p', 'i'},
					    {'k', 'a', 'e', 'g', 'n', 'd', 'r', 'g', 'a'},
					        {'h', 'n', 'l', 's', 'a', 't', 'e', 't', 'x'},
	};

	vector<string> res = boggleBoard(board, words);

	for(string s: res)
		cout << s << "," << endl;
	return 0;
}
