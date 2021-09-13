#pragma once
#include"Cars.h"
#include<string.h>

class Vector {
	Car* data;
	size_t  capacity;
	size_t size;
	
	void Realloc();
public:
	Vector();
	Vector(const Vector& inf);
	const Car& operator[](size_t index) const {
		return data[index];
	}
	Car& operator[] (size_t index) {
		return data[index];
	}

	size_t Get_size() const;
	size_t Get_capacity() const;

	void Pushback(const Car& item);
	void Insert(size_t index, const Car& item);
	void Erase(const size_t index);
	void Clear();
	~Vector();

	void Read_file(const char* patch);
	void Write_file(const char* patch) const;
	typedef bool(comporator)(const Car& lsh, const Car& rhs);

	void Alfa_sort(comporator cmp);
};

class ESetException {
protected:
	char message[256];
public:
	ESetException(const char* message) {
		strncpy(this->message, message, 255);
		this->message[255] = 0;
	}
	virtual const char* Get_Message() { return message; }
};

class EInsertOutOfRange : public ESetException {
protected:
	size_t index;
public:
	EInsertOutOfRange(const size_t index) : ESetException("Insert index is wrong "), index(index) {};
	size_t GetIndex() { return index; }
};

class EEraseOutOfRange : public ESetException {
protected:
	size_t index;
public:
	EEraseOutOfRange(const size_t index) : ESetException("Erase index is wrong "), index(index) {};
	size_t GetIndex() { return index; }
};

class EFileNotExist : public ESetException {
public:
	EFileNotExist() : ESetException("File does not exist ") {};
};