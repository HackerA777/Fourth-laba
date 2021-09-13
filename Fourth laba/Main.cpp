#define  _CRT_SECURE_NO_WARNINGS
#include"Cars.h"
#include"Vector.h"
#include<stdlib.h>
#include<locale.h>
#include<conio.h>
#include<stdio.h>
#include<Windows.h>
#include<string.h>
#include<conio.h>

void my_getch()
{
	int a = getchar();
}

int get_key()
{
	int key = _getch();
	if ((key == 0) || (key == 224))
		key = _getch();
	return key;
}

int menu_1()
{
	printf("\n");
	printf("\nРабота с файлом: 1\nЗаписать информацию о новой машине: 2\nПросмотр массива поэлементно: 3\nСортировка массива: 4\nСоздать новый массив по заданию: 5\nПоиск по марке авто: 6\nОчистить массив: 7\nВыйти из программы: esc\n");
	while (true)
	{
		int key = get_key();
		if ((key == 27) || (key == 48) || (key == 49) || (key == 50) || (key == 51) || (key == 52) || (key == 53) || (key == 54) || (key == 55) || (key == 56) || (key == 57) || (key == 58))
			return key;
	}
}

int menu_2()
{
	printf("\nВперёд ->\nНазад <-\nДобавить запись о новом авто: 1\nРедактировать запись: 2\nУдалить запись: 3\nВыйти: esc\n");
	while (true)
	{
		int key = get_key();
		if ((key == 27) || (key == 49) || (key == 50) || (key == 51) ||(key==75) ||(key==77))
			return key;
	}
}

int menu_3()
{
	printf("\nСчитать данные из файла: 1\nЗаписать данные в файл: 2\nВыйти: esc\n");
	while (true)
	{
		int key = get_key();
		if ((key == 27) || (key == 49) || (key == 50))
			return key;
	}
}

int menu_4() {
	printf("\nРедактировать марку и модель авто: 1\nРедактировать номер авто: 2\nРедактировать дату выпуска: 3\nРедактировать дату последнего прохождения ТО: 4\nВыход: esc\n");
	while (true) {
		int key = get_key();
		if ((key == 27) || (key == 49) || (key == 50) || (key == 51) || (key == 52))
			return key;
	}
}

int menu_5()
{
	printf("\n");
	printf("Отсортировать по марке: 1\nОтсортировать по модели: 2\nОтсортировать по номеру: 3\nОтсортировать по дате выпуска: 4\nОтсортировать по дате прохождения последнего ТО: 5\nВывести отсортированный массив: 6\nВыход: Esc\n\n");
	while (true)
	{
		int key = get_key();
		if ((key == 27) || (key == 49) || (key == 50) || (key == 51) || (key == 52) || (key == 53) || (key == 54) || (key == 55))
			return key;
	}
}

int menu_6() {
	printf("\n");
	printf("Поиск по подстроке в марке автомобиля: 1\nВыход: Esc\n\n");
	while (true)
	{
		int key = get_key();
		if ((key == 27) || (key == 49))
			return key;
	}
}


bool Rec_number_comparator(const Car& lhs, const Car& rhs) {
	char lhssur[255] = "";
	char rhssur[255] = "";
	strcpy(lhssur, lhs.Get_number());
	strcpy(rhssur, rhs.Get_number());
	for (size_t i = 0; i < strlen(lhssur); ++i) {
		lhssur[i] = tolower(lhssur[i]);
	}
	for (size_t i = 0; i < strlen(rhssur); ++i) {
		rhssur[i] = tolower(rhssur[i]);
	}
	return (strcmp(lhssur, rhssur) < 0);
}

bool Rec_brand_comparator(const Car& lhs, const Car& rhs) {
	return (strcmp(lhs.Get_brand(), rhs.Get_brand()) < 0);
}

bool Rec_model_comparator(const Car& lhs, const Car& rhs) {
	return (strcmp(lhs.Get_model(), rhs.Get_model()) < 0);
}

