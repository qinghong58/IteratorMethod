#pragma once
#include<iostream>
#include"Container.h"
#include"Iterator.h"

using namespace std;

//����һ���º����������ж�����Ԫ�صĴ�С
template <typename T>
struct sort
{
    bool operator()(const T& a, const T& b) const
    {
        return a < b;
    }
};