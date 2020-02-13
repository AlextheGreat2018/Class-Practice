#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double swordAttack(double chance, double points, double bonus);

double bowAttack(double chance, double points, double bonus);

double spearAttack(double chance, double points, double bonus);

double fireMagic(double chance, double points, double bonus);

double iceMagic(double chance, double points, double bonus);

double lightningMagic(double chance, double points, double bonus);

double clawAttack(double chance, double points, double bonus);

double biteAttack(double chance, double points, double bonus);

double breathAttack(double chance, double points, double bonus);

double tailAttack(double chance, double points, double bonus);

int main(void)
{
	double playerHealth = 125.0, dragonHealth = 200.0;
	int decision;
	srand(time(NULL));
	double success, hit, bonus;
	
	double(*player[])(double, double, double) = 
	{swordAttack, bowAttack, spearAttack, fireMagic, iceMagic, lightningMagic};
	
	double(*dragon[])(double, double, double) = 
	{clawAttack, biteAttack, breathAttack, tailAttack};
	
	do
	{
		printf("Player Health: %5.2f\n", playerHealth);
		printf("Dragon Health: %5.2f\n", dragonHealth);
		
		printf("\nWhat will you do?\n");
		printf("1. Strike with sword.\n");
		printf("2. Shoot with bow.\n");
		printf("3. Strike with spear.\n");
		printf("4. Cast a ball of fire.\n");
		printf("5. Cast storm of ice.\n");
		printf("6. Cast a lightning bolt.\n");
		scanf("%d", &decision);
		
		if(decision < 1 || decision > 6)
		{
			printf("\nThat isn't a choice.\n\n");
		}
		else
		{
			dragonHealth = dragonHealth - (*player[decision - 1])(success, hit, bonus);
			if(dragonHealth <= 0.0)
			{
				printf("\nGame Over. You win!\n");
				break;
			}

			int enemyChoice = rand() % 4;
			playerHealth = playerHealth - (*dragon[enemyChoice])(success, hit, bonus);
			if(playerHealth <= 0.0)
			{
				printf("\nGame Over. You lose!\n");
				break;
			}
		}
	}while(playerHealth > 0.0 && dragonHealth > 0.0);
}

double swordAttack(double chance, double points, double bonus)
{
	chance = (double)(rand() % 20) + 1.0;
	
	if(chance < 15.0)
	{
		printf("\nYou swing with your sword.\n");
		printf("You deal 0 damage.\n");
		return 0.0;
	}
	else
	{
		printf("\nYou swing with your sword.\n");
		points = (double)(rand() % 10) + 1.0;
		bonus = (double)(rand() % 5) + 1.0;
		printf("You deal %5.2f points of damage.\n", points + bonus);
		return points + bonus;
	}
}

double bowAttack(double chance, double points, double bonus)
{
	chance = (double)(rand() % 20) + 1.0;
	
	if(chance < 15.0)
	{
		printf("\nYou fire your bow.\n");
		printf("You deal 0 damage.\n");
		return 0.0;
	}
	else
	{
		printf("\nYou fire your bow.\n");
		points = (double)(rand() % 8) + 1.0;
		bonus = (double)(rand() % 5) + 1.0;
		printf("You deal %5.2f points of damage.\n", points + bonus);
		return points + bonus;
	}
}

double spearAttack(double chance, double points, double bonus)
{
	chance = (double)(rand() % 20) + 1.0;
	
	if(chance < 15.0)
	{
		printf("\nYou strike with your spear.\n");
		printf("You deal 0 damage.\n\n");
		return 0.0;
	}
	else
	{
		printf("\nYou strike with your spear.\n");
		points = (double)(rand() % 12) + 1.0;
		bonus = (double)(rand() % 5) + 1.0;
		printf("You deal %5.2f points of damage.\n", points + bonus);
		return points + bonus;
	}
}

double fireMagic(double chance, double points, double bonus)
{
	chance = (double)(rand() % 20) + 1.0;
	
	if(chance < 15.0)
	{
		printf("\nYou cast a ball of fire.\n");
		points = (double)(rand() % 48) + 1.0;
		bonus = (double)(rand() % 5) + 1.0;
		printf("You deal %5.2f points of damage.\n", points + bonus);
		return points + bonus;
	}
	else
	{
		printf("\nYou cast a ball of fire.\n");
		points = (double)(rand() % 48) + 1.0;
		bonus = (double)(rand() % 5) + 1.0;
		printf("You deal %5.2f points of damage.\n", (points + bonus) * 2.0);
		return (points + bonus) * 2.0;
	}
}

