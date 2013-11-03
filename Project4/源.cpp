#include<iostream>
#include<stdlib.h>
using namespace std;
struct Student{
	char name[10];
	char sex[6];
	long number;
	char major[30];
    int mark;
}students[160];
const int flag=0;
int find(long number);
void Input();
void Delete();
void List(){
	cout<<"-----学生信息-----"<<endl;
	cout<<"姓名\t"<<"性别\t"<<"学号\t"<<"专业\t"<<"C++成绩"<<endl;
	for(int i=0;i<160;i++){
		cout<<students[i].name<<"\t"<<students[i].sex<<"\t"<<students[i].number<<"\t"<<students[i].major<<students[i].mark<<endl;
	}
	cout<<"-----学生信息-----"<<endl;
}
void SelectCourse(){
	cout<<"-----选课-----"<<endl;
	struct Student student;
    cout<<"输入学生学号"<<endl;
	cin>>student.number;
	int index=find(student.number);
    if(index==flag){
		Input();
		cout<<"-----选课成功-----"<<endl;
	}
	else{
		cout<<"已选此门课程"<<endl;
	}
}
void DropCourse(){
	cout<<"-----退选-----"<<endl;
	struct Student student;
	cout<<"输入学生学号"<<endl;
	cin>>student.number;
	int index=find(student.number);
	if(index!=flag){
		Delete();
		cout<<"退选成功"<<endl;
	}
	else{
		cout<<"没有选此课程"<<endl;
	}
}
void TypeInMark(){
	cout<<"-----录入成绩-----"<<endl;
	do{
	cout<<"录入哪位学生的成绩（请输入学号）"<<endl;
	int k,mark;
	long i;
	cin>>i;
	for(int j=0;j<160;j++){
		if(i==students[j].number){
			cout<<"请输入成绩"<<endl;
			cin>>mark;
			students[j].mark=mark;
			break;
		}
		else{
			cout<<"没有这位学生"<<endl;
		}
	}
	cout<<"是否继续"<<endl;
	cout<<"是请输入1，否请输入0"<<endl;
	cin>>k;
	if(k==0){
		break;
	}
	}while(1);
	cout<<"录入成功"<<endl;
}
int find(long number){
	int i;
	for(i=0;i<160;i++){
		if(students[i].number==number){
			break;
		}
	}
	if(i==160){
		i=0;
	}
	return i;
}
int Count=0;
void Input(){
	if(Count<160){
	cout<<"请输入学号"<<endl;
	cin>>students[Count].number;
	cout<<"性别"<<endl;
	cin>>students[Count].sex;
	cout<<"姓名"<<endl;
	cin>>students[Count].name;
	cout<<"专业"<<endl;
	cin>>students[Count].major;
	Count++;
	}
	else{
		cout<<"选课人数已满"<<endl;
	}
}
void Delete(){
	long i;
	cout<<"输入该生学号"<<endl;
	cin>>i;
	if(Count>=0){
	for(int j=0;j<160;j++){
		if(i==students[j].number){
			for(;j<160;j++){
				students[j].number=students[j+1].number;
				strcpy(students[j].sex,students[j+1].sex);
				strcpy(students[j].name,students[j+1].name);
				strcpy(students[j].major,students[j+1].major);
				students[j].mark=students[j+1].mark;
			}
			Count--;
			break;
		}
		else{
			cout<<"没有这位学生"<<endl;
		}
	}
	}
	else{
		cout<<"已经没有学生了"<<endl;
	}
}
int main(){
	char action;
	do{
		cout<<"\t\t\tC++考试成绩管理"<<endl;
	    cout<<"(1)查看学生名字"<<endl;
	    cout<<"(2)选课"<<endl;
	    cout<<"(3)退选"<<endl;
	    cout<<"(4)录入成绩"<<endl;
	    cout<<"(5)退出程序"<<endl;
	    cin>>action;
		switch((int)action-48){
		case 1:
			List();
			break;
		case 2:
			SelectCourse();
			break;
		case 3:
			DropCourse();
			break;
		case 4:
			TypeInMark();
			break;
		case 5:
			return 0;
		default:
			cout<<"输入错误"<<endl;
       }
	}while(1);
}