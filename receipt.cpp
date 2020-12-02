class receipt {

	public:

		void receiptDo(string name, string m, string whichSeat, string timing, bool isVip)
		{
		  double price = 15;

		  if(isVip) price = 25;

		  fstream receipt;
		  receipt.open("receipt.txt", ios::out | ios::app);

		  fstream all_IDS;
		  all_IDS.open("Receipts.txt", ios::out | ios::app);

		  time_t ticketDate = time(NULL);
		  string id = name + "_" + m + "_" + whichSeat + "_" + timing;

		  receipt << "      OSS MOVIES ~ Movie Ticket\n" <<"Username: " << name<<"\nDate: "<< ctime(&ticketDate)<<"Ticket ID: "<<id<<"\nAmount charged: "<<price<<"\nMovie Chosen: "<<m<<"\nMovie Timing: "<<timing<<"\n\n";

		  all_IDS << id << "\n";

		  cout<<"Your ticket ID is "<<id<<endl<<"Please save it for future reference."<<endl;
		  receipt.close();
		  all_IDS.close();
		}		

};
