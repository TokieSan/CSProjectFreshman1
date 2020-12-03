class wallet {
	public:
		bool fastCheckSub(string sub, string dom) {
			for(int i=0; i<sub.length(); i++) {
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
			all_IDS.open("Receipts.txt", ios::in);
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

		bool specialOrNot(string userName)
		{
			fstream all_IDS;
			all_IDS.open("Receipts.txt", ios::in);
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
			{
				return true;
				//in function of price,
				//if (specialOrNah==true)
				  //price*0.8;
			}
			
			return false;

		}
/***
		void returnTicket()
		{
			cout << "You've chosen to return and refund your ticket.\nPlease enter '1' to confirm, or '2' to cancel: ";
			int yesOrNo;
			cin >> yesOrNo;
			fstream all_IDS;
			all_IDS.open("Receipts.txt", ios::out);

			fstream refundReceipts;
			refundReceipts.open("Refunds.txt", ios::out | ios::app);

			string fileID, searchID;
			int refunded = 0;
			time_t ticketDate = time(NULL);

			if (yesOrNo == 1)
			{
				cout << "Next step! Please enter your ticket ID: \n";
				cin >> searchID;
				while (!all_IDS.eof())
				{
					all_IDS >> fileID;
					if (searchID == fileID)
					{
						cout << "How much did you pay for this ticket?\n";
						cin >> refunded;
						all_IDS << " ";
						refundReceipts << "          Refund Ticket \nRefund date: " << ctime(&ticketDate) << "\nID of Ticket Refunded: " << searchID << "\nBalance added to wallet: " << refunded;
						wallet(refunded, searchID);
					}
				}

			}
			else
				cout << "You've chosen to cancel the refunding process. Thank you for using OSS Cinemas!";
			all_IDS.close();
			refundReceipts.close();
		}
		***/
};
