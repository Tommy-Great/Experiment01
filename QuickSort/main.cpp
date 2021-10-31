/*
 * main.cpp
 *
 *  Created on: 2021年10月23日
 *      Author: windows
 */

#include"QSort.h"
#include"Bond.h"
#include<iostream>
#include<ctime>
using namespace std;
//对于随机的队列其实RDSort和Sort没啥区别·
//因为此时Sort的选r-1就是一种随机
//二者的区别主要体现在对于一些固定的恶劣情况
//如已经排好序之后,RDSort远远快于Sort
//当时复制的时候，忘记改了！！变成rdqsort里面用qsort递归


int main(){

	int n=20000;
//	cout<<"Enter the number of elements:";
//	cin>>n;
	Array<Bond> A(n),B(A);
	clock_t start1,end1,end2;
	//A.RDQSort();
	start1=clock();
	A.QSort();
	end1=clock();
	B.RDQSort();
	end2=clock();
	cout<<"QSort:"<<end1-start1<<" ms"<<endl;
	cout<<"RDQSort:"<<end2-end1<<" ms"<<endl;



}


