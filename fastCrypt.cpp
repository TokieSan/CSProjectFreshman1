#include <bits/stdc++.h>

using namespace std;

#define tt(n) for (int i=0; i<n; i++)
#define FOR(i,a,n) for (auto i=a; i!=n; i++)
class security{
	private:
		char xorKey = '~';

	public:
		void encryptDecrypt(string fileName) {
			fstream file;
			file.open(fileName, ios::in);
			if(!file.is_open()) {
				cout << "Error encrypting the file!\n";
				return;
			}
			vector<char> inputChars;
			while(!file.eof()) {
				char ch;
				file.get(ch);
				ch=ch^xorKey;
				inputChars.push_back(ch);
			}
			file.close();
			
			inputChars.pop_back();
			file.open(fileName, ios::out);
			
			for(auto i=inputChars.begin(); i!=inputChars.end(); ++i) {
				file << *i;
			}
		}		
};


int main(int argc, char *argv[]) {
	ios::sync_with_stdio(0);
	security sec;
	sec.encryptDecrypt(argv[1]);
	/* freopen("in", "r", stdin);
	 * freopen("out", "w", stdout);
	 */
	
	return 0;
}


