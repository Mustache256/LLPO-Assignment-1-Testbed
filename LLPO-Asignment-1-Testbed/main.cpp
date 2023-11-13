#include "Common.h"
#include "Tracker.h"
#include "MemPool.h"
#include "Global.h"

int main()
{
	MemPool* pool = new MemPool(8, 2);

	int* myInt = (int*)pool->operator new(sizeof(int), pool);
	bool* myBool = (bool*)pool->operator new(sizeof(bool), pool);


	pool->operator delete(&myInt, pool);

	int* myInt2 = (int*)pool->operator new(sizeof(int), pool);

	pool->operator delete(&myBool, pool);
	pool->operator delete(&myInt2, pool);

	pool->DeletePool();
	return 0;
}