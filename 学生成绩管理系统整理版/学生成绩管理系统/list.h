#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct xscj
{
	int number;
	char name[10];
	int sco[6];
	int rank;
	float ave;
	float sum;
};
void Menu();
void Input_record();
void To_Ave_Course();
void To_Ave_student();
void Order_by_total_score();
void Ascending_Order_by_total_score();
void Ascending_Order_by_number();
void Sort_in_dictionary();
void Search_by_number();
void Search_by_name();
void Analysis_for_every_course();
void List_record();
void Write_To_A_file();
void Read_From_a_file();
int Judge();