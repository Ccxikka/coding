/*
题目：
在漆黑的夜里，四位旅行者来到了一座狭窄而且没有护栏的桥边。如果不借助手电筒的话，大家是无论如何也不敢过桥去的。
不幸的是，四个人一共只带了一只手电筒，而桥窄得只够让两个人同时通过。如果各自单独过桥的话，四人所需要的时间分别是1，2，5，8分钟；
而如果两人同时过桥，所需要的时间就是走得比较慢的那个人单独行动时所需的时间。
问题是，你如何设计一个方案，让用的时间最少。

解析如下：用时短的人必须要多跑几趟以便传递手电筒。
设这四个人叫做A，B，C，D，他们所需要的时间分别是1，2，5，8分钟。
第一步：A和B过桥，花费2分钟。
第二步：A回来，花费1分钟。
第三步：C和D过桥，花费8分钟。
第四步：B回来，花费2分钟。
第五步：A和B过桥，花费2分钟。
这样只要花费2+1+8+2+2=15分钟，假设A，B，C，D四个人所需要的时间分别是1，8，9，10分钟。
方案一
第一步：A和B过桥，花费8分钟。
第二步：A回来，花费1分钟。
第三步：C和D过桥，花费10分钟。
第四步：B回来，花费8分钟。
第五步：A和B过桥，花费8分钟。
一共要8+1+10+8+8=35分钟。
方案二
第一步：A和B过桥，花费8分钟。
第二步：A回来，花费1分钟。
第三步：A和C过桥，花费9分钟。
第四步：A回来，花费1分钟。
第五步：A和D过桥，花费10分钟。
一共要8+1+9+1+10=29分钟。
因此可以得出更加细化的解决方案——要么是最快者将最慢的2个送过桥，要么是最快的2个将最慢的2个送过桥。即将过桥的人按其过桥的时间从小到大排列，设为A，B，……Y，Z。其中A和B是最快的二个，Y和Z是最慢的二个。那么就有二种方案：
方案一 最快者将最慢的2个送过桥
第一步：A和Z过桥，花费Z分钟。
第二步：A回来，花费A分钟。
第三步：A和Y过桥，花费Y分钟。
第四步：A回来，花费A分钟。
这四步后总人数就减小2个，花费时间为A + A + Y + Z分钟。
方案二 最快的2个将最慢的2个送过桥
第一步：A和B过桥，花费B分钟。
第二步：A回来，花费A分钟。
第三步：Y和Z过桥，花费Z分钟。
第四步：B回来，花费B分钟。
这四步后总人数同样减小2个，花费时间为A + B + B + Z分钟。
这样，每次比较一下这二种方案就能将总人数减小2。然后我们再考虑一些边界情况：
有三个人过桥设为A，B，C（已经排好序，下同）。应该花费A + B + C分钟。
有二个人过桥设为A，B。那么肯定是花费B分钟。
有一个人过桥设为A。肯定花费A分钟。
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int gettime(vector<int>& num)
{
    if (num.size() < 1)
        return 0;
    int end = num.size() - 1;
    sort(num.begin(), num.end());
    int begin = 0, time = 0;
    while (end - begin > 2)
    {
        int time1 = num[begin] * 2 + num[end] + num[end - 1];//最小一个的分别送两个最大的过去，最小的返回
        int time2 = num[begin] + num[begin + 1] * 2 + num[end];//两小送两大，两个大的一起过去,两个小的返回
        time = time1 < time2 ? time + time1 : time + time2;
        end = end - 2;
    }
    if (end-begin<=1)//只有一个人或者两个人，时间为长的那个
        time += num[end];
    else if (end-begin == 2)//三个人，最小的送两个大的
        time += num[begin] + num[begin + 1] + num[end];
    return time;
}
int main(int argc, char* argv[])
{
    vector<int> num{1,3,6,8,12};
    int time = gettime(num);
    cout << time << endl;

    return 0;
}
