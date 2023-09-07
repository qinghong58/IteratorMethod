#pragma once
#include<iostream>
#include"Container.h"
#include"Iterator.h"

using namespace std;

//定义一个仿函数，用来判断两个元素的大小
template <typename T>
struct sort
{
    bool operator()(const T& a, const T& b) const
    {
        return a < b;
    }
};