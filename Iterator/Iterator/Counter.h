#pragma once
class Counter
{
public:
	int sharePtrCount = 0; // 当sharePtrCount为0时，删除T*对象。
	int weakPtrCount = 0; // 当weakPtrCount为0同时sharePtrCount为0时，删除Counter*对象。
};