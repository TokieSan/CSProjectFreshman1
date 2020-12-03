using namespace std;

class sysObjects {
	public:
		void clearScreen() {
			/*
			 * Just a fast way to clear screen
			 */
			if(system("CLS"))
				system("clear");
		}

	
};

class utilities {
	/*
	 * Here, the non system utilities that made to assist me in
	 * some specific task
	 */
	public:
		void dashLine(int n) {
			cout << endl;
			for(int i = 0 ; i < n; i++)
				cout << "-";
			cout << endl;
		}
};

class ux {
	private:
		utilities util;
	public:
		void welcome() {
			/*
			 * Welcome Screen, pretty straightforward
			 */
			util.dashLine(79);
			cout << "\n\n __          __  _                            _           ____   _____ _____ \n \\ \\        / / | |                          | |         / __ \\ / ____/ ____|\n  \\ \\  /\\  / ___| | ___ ___  _ __ ___   ___  | |_ ___   | |  | | (___| (___  \n   \\ \\/  \\/ / _ | |/ __/ _ \\| '_ ` _ \\ / _ \\ | __/ _ \\  | |  | |\\___ \\\\___ \\ \n    \\  /\\  |  __| | (_| (_) | | | | | |  __/ | || (_) | | |__| |____) ____) |\n     \\/  \\/ \\___|_|\\___\\___/|_| |_| |_|\\___|  \\__\\___/   \\____/|_____|_____/ \n                                                                             \n                                                                             \n\n" ;
			util.dashLine(79);		}
		
};
