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
	ʱ�临�Ӷȣ��O(n^2) ƽ��(n^2) ���O(n)
	�ռ临�Ӷȣ�O(1)
	�ȶ��ԣ��ȶ�
	�������жȣ�����
*/
void bubbleSort(int arr[], int len){
	while( len ){
		int end = len;
		// һ��ð������
		for (int i = 0; i<end - 1; i++){
			// ����Ԫ�ؽ��бȽ�
			if (arr[i] > arr[i + 1]){
				swap(arr, i, i + 1);
			}
		}
		len--;
	}
}

// �Ż�
// �����ϵ����Ҫ�ٽ���
void bubbleSort1(int arr[], int len){
	while (len){
		// �����Ѿ���������У�ͨ����ǩ��ǰ�����������
		int flag = 1; // ��ʾ�Ƿ���������1 ��ʾһ�ֹ�����û�з�������
		int end = len;
		// һ��ð������
		for (int i = 0; i<end - 1; i++){
			// ����Ԫ�ؽ��бȽ�
			if (arr[i] > arr[i + 1]){
				swap(arr, i, i + 1);
				flag = 0;
			}
		}
		// flag ��־����һ����û�з������������ֱ���˳�
		// û�з�������
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
	// ����������
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
	printf("ð����������ʱ��Ϊ:>%d\n", end - begin);
	begin = clock();
	bubble(arr, num);
	end = clock();
	//display(arr, num);
	printf("�ź���֮���ϣ����������ʱ��Ϊ:>%d\n", end - begin);
}
int main(){
	testBubble();
	system("pause");
	return 0;
}