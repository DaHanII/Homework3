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
	cout<<"-----ѧ����Ϣ-----"<<endl;
	cout<<"����\t"<<"�Ա�\t"<<"ѧ��\t"<<"רҵ\t"<<"C++�ɼ�"<<endl;
	for(int i=0;i<160;i++){
		cout<<students[i].name<<"\t"<<students[i].sex<<"\t"<<students[i].number<<"\t"<<students[i].major<<students[i].mark<<endl;
	}
	cout<<"-----ѧ����Ϣ-----"<<endl;
}
void SelectCourse(){
	cout<<"-----ѡ��-----"<<endl;
	struct Student student;
    cout<<"����ѧ��ѧ��"<<endl;
	cin>>student.number;
	int index=find(student.number);
    if(index==flag){
		Input();
		cout<<"-----ѡ�γɹ�-----"<<endl;
	}
	else{
		cout<<"��ѡ���ſγ�"<<endl;
	}
}
void DropCourse(){
	cout<<"-----��ѡ-----"<<endl;
	struct Student student;
	cout<<"����ѧ��ѧ��"<<endl;
	cin>>student.number;
	int index=find(student.number);
	if(index!=flag){
		Delete();
		cout<<"��ѡ�ɹ�"<<endl;
	}
	else{
		cout<<"û��ѡ�˿γ�"<<endl;
	}
}
void TypeInMark(){
	cout<<"-----¼��ɼ�-----"<<endl;
	do{
	cout<<"¼����λѧ���ĳɼ���������ѧ�ţ�"<<endl;
	int k,mark;
	long i;
	cin>>i;
	for(int j=0;j<160;j++){
		if(i==students[j].number){
			cout<<"������ɼ�"<<endl;
			cin>>mark;
			students[j].mark=mark;
			break;
		}
		else{
			cout<<"û����λѧ��"<<endl;
		}
	}
	cout<<"�Ƿ����"<<endl;
	cout<<"��������1����������0"<<endl;
	cin>>k;
	if(k==0){
		break;
	}
	}while(1);
	cout<<"¼��ɹ�"<<endl;
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
	cout<<"������ѧ��"<<endl;
	cin>>students[Count].number;
	cout<<"�Ա�"<<endl;
	cin>>students[Count].sex;
	cout<<"����"<<endl;
	cin>>students[Count].name;
	cout<<"רҵ"<<endl;
	cin>>students[Count].major;
	Count++;
	}
	else{
		cout<<"ѡ����������"<<endl;
	}
}
void Delete(){
	long i;
	cout<<"�������ѧ��"<<endl;
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
			cout<<"û����λѧ��"<<endl;
		}
	}
	}
	else{
		cout<<"�Ѿ�û��ѧ����"<<endl;
	}
}
int main(){
	char action;
	do{
		cout<<"\t\t\tC++���Գɼ�����"<<endl;
	    cout<<"(1)�鿴ѧ������"<<endl;
	    cout<<"(2)ѡ��"<<endl;
	    cout<<"(3)��ѡ"<<endl;
	    cout<<"(4)¼��ɼ�"<<endl;
	    cout<<"(5)�˳�����"<<endl;
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
			cout<<"�������"<<endl;
       }
	}while(1);
}