/**~*~*
 Heap template

Written By:
Changed by:Matthew Hoang
*~**/

#ifndef HEAP_H_
#define HEAP_H_
#include <iostream>
using namespace std;

template<class ItemType>
class Heap
{
private:
	ItemType* heapAry;
	int heapSize;
    int count;
	//, int compare(ItemType &, ItemType &) , ItemType &
    //function pointer compare : 0 means equal, 1 means left > right, -1 means left < right
	void _reHeapUp(int lastndx);
	void _reHeapDown(int rootndx, ItemType &second_element);
    int _findParent(int index)     { return (index <= 0) ? (-1) : (index - 1) / 2; }
    int _findLeftChild(int index)  { return (2 * index + 1 > count) ? (-1) : ( 2 * index + 1); }
    int _findRightChild(int index) { return (2 * index + 2 > count) ? (-1) : ( 2 * index + 2); }

public:
	Heap()		{ count = 0; heapSize = 128; heapAry = new ItemType[heapSize]; }
	Heap(int n)	{ count = 0; heapSize = n;	heapAry = new ItemType[heapSize]; }
	~Heap(){ delete [] heapAry; }

	int getCount() const	{ return count; }
    int getSize() const { return heapSize; }
	bool isEmpty() const	{ return count == 0; }
    bool isFull()  const	{ return count == heapSize; }
	bool insertHeap( ItemType &itemIn);
	bool deleteHeap( int count, ItemType &itemOut  );
    void printHeap();

};

/**~*~*
 The private member function _reHeapUp rearranges the heap after insert by moving the 
 last item up to the correct location in the heap
 int compare(ItemType &first_element,
 ,  ItemType &second_element)
 *~**/

template<class ItemType>
void Heap<ItemType>::_reHeapUp(int lastndx)
{
    if(lastndx)
    {
        int temp;
        if(lastndx != heapAry[0]){
            int parent = _findParent(lastndx);
            
            if(heapAry[lastndx] > heapAry[parent]){
                temp =  heapAry[parent];
                heapAry[parent] = heapAry[lastndx];
                heapAry[lastndx] = temp;
                _reHeapUp(parent);
            }
            
        }
        // finish writing this recursive function
        
    }
}


/**~*~*
 The private member function _reHeapDown rearranges the heap after delete by moving the
 data in the root down to the correct location in the heap
 , int compare(ItemType &, ItemType &)
 *~**/
/*
template<class ItemType>
void Heap<ItemType>::_reHeapDown(int rootdex)
{
    int rightKey;
    int largest;
    if(heapAry[left] !=){
        int left = _findLeftChild(rootdex);
        if(left != ){
            rightKey;
        }
        else{rightKey = null;}
        
    }
    // finish writing this recursive function

}
*/
/**~*~*
 The public member function insertHeap inserts a new item into a heap. 
 It calls _reheapUp.
 , int compare(ItemType &, ItemType &)
 *~**/
template<class ItemType>
bool Heap<ItemType>::insertHeap(ItemType& newItem)
{
	// finish writing this function
    if(heapSize == count){
        return false;
    }
    count++;
    heapAry[count] = newItem;

    //_reHeapUp(count);
	return true;
}

/**~*~*
 The public member function deleteHeap deletes the root of the heap and
 passes back the root's data. It calls _reheapDown.
 , int compare(ItemType &, ItemType &)
 *~**/
template<class ItemType>
bool Heap<ItemType>::deleteHeap(int count, ItemType& returnItem)
{
	// finish writing this function
    if(count == 0){return false;}
    
    heapAry[0] = heapAry[count];
    //_reheapDown(0,count);
	return true;
}

template<class ItemType>
void Heap<ItemType>::printHeap()
{
    int counter = 0;
    for(int i = 0; i < getCount(); i++){
        cout<<heapAry[2*i+2]<<endl<<"   "<<heapAry[i]<<endl<<"      "<<heapAry[2*i+1]<<endl;
    }
}

#endif // HEAP_H_
