#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 3

struct user             /*使用结构体用于存储玩家的信息 */
{
	long num;           /*玩家玩的总次数 */
	char name[20];      /*用于存储玩家的姓名*/
	int count;
	int win;
	int draw;  
	int lost;
}stu[N];

/*函数声明 */
int menu();
void lianximoshi();
void duizhanmoshi(struct user *p);
void paihangbang(struct user *p);

void main()
{


	int chose=0;

	printf ("       |********************************************|\n");
	printf ("       |              欢迎来到                      |\n");
	printf ("       |         石头剪刀布人机大战                 |\n");
	printf ("       |            你准备好么？                    |\n");
	printf ("       |            现在快开始吧!                   |\n");
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
		default:printf(" #请重新选择模式!#\n");
			break;
		}
	}
}

void lianximoshi()
{
	int a=0,b=0,num1,num2,i,draw=0,win=0,lose=0,sum=0;
	srand(time(0));
	printf("请输入1,2,3。           1代表石头，2代表剪刀，3代表布   \n");
	for(i=1;i<=5;i++)
	{
		scanf("%d",&num1);
		num2=rand()%3;
		printf("%d",num2);
		if(num1==num2)
		{
			printf(" * 不分胜负 *\n");
		    draw=draw+1;
		}
		else if(num1==1&&num2==2)
		{
		    printf(" * 恭喜你，你赢了！ * \n");
		    a++;
			win=win+1;	
		}
		else if(num1==2&&num2==3)
		{
			printf(" * 恭喜你，你赢了！ * \n");
			a++;
			win=win+1;	
		}
		else if(num1==3&&num2==1)
		{
			printf(" * 恭喜你，你赢了！ * \n");
			a++;
			win=win+1;	
		}
		else 
		{
			printf(" * 很遗憾，你输了！ * \n");
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
    printf("                       +  你总共玩了%d盘      +\n",sum);
    printf("                       +++++++++++++++++++++++\n");
    printf("                           游戏结束 ！！！！！！！\n"); 

	if(a>b)
		printf("                * 恭喜你获得了最终的胜利 *\n");
	else if(a==b)
		printf("                * 没想到最后还是没分出胜负 *\n");
	else
		printf("           * 颤抖吧，渣渣，最后你还是要臣服于我！ *\n");
}
int menu()
{
	int i;

    printf("                             \n");
    printf("                             \n");
	printf("                        [请选择模式]\n");
	printf("              1.练习模式 2.对战模式 3.查看游戏排行榜 4.退出\n");
    scanf("%d",&i);
	return i;
}
/*说明如何输入*/
void shouming()
{
	int i;
    for(i=0;i<50;i++)
		putchar('*');
	printf("\n1-代表剪刀，2-代表石头，3-代表布,0-退出比赛\n");
	for(i=0;i<50;i++)
		putchar('*');
	printf("\n");
}

	/*接收用户输入*/
int scan_data()
{
	int get;
	printf("\n请输入剪刀石头布：");		
	while(1)
	{
		scanf("%d",&get);
			if(get>=0&&get<=3 )
				break;
			printf("输入错误，请重新输入。\n");
	}
	return get;
}

	/*电脑输出*/
int computer()
{
	int i;
	switch(i=rand() % 3)
	{
	case 1:
		printf("电脑出的是剪刀。");	
		break;
	case 2:
		printf("电脑出的是石头。");
		break;
	case 3:
		printf("电脑出的是布。");
		break;
	}
	return i;
}

void win_or_lose(int get,int i,int *win,int *lose,int *count){
	/*判断胜负*/
	switch(get-i)
	{
	case 0:
		printf("平局.\n");
		++*count;
		break;
	case 1:
	case -2:
		printf("恭喜，你胜利了！！！.\n");
		++*win;
		++*count;
		break;
	case -1:
	case 2:
		printf("很遗憾，你输了！！！.\n");
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
	printf("胜利：%d盘\t失败：%d盘\t总盘数：%d盘\n",win,lose,count);
	if(win==2) {printf("You win! \n");}
	else {printf("Sorry,you lose!!!\n");}
	printf("大侠，请留名:");
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
	printf("胜利：%d盘\t失败：%d盘\t总盘数：%d盘\n",win,lose,count);
}
void paihangbang(struct user *p)
{
	int c,d,e;
	struct user temporary;
	for(c=0;c<N-1;c++)			//排序算法
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