#pragma once
class Counter
{
public:
	int sharePtrCount = 0; // ��sharePtrCountΪ0ʱ��ɾ��T*����
	int weakPtrCount = 0; // ��weakPtrCountΪ0ͬʱsharePtrCountΪ0ʱ��ɾ��Counter*����
};