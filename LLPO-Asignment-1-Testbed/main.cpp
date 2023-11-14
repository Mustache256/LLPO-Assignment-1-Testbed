#include <thread>
#include <mutex>

#include "Common.h"
#include "Tracker.h"
#include "MemPool.h"
#include "Global.h"

using namespace std;

//int GlobalValue = 0;
//mutex aMutex;

/*void CallFromThread()
{
	aMutex.lock();
	cout << "\nInput Parameter: " << GlobalValue++ << "\n";
	aMutex.unlock();
}*/

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

	/*chrono::steady_clock::time_point begin = chrono::steady_clock::now();

	thread MyThread(CallFromThread);
	thread MyThread2(CallFromThread);
	MyThread.join();
	MyThread2.join();

	chrono::steady_clock::time_point end = chrono::steady_clock::now();

	cout << "\nTook: " << chrono::duration_cast<chrono::microseconds>(end - begin).count() << " microseconds\n";*/

	return 0;
}