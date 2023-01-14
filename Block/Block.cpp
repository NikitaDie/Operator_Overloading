#include "Block.h"

Block::Block(int size, int* tmp_arr) :
	size{ size },
	count{ size  },
	arr{ new int[size] }
{
	for (int i{ 0 }; i < size; ++i) {
		arr[i] = tmp_arr[i];
	}
}

Block::Block(const Block& block) :
	size{ block.size },
	count{ block.count },
	arr{ new int[block.size] }
{
	for (int i{ 0 }; i < block.count; ++i) {
		arr[i] = block.arr[i];
	}
}

Block::Block(Block&& block) :
	size{ block.size },
	count{ block.count },
	arr{ block.arr }
{
	block.arr = nullptr;
}

Block& Block::operator=(const Block& block)
{

	if (this == &block)
		return *this;

	this->size = block.size;
	this->count = block.count;

	delete[] this->arr;

	this->arr = new int[block.size];

    for (int i{ 0 }; i < block.count; ++i) {
		this->arr[i] = block.arr[i];
		}

	return *this;
}

Block& Block::operator=(Block&& block)
{

	delete[] this->arr;

	this->size = block.size;
	this->count = block.count;
	this->arr = block.arr;
	
	block.arr = nullptr;
	
	return *this;
}

void Block::setSize(const int size)
{

	if (size < this->size) {
		int* tmp_arr{ new int[size] };

		for (int i{ 0 }; i < size; ++i) {
			tmp_arr[i] = this->arr[i];
		}

		delete[] this->arr;

		this->arr = tmp_arr;

		if (this->count > size) {
			this->count = size;
		}

	}
	else if (size > this->size) {
		int* tmp_arr{ new int[size] };

		for (int i{ 0 }; i < this->count; ++i) {
			tmp_arr[i] = this->arr[i];
		}

		delete[] arr;

		this->arr = tmp_arr;
	}
	else {
		return;
	}


	this->size = size;

}

int Block::getSize() const
{
	return this->count;
}

void Block::pushBack(const int element)
{
	if (this->count == this->size) {
		setSize(this->size + EXTENTION_SIZE);
	}
	this->arr[count] = element;
	++this->count;
}

void Block::popBack()
{
	--(this->count);
}

void Block::insert(const int element, const int id)
{
	if (id < this->count) {
		this->arr[id] = element;
	}
	else {
		pushBack(element);
	}

}

void Block::erase(const int element)
{
	int counter{ 0 };
	for (int i{ 0 }; i < this->count; ++i) {
		if (this->arr[i] == element) ++counter;
	}

	if (counter == 0) return;

	this->count -= counter;

	int* tmp_arr{ new int[this->size] };

	for (int j{ 0 }, i{ 0 }; i < this->count; ++i, ++j) {
		if (this->arr[j] != element) {
			tmp_arr[i] = this->arr[j];
		}
		else --i; //skip
	}

	delete[] this->arr;

	this->arr = tmp_arr;
}

Block& Block::operator+(const int element) //proved (push an element )
{
	pushBack(element);

	return *this;
}

Block& Block::operator+(const Block& block) //proved (make from two arrays, one long)
{
	if (this->size < this->count + block.count) {
		setSize(this->count + block.count);
	}

	for (int i{ 0 }; i < block.count; ++i) {
		this->pushBack(block.arr[i]);
	}

	return *this;
}

Block& Block::operator-(const int element) //proved (remove all occurrences of an element)
{
	erase(element);

	return *this;
}

Block& Block::operator-(const Block& block) //proved (subtracts the value of the array elements from the values of another array, 
{											//subtracted to the "count size" of the smaller array)
	
	int limiter{ 0 };

	if (this->count > block.count) limiter = block.count;
	else limiter = this->count;
		
	for (int i{ 0 }; i < limiter; ++i) {
		this->arr[i] -= block.arr[i];
	}

	return *this;
}

Block& Block::operator*(const int index) //proved (multiplies each element of the array by an element)
{
	for (int i{ 0 }; i < this->count; ++i) {
		this->arr[i] *= index;
	}

	return *this;
}

Block& Block::operator*(const Block& block) //proved (multiplies each element of the array by an element from other array, copy the difference from the biggest)
{
	if (this->count >= block.count) {
		for (int i{ 0 }; i < block.count; ++i) {
			this->arr[i] *= block.arr[i];
		}
	}
	else {
		if (this->size < block.count) {
			this->size = block.count;
		}

		int* tmp_arr{ new int[this->size] };
		for (int i{ 0 }; i < this->size; ++i) {
			tmp_arr[i] = this->arr[i] * block.arr[i];
		}

		for (int i{ this->count }; i < block.count; ++i) {
			tmp_arr[i] = block.arr[i];
		}

		delete[] this->arr;

		this->arr = tmp_arr;
		this->count = this->size;
	}
	
	return *this;

}

Block& Block::operator/(const int index) //proved (multiplies each element of the array by an element, integer division)
{
	for (int i{ 0 }; i < this->count; ++i) {
		this->arr[i] /= index;
	}
	return *this;
}

Block& Block::operator--() //prefix
{
	popBack();
	return *this;
}

Block Block::operator--(int) //postfix
{
	Block temp{ *this };
	--(*this);
	return temp;
}

int& Block::operator[](const int id) //add also const version
{
	return this->arr[id];
}

const int& Block::operator[](const int id) const
{
	return this->arr[id];
}

std::ostream& operator<<(std::ostream& out, const Block& block) //proved
{
	for (int i{ 0 }; i < block.count - 1; ++i) {
		out << block.arr[i] << ", ";
	}

	out << block.arr[block.count - 1] << "\n";

	return out;
}

Block::~Block()
{
	if (this->arr != nullptr)
		delete[] this->arr;
}