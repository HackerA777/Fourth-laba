#include"Cars.h"
#include <string.h>
#include <stdio.h>

Car::Car() : brand(), model(), number(), release_date("00.00.0000"), last_to("00.00.0000") {};

Car::Car(const char* a_brand, const char* a_model, const char* a_number, const char* a_release_date, const char* a_last_to) {
	strcpy_s(brand, a_brand);
	strcpy_s(model, a_model);
	strcpy_s(number, a_number);
	strcpy_s(release_date, a_release_date);
	strcpy_s(last_to, a_last_to);
};

Car::Car(const Car& info_of_car)
{
	strcpy_s(this->brand, info_of_car.brand);
	strcpy_s(this->model, info_of_car.model);
	strcpy_s(this->number, info_of_car.number);
	strcpy_s(this->release_date, info_of_car.release_date);
	strcpy_s(this->last_to, info_of_car.last_to);
}

void Car::Set_brand(const char* a_brand) {
	strcpy_s(brand, a_brand);
}
void Car::Set_model(const char* a_model) {
	strcpy_s(model, a_model);
}

void Car::Set_number(const char* a_number) {
	strcpy_s(number, a_number);
}

void Car::Set_realese_date(const char* a_release_date) {
	strcpy_s(release_date, a_release_date);
}

void Car::Set_last_to(const char* a_last_to) {
	strcpy_s(last_to, a_last_to);
}

const char* Car::Get_brand() const{
	return brand;
}

const char* Car::Get_model() const {
	return model;
}

const char* Car::Get_number() const {
	return number;
}

const char* Car::Get_realease_date() const {
	return release_date;
}

const char* Car::Get_last_to() const {
	return last_to;
}

void Car::Printf_info_of_car() const {
	printf("\nМарка автомобиля: %s\nМодель автомобиля: %s\nГос. номер автомобиля: %s\nДата выпуска автомобиля: %s\nДата прохождения последнего ТО: %s\n", brand, model, number, release_date, last_to);
}