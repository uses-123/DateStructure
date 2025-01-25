/*
	一个陷入迷宫的老鼠如何找到出口的问题。老鼠希望系统性地尝试所有的路径之后走出迷宫.
	如果它到达一个死胡同，将原路返回到上一个位置，尝试新的路径.
	在每个位置上老鼠可以向八个方向运动，顺序是从正东开始按照顺时针进行.
	无论离出口多远，它总是按照这样的顺序尝试，当到达一个死胡同之后，老鼠将进行"回溯".
	迷宫只有一个入口，一个出口，设计程序要求输出迷宫的一条通路。迷宫用二维存储结构表示 
	1表示障碍，0表示通路；采用回溯法设计求解通路的算法。要求如下:
    1、实现栈的相关操作；
    2、利用栈实现回溯算法输出路径；
	输入格式:
	输入包括三部分：
	第一个输入是迷宫大小；第二个输入是迷宫的状态；第三个输入是入口和出口位置
	输出格式:
	反向输出探索的路径，注意包括入口和出口位置。每个位置之间用分号;分隔。
	输入样例:
9
1 1 1 1 1 1 1 1 1
1 0 0 1 1 0 1 1 1
1 1 0 0 0 0 0 0 1
1 0 1 0 0 1 1 1 1
1 0 1 1 1 0 0 1 1
1 1 0 0 1 0 0 0 1
1 0 1 1 0 0 0 1 1
1 1 1 1 1 1 1 0 1
1 1 1 1 1 1 1 1 1
1 1 7 7 
     输出样例:
     7 7;6 6;5 7;4 6;4 5;3 4;2 5;2 4;2 3;1 2;1 1;
*/
#include<stdio.h> // 包含标准输入输出头文件
#include<stdlib.h> // 包含标准库头文件
#include<iostream> // 包含输入输出流头文件
#include<stack> // 包含栈头文件
 
#define size 100 // 定义数组大小为100
int land[size][size] = { 0 }; // 定义一个地图数组并初始化为0
using namespace std; // 使用命名空间std
 
typedef struct point { // 定义一个结构体point
	int y; // 表示y坐标
	int x; // 表示x坐标
}Node; // 结构体重命名为Node
// 定义一个二维数组表示8个方向的移动
int help[8][2] = { {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}}; 
 
// 定义一个函数用于查找可行路径
bool find_way(int cur_y, int cur_x, int* xx, int* yy, int n)
{
	for (int i = 0; i < 8; i++) // 遍历8个方向
	{
		*yy = cur_y + help[i][0]; // 更新y坐标
		*xx = cur_x + help[i][1]; // 更新x坐标
		if (*xx < n && *xx >= 0 && *yy < n && *yy >= 0) // 判断是否在地图范围内
		{
			if (land[*yy][*xx] == 0) // 判断是否为可行路径
			{
				return true; // 返回true
			}
			
		}
	}
	return false; // 返回false
}
 
int main() // 主函数
{
	int n; // 定义变量n
	scanf("%d\n", &n); // 输入n的值
	
	for (int i = 0; i < n; i++) // 遍历地图数组
	{
		for (int j = 0; j < n; j++) // 遍历地图数组
		{
			scanf("%d", &land[i][j]); // 输入地图值
 
		}
		scanf("\n"); // 输入换行符
 
	}
	int s_y, s_x, e_y, e_x; // 定义起点和终点坐标
	scanf("%d %d %d %d", &s_y, &s_x, &e_y, &e_x); // 输入起点和终点坐标
	int cur_x, cur_y; // 定义当前坐标
	int xx, yy; // 定义新坐标
	stack<Node>s; // 定义一个栈存放节点
	Node t_node; // 定义一个节点
	t_node.y = s_y; // 节点y坐标赋值
	t_node.x = s_x; // 节点x坐标赋值
	s.push(t_node); // 将节点压入栈
	land[s_y][s_x] = 1; // 标记起点为已访问
	while (!s.empty()) // 当栈不为空时循环
	{
		cur_y = s.top().y; // 获取栈顶y坐标
		cur_x = s.top().x; // 获取栈顶x坐标
		if (find_way(cur_y, cur_x, &xx, &yy, n)) // 调用函数查找可行路径
		{
			t_node.y = yy; // 更新节点y坐标
			t_node.x = xx; // 更新节点x坐标
			land[yy][xx] = 1; // 标记新节点为已访问
			s.push(t_node); // 将新节点压入栈
			if (xx == e_x && yy == e_y) // 如果到达终点
			{
				break; // 跳出循环
			}
		}
		else {
			land[s.top().y][s.top().x] = 1; // 标记当前节点为已访问
			s.pop(); // 弹出栈顶元素
			
		}
	}
 
	while (!s.empty()) // 当栈不为空时循环
	{
		
		printf("%d %d;", s.top().y, s.top().x); // 输出路径坐标
		s.pop(); // 弹出栈顶元素
	}
	
	return 0; // 返回0表示正常结束
}
