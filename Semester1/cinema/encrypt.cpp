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
			file.close();
		}		
};


