#include "list.h"
int main()
{
	int num = 0;
	int choice=0;
	Menu();
	while (1)
	{
		scanf("%d", &choice);
		switch (choice)
		{
		case   1:
		{
					Input_record();
					break;
		}
		case 2:
		{
				  num = Judge();
				  if (num == 0)
					  break;
				  else
				  {
					 To_Ave_Course();
					 break;
				  }
		}
		case 3:
		{
				  num = Judge();
				  if (num == 0)
					  break;
				  else
				  {
					  To_Ave_student();
					  break;
				  }

		}
		case 4:
		{
				  num = Judge();
				  if (num == 0)
					  break;
				  else
				  {
					  Order_by_total_score();
					  break;
				  }
		}
		case 5:
		{
				  num = Judge();
				  if (num == 0)
					  break;
				  else
				  {
					  Ascending_Order_by_total_score();
					  break;
				  }

		}
		case 6:
		{
				  num = Judge();
				  if (num == 0)
					  break;
				  else
				  {
					  Ascending_Order_by_number();
					  break;
				  }
		}
		case 7:
		{
				  num = Judge();
				  if (num == 0)
					  break;
				  else
				  {
					  Sort_in_dictionary();
					  break;
				  }
		}
		case 8:
		{
				  num = Judge();
				  if (num == 0)
					  break;
				  else
				  {
					  Search_by_number();
					  break;
				  }
		}
		case 9:
		{
				  num = Judge();
				  if (num == 0)
					  break;
				  else
				  {
					  Search_by_name();
					  break;
				  }
		}
		case 10:
		{
				   num = Judge();
				   if (num == 0)
					   break;
				   else
				   {
					   Analysis_for_every_course();
					   break;
				   }
		}
		case 11:
		{
				   num = Judge();
				   if (num == 0)
					   break;
				   else
				   {
					   void List_record();
					   break;
				   }

		}
		case 12:
		{
				   Write_To_A_file();
				   break;
		}
		case 13:
		{
				   Read_From_a_file();
				   break;
		}
		case 0:
		{
				  exit(0);
		}
		}

	}
	return 0;
}
