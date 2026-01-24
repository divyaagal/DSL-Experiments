#include<iostream>
using namespace std;
int main() {
	int a[2][2],b[2][2],c[2][2];
	int choice;
	int i,j,k;
	float det;
	cout<<"Enter first matrix:";
	for(i=0;i<2;i++) {
	for(j=0;j<2;j++) {
		cin>>a[i][j];
		}
	}
	cout<<"Enter second matrix:";
	for(i=0;i<2;i++) {
	for(j=0;j<2;j++) {
		cin>>b[i][j];
		}
	}
	cout<<"1.Addition \n";
	cout<<"2.Subtraction \n";
	cout<<"3.Multiplication \n";
	cout<<"4.Transpose first matrix \n";
	cout<<"5.Transpose second matrix \n";
	cout<<"6.Inverse first matrix\n";
	cout<<"Enter your choice:";
	cin>>choice;
	switch(choice)
	{
	case 1:
		cout<<"Matrix Addition:\n";
		for(i=0;i<2;i++) {
		for(j=0;j<2;j++) {
		c[i][j]=a[i][j]+b[i][j];
		cout<<c[i][j]<<" ";
		}
		cout<<endl;
		}
		break;
	case 2:
		cout<<"Matrix Subtraction:\n";
		for(i=0;i<2;i++) {
		for(j=0;j<2;j++) {
		c[i][j]=a[i][j]-b[i][j];
		cout<<c[i][j]<<" ";
		}
		cout<<endl;
		}
		break;	
	case 3:
		cout<<"Matrix Multiplication:\n";
		for(i=0;i<2;i++) {
		for(j=0;j<2;j++) {
		c[i][j]=0;
		for(k=0;k<2;k++) {
		c[i][j]+=a[i][k]*b[k][j];
		}
		cout<<c[i][j]<<" ";
		}
		cout<<endl;
		}
	break;
	case 4:
		cout<<"Transpose First Matrix:\n";
		for(i=0;i<2;i++) {
		for(j=0;j<2;j++) {
		cout<<a[j][i]<<" ";
		}
		cout<<endl;
		}
	break;
	case 5:
		cout<<"Transpose Second Matrix:\n";
		for(i=0;i<2;i++) {
		for(j=0;j<2;j++) {
		cout<<b[j][i]<<" ";
		}
		cout<<endl;
		}
		break;	
		case 6:
		det=(a[0][0]*a[1][1])-(a[0][1]*a[1][0]);
		if(det==0) {
		cout<<"inverse doesn't exist:\n";
		} else {
			cout<<"Inverse of first matrix:\n";
			cout<<a[1][1]/det<<" "<<-a[0][1]/det<<endl;
			cout<<-a[1][0]/det<<" "<<a[0][0]/det<<endl;
			}	
	break;
	default:
		cout<<"Invalid Choice:";		    
	}
	return 0;
}