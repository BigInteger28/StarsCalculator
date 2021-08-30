#include <stdio.h>

float newRating(float multiplier, float ownRating, float averageOpponent, float matches, float score)
{
	float mid = matches / ((averageOpponent / ownRating) * 2);
	if (mid > matches * 0.6) mid = matches * 0.6;
	float abovemid = score - mid;
	return ownRating + (abovemid * multiplier);
}

int main()
{
	while (1 != 2)
    {
		float multiplier;
		float ownRating;
		float sumRatingAllOpponents;
		float matches;
		float score;
		float averageOpponent;
		float highestRatingInList; //Voorlopig is dit Amon
		char teams;
		char placements;
		char human;

		printf("Teams? (y): ");
		scanf(" %c", &teams);

		if (teams != 'y') {
			printf("Placements? (y): ");
			scanf(" %c", &placements);
			if (placements == 'y') {
				printf("Human? (y): ");
				scanf(" %c", &human);
			}

			if (placements != 'y' || human == 'y') {
				printf("Total sum all ratings played against: ");
				scanf("%f", &sumRatingAllOpponents);
			}
		}

		printf("Matches played: ");
		scanf("%f", &matches);
		printf("Score: ");
		scanf("%f", &score);       

		if (placements == 'y') {
			if (human == 'y') {
				multiplier = 5;
				ownRating = (sumRatingAllOpponents / matches) / 2;
			} else {
				multiplier = 3;
				printf("Average rating: ");
				scanf("%f", &averageOpponent);
                printf("Highest rating in list: ");
		        scanf("%f", &highestRatingInList); 
				averageOpponent = (averageOpponent + (highestRatingInList / 2)) / 2;
				ownRating = averageOpponent;
			}
		}
		else {
			printf("Multiplier: ");
			scanf("%f", &multiplier);
			//if (teams != 'y') {
				printf("Your own rating: ");
				scanf("%f", &ownRating);
			//}
		}

		if (teams == 'y') {
			printf("Median rating: ");
			scanf("%f", &averageOpponent);
			//ownRating = averageOpponent / 2;
		}

		if (teams != 'y' && (human == 'y' || placements != 'y')) averageOpponent = sumRatingAllOpponents / matches;

		printf("\nAverage opponent is %.1f", averageOpponent);
		printf("\nYour new rating is %.1f", newRating(multiplier, ownRating, averageOpponent, matches, score));
		printf("\n\n");
	}
}
