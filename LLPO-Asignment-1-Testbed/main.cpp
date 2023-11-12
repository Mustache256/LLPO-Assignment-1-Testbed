#include "Common.h"
#include "Tracker.h"
#include "MemPool.h"
#include "Global.h"

int main()
{
	MemPool* pool = new MemPool(50, 50);

	pool->DeletePool();
	return 0;
}