#pragma once
#include <iostream>
#include <vector>

#include "Tracker.h"
#include "Global.h"
#include "Common.h"

using namespace std;

class MemPool
{
public:
	MemPool(size_t lSizeOfSlice, int lNumOfSlices);
	~MemPool() { DeletePool(); };

	char* AddrFromIndex(int i) const;
	int IndexFromAddr(const char* p) const;

	void* Alloc();
	void Free(void* p);

	void DeletePool();

	void* operator new(size_t size);
	void operator delete(void* pMem);

private:
	int mNumOfSlices;
	size_t mSizeOfSlice;
	int mNumFreeSlices;
	int mNumSlicesInitialised;
	char* pMemStart;
	char* pNext;
};

