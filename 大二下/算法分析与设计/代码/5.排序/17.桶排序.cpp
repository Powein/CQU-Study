#include <iostream>
#include <cmath>
using namespace std;

void inssort(int A[],int n){
    for(int i=1;i<n;i++){
        for(int j=i;j>0;j--){
            if(A[j]<A[j-1]){
            	int tmp=A[j];
            	A[j]=A[j-1];
            	A[j-1]=tmp;
            }
            else{
                break;
            }
        }
    }
}

void bucketSort(int A[],int n,int numBuckets){
    //����Ͱ
    int buckets[numBuckets][n]; 	//��ά���飬ÿ�б�ʾһ��Ͱ
    int bucketSizes[numBuckets]; 	//ÿ��Ͱ��Ԫ�ص�����
    //��ʼ��Ͱ�Ĵ�С
    for(int i=0;i<numBuckets;i++){
        bucketSizes[i]=0;
    }
    //ȷ������Ԫ�ط�Χ
	int maxA=-999,minA=999;
	for(int i=0;i<n;i++){
		if(A[i]>maxA)	maxA=A[i];
		if(A[i]<minA)	minA=A[i];
	} 
    //��Ԫ�ط���Ͱ��
    for(int i=0;i<n;i++){
    	int bucketGap=ceil((maxA-minA)/(float)numBuckets);
        int bucketIndex=(A[i]-minA)/bucketGap;
        buckets[bucketIndex][bucketSizes[bucketIndex]++]=A[i];
    }
    //��ÿ��Ͱ�е�Ԫ�ؽ��в�������
    for(int i=0;i<numBuckets;i++){
        inssort(buckets[i],bucketSizes[i]);
    }
    // �ϲ�Ͱ�е�Ԫ��
    int index=0;
    for(int i=0;i<numBuckets;i++){
        for(int j=0;j<bucketSizes[i];j++){
            A[index++]=buckets[i][j];
        }
    }
}

int main() {
    int A[]={29,25,3,49,9,37,21,43};
    int n=sizeof(A)/sizeof(A[0]);
    int numBuckets=5;
    bucketSort(A, n, numBuckets);

    printf("Sorted array: ");
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }

    return 0;
}

