struct movieInfo {
	string movieName, movieTime, MovieDescription;
};
class movies {
	public:
		int moviesInfo() {
			ifstream file("MoviesInfo.txt");
			int totalLength=0;
			movieInfo moviesList[20];
			for(int i=0; !file.eof(); ++i) {
				getline(file, moviesList[i].movieName);
				getline(file, moviesList[i].MovieDescription);
				getline(file, moviesList[i].movieTime);
				totalLength++;
			}
			for(int i=0; i<totalLength; ++i)
			{
				cout << "\n\n";
				
				if(moviesList[i].movieTime.length()>0) {
					cout << i+1 << ") " << moviesList[i].movieName << ", available at " << moviesList[i].movieTime << "\n"<< moviesList[i].MovieDescription;

				}
			}
			sleep(2);
			cout << "\nWhat do you want now? \n" << "	1) Reserve a movie\n	2) Back to the main menu";
			int tmpDigit; cin >> tmpDigit;
			return tmpDigit;
		}

};
