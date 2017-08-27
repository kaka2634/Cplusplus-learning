#ifndef _MAXHEAP_H
#define _MAXHEAP_H

#include <iostream>

#include "Heap.h"

template <typename T>
class MaxHeap : public Heap <T> {
public:
  MaxHeap(int);
  MaxHeap(const T [], const int);
  ~MaxHeap();
public:
  bool insert_heap(const T&);
  bool remove_heap(T &);

  void show_heap()const;

protected:
  void sift_down(/* arguments */) {
    /* code */
  }
  void sift_up(/* arguments */) {
    /* code */
  }
private:
  T *heap;
  int size; //包含数据的大小
  int capacity; //总容量大小
};

template <typename T>
MaxHeap<T>::MaxHeap(int sz = DEFAULT_SIZE)
{
  capacity = sz > DEFAULT_SIZE ? sz : DEFAULT_SIZE;
  heap = new T[capacity];
  assert(heap != NULL);
  size = 0;
}

template <typename T>
MaxHeap<T>::MaxHeap(const T arr[], const int arrSize)
{
  capacity = arrSize > DEFAULT_SIZE ? arrSize : DEFAULT_SIZE;
  heap = new T [capacity];
  assert(heap != NULL);
  size = arrSize;

  for(int i = 0; i < size; i++)
  {
    heap[i] = arr [i];
  }
  int curPos = size/2 - 1; //从最后一个节点的父节点开始调整
  while(curPos>=0){
    sift_down(curPos, size -1);
    --curPos; //每次减一,判断父节点调整
  }
}

template <typename T>
MaxHeap<T>::~MaxHeap(){
  delete []heap;
  heap = NULL;
  capacity = size = 0;
}

template <typename T>
bool MaxHeap<T>::insert_heap(const T& val)
{
  if(size >= capacity)
                  return false;
  heap[size] = val;
  sift_up(size);
  ++size;
  return true;
}


template <typename T>
void MaxHeap<T>::show_heap()const
{
	for(int i=0; i<size; ++i)
		std::cout << heap[i] << " ";
	std::cout << std::endl;
}

//protected interface

template <typename T>
void MaxHeap<T>::sift_down(int start, int end)
{
	int i = start;
	int j = i*2 + 1;

//迭代堆根节点sift_down
	T tmp = heap[i];
	while(j <= end){
		if(j+1 <= end && heap[j] < heap[j+1])
			++j;
		if(tmp < heap[j])
			heap[i] = heap[j];
		else
			break;

		i = j;
		j = j*2 + 1;
	}
	heap[i] = tmp;
}

template <typename T>
void MaxHeap<T>::sift_up(int start)
{
  //迭代对叶子节点升
	int j = start;
	int i = (start-1) / 2;

	T tmp = heap[j];
	while(j > 0){
		if(tmp < heap[i])
			break;
		else
			heap[j] = heap[i];

		j = i;
		i = (i-1) / 2;
	}
	heap[j] = tmp;
}

#endif   /*MaxHeap.h*/