double iceMagic(double chance, double points, double bonus)
{
	chance = (double)(rand() % 20) + 1.0;
	
	if(chance < 15.0)
	{
		printf("\nYou cast a storm of ice.\n");
		points = (double)(rand() % 40) + 1.0;
		bonus = (double)(rand() % 5) + 1.0;
		printf("You deal %5.2f points of damage.\n", (points + bonus) / 4.0);
		return (points + bonus) / 4.0;
	}
	else
	{
		printf("\nYou cast a ball of fire\n");
		points = (double)(rand() % 40) + 1.0;
		bonus = (double)(rand() % 5) + 1.0;
		printf("You deal %5.2f points of damage.\n", (points + bonus) / 2.0);
		return (points + bonus) / 2.0;
	}
}

double lightningMagic(double chance, double points, double bonus)
{
	chance = (double)(rand() % 20) + 1.0;
	
	if(chance < 15.0)
	{
		printf("\nYou cast a bolt of lightning.\n");
		points = (double)(rand() % 48) + 1.0;
		bonus = (double)(rand() % 5) + 1.0;
		printf("You deal %5.2f points of damage.\n", (points + bonus) / 2.0);
		return (points + bonus) / 2.0;
	}
	else
	{
		printf("\nYou cast a bolt of lightning.\n");
		points = (double)(rand() % 48) + 1.0;
		bonus = (double)(rand() % 5) + 1.0;
		printf("You deal %5.2f points of damage.\n", points + bonus);
		return points + bonus;
	}
}

double clawAttack(double chance, double points, double bonus)
{
	chance = (double)(rand() % 20) + 1.0;
	
	if(chance < 15.0)
	{
		printf("\nThe dragon strikes with its claws.\n");
		printf("It deals 0 damage.\n\n");
		return 0.0;
	}
	else
	{
		printf("\nThe dragon strikes with its claws.\n");
		points = (double)(rand() % 12) + 1.0;
		bonus = (double)(rand() % 6) + 1.0;
		printf("It deals %5.2f points of damage.\n\n", points + bonus);
		return points + bonus;
	}
}

double biteAttack(double chance, double points, double bonus)
{
	chance = (double)(rand() % 20) + 1.0;
	
	if(chance < 15.0)
	{
		printf("\nThe dragon goes to bite.\n");
		printf("It deals 0 damage.\n\n");
		return 0.0;
	}
	else
	{
		printf("\nThe dragon goes to bite.\n");
		points = (double)(rand() % 28) + 1.0;
		bonus = (double)(rand() % 6) + 1.0;
		printf("It deals %5.2f points of damage.\n\n", points + bonus);
		return points + bonus;
	}
}

double breathAttack(double chance, double points, double bonus)
{
	chance = (double)(rand() % 20) + 1.0;
	
	if(chance < 15.0)
	{
		printf("\nThe dragon breaathes searing cold ice.\n");
		points = (double)(rand() % 96) + 1.0;
		bonus = (double)(rand() % 6) + 1.0;
		printf("It deals %5.2f points of damage.\n\n", (points + bonus) / 2.0);
		return (points + bonus) / 2.0;
	}
	else
	{
		printf("\nThe dragon breathes searing cold ice.\n");
		points = (double)(rand() % 96) + 1.0;
		bonus = (double)(rand() % 6) + 1.0;
		printf("It deals %5.2f points of damage.\n\n", points + bonus);
		return points + bonus;
	}
}

double tailAttack(double chance, double points, double bonus)
{
	chance = (double)(rand() % 20) + 1.0;
	
	if(chance < 15.0)
	{
		printf("\nThe dragon strikes with its tail.\n");
		printf("It deals 0 damage.\n\n");
		return 0.0;
	}
	else
	{
		printf("\nThe dragon strikes with its tail.\n");
		points = (double)(rand() % 16) + 1.0;
		bonus = (double)(rand() % 6) + 1.0;
		printf("It deals %5.2f points of damage.\n\n", points + bonus);
		return points + bonus;
	}
}
