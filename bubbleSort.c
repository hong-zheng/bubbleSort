#include "SORT.h"
void display(int arr[], int len){
	for (int i = 0; i < len; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void swap(int arr[], int start, int min){
	int tmp = arr[start];
	arr[start] = arr[min];
	arr[min] = tmp;
}

/*
	时间复杂度：最坏O(n^2) 平均(n^2) 最好O(n)
	空间复杂度：O(1)
	稳定性：稳定
	数据敏感度：敏感
*/
void bubbleSort(int arr[], int len){
	while( len ){
		int end = len;
		// 一轮冒泡排序
		for (int i = 0; i<end - 1; i++){
			// 相邻元素进行比较
			if (arr[i] > arr[i + 1]){
				swap(arr, i, i + 1);
			}
		}
		len--;
	}
}

// 优化
// 满足关系不需要再交换
void bubbleSort1(int arr[], int len){
	while (len){
		// 对于已经有序的序列，通过标签提前结束排序过程
		int flag = 1; // 表示是否发生交换，1 表示一轮过程中没有发生交换
		int end = len;
		// 一轮冒泡排序
		for (int i = 0; i<end - 1; i++){
			// 相邻元素进行比较
			if (arr[i] > arr[i + 1]){
				swap(arr, i, i + 1);
				flag = 0;
			}
		}
		// flag 标志任意一轮中没有发生交换便可以直接退出
		// 没有发生交换
		if (flag)
			break;
		len--;
	}
}
void bubble(int arr[], int len){
	for (int i = 0; i < len - 1; i++){
		for (int j = 0; j < len - i - 1; j++){
			if (arr[j + 1] < arr[j]){
				swap(arr, j + 1, j);
			}
		}
	}
}
void testBubble(){
	void shl(int arr[], int len);
	srand(time(NULL));
	// 定义数据量
	int num = 0;
	scanf("%d", &num);
	int* arr = (int*)malloc(sizeof(int)*num);
	for (int i = 0; i < num; i++){
		arr[i] = rand();
	}
	display(arr, num);
	int begin = clock();
	bubbleSort1(arr, num);
	int end = clock();
	display(arr, num);
	printf("冒泡排序所费时间为:>%d\n", end - begin);
	begin = clock();
	bubble(arr, num);
	end = clock();
	//display(arr, num);
	printf("排好序之后的希尔排序所费时间为:>%d\n", end - begin);
}
int main(){
	testBubble();
	system("pause");
	return 0;
}