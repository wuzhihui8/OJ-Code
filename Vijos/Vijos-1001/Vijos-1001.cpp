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
		
		//院士奖学金，每人8000元，期末平均成绩高于80分（>80），并且在本学期内发表1篇或1篇以上论文的学生均可获得；
		if(stu[i].average > 80 && stu[i].paper_count >= 1) sum += 8000;
		
		//五四奖学金，每人4000元，期末平均成绩高于85分（>85），并且班级评议成绩高于80分（>80）的学生均可获得；
		if(stu[i].average > 85 && stu[i].class_score > 80) sum += 4000;
		
		// 成绩优秀奖，每人2000元，期末平均成绩高于90分（>90）的学生均可获得；
		if(stu[i].average > 90) sum += 2000;
		
		// 西部奖学金，每人1000元，期末平均成绩高于85分（>85）的西部省份学生均可获得；
		if(stu[i].is_west == 'Y' && stu[i].average > 85) sum += 1000;
		
		//班级贡献奖，每人850元，班级评议成绩高于80分（>80）的学生干部均可获得；
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
