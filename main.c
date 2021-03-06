//A170 shreyash
// Assignment 3
//Implement a sparse matrix with operations like initialize empty sparse matrix, insert an element, add two matrices, transpose a matrix.

#include <stdio.h>

void display(int v,int sp_mat[20][20],int rcv[3])
 {
 int i,j;
 printf("R:%d\t C:%d\t V:%d\n",rcv[0],rcv[1],rcv[2]);
 for(i=0;i<v;i++)
 {

 for(j=0;j<3;j++)
 {
 printf("%d\t\t",sp_mat[i][j]);
 }
 printf("\n");
 }
}
void get_mat(int sp_mat[20][20],int choice,int rcv[3])
{
 int i,j,k;
 int r,c,v;
 printf("\nenter no of rows,columns and non-zero values:\n");
 scanf("%d %d %d",&r,&c,&v);
 rcv[0]=r;
 rcv[1]=c;
 rcv[2]=v;
 for(i=0;i<v;i++)
 {
 printf("\nValue of row number,column number &value:\n");
 scanf("%d %d %d",&sp_mat[i][0],&sp_mat[i][1],&sp_mat[i][2]);
 }

printf("\n");
if(choice==1)
{
 display(v,sp_mat,rcv);
}
}
void add(int choice,int m1[20][20],int m2[20][20])
{
 int rcv1[3],rcv2[3];
 get_mat(m1,choice,rcv1);
 get_mat(m2,choice,rcv2);
int i,j,k;
int c[20][20];
 for(i=0,j=0,k=0;i<rcv1[2] && j<rcv2[2];k++)
 {
 if(m1[i][0]<m2[j][0]) //comparing row
 {
 c[k][0]=m1[i][0];
 c[k][1]=m1[i][1];
 c[k][2]=m1[i][2];
 i++;
 }
 else if(m1[i][0]>m2[j][0]) // comparing row
 {
 c[k][0]=m2[j][0];
 c[k][1]=m2[j][1];
 c[k][2]=m2[j][2];
 j++;
 }
 else if(m1[i][1]<m2[j][1]) //comparing column
 {
 c[k][0]=m1[i][0];
 c[k][1]=m1[i][1];
 c[k][2]=m1[i][2];
 i++;
 }
 else if(m1[i][1]>m2[j][1])
 {
 c[k][0]=m2[j][0];
 c[k][1]=m2[j][1];
 c[k][2]=m2[j][2];
 j++;
 }
 else
 {
 c[k][0]=m1[i][0];
 c[k][1]=m1[i][1];
 c[k][2]=m1[i][2]+m2[j][2];
 i++;
 j++;
 }
 }
 while(i<rcv1[2])
 {
 c[k][0]=m1[i][0];
 c[k][1]=m1[i][1];
 c[k][2]=m1[i][2];
 k++;
 i++;
 }
 while(j<rcv2[2])
 {
 c[k][0]=m2[j][0];
 c[k][1]=m2[j][1];
 c[k][2]=m2[j][2];
 j++;
 k++;
 }

 printf("ADDITION");
 for(i=0;i<k;i++)
 {
 printf("\n%d\t%d\t%d",c[i][0],c[i][1],c[i][2]);

 }
 
  void trans()

 int transpose[10][10],sp_mat3[10][10];
  i,j=0,k;
 int r,c,v,ch;
 int rcv[3];
 printf("\nenter no of rows,columns and non-zero values:\n");
 scanf("%d %d %d",&r,&c,&v);
 rcv[0]=r;
 rcv[1]=c;
 rcv[2]=v;
 for(i=0;i<v;i++)
 {
 printf("\nEnter row,column index and value:\n");
 scanf("%d %d %d",&sp_mat3[i][0],&sp_mat3[i][1],&sp_mat3[i][2]);
 }
 printf("1)simple transpose 2)fast transpose:\n");
 scanf("%d",&ch);
 if(ch==1){
 for(k=0;k<c;k++)
 {
 for(i=0;i<v;i++)
 {
 if(sp_mat3[i][1]==k)
 {
 transpose[j][0]=sp_mat3[i][1];
 transpose[j][1]=sp_mat3[i][0];
 transpose[j][2]=sp_mat3[i][2];
 j++;
 }
 }
 }
 }
 else if(ch==2)
 {
 //FAST TRANSPOSE
 int col;

 int total[c],index[c+1];


 for(i=0;i<c;i++)
 {
 total[i]=0;
 }
 for(i=0;i<v;i++)
 {
 printf("b");
 col= sp_mat3[i][1];
 total[col]++;
 }
 for(i=0;i<c;i++)
 {printf("total\n");
 printf("%d",total[i]);
 }
 index[0]=1;

 for(i=1;i<=c;i++)
 {printf("t");
 index[i] = index[i-1]+total[i-1];
 }
 for(i=0;i<c+1;i++)
 {printf("INDEX\n");
 printf("%d",index[i]);
 }
 for(i=0;i<v;i++)
 {

 col=sp_mat3[i][1];
 int p=index[col];
 transpose[p][0]=sp_mat3[i][1];
 transpose[p][1]=sp_mat3[i][0];
 transpose[p][2]=sp_mat3[i][2];
 index[col]++;

 }
 printf("mat");
 for(i=0;i<v;i++)
 {
 printf("\n%d %d %d\n",transpose[i][0],transpose[i][1],transpose[i][2]);
 }
 }
 printf("\nAcutal Matrix:\n");
 printf("%d\t\t%d\t\t%d\n",rcv[0],rcv[1],rcv[2]);
 for(i=0;i<v;i++)
 {

printf("%d\t\t%d\t\t%d\n",sp_mat3[i][0],sp_mat3[i][1],sp_mat3[i][2]);
 }
 printf("\nTranspose Matrix:\n");
 printf("%d\t\t%d\t\t%d\n",rcv[1],rcv[0],rcv[2]);
 for(i=0;i<v;i++)
 {

printf("%d\t\t%d\t\t%d\n",transpose[i][0],transpose[i][1],transpose[i][2]);
 }
 }

int main(void) {

 int choice;
 do{
 printf("\nEnter choice:\n1)DISPLAY THREE TUPPLE REPRESENTATION\n2)ADDITION OF MATRIX\n3)SIMPLE TRANSPOSE \n4)exit\n");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1:
 { int v;
 int sp_mat[20][20],rcv[3];
 get_mat(sp_mat,choice,rcv);
 break;
 }
 case 2:
 {
 int mat1[20][20],mat2[20][20];
 add(choice,mat1,mat2);
 break;
 }
case 3:
 {

 trans();
 break;
 }
 case 4:
 {

 trans();
 }
 break;

 }
 }while(choice!=4);

 return 0;
}