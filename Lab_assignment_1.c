//CSE 1101L Assignment to make A TicTacToe Gamebot
//Instructor: Mridha Md. Nafis Fuad Sir
// Created by shams on 8/7/2025.
//

#include<stdio.h>
char a = '1',  b = '2',  c = '3',  d = '4',  e = '5',  f = '6',  g = '7',  h = '8',  i = '9';
int c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0, c7 = 0, c8 = 0, c9 = 0; // cell number
int p1 = 0, p2 = 0, p3 = 0, p4 = 0, p5 = 0, p6 = 0, p7 = 0, p8 = 0, p9 = 0; //checks which cell is occupied by player
int b1 = 0, b2 = 0, b3 = 0, b4 = 0, b5 = 0, b6 = 0, b7 = 0, b8 = 0, b9 = 0; //checks which cell is occupied by bot

void playerMove(int val); //defines logic for the player move
void botMove(); // defines logic for the bot move; Priority: Win->Block->Occupy Center-> Occupy corner-> Occupy free cell
int BotwinChecker(); // checks when bot wins and ends the game
int PlayerwinChecker(); // checks when player wins and ends the game


void table(){

	printf("  %c | %c  | %c \n",a,b,c);
	printf("----------------\n");
	printf("  %c | %c  | %c \n",d,e,f);
	printf("----------------\n");
	printf("  %c | %c  | %c \n",g,h,i);

}

int main(){
	int val,n;

	printf("Current Board\n ");
	table();
	printf("\n");
	printf("Choose 1 for Hard Mode and 0 for easy mode \n");
	printf("Input 1 so that bot gives the first move or input 0 so that Player gives the first move: ");
	scanf("%d",&n);

	if(n == 1) {
		for(int i = 0; i < 5; i++){

			printf("Bot move: \n");
			botMove(); // the bot gives it's move
			if (c1+c2+c3+c4+c5+c6+c7+c8+c9 == 9) {
				printf("\nGame ended\nDraw :>\n");
				break;
			}
			if (BotwinChecker()) {
				printf("\nGame ended\nComputer Wins! :(\n");
				break;
			}

			printf("\n");
			printf("Enter the cell number: ");
			scanf("%d", &val);

			printf("\nCurrent Board: \n");

			playerMove(val);// the player gives his move
			if (c1+c2+c3+c4+c5+c6+c7+c8+c9 == 9) {
				printf("\nGame ended\nDraw :>\n");
				break;
			}
			if (PlayerwinChecker()) {
				printf("\nGame ended\nPlayer Wins!! :)\n");
				break;
			}

			printf("\n");
		}
	}

	else {
		for(int i = 0; i < 5; i++){

			printf("Enter the cell number: ");
			printf("\n");
			scanf("%d", &val);
			printf("\nCurrent Board: \n");
			playerMove(val);// the player gives his move
			if (c1+c2+c3+c4+c5+c6+c7+c8+c9 == 9) {
				printf("\nGame ended\nDraw :>\n");
				break;
				return 0;
			}
			if (PlayerwinChecker()) {
				printf("\nGame ended\nPlayer Wins!! :)\n");
				break;
				return 0;
			}

			printf("\n");

			printf("Bot move: \n");
			botMove(); // the bot gives it's move
			if (c1+c2+c3+c4+c5+c6+c7+c8+c9 == 9) {
				printf("\nGame ended\nDraw :>\n");
				break;
				return 0;
			}
			if (BotwinChecker()) {
				printf("\nGame ended\nComputer Wins! :(\n");
				break;
				return 0;
			}
			printf("\n");
		}
	}

	return 0;
}
void playerMove(int val){

	if(val == 1){
		a = 'X';
		c1 = 1;
		p1 = 1;
		table();
	}
	else if(val == 2){
		b = 'X';
		p2 = 1;
		c2 = 1;
		table();
	}
	else if(val == 3){
		c = 'X';
		p3 = 1;
		c3 = 1;
		table();
	}
	else if(val == 4){
		d = 'X';
		p4 = 1;
		c4 = 1;
		table();
	}
	else if(val == 5){
		e = 'X';
		p5 = 1;
		c5 = 1;
		table();
	}
	else if(val == 6){
		f = 'X';
		p6 = 1;
		c6 = 1;
		table();
	}
	else if(val == 7) {
		g = 'X';
		p7 = 1;
		c7 = 1;
		table();
	}
	else if(val == 8) {
		h = 'X';
		p8 = 1;
		c8 = 1;
		table();
	}
	else if(val == 9) {
		i = 'X';
		p9 = 1;
		c9 = 1;
		table();
	}
}

