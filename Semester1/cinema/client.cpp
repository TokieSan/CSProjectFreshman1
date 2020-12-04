//client class, w/ func personalInfo to store user's details in a file
class client {
	private:
		security sec;
		seats res;
	public:
		/*
		 * Here the encryption and storing for user info should be added
		 */

	//func personalInfo registers user's name, age, and credit card details 
	int personalInfo() {
		fstream personalInfo;
		sec.encryptDecrypt("pInfo.txt");
		personalInfo.open("pInfo.txt", ios::out | ios::app);
		cout << "Please enter your username: ";
		string name; cin >> name;
		int age, ccv;
		//long long used because card numbers are typically ~16
		long long cardNumber;
		string expiry;
		personalInfo << "\n" << name << " ";
		cout << "Please enter your age: ";
		cin >> age;
		personalInfo << age << " ";
		cout << "Enter your credit/ debit card number: "; cin >> cardNumber;
		cout << "Write card's expiration date: "; cin >> expiry;
		cout << "Write the CCV: "; cin >> ccv;
		srand(time(0));
		//fill wallet with random amount
		double walletMoney = (rand()%1000000)/10;
		personalInfo << cardNumber << " " << expiry << " " << ccv << " " << walletMoney << "\n";
		personalInfo.close();
		sec.encryptDecrypt("pInfo.txt");		

		//ask user to either reserve ticket or utilize other main menu options
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