bool Rec_date_comparator(const Car& lhs, const Car& rhs) {
	char date1[127];
	char date2[127];
	strcpy(date1, lhs.Get_realease_date());
	strcpy(date2, rhs.Get_realease_date());
	auto day1 = strtok(date1, "./");
	auto month1 = strtok(NULL, "./");
	auto year1 = strtok(NULL, "./");
	auto day2 = strtok(date2, "./");
	auto month2 = strtok(NULL, "./");
	auto year2 = strtok(NULL, "./");
	if (atoi(year1) < atoi(year2)) return true;
	else if (atoi(year1) == atoi(year2)) {
		if (atoi(month1) < atoi(month2)) {
			return true;
		}
		else if (atoi(month1) == atoi(month2)) {
			if (atoi(day1) < atoi(day1)) {
				return true;
			}
			else {
				return false;
			}
		}
		else return false;
	}
	else return false;
}

bool Rec_last_comparator(const Car& lhs, const Car& rhs) {
	char date1[127];
	char date2[127];
	strcpy(date1, lhs.Get_last_to());
	strcpy(date2, rhs.Get_last_to());
	auto day1 = strtok(date1, "./");
	auto month1 = strtok(NULL, "./");
	auto year1 = strtok(NULL, "./");
	auto day2 = strtok(date2, "./");
	auto month2 = strtok(NULL, "./");
	auto year2 = strtok(NULL, "./");
	if (atoi(year1) < atoi(year2)) return true;
	else if (atoi(year1) == atoi(year2)) {
		if (atoi(month1) < atoi(month2)) {
			return true;
		}
		else if (atoi(month1) == atoi(month2)) {
			if (atoi(day1) < atoi(day1)) {
				return true;
			}
			else {
				return false;
			}
		}
		else return false;
	}
	else return false;
}

char* Read_line() {
	size_t capacity = 4;
	size_t size = 0;
	setlocale(LC_ALL, "RUS");
	char* buffer = (char*)malloc(capacity);
	if (buffer == NULL)
		return NULL;

	while (true) {
		int c = fgetc(stdin);
		if (c == '\n' || c == EOF)
			break;
		buffer[size] = (char)c;
		++size;
		if (size == capacity) {
			capacity *= 2;
			char* new_buffer = (char*)realloc(buffer, capacity);
			if (new_buffer == NULL) {
				free(buffer);
				return NULL;
			}
			buffer = new_buffer;
		}
	}
	buffer[size] = 0;
	return buffer;
}

char* Fix_str(char* str)
{
	for (int i = 0; i < strlen(str); ++i)
	{
		str[i] = tolower(str[i]);
	}
	return str;
}


bool Check_date(char* input) {
	char str[50];
	setlocale(LC_ALL, "RUS");
	strcpy(str, input);
	auto date = strtok(str, "./");
	auto month = strtok(NULL, "./");
	auto year = strtok(NULL, "./");
	if (atoi(date) < 1 || atoi(date) > 31 || atoi(month) < 1 || atoi(month) > 12 || atoi(year) < 1900 || atoi(year) > 2030) {
		return false;
	}
	if (atoi(month) == 4 || atoi(month) == 6 || atoi(month) == 9 || atoi(month) == 11) {
		if (atoi(date) == 31) {
			return false;
		}
	}
	if (atoi(month) == 2) {
		if (atoi(date) > 29) {
			return false;
		}
	}
	return true;
}

