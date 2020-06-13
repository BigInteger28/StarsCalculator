#include <iostream>

using namespace std;

double newRating(double multiplier, double ownRating, double averageOpponent, double matches, double score)
{	
	double mid = matches / ((averageOpponent / ownRating) * 2);
	double abovemid = score - mid;	
	return ownRating + (abovemid * multiplier);
}

int main()
{
	while (1 != 2)
    {
		double multiplier = 1; //Placements op 10 (per draw 5* == een league)
		double ownRating;        
		double sumRatingAllOpponents;        
		double matches;
		double score;

		cout << "Multiplier: ";
		cin >> multiplier;
		cout << "Your own rating: ";
		cin >> ownRating;        
		cout << "Total sum all ratings played against: ";
		cin >> sumRatingAllOpponents;        
		cout << "Matches played: ";
		cin >> matches;
		cout << "Score: ";
		cin >> score;
		
		double averageOpponent = sumRatingAllOpponents / matches;
		
		cout << "\nAverage opponent is " << averageOpponent;
		cout << "\nYour new rating is " << newRating(multiplier, ownRating, averageOpponent, matches, score);
		cout << "\n\n";
	}
}