void botMove() {
	if (!c5) {
		e = 'O';
		b5 = 1;
		c5 = 1;
		table();
	}

	else if((b2+b3 == 2 || b4+b7 == 2) && !c1) {
		a = 'O';
		b1 = 1;
		c1 = 1;
		table();
	}
	else if((b7+b8 == 2 || b3+b6 == 2) && !c9) {
		i = 'O';
		b9 = 1;
		c9 = 1;
		table();
	}
	else if ((b8+b9 == 2 || b1+b4 == 2) &&!c7) {
		g = 'O';
		b7 = 1;
		c7 = 1;
		table();
	}

	else if ((b1+b7 == 2 ) && !c4) {
		d = 'O';
		b4 = 1;
		c4 = 1;
		table();
	}
	else if ((b3+b9 == 2 || b4+b5 == 2) &&!c6) {
		f = 'O';
		b6 = 1;
		c6 = 1;
		table();
	}
	else if ((b9+b6 == 2 || b2+b1 == 2) &&!c3) {
		c = 'O';
		b3 = 1;
		c3 = 1;
		table();
	}
	else if ((b1+b3 == 2 || b5+b8 == 2) &&!c2) {
		b = 'O';
		b2 = 1;
		c2 = 1;
		table();
	}
	else if ((b7+b9 == 2 || b2+b5 == 2) && !c8) {
		h = 'O';
		b8 = 1;
		c8 = 1;
		table();
	}
	else if ((b1+b5 == 2) &&!c9) {
		i = 'O';
		b9 = 1;
		c9 = 1;
		table();
	}
	else if ((b9+b5 == 2) &&!c1) {
		a = 'O';
		b1 = 1;
		c1 = 1;
		table();
	}

	else if ((b7+b5 == 2) &&!c3) {
		c = 'O';
		b3 = 1;
		c3 = 1;
		table();
	}
	else if ((b3+b5 == 2) &&!c7) {
		g = 'O';
		b7 = 1;
		c7 = 1;
		table();
	}
	else if ((p9+p5 == 2) &&!c1) {
		a = 'O';
		b1 = 1;
		c1 = 1;
		table();
	}
	else if ((p1+p5 == 2) &&!c9) {
		i = 'O';
		b9 = 1;
		c9 = 1;
		table();
	}
	else if ((p7+p5 == 2) &&!c3) {
		c = 'O';
		b3 = 1;
		c3 = 1;
		table();
	}
	else if ((p3+p5 == 2) &&!c7) {
		g = 'O';
		b7 = 1;
		c7 = 1;
		table();
	}
	else if((p2+p3 == 2 || p4+p7 == 2) && !c1) {
		a = 'O';
		b1 = 1;
		c1 = 1;
		table();
	}
	else if((p7+p8 == 2 || p3+p6 == 2) && !c9) {
		i = 'O';
		b9 = 1;
		c9 = 1;
		table();
 	}
	else if ((p8+p9 == 2 || p1+p4 == 2) &&!c7) {
		g = 'O';
		b7 = 1;
		c7 = 1;
		table();
	}
	else if ((p1+p7 == 2 || p5+p6 == 2) && !c4) {
		d = 'O';
		b4 = 1;
		c4 = 1;
		table();
	}
	else if ((p3+p9 == 2 || p4+p5 == 2) &&!c6) {
		f = 'O';
		b6 = 1;
		c6 = 1;
		table();
	}
	else if ((p9+p6 == 2 || p2+p1 == 2) &&!c3) {
		c = 'O';
		b3 = 1;
		c3 = 1;
		table();
	}
	else if ((p1+p3 == 2 || p5+p8 == 2) &&!c2) {
		b = 'O';
		b2 = 1;
		c2 = 1;
		table();
	}
	else if ((p7+p9 == 2 || p2+p5 == 2) && !c8) {
		h = 'O';
		b8 = 1;
		c8 = 1;
		table();
	}
	else {
		if(!c1) {
			a = 'O';
			b1 = 1;
			c1 = 1;
			table();
		}
		else if (!c7) {
			g = 'O';
			b7 = 1;
			c7 = 1;
			table();
		}
		else if (!c3) {
			c = 'O';
			b3 = 1;
			c3 = 1;
			table();
		}
		else if(!c9) {
			i = 'O';
			b9 = 1;
			c9 = 1;
			table();
		}
		else if (!c4) {
			d = 'O';
			b4 = 1;
			c4 = 1;
			table();
		}
		else if (!c6) {
			f = 'O';
			b6 = 1;
			c6 = 1;
			table();
		}
		else if (!c2) {
			b = 'O';
			b2 = 1;
			c2 = 1;
			table();
		}
		else if (!c8) {
			h = 'O';
			b8 = 1;
			c8 = 1;
			table();
		}
	}
}

int BotwinChecker() {
	if (b1+b2+b3 == 3) {
		return 1;
	}
	else if (b1+b4+b7 == 3) {
		return 1;
	}
	else if (b1+b5+b9 == 3) {
		return 1;
	}
	else if (b2+b5+b8 == 3) {
		return 1;
	}
	else if (b3+b6+b9 == 3) {
		return 1;
	}
	else if (b3+b5+b7 == 3) {
		return 1;
	}
	else if (b4+b5+b6 == 3) {
		return 1;
	}
	else if (b7+b8+b9 == 3) {
		return 1;
	}
	else {
		return 0;
	}
}
int PlayerwinChecker() {
	if (p1+p2+p3 == 3) {
		return 1;
	}
	else if (p1+p4+p7 == 3) {
		return 1;
	}
	else if (p1+p5+p9 == 3) {
		return 1;
	}
	else if (p2+p5+p8 == 3) {
		return 1;
	}
	else if (p3+p6+p9 == 3) {
		return 1;
	}
	else if (p3+p5+p7 == 3) {
		return 1;
	}
	else if (p4+p5+p6 == 3) {
		return 1;
	}
	else if (p7+p8+p9 == 3) {
		return 1;
	}
	else {
		return 0;
	}
}
