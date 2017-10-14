 /* Виневский Максим Викторович
    Лабораторная работа №1
	Вариант №5
	Задание :Перевести лот в карат и выразить в унциях.
 */
void main(){
	setlocale(LC_ALL, "Rus");
	float lot, karat;
	double ynciy;
	printf("Введите кол-во лот : ");
	int result = scanf_s("%f", &lot);
	if (result == 0)
	{
		printf("ошибка \n");
	}
	else
	{
		karat = lot * LOT_IN_KARAT;
		printf("\n Это %.3f карат", karat);
		ynciy = lot * LOT_IN_YNCIY;
		printf(" и %.3f унций \n", ynciy);
	}
	_getch();
}