bool Check_date_to(char* input_to, const char* input) {
	char str_to[50];
	char str[50];
	strcpy(str, input);
	setlocale(LC_ALL, "RUS");
	strcpy(str_to, input_to);
	auto date = strtok(str, "./");
	auto month = strtok(NULL, "./");
	auto year = strtok(NULL, "./");
	auto date_to = strtok(str_to, "./");
	auto month_to = strtok(NULL, "./");
	auto year_to = strtok(NULL, "./");
	if (atoi(date_to) < 1 || atoi(date_to) > 31 || atoi(month_to) < 1 || atoi(month_to) > 12 || (atoi(year_to) < 1900 || atoi(year_to) > 2030)) {
		return false;
	}
	if (atoi(month_to) == 4 || atoi(month_to) == 6 || atoi(month_to) == 9 || atoi(month_to) == 11) {
		if (atoi(date_to) == 31) {
			return false;
		}
	}
	if (atoi(month_to) == 2) {
		if (atoi(date_to) > 29) {
			return false;
		}
	}
	if (atoi(year_to) == atoi(year))
	{
		if (atoi(month_to) == atoi(month)) {
			if (atoi(date_to) < atoi(date))
				return false;
		}
		else {
			if (atoi(month_to) < atoi(month))
				return false;
		}
	}
	else {
		if (atoi(year_to) < atoi(year))
			return false;
	}
	return true;
}

bool Check_number(char* input) {
	char tmp[60];
	setlocale(LC_ALL, "RUS");
	strcpy(tmp, input);
	auto n = strtok(tmp, " ");
	auto r = strtok(NULL, "");
	for (int i = 0; i < 10; i++) {
		if (i == 6) {
			continue;
		}
		if ((i == 0) || (i == 4) || (i == 5)) {
			if ((tmp[i] < -64) || (tmp[i] == -63) || ((tmp[i] > -62) && (tmp[i] < -59)) || ((tmp[i] > -59) && (tmp[i] < -56)) || (tmp[i] == -53) || (tmp[i] == -49) || ((tmp[i] > -43) && (tmp[i] < -32)) || (tmp[i] == -31) || (tmp[i] == -29) || (tmp[i] == -28) || ((tmp[i] > -27) && (tmp[i] < -24)) || (tmp[i] == -17) || (tmp[i] == -12) || (tmp[i] > -11))
				return false;
		}
		else {
			if (((tmp[i] < 48) || (tmp[i] > 57))&& (tmp[i]!=0))
				return false;
		}
	}
	return true;
}

