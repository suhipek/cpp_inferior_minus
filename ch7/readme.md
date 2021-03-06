这章的代码全是PE

# C++ 第七章作业

## C++ 第七章作业一（类和对象）

[a.cpp](./a.cpp)

### 题目描述
建立一个对象数组，内放4个学生的数据（学号 int、成绩 int），设立一个函数max()，用指向对象的指针作函数参数，在max函数中找出4个学生中成绩最高者，并输出其学号和成绩。如有相同最高成绩，按学号从小到大的顺序输出所有符合的学号和成绩。

### 输入
输入8个整数：学号1 成绩1 学号2 成绩2… 用空格分隔。

### 输出
输出n行，n为最高成绩的数目，每行包含两个整数，为学号和对应的成绩。

### 样例输入
3 100 2 90 4 78 5 100

### 样例输出
3 100
5 100

## C++ 第七章作业三（链表）

[b.cpp](./b.cpp)

### 题目描述
编写程序，实现单向链表结构。为每个输入的素数创建新节点，并按照从小到大的顺序插入到链表中的适当位置。当输入非素数时，停止创建新节点并将链表内的内容从首至尾遍历输出。请注意，输出内容严格单增，即输出的元素不能重复。

### 输入
任意n个整数，彼此间用空格分隔，整数范围[-10000, 10000]，保证n ≤ 100。

### 输出
m个素数，并且保持严格单增（m ≤ n）

### 样例输入
23 5 37 31 17 5 23 28

### 样例输出
5 17 23 31 37

## C++ 第七章作业二（运算符重载）

[c.cpp](./c.cpp)

设计一个Rational类，进行带分数的运算。要求：
（1）包含两个整数成员变量表示分子和分母。
（2）包含一个对所声明对象初始化的构造函数。不提供参数时，构造函数应提供默认值。分数存放成简化形式，例如分数“2/4”应在对象中存放成分子1和分母2的形式。
（3）采用成员函数的方式重载加法、减法运算符，采用友元函数的方式重载乘法和除法运算符，实现如下功能：
a）两个Rational值相加，结果保存成简化形式并输出。
b）两个Rational值相减，结果保存成简化形式并输出。
c）两个Rational值相乘，结果保存成简化形式并输出。
d）两个Rational值相除，结果保存成简化形式并输出。
e）重载++运算符，实现对两个Rational值的自增操作，结果保存成简化形式并输出（1/2++的结果为3/2）。
f）声明两个类对象Rational R1，R2;重载赋值运算符”=”,使得操作”R1=R2”为将R2值分子和分母颠倒位置后，赋值给R1，并简化输出。（2/3 变为 3/2，如果分母是1，直接输出整数形式。）
g）重载输出运算符，按a/b形式打印Rational值，其中a为分子，b为分母。

### 输入
第一行输入一个整数n，代表运算指令的个数。接下来n行，每行代表一个运算指令，对于每一个运算指令：
第一个整数opt，表示这行运算指令的类型，若opt=1，则代表该行指令为一个加法指令；若opt=2，则代表该行指令为一个减法指令；若opt=3，则代表该行指令为一个乘法指令；若opt=4，则代表该行指令为一个除法指令；若opt=5，则代表该行指令为一个自增指令；若opt=6，则代表该行指令为一个求倒数指令。接下来，对于opt∈\[1,4\]，后接两个分数，格式形如”a1/b1 a2/b2”，表示指令的两个操作数；对于opt∈\[5,6\]，后接一个分数，格式形如”a/b”，表示指令的一个操作数。

### 输出
输出共n行，对于每一个运算指令，输出其运算的结果，格式形如”a/b”。
注意：如果运算结果为整数，直接输出整数形式。

### 数据范围：
1≤n≤50，输入中分子分母a,b均满足1≤a,b≤100，不保证输入分数为最简形式

### 样例输入：
6  
1 1/2 1/3  
2 1/2 1/3  
3 1/2 1/3  
4 1/2 1/3  
5 1/2  
6 1/2  

### 样例输出：
5/6  
1/6  
1/6
3/2
3/2
2