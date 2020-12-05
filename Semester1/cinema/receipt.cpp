class receipt {
	private:
		security sec;
		walletBig wal;
	public:
		//Charging user with cinema fees and storing the transaction processes in a file
		void chargeHisWallet(string userName, double price) {
			fstream file("transaction.txt", ios::in | ios::app);

			file << userName << ": "  << -1*price << "\n";
				
			file.close();
		}
		//Withdrawing the cinema fees from the user wallet
		void receiptDo(string name, string m, string whichSeat, string timing, bool isVip)
		{
		  double price = 15;

		  if(isVip) price = 25;
		  //Checking if the user if special and if so, making 20% discount
		  if(wal.specialOrNot(name))  price-=(0.2*price);

		  fstream walletTmp;
		  walletTmp.open("wallet.txt", ios::in | ios::app);
		  while (!walletTmp.eof()) 
		  { 
			string searchUser;
			int walletMoney;
			walletTmp >> searchUser;
			if (searchUser == name) 
			{ 
				walletTmp >> walletMoney;
				price -= walletMoney; 
				break;
			} 
		  }
		  
		  chargeHisWallet(name, price);

		  fstream receiptTmp;
		  receiptTmp.open("receipt.txt", ios::in | ios::app);

		  fstream all_IDS;
		  all_IDS.open("Receipts.txt", ios::in | ios::app);
		  //getting the reservation time
		  time_t ticketDate = time(NULL);
		  string id = name + "_" + m + "_" + whichSeat + "_" + timing;
		  //getting the tickey and storing it in a file
		  receiptTmp << "      OSS MOVIES ~ Movie Ticket\n" <<"Username: " << name<<"\nDate: "<< ctime(&ticketDate)<<"Ticket ID: "<<id<<"\nAmount charged: "<<price<<"\nMovie Chosen: "<<m<<"\nMovie Timing: "<<timing<<"\n\n";
		  //storing the receipt in a file
		  all_IDS << id << "\n";
		sleep(1);
			//Displaying the ticket to the user
		  cout<<"Your ticket ID is "<<id<<", please save it for future reference."<<endl;

		  receiptTmp.close();
		  all_IDS.close();
		  sleep(1);
		}		

};
