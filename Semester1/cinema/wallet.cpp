
class walletBig {
	public:
		//compare username and ticket ID to see if username is subset of ID
		bool fastCheckSub(string sub, string dom) {
			for(int i=0; i<(int)sub.length(); i++) {
				if(sub[i]!=dom[i]) return false;
			}
			return true;
		}
		
		int viewReservation()
		{
			string userNameSub;
			cout << "\nCan you enter your username? "; cin >> userNameSub;
			specialOrNot(userNameSub) ? cout << "\nYou are a special customer! you have 20% discout on tickets\n\n" : cout << "\nAccount type: Normal\n";
			fstream all_IDS;
			all_IDS.open("Receipts.txt", ios::in | ios::app);
			string id;
			cout << "\nYour tickets:\n";
			while(!all_IDS.eof()) {
				getline(all_IDS, id);
				if(fastCheckSub(userNameSub, id))
					cout << "	- " << id << "\n";
				sleep(1);
			}
			sleep(1);
			cout << "\nWhat do you want right now?\n	1) Reserve a ticket\n	2) Back to the main menu\n";
			int tmpNew;
			all_IDS.close();
			cin >> tmpNew;
			return tmpNew;

		}
		//check if user qualifies for 20% discount acc. to no. of tickets purchased
		bool specialOrNot(string userName)
		{
			fstream all_IDS;
			all_IDS.open("Receipts.txt", ios::in | ios::app);
			string tmpStr;
			int countCustomer = 0;
			while (!all_IDS.eof())
			{
				all_IDS >> tmpStr;
				if (tmpStr == userName)
					countCustomer++;
			}
			all_IDS.close();
			if (countCustomer > 10)
				return true;
			else
				return false;

		}
		//check if seat is a normal one or VIP acc. to seat
		bool isTicketVip(string id) {
			int ch =0;
			for(int i=0; i<(int)id.length(); i++) {
				if(id[i]=='_'){ ch++; continue;}
				if(ch==1 && id[i]=='_') {
					if(id[i+1]=='I'||id[i+1]=='J') return true;
					else return false;
				}
			}
			return false;
		}
		//refunds user's money into file "wallet", money to be deducted in next purchase
		void returnTicket()
		{
			cout << "\nYou've chosen to return and refund your ticket!\n\nPlease enter '1' to confirm, or '2' to cancel: ";
			int yesOrNo;
			cin >> yesOrNo;
			fstream all_IDS;
			all_IDS.open("Receipts.txt", ios::in | ios::app);

			fstream refundReceipts;
			refundReceipts.open("Refunds.txt", ios::in | ios::app);

			string fileID, searchID;
			double refunded = 15;
			
			time_t ticketDate = time(NULL);

			if (yesOrNo == 1)
			{
				cout << "\nNext step! Please enter your username: ";
				string newUserName; cin >> newUserName;
				cout << "\nWrite your ticket ID: ";
				cin >> searchID;
				if(isTicketVip(searchID)) refunded = 25;
				if(specialOrNot(newUserName)) refunded-=(0.2*refunded);
				bool x = true;
				while (!all_IDS.eof())
				{
					all_IDS >> fileID;
					if (searchID == fileID)
					{
						refundReceipts << "          Refund Ticket \nRefund date: " << ctime(&ticketDate) << "\nID of Ticket Refunded: " << searchID << "\nBalance added to wallet: " << refunded;
						//calls func wallet() to store refunded money & ticket ID
						wallet(refunded, searchID);
						cout << "\nNow you are done! sending you to the main menu...\n";
						x = false;
						break;

					}
				}
				

			}
			else if (yesOrNo == 2) {
				cout << "You've chosen to cancel the refunding process. Thank you for using OSS Cinemas!";
			} else {
				cout << "The number you entered is invalid. \n";
			}
			if(x) {
						cout << "\n\nTicket ID not found, sending you to the main menu...\n";
			}
			all_IDS.close();
			refundReceipts.close();
			sleep(2);
		}

		//saves ticket ID and wallet money for later use
		void wallet(int walletBalance, string searchID)
		{
			fstream wallet;
			wallet.open("wallet.txt", ios::in | ios::app);

			wallet << searchID << " " << walletBalance;
			wallet.close();
		}
};
