class client {
	private:
		security sec;
		seats res;
	public:
		/*
		 * Here the encryption and storing for user info should be added
		 */

	int personalInfo() {
		fstream personalInfo;
		sec.encryptDecrypt("pInfo.txt");
		personalInfo.open("pInfo.txt", ios::out | ios::app);
		cout << "Please enter your username: ";
		string name; cin >> name;
		int age, ccv;
		long long cardNumber;
		string expiry;
		personalInfo << name << " ";
		cout << "Please enter your age: ";
		cin >> age;
		personalInfo << age << " ";
		cout << "Enter your credit/ debit card number: "; cin >> cardNumber;
		cout << "Write card's expiration date: "; cin >> expiry;
		cout << "Write the CCV: "; cin >> ccv;
		personalInfo << cardNumber << " " << expiry << " " << ccv << "\n";
		personalInfo.close();
		sec.encryptDecrypt("pInfo.txt");		

		cout << "\nDone!, what do you want now?\n";
		cout << "	1) Reserve a ticket\n	2) Back to the main menu\n\n";
		int newOpChecker; cin >> newOpChecker;
		switch(newOpChecker) {
			case 1:
				/*
				 * Reserve function function
				 */
				res.movieRegistration("Movies.txt");
			case 2:
				return -1;
							
		}	
		return 0;
	}
	

};

class wallet {
	public:
		/*
		 * Here the managing for client's wallet
		 */
};
