#define _CRT_SECURE_NO_WARNINGS
#include"Vector.h"
#include<conio.h>
#include<stdio.h>

int a_ = 1;

void Vector::Realloc() {
	size_t new_capacity = 0;
	if (capacity == 0) {
		new_capacity = 10;
		Car* newData = new Car[new_capacity];
		for (size_t i = 0; i < size; ++i) {
			newData[i] = data[i];
		}
		capacity = new_capacity;
		delete[] data;
		data = newData;
		return;
	}
	if (size == capacity) {
		new_capacity = capacity + (capacity / 2);
		Car* newData = new Car[new_capacity];
		for (size_t i = 0; i < size; ++i) {
			newData[i] = data[i];
		}
		capacity = new_capacity;
		delete[] data;
		data = newData;
		return;
	}
	else
		return;
}

Vector::Vector() : data(nullptr), capacity(0), size(0) {};
Vector::Vector(const Vector& rhs): data(new Car[rhs.size]), size(rhs.Get_size()), capacity(rhs.Get_capacity()) {
	for (size_t i = 0; i < size; ++i) {
		data[i] = rhs.data[i];
	}
}

size_t Vector::Get_capacity() const {
	return capacity;
}

size_t Vector::Get_size() const {
	return size;
}

void Vector::Pushback(const Car& item) {
	Realloc();
	data[size] = item;
	++size;
}

void Vector::Insert(size_t index, const Car& item) {
	if (index > size || index < 0) {
		throw (EInsertOutOfRange(index));
	}
	Realloc();
	for (size_t i = size - 1; i >= index; i--) {
		data[i] = data[i + 1];
	}
	data[index] = item;
	++size;
}

void Vector::Erase(const size_t index) {
	if (index<0 || index>size - 1) {
		throw(EInsertOutOfRange(index));
	}
	for (size_t i = index; i < size - 1; ++i) {
		data[i] = data[i + 1];
	}
	--size;
}

void Vector::Clear() {
	delete[] data;
	size = 0;
	data = nullptr;
	capacity = 0;
}

Vector::~Vector() {
	delete[] data;
}

void Vector::Read_file(const char* path) {
	FILE* input = NULL;
	input = fopen(path, "rb");
	if (input == NULL) {
		throw EFileNotExist();
	}
	Car temp;
	while (!feof(input)) {
		fread(&temp, sizeof(Car), 1, input);
		Pushback(temp);
	}
	size--;
	fclose(input);
}
void Vector::Write_file(const char* path) const {
	FILE* output = NULL;
	output = fopen(path, "wb");
	if (output == NULL) {
		throw (EFileNotExist());
	}
	for (size_t i = 0; i < size; ++i) {
		fwrite(&data[i], sizeof(Car), 1, output);
	}
	fclose(output);
}

typedef bool (comparator)(const Car& lhs, const Car& rhs);

void Vector::Alfa_sort(comparator cmp) {
	if (size == 0) return;
	for (size_t i = 0; i < size - 1; ++i)
	{
		bool swapped = false;
		for (int j = 0; j < size - i - 1; j++)
		{
			if (cmp(data[j], data[j + 1]) == false)
			{
				Car b = data[j];
				data[j] = data[j + 1];
				data[j + 1] = b;
				swapped = true;
			}
		}
		if (!swapped) break;
	}
}