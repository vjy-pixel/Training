// Linear Search is a technique of searching an element in any random ordered array. Here we will pick the desired element(X)
// and we will check one by one through out the array.

// While in Binary Search we have to sort array first, then we will find the middle element(M) ((floor)(lower+upper)/2)).
// Then we will check whether desired element(X) is Greater or Smaller. 
// If Greater then new_lower will be (M+1) else new_upper will be (M-1). And we will continue this method till we find 
// the desired element(X)
// By this method every time array will be trimmed by half. Because of this the searching becomes faster and more efficient than 
// lineat search.

#include<stdio.h>
#include<time.h>

void main()
{
	int a[10],i;
	printf("Enter elements if array:\n");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	
	int x;
	printf("Enter Desired Element:");
	scanf("%d",&x);
	int flag=0;
	//Linear Search
	clock_t linSTime = clock();
	for(i=0;i<10;i++)
		if(x==a[i]){
			flag=1;
			printf("%d found\n",a[i]);
		}
	if(flag==0)
		printf("Element not found\n");
	linSTime = clock()-linSTime;
	//double linDiff = linETime - linSTime;
	printf("Linear Search Time:%f\n", (float)linSTime/CLOCKS_PER_SEC);
		
	//Binary Search
	linSTime = clock();
	int j;
	for(i=0;i<10;i++)
		for(j=i+1;j<10;j++){
			if(a[i]>a[j]){
				a[i]=a[i]+a[j];
				a[j]=a[i]-a[j];
				a[i]=a[i]-a[j];
			}
		}
	linSTime = clock()-linSTime;
	printf("\nSorting Time:%f\n",(float)linSTime/CLOCKS_PER_SEC);	
	int l=0,u=9;
	int m;
	linSTime=clock();
	while(1)
	{
		m=((l+u)/2);
		if(x==a[m]){
			flag=1;
			printf("%d found\n",x);
			break;
		}
		else if(x>m){
			l=m+1;
			continue;
		}
		else if(x<m){ 
			u=m-1;
			continue;
		}
		
	}
	if(flag ==0)
		printf("Element not found\n");
	linSTime = clock() - linSTime;
	printf("Binary Search Time:%f\n",(float)linSTime/CLOCKS_PER_SEC);
	//getch();
}
		