void Create_info(Car& rec) {
	char brand[100];
	char model[255];
	char number[100];
	char release_date[50];
	char last_to[50];
	printf("Введите марку автомобиля: ");
	gets_s(brand, 100);
	printf("Введите модель автомобиля: ");
	gets_s(model, 255);
	do {
		printf("Введите гос. номер автомобиля (Формат: А111АА 163)\n");
		gets_s(number, 100);
	} while (Check_number(number) == false);
	do {
		printf("Введите дату выпуска автомобиля (Формат: дд.мм.гггг)\n");
		gets_s(release_date, 50);
	} while (Check_date(release_date) == false);
	do {
		printf("Введите дату прохождения последнего тех. осмотра (Формат: дд.мм.гггг)\n");
		gets_s(last_to, 50);
	} while (Check_date_to(last_to, release_date) == false);
	rec.Set_brand(brand);
	rec.Set_model(model);
	rec.Set_number(number);
	rec.Set_realese_date(release_date);
	rec.Set_last_to(last_to);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Vector Vec;
	int end = 1;
	do {
		system("cls");
		int m1 = menu_1();
		switch (m1)
		{
		case 49:// Работа с файлом
		{
			system("cls");
			int end3 = 1;
			do {
				int m3 = menu_3();
				switch (m3)
				{
				case 49:
				{
					printf("Введите путь к файлу\n");
					auto path = Read_line();
					try {
						Vec.Read_file(path);
					}
					catch (EFileNotExist& err) {
						printf("%s \n", err.Get_Message());
						my_getch();
						free(path);
						break;
					}
					printf("\nДанные считаны\n");
					my_getch();
					free(path);
					break;
				}
				case 50:
				{
					printf("Введите путь к файлу\n");
					auto path = Read_line();
					try {
						Vec.Write_file(path);
					}
					catch (ESetException& err) {
						printf("%s \n", err.Get_Message());
						my_getch();
						free(path);
						break;
					}
					printf("\nДанные записаны\n");
					my_getch();
					free(path);
					break;
				}
				case 27:
				{
					end3 = 0;
				}
				}
			} while (end3 == 1);
			break;
		}
		case 50:
		{
			system("cls");
			Car info_of_car;
			Create_info(info_of_car);
			int answer;
			do {
				printf("Введите 1, если хотите добавить элемент в конец массива\n");
				printf("Введите 0, если хотите добавить элемент по индексу\n");
				scanf_s("%d", &answer);
				if ((answer < 0) || (answer > 1))
					printf("Введено некорректное число.\n");
			} while ((answer < 0) || (answer > 1));
			if (answer == 1) {
				Vec.Pushback(info_of_car);
			}
			if (answer == 0) {
				int index;
				do {
					printf("Введите индекс, куда добавить элемент. ( 0<= i <= %zu)\n", Vec.Get_size());
					scanf_s("%d", &index);
					if ((index < 0) || (index > Vec.Get_size()))
						printf("Введен некорректный индек.\n");
				} while ((index < 0) || (index > Vec.Get_size()));
				try {
					Vec.Insert(index, info_of_car);
				}
				catch (EInsertOutOfRange& err) {
					printf("%s, wrong index is %zu \n", err.Get_Message(), err.GetIndex());
				}
			}
			my_getch();
			break;
		}
		case 51:
		{
			{
				size_t index = 0;
				while (true) {
					system("cls");
					if (Vec.Get_size() > 0) {
						printf("%zu. (из %zu)\n", index + 1, Vec.Get_size());
						Vec[index].Printf_info_of_car();
					}
					else {
						printf("Массив пуст! \n");
					}
					int m2 = menu_2();
					if (m2 == 27) {
						break;
					}
					switch (m2) {
					case 75: {
						if (index > 0) {
							index--;
						}
						break;
					}
					case 77: {
						if (index < Vec.Get_size() - 1) {
							index++;
						}
						break;
					}
					case 49:
					{
						while (true) {
							system("cls");
							Car info_of_car;
							Create_info(info_of_car);
							Vec.Pushback(info_of_car);
							break;
						}
						break;
					}
					case 50: {
						while (true) {
							system("cls");
							if (Vec.Get_size() == 0) {
								system("cls");
								printf("Нельзя редактировать пустой массив\n");
								my_getch();
								break;
							}
							Vec[index].Printf_info_of_car();
							int m4 = menu_4();
							if (m4 == 27) {
								break;
							}
							switch (m4) {
							case 49: {
								char brand[100];
								system("cls");
								printf("Введите марку автомобиля\n");
								gets_s(brand, 100);
								Vec[index].Set_brand(brand);
								char model[255];
								system("cls");
								printf("Введите модель автомобиля\n");
								gets_s(model, 255);
								Vec[index].Set_model(model);
								break;
							}
							case 50: {
								char number[100];
								system("cls");
								printf("Введите номер автомобиля\n");
								gets_s(number, 100);
								Vec[index].Set_number(number);
								break;
							}
							case 51: {
								char release_data[50];
								system("cls");
								do {
									printf("Введите дату выпуска автомобиля\n");
									gets_s(release_data, 50);
								} while (Check_date(release_data) == false);
								Vec[index].Set_realese_date(release_data);
								break;
							}
							case 52: {
								char last_to[50];
								system("cls");
								do {
									printf("Дата выпуска %s\n", Vec[index].Get_realease_date());
									printf("Введите дату последнего прохождения ТО (формат: дд.мм.гггг)\n");
									gets_s(last_to, 50);
								} while (Check_date_to(last_to, Vec[index].Get_realease_date()) == false);
								Vec[index].Set_last_to(last_to);
								break;
							}
							}
						}
						break;
					}
					case 51: {
						if (Vec.Get_size() == 0) {
							system("cls");
							printf("Массив пуст.\n");
							my_getch();
							break;
						}
						else {
							try {
								Vec.Erase(index);
							}
							catch (EEraseOutOfRange& err) {
								printf("%s, wrong index is %zu \n", err.Get_Message(), err.GetIndex());
							}
							if (index == 0 && Vec.Get_size() > 0) {
								++index;
							}
							else {
								--index;
							}
						}
						break;
					}
					}
				}
				break;
			}
		}
		case 52: //Сортировка по ...
		{
			{
				while (true) {
					system("cls");
					int m5 = menu_5();
					if (m5 == 27) {
						break;
					}
					switch (m5) {
					case 49: {
						Vec.Alfa_sort(Rec_brand_comparator);
						printf("Массив отсортирован по марке авто\n");
						my_getch();
						break;
					}
					case 50: {
						Vec.Alfa_sort(Rec_model_comparator);
						printf("Массив отсортирован по модели авто\n");
						my_getch();
						break;
					}
					case 51: {
						Vec.Alfa_sort(Rec_number_comparator);
						printf("Массив отсортирован по гос. номеру\n");
						my_getch();
						break;
					}
					case 52: {
						Vec.Alfa_sort(Rec_date_comparator);
						printf("Массив отсортирован по дате выпуска авто\n");
						my_getch();
						break;
					}
					case 53: {
						Vec.Alfa_sort(Rec_last_comparator);
						printf("Массив отсортирован по дате последнего ТО\n");
						my_getch();
						break;
					}
					case 54: {
						system("cls");
						for (size_t i = 0; i < Vec.Get_size(); ++i) {
							Vec[i].Printf_info_of_car();
						}
						printf("\n\nНажмите любую клавишу, чтобы закрыть вывод\n");
						my_getch();
					}
					}
				}
				break;
			}

		}
		case 53: //Новый массив по заданию
		{
			Vector info_of_car2;
			for (size_t i = 0; i < Vec.Get_size(); ++i) {
				info_of_car2.Pushback(Vec[i]);
			}
			printf("Введите дату, чтобы вывести данны о автомобилях, у которых просрочен тех. осмотр.\n");
			auto date = Read_line();
			do {
				if (Check_date(date) == false) {
					printf("Введена некорректная дата.\n");
					free(date);
					date = Read_line();
				}
			} while (Check_date(date) == false);

			info_of_car2.Alfa_sort(Rec_last_comparator);
			for (size_t i = 0; i < info_of_car2.Get_size(); ++i)
			{
				char date1[50];
				char date2[50];
				char date3[50];
				strcpy(date1, info_of_car2[i].Get_realease_date());
				strcpy(date2, info_of_car2[i].Get_last_to());
				strcpy(date3, date);
				auto day1 = strtok(date1, "./");
				auto month1 = strtok(NULL, "./");
				auto year1 = strtok(NULL, "./");
				auto day2 = strtok(date2, "./");
				auto month2 = strtok(NULL, "./");
				auto year2 = strtok(NULL, "./");
				auto day3 = strtok(date3, "./");
				auto month3 = strtok(NULL, "./");
				auto year3 = strtok(NULL, "./");

				int sc, lto, realease, mp, tmp;
				realease = atoi(year1);
				lto = atoi(year2)+1;
				sc = atoi(year3);
				mp = sc-realease;
				tmp = lto - sc;
				if(mp<0||tmp>0){
					try {
						info_of_car2.Erase(i);
						--i;
					}
					catch (EEraseOutOfRange& err) {
						printf("%s , wrong index is %zu \n", err.Get_Message(), err.GetIndex());
						my_getch();
						break;
					}
				}
				else{
					for (int j = 3; j < mp; j++) {
						if ((realease + j) == lto && lto == sc)
						{
							if (atoi(month1) == atoi(month2)) {
								if (atoi(date1) < atoi(date2) && atoi(date2) > atoi(date3)) {
									try {
										info_of_car2.Erase(i);
										--i;
									}
									catch (EEraseOutOfRange& err) {
										printf("%s , wrong index is %zu \n", err.Get_Message(), err.GetIndex());
										my_getch();
										break;
									}

									break;;
								}
							}
							else {
								if (atoi(month1) < atoi(month2) && atoi(month2) > atoi(month3)) {
									try {
										info_of_car2.Erase(i);
										--i;
									}
									catch (EEraseOutOfRange& err) {
										printf("%s , wrong index is %zu \n", err.Get_Message(), err.GetIndex());
										my_getch();
										break;
									}

									break;
								}
							}
						}
						else {
							if ((realease + j) < lto && lto > sc) {
								try {
									info_of_car2.Erase(i);
									--i;
								}
								catch (EEraseOutOfRange& err) {
									printf("%s , wrong index is %zu \n", err.Get_Message(), err.GetIndex());
									my_getch();
									break;
								}

								break;
							}
							if (j == 3)
								j++;
						}
					}
				}
			}

					//
				/*if ((tmp+5) > tmp2 && tmp2 < sc) {
					if (atoi(month1) < atoi(month2)) {
						try {
							info_of_car2.Erase(i);
							--i;
						}
						catch (EEraseOutOfRange& err) {
							printf("%s , wrong index is %zu \n", err.Get_Message(), err.GetIndex());
							my_getch();
							break;
						}
						continue;
					}
					if (atoi(month1) == atoi(month2)) {
						if (atoi(day1) < atoi(day1)) {
							try {
								info_of_car2.Erase(i);
								--i;
							}
							catch (EEraseOutOfRange& err) {
								printf("%s , wrong index is %zu \n", err.Get_Message(), err.GetIndex());
								my_getch();
								break;
							}
							continue;
						}
						else {
							continue;
						}
					}
					if (atoi(month1) > atoi(month2)) {
						continue;
					}
				}
				if (atoi(year1) > atoi(year2)) {
					continue;
				}
			}*/
			printf("Автомобили, у которых просрочен ТО на %s, и отсортированные по марке: \n", date);
			info_of_car2.Alfa_sort(Rec_brand_comparator);
			for (size_t i = 0; i < info_of_car2.Get_size(); ++i) {
				info_of_car2[i].Printf_info_of_car();
			}
			free(date);
			printf("\nНажмите 1, если хотите сохранить результат в файл\nЛибо нажмите Esc\n");
			int ans1;
			while (true) {
				ans1 = _getch();
				if (ans1 == 49 || ans1 == 27) break;
			}
			if (ans1 == '1') {
				printf("Ведите путь к файлу, в который следует записать результат\n");
				auto path = Read_line();
				try {
					info_of_car2.Write_file(path);
				}
				catch (EFileNotExist& err) {
					printf("%s\n", err.Get_Message());
					my_getch();
					free(path);
					break;
				}
				printf("Данные записаны\n");
				my_getch();
				free(path);
			}
			info_of_car2.Clear();
			break;
		}
		case 54: //Поиск
		{
		system("cls");
		for (size_t i = 0; i < Vec.Get_size(); ++i) {
			Vec[i].Printf_info_of_car();
		}
		while (true) {
			int m6 = menu_6();
			if (m6 == 27) {
				break;
			}
			if (m6 == 49) {
				system("cls");
				printf("Введите подстроку марки, по которой производить поиск \n");

				char* substr = Read_line();

				substr = Fix_str(substr);

				for (size_t i = 0; i < Vec.Get_size(); ++i) {
					char surname[255];
					strcpy(surname, Vec[i].Get_brand());
					for (size_t i = 0; i < strlen(surname); ++i) {
						surname[i] = tolower(surname[i]);
					}
					if (strstr(surname, substr) != NULL) {
						Vec[i].Printf_info_of_car();
						printf("------------------------------------------------------------------------------------\n");
					}
				}
				free(substr);
				my_getch();
				break;
			}
				}
				break;
		}
		case 55: //Очистка
		{
			system("cls");
			Vec.Clear();
			printf("Массив очищен\n");
			my_getch();
			break;
		}
		case 27:
		{
			Vec.Clear();
			end = 0;
			break;
		}
		}

	} while (end == 1);
}