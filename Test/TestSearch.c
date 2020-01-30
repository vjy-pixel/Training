#include<stdio.h>
#include<time.h>
//#define 10 10
void main()
{
    int iArray[10]={2,1,5,6,8,98,45,6,3,21};
    
  //  printf("Enter elements if array(10 elements):\n");
    

    int iDesired =8;
    
    int iFlag=0;
  
    
    for(int index=0; index< 10; index++){
        
        for(int cnt=index+1;cnt< 10;cnt++){
            
            if(iArray[index]>iArray[cnt]){
                
                iArray[index]=iArray[index]+iArray[cnt];
                iArray[cnt]=iArray[index]-iArray[cnt];
                iArray[index]=iArray[index]-iArray[cnt];
            
            }
        }
    }
  
    int iLower=0,iUpper=9;
    int iMedian=0;
    
 //   clock_t binSTime=clock();
    while(1)
    {
        iMedian=((iLower+iUpper)/2);
        printf("low: %d,up:%d\n",iLower,iUpper);
        printf("Med: %d,%d\n",iMedian,iArray[iMedian]);
        if(iDesired==iArray[iMedian]){
            iFlag=1;
            printf("%d found\n",iDesired);
            break;
        }

        else if(iDesired > iArray[iMedian]){
            iLower = iMedian+1;
            continue;
        }

        else if(iDesired<iArray[iMedian]){ 
            iUpper=iMedian-1;
            continue;
        }
        
    }
    if(iFlag ==0)
        printf("Element not found\n");
    
  
}