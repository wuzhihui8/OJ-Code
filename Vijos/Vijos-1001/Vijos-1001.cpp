#include <iostream>

using namespace std;

int n; //1 <= N <= 100
struct Stu
{
	char name[22];
	int average;
	int class_score;
	char is_officer;
	char is_west;
	int paper_count;
} stu[102];

int main()
{
	//freopen("input.txt", "r", stdin);
	
	scanf("%d", &n);
	getchar();
	
	for(int i = 0; i < n; ++i)
	{
		scanf("%s %d %d %c %c %d", &stu[i].name, &stu[i].average, &stu[i].class_score, &stu[i].is_officer, &stu[i].is_west, &stu[i].paper_count);
	}
	
//	for(int i = 0; i < n; ++i)
//	{
//		printf("stu[%d]:%s,%d,%d,%c,%c,%d\n", i, stu[i].name, stu[i].average, stu[i].class_score, stu[i].is_officer, stu[i].is_west, stu[i].paper_count);
//	}


	int max_sum = 0, max_idx, sum_all = 0;
	for(int i = 0; i < n; ++i)
	{
		int sum = 0;
		
		//Ժʿ��ѧ��ÿ��8000Ԫ����ĩƽ���ɼ�����80�֣�>80���������ڱ�ѧ���ڷ���1ƪ��1ƪ�������ĵ�ѧ�����ɻ�ã�
		if(stu[i].average > 80 && stu[i].paper_count >= 1) sum += 8000;
		
		//���Ľ�ѧ��ÿ��4000Ԫ����ĩƽ���ɼ�����85�֣�>85�������Ұ༶����ɼ�����80�֣�>80����ѧ�����ɻ�ã�
		if(stu[i].average > 85 && stu[i].class_score > 80) sum += 4000;
		
		// �ɼ����㽱��ÿ��2000Ԫ����ĩƽ���ɼ�����90�֣�>90����ѧ�����ɻ�ã�
		if(stu[i].average > 90) sum += 2000;
		
		// ������ѧ��ÿ��1000Ԫ����ĩƽ���ɼ�����85�֣�>85��������ʡ��ѧ�����ɻ�ã�
		if(stu[i].is_west == 'Y' && stu[i].average > 85) sum += 1000;
		
		//�༶���׽���ÿ��850Ԫ���༶����ɼ�����80�֣�>80����ѧ���ɲ����ɻ�ã�
		if(stu[i].is_officer == 'Y' && stu[i].class_score > 80) sum += 850;
		
		sum_all += sum;
		if(max_sum < sum)
		{
			max_sum = sum;
			max_idx = i;	
		} 
	}
	
	printf("%s\n%d\n%d\n", stu[max_idx].name, max_sum, sum_all);
	
	//fclose(stdin);
	
	return 0;
}
