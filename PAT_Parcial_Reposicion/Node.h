#pragma once
template<typename T>
struct Node
{
	T value;
	Node* next;
	Node(T value) : data(value), next(nullptr) {}
};

