#include "snake&ladder.h"
int main()
{

	uart_init();
	unsigned period = 0;
	int i;
	position=0;
	printf("\e[2J\e[H");
	//printf("\n\n\n\n");
	printf("Would you like to:\n    1)Read the rules\n    2)Play the game\n\n");

	//srand(time(NULL));
	//	scanf("%d", &choice);
	choice =1;

	if (choice==1)
	{

		printf("\nThe rules are simple: \n   You press enter to roll the die\n   You are then told which space you have landed on\n   If you land on a snake you will move down the board\n   If you land on a ladder then you will move up it\n   In order to win you must land on 64 exactly\n   If you go over 64 then your imaginary piece will be moved backwards for the remainder of your dice roll\n\n Good Luck\n\n");

	}

	if (choice==1,2){


		printf("\nWelcome to Snakes and Ladders.\n");
		printf("\n64  63  62  61  60  59  58  57         1=Start           27=Ladder to 37\n");
		printf("49  50  51  52  53  54  55  56         4=Ladder to 35    34=Snake  to 20\n");
		printf("48  47  46  45  44  43  42  41         7=Ladder to 23    42=Snake  to 11\n");
		printf("33  34  35  36  37  38  39  40         9=Snake  to 5     46=Ladder to 53\n");
		printf("32  31  30  29  28  27  26  25        14=Ladder to 43    49=Snake  to 32\n");
		printf("17  18  19  20  21  22  23  24        17=Snake  to 13    63=Snake  to 2\n");
		printf("16  15  14  13  12  11  10   9        21=Snake  to 3     64=End\n");
		printf(" 1   2   3   4   5   6   7   8        24=Ladder to 58\n");                       /*Prints the board for user's reference*/


		do
		{

			unsigned lsb = lfsr & 1;  /* Get lsb (i.e., the output bit). */
			lfsr >>= 1;               /* Shift register */
			if (lsb == 1)             /* Only apply toggle mask if output bit is 1. */
				lfsr ^= 0xB400u;        /* Apply toggle mask, value has 1 at bits corresponding
							 * to taps, 0 elsewhere. */
			++period;

			printf("\e[2J\e[H");
			display_square(position);
			printf("\t \tPlease press enter to roll");
			getchar();

			dice=((lfsr%6)+1);
			//			printf("\nYou have rolled a %d.", dice);


			position+=dice;

			if(position >64)
			{
				above = (position-64);
				position = (64 - above);
			}



			printf("\e[2J\e[H");
			printf("You have rolled a %d.", dice);
			display_square(position);

			//			printf(" Press a key to check your Luck...\n");
			//			getchar();

			//			printf("\e[2J\e[H");
			//			printf("Checking you Luck...\n");
			//			printf("Checking you Luck...\n");

			checkposition();
			//write a rotating program here
			getchar();
			printf("\e[2J\e[H");

			if (position<newposition)
			{
				printf("Well done, you have landed on a ladder. You are now on space %d.", newposition);
				position = newposition;
				display_square(position);
			}

			else if (position>newposition)
			{
				printf("Unlucky, you have landed on a snake. You are now on space %d.", newposition);
				position = newposition;
				display_square(position);
			}
			else
			{
				printf("No Problem \n");
			}

			printf("\n \n \t \t Press a key to continue...\n");
			getchar();

		} while(position<64);

		printf("\e[2J\e[H");
		printf("Congratulations, you have won!!!");
	}

	getchar();
	return 0;
}
