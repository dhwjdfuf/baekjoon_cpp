#include <stdio.h>

int main(void)

{

	int final, day, month;
	int days = 0;

	scanf("%d %d", &month, &day);

	for (int count = 1; count <= month; count++)

	{

		switch (count)

		{

		case 2:case 4: case 6: case 8: case 9: case 11: days += 31; break;

		case 5:case 7: case 10: case 12: days += 30; break;

		case 3: days += 28; break;
		case 1: break;
		}

	}

	final = days + day - 1;



	switch (final % 7)

	{

	case 0: printf("MON"); break;

	case 1: printf("TUE"); break;

	case 2: printf("WED"); break;

	case 3: printf("THU"); break;

	case 4: printf("FRI"); break;

	case 5: printf("SAT"); break;

	case 6: printf("SUN"); break;

	}







	return 0;

}