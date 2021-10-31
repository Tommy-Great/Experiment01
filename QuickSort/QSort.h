/*
 * QSort.h
 *
 *  Created on: 2021年10月23日
 *      Author: windows
 */

#ifndef QSORT_H_
#define QSORT_H_

#include<iostream>
#include<ctime>
#include<cassert>


template<class T>
class Array{
	int len;
	T* store;

	//The range is[p,r) !!
	void qsort(int p,int r){
		assert(r-p>=0);
		if(r-p==1||r-p==0)return;
		else{
			int q=partition(p,r);
			qsort(p,q);
			qsort(q+1,r);
		}
	}
	void rdqsort(int p,int r){
		assert(r-p>=0);
		if(r-p==1||r-p==0)return;
		else{
			int q=randpartition(p,r);
			rdqsort(p,q);
			rdqsort(q+1,r);
		}
	}
	void exchange(int i,int j){
		T temp=store[i];
		store[i]=store[j];
		store[j]=temp;
	}
	int partition(int p,int r){
		assert(r-p>1);
		int tail=p;
		T pivot=store[r-1];
		for(int i=p;i<r-1;i++){
			if(store[i]<pivot){
				exchange(tail,i);
				tail++;
			}
		}
		exchange(tail,r-1);
		return tail;
	}
	int randpartition(int p,int r){
		int q=(rand()*1000+rand())%(r-p)+p;
		exchange(q,r-1);
		return partition(p,r);
	}

public:
	Array(int n):len(n){
		store=new T[len];
		srand(time(0));
		for(int i=0;i<len;i++){
			store[i]=T((rand()*10000+rand())%10000000);
		}
		std::cout<<"store:"<<std::endl;
		//Show();
	}

	Array(const Array& A){
		len=A.len;
		store=new T[len];
		srand(time(0));
		for(int i=0;i<len;i++){
			store[i]=A.store[i];
		}
		std::cout<<"storeCpy:"<<std::endl;
		//Show();
	}
	void Show(){
		for(int i=0;i<len;i++){
			if(!(i%100)&&i)std::cout<<std::endl;
			std::cout<<store[i]<<" ";
		}
		std::cout<<std::endl;
	}

	void QSort(){
		qsort(0,len);
		std::cout<<"QSort:"<<std::endl;
		//Show();
	}
	void RDQSort(){
		rdqsort(0,len);
		std::cout<<"RDQSort:"<<std::endl;
		//Show();
	}

};

















#endif /* QSORT_H_ */
