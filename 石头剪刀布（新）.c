#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 3

struct user             /*ʹ�ýṹ�����ڴ洢��ҵ���Ϣ */
{
	long num;           /*�������ܴ��� */
	char name[20];      /*���ڴ洢��ҵ�����*/
	int count;
	int win;
	int draw;  
	int lost;
}stu[N];

/*�������� */
int menu();
void lianximoshi();
void duizhanmoshi(struct user *p);
void paihangbang(struct user *p);

void main()
{


	int chose=0;

	printf ("       |********************************************|\n");
	printf ("       |              ��ӭ����                      |\n");
	printf ("       |         ʯͷ�������˻���ս                 |\n");
	printf ("       |            ��׼����ô��                    |\n");
	printf ("       |            ���ڿ쿪ʼ��!                   |\n");
	printf ("       |********************************************|\n");

	while(1)
	{
		chose=menu();
		if(chose==4)
			break;
		switch(chose)
		{
		case 1:lianximoshi();
			break;
		case 2:duizhanmoshi(stu);
			break;
		case 3:paihangbang(stu);
			break;
		default:printf(" #������ѡ��ģʽ!#\n");
			break;
		}
	}
}

void lianximoshi()
{
	int a=0,b=0,num1,num2,i,draw=0,win=0,lose=0,sum=0;
	srand(time(0));
	printf("������1,2,3��           1����ʯͷ��2���������3����   \n");
	for(i=1;i<=5;i++)
	{
		scanf("%d",&num1);
		num2=rand()%3;
		printf("%d",num2);
		if(num1==num2)
		{
			printf(" * ����ʤ�� *\n");
		    draw=draw+1;
		}
		else if(num1==1&&num2==2)
		{
		    printf(" * ��ϲ�㣬��Ӯ�ˣ� * \n");
		    a++;
			win=win+1;	
		}
		else if(num1==2&&num2==3)
		{
			printf(" * ��ϲ�㣬��Ӯ�ˣ� * \n");
			a++;
			win=win+1;	
		}
		else if(num1==3&&num2==1)
		{
			printf(" * ��ϲ�㣬��Ӯ�ˣ� * \n");
			a++;
			win=win+1;	
		}
		else 
		{
			printf(" * ���ź��������ˣ� * \n");
			b++;
			lose=lose+1;
		}
		sum=win+lose+draw;
		if(a==3||b==3)
			break;
	}
	printf("                       +++++++++++++++++++++++\n");
    printf("                       +  win=%d              +\n",win);
    printf("                       +  lose=%d             +\n",lose);
    printf("                       +  draw=%d             +\n",draw);
    printf("                       +  ���ܹ�����%d��      +\n",sum);
    printf("                       +++++++++++++++++++++++\n");
    printf("                           ��Ϸ���� ��������������\n"); 

	if(a>b)
		printf("                * ��ϲ���������յ�ʤ�� *\n");
	else if(a==b)
		printf("                * û�뵽�����û�ֳ�ʤ�� *\n");
	else
		printf("           * �����ɣ�����������㻹��Ҫ�������ң� *\n");
}
int menu()
{
	int i;

    printf("                             \n");
    printf("                             \n");
	printf("                        [��ѡ��ģʽ]\n");
	printf("              1.��ϰģʽ 2.��սģʽ 3.�鿴��Ϸ���а� 4.�˳�\n");
    scanf("%d",&i);
	return i;
}
/*˵���������*/
void shouming()
{
	int i;
    for(i=0;i<50;i++)
		putchar('*');
	printf("\n1-���������2-����ʯͷ��3-����,0-�˳�����\n");
	for(i=0;i<50;i++)
		putchar('*');
	printf("\n");
}

	/*�����û�����*/
int scan_data()
{
	int get;
	printf("\n���������ʯͷ����");		
	while(1)
	{
		scanf("%d",&get);
			if(get>=0&&get<=3 )
				break;
			printf("����������������롣\n");
	}
	return get;
}

	/*�������*/
int computer()
{
	int i;
	switch(i=rand() % 3)
	{
	case 1:
		printf("���Գ����Ǽ�����");	
		break;
	case 2:
		printf("���Գ�����ʯͷ��");
		break;
	case 3:
		printf("���Գ����ǲ���");
		break;
	}
	return i;
}

void win_or_lose(int get,int i,int *win,int *lose,int *count){
	/*�ж�ʤ��*/
	switch(get-i)
	{
	case 0:
		printf("ƽ��.\n");
		++*count;
		break;
	case 1:
	case -2:
		printf("��ϲ����ʤ���ˣ�����.\n");
		++*win;
		++*count;
		break;
	case -1:
	case 2:
		printf("���ź��������ˣ�����.\n");
		++*lose;
		++*count;
		break;
	}
}

void duizhanmoshi(struct user *p)
{
	int get,i,count=0,win=0,lose=0;
	srand(time(0));
	shouming();
	while((win!=2)&&(lose!=2)){
	get=scan_data();
	i=computer();
	win_or_lose(get,i,&win,&lose,&count);
	}
	printf("ʤ����%d��\tʧ�ܣ�%d��\t��������%d��\n",win,lose,count);
	if(win==2) {printf("You win! \n");}
	else {printf("Sorry,you lose!!!\n");}
	printf("������������:");
	getchar();
	gets(stu[N].name);
	stu[N].win=win;
	stu[N].count=count;
	save_data(&stu[N]);
}
void practice()
{	
	int get,i,count=0,win=0,lose=0;
	srand(time(0));
	shouming();
	while(1){
	get=scan_data();
	if(get==0)
		break;
	i=computer();
	win_or_lose(get,i,&win,&lose,&count);
	}
	printf("ʤ����%d��\tʧ�ܣ�%d��\t��������%d��\n",win,lose,count);
}
void paihangbang(struct user *p)
{
	int c,d,e;
	struct user temporary;
	for(c=0;c<N-1;c++)			//�����㷨
		{
			e=c;
			for(d=c+1;d<N;d++)
			{
				if(p[e].draw<p[d].draw)
					e=d;
			}
			temporary = p[c];
			p[c] = p[e];
			p[e] = temporary;
		}
		for(c=0;c<N;c++)
		{
			printf("%d%s\n",p[c].num,p[c].name);
		}
}