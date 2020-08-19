#include <iostream>
#include <string>

using namespace std;

class Solution{
	public:
		Solution(int nonce){
			this->nonce = nonce;
		}
		string encrypt(string s){
			string ret = "";
			for(char c: s){
				if(isalpha(c)){
					ret+= c+nonce <= 'z' ? c+nonce : 'a' + c+nonce - 'z';
				}
				else
					ret+=c;
			}
			return ret;
		}

		string decrypt(string s){
			string ret = "";
			for(char c: s){
				if(isalpha(c)){
					ret+= c-nonce >= 'a' ? c - nonce : 'z' - 'a' - c - nonce;
				}
				else
					ret+=c;
			}
			return ret;
		}
	private:
		int nonce;
};

int main(){
	Solution* s = new Solution(4);

	string test = "this is a test";

	cout << s->encrypt(test) << endl;

	cout << s->decrypt(s->encrypt(test)) << endl;

	delete s;

	return 0;
}
