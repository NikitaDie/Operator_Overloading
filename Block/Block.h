#pragma once

#include <iostream>

const int EXTENTION_SIZE = 5;

class Block
{
private:
	int size{ 0 };
	int count{ 0 };
	int* arr{ nullptr };

public:
	Block() = default;

	Block(int size, int* tmp_arr);

	Block(const Block& block);

	Block(Block&& block);

	Block& operator=(const Block& block);

	Block& operator=(Block&& block);

	void setSize(const int size);

	int getSize() const;

	void pushBack(const int element);

	void popBack(); //--

	void insert(const int element, const int id);

	void erase(const int element);

	Block& operator+(const int element);

	Block& operator+(const Block& block);

	Block& operator-(const int element);

	Block& operator-(const Block& block);

	Block& operator*(const int index);

	Block& operator*(const Block& block);

	Block& operator/(const int index);

	int& operator[](const int id);

	friend std::ostream& operator<< (std::ostream& out, const Block& block);

	~Block();
};

