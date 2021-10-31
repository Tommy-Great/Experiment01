/*
 * Bond.h
 *
 *  Created on: 2021年10月23日
 *      Author: windows
 */

#ifndef BOND_H_
#define BOND_H_


#include<iostream>


class Bond{
	int key;
	int value;

public:
	Bond(){
		key=rand()%100;
		value=rand()%10000;
	}
	Bond(int x){
		key=x;
		value=rand()%10000;
	}
	Bond(int x,int y){
		key=x;
		value=y;
	}
	Bond(const Bond&B){
		key=B.key;
		value=B.value;
	}

	Bond& operator=(const Bond& B){
		key=B.key;
		value=B.value;
		return *this;
	}

	friend bool operator<(const Bond&B1,const Bond&B2){
		return B1.key<B2.key;
	}
	friend bool operator>=(const Bond&B1,const Bond&B2){
		return !(B1<B2);
	}
	friend bool operator>(const Bond&B1,const Bond&B2){
		return B1.key>B2.key;
	}
	friend bool operator<=(const Bond&B1,const Bond&B2){
		return !(B1>B2);
	}
	friend bool operator==(const Bond&B1,const Bond&B2){
		return B1.key==B2.key;
	}


	friend std::ostream& operator<<(std::ostream& os,const Bond& B){
		os<<B.value<<"["<<B.key<<"] ";
		return os;
	}

};




#endif /* BOND_H_ */
