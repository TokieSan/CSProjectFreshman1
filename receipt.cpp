class receipt {
	private:
		security sec;
		wallet wal;
	public:
		void chargeHisWallet(string userName, double price) {
			fstream file("transaction.txt", ios::in | ios::app);

			file << userName << ": "  << -1*price << "\n";
				
			file.close();
		}
	
		void receiptDo(string name, string m, string whichSeat, string timing, bool isVip)
		{
		  double price = 15;

		  if(isVip) price = 25;

		  if(wal.specialOrNot(name))  price-=(0.2*price);
			
		  chargeHisWallet(name, price);

		  fstream receipt;
		  receipt.open("receipt.txt", ios::out | ios::app);

		  fstream all_IDS;
		  all_IDS.open("Receipts.txt", ios::out | ios::app);

		  time_t ticketDate = time(NULL);
		  string id = name + "_" + m + "_" + whichSeat + "_" + timing;

		  receipt << "      OSS MOVIES ~ Movie Ticket\n" <<"Username: " << name<<"\nDate: "<< ctime(&ticketDate)<<"Ticket ID: "<<id<<"\nAmount charged: "<<price<<"\nMovie Chosen: "<<m<<"\nMovie Timing: "<<timing<<"\n\n";

		  all_IDS << id << "\n";
		sleep(1);
		  cout<<"Your ticket ID is "<<id<<", please save it for future reference."<<endl;

		  receipt.close();
		  all_IDS.close();
		  sleep(1);
		}		

};
