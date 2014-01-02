#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  while(1)
  {
    int stack[7][3] = {
			{ 1, 0, 0 },
			{ 2, 0, 0 },
			{ 3, 0, 0 },
			{ 4, 0, 0 },
			{ 5, 0, 0 },
			{ 6, 0, 0 },
			{ 7, 0, 0 },
		      };
    int totala;
    int totalb;
    int totalc;
    totala = stack[0][0]+stack[1][0]+stack[2][0]+stack[3][0]+stack[4][0]+stack[5][0]+stack[6][0];
    totalb = stack[0][1]+stack[1][1]+stack[2][1]+stack[3][1]+stack[4][1]+stack[5][1]+stack[6][1];
    totalc = stack[0][2]+stack[1][2]+stack[2][2]+stack[3][2]+stack[4][2]+stack[5][2]+stack[6][2];
    int loop0;
    int loop1;	// check the first input and convert it in a number (a -> 0, b -> 1, c -> 2)
    int loop2;	// check the second input and convert it in a number (a -> 0, b -> 1, c -> 2)
    int loop3;	// Check that the stack from which you want to take is not empty
    int loop4;	// Check that the disc is not placed on the same stack from which it comes.
    int loop5;	// Check that the second disc of which you want to put the first disc is bigger than the first
    int loop6;	// The last menuselectionconrolloop
    int input0;	// The menuselectioninput (1 -> Play, 2 -> About, 3 -> Exit)
    char input1;	// The Users input for the first stack (a, A, b, B, c, C)
    char input2;	// The Users input for the second stack (a, A, b, B, c, C)
    int input3;	// The numeric translation of input1 (a -> 0, b -> 1, c -> 2)
    int input4;	// The numeric translation of input2 (a -> 0, b -> 1, c -> 2)
    int input5;	// After winning the game selection (1 -> Main Menu, 2 -> Exit)
    int count0;	// Will count every new round 
    int x;
    int y;

    printf("\nWelcome to my small *Towers of Hanoi* Game\n");
    
    loop0 = 1;
    do
    {
      printf("\nWhat do you want to do?\n1 -> Let's play *Towers of Hanoi*\n2 -> About\n3 -> Exit\n");
      printf("Please make input(1-3): ");
      scanf("%d",&input0);
      fflush(stdin);
    
      switch(input0)
      {
	case 1 : printf("\nLet's go! (:\n");
	  loop0 = 0;
	  break;
	case 2 : printf("\n==================About==================\nCreated by Moritz Wenzel\nmoritz.wenzel@secure-mail.biz\nThanks for the contest\nfacebook.com/groups/dbsoftwares/\nDo what you want with the code -> GPL ;)\n=========================================\n");
	  break;
	case 3 : return 0;
	  break;
	default: printf("\nUnknown value, please try again\n");
	  break;
      }
    
    }while(loop0 == 1);
    
    count0 = 0;
    do
    {
      system("clear");
      count0++;
      printf("Towers of Hanoi\nRound %d\n\n", count0);
      printf("-%d- -%d- -%d-\n",stack[0][0],stack[0][1],stack[0][2]);
      printf("-%d- -%d- -%d-\n",stack[1][0],stack[1][1],stack[1][2]);
      printf("-%d- -%d- -%d-\n",stack[2][0],stack[2][1],stack[2][2]);
      printf("-%d- -%d- -%d-\n",stack[3][0],stack[3][1],stack[3][2]);
      printf("-%d- -%d- -%d-\n",stack[4][0],stack[4][1],stack[4][2]);
      printf("-%d- -%d- -%d-\n",stack[5][0],stack[5][1],stack[5][2]);
      printf("-%d- -%d- -%d-\n",stack[6][0],stack[6][1],stack[6][2]);
      printf("-----------\n-A- -B- -C-\n");
      
      do
      {
	printf("\nTake Disc of stack(A, B, C): ");
	scanf("%s",&input1);
	fflush(stdin);
	printf("\nAnd put them on stack(A, B, C): ");
	scanf("%s",&input2);
	fflush(stdin);
	
	switch(input1) // check the first input and convert it in a number (a -> 0, b -> 1, c -> 2)
	{
	  case 'a' :	input3 = 0;
			loop1 = 0;
			break;
	  case 'A' :	input3 = 0;
			loop1 = 0;
			break;
	  case 'b' :	input3 = 1;
			loop1 = 0;
			break;
	  case 'B' :	input3 = 1;
			loop1 = 0;
			break;
	  case 'c' :	input3 = 2;
			loop1 = 0;
			break;
	  case 'C' :	input3 = 2;
			loop1 = 0;
			break;
	  default :	printf("\nCan't understand your first input, please try it again");
			loop1 = 1;
			break;
	}
	switch(input2) // check the second input and convert it in a number (a -> 0, b -> 1, c -> 2)
	{
	  case 'a' :	input4 = 0;
			loop2 = 0;
			break;
	  case 'A' :	input4 = 0;
			loop2 = 0;
			break;
	  case 'b' :	input4 = 1;
			loop2 = 0;
			break;
	  case 'B' :	input4 = 1;
			loop2 = 0;
			break;
	  case 'c' :	input4 = 2;
			loop2 = 0;
			break;
	  case 'C' :	input4 = 2;
			loop2 = 0;
			break;
	  default :	printf("\nCan't understand your second input, please try it again");
			loop2 = 1;
			break;
	}
	if(loop1 == 0 && loop2 == 0)
	{
	  if(stack[6][input3] == 0) // Check that the stack from which you want to take is not empty
	  {
	    loop3 = 1;
	    printf("\nThe stack from which you want to take is empty. Please try again");
	  }
	  else
	  {
	    loop3 = 0;
	  
	    if(input3 == input4) // Check that the disc is not placed on the same stack from which it comes.
	    {
	      loop4 = 1;
	      printf("\nYou can't put the disc on the same stack! That would not make sense.");
	    }
	    else
	    {
	      loop4 = 0;
	    
	      x = 0;
	      while(stack[x][input3] == 0 )
	      {  
		x++; 
	      }	
	
	      y = 6;
	      while(stack[y][input4] != 0)
	      {
		y = y-1;
	      }
	  
	      if(y == 6 && stack[y][input4] == 0) // Check that the second disc of which you want to put the first disc is bigger than the first
	      {
		loop5 = 0;
	      }
	      else
	      {
		y++;
		if(stack[y][input4] > stack[x][input3])
		{
		  loop5 = 0;
		}
		else if(stack[y][input4] < stack[x][input3])
		{
		  loop5 = 1;
		  printf("\nThis move is not allowed!");
		}
		else
		{
		  printf("\nError, please try again");
		}
		y = y-1;
	      }
	    }
	  }
	}
      }while(loop1 == 1 || loop2 == 1 || loop3 == 1 || loop4 ==1 || loop5 == 1);
      
      stack[y][input4] = stack[x][input3];
      stack[x][input3] = 0;
      totalc = stack[0][2]+stack[1][2]+stack[2][2]+stack[3][2]+stack[4][2]+stack[5][2]+stack[6][2];
    }while(totalc != 28);
    
    printf("\n!!!YEAHH CONGRATULATION!!!\nYou solved it in only %d rounds!\n\nWhat do you want to do?\n1 -> Back to the Main Menu\n2 -> Exit\n",count0);
    loop6 = 1;
    do
    {
      printf("Please make input(1-2): ");
      scanf("%d",&input5);
      fflush(stdin);
    
      switch(input5)
      {
	case 1:	loop6 = 0;
		break;
	case 2:	return 0;
		break;
	default:	printf("\nUnknown value, please try again\n");
		break;
      }
    }while(loop6 == 1);
  }
}
