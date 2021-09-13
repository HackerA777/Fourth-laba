#pragma once
class Car{
	char brand[100], model[255], number[100], release_date[50], last_to[50];
public:
	Car();
	Car(const char* brand, const char* model, const char* number, const char* release_date, const char* last_to);
	Car(const Car& info_of_car);
	
	void Set_brand(const char* brand);
	void Set_model(const char* model);
	void Set_number(const char* number);
	void Set_realese_date(const char* realease_date);
	void Set_last_to(const char* lastr_to);

	const char* Get_brand() const;
	const char* Get_model() const;
	const char* Get_number() const;
	const char* Get_realease_date() const;
	const char* Get_last_to() const;
	
	void Printf_info_of_car() const;
};
