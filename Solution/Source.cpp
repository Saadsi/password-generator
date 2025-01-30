#include <iostream>
#include <random>
#include <string>

using namespace std;

string GeneratePassword(int length)
{
	const string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()";
	string password = "";

	// Инициализация генератора случайных чисел
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, alphabet.size() - 1);

	for (int i = 0; i < length; ++i) {
		password += alphabet[dis(gen)];
	}

	return password;
}

int main()
{
	int length;
	cout << "Enter password length: ";
	cin >> length;

	// Проверка длины пароля
	if (length <= 0) {
		cout << "Password length must be greater than 0!" << endl;
		return 1;
	}

	string password = GeneratePassword(length);
	cout << "Generated password: " << password << endl;
	return 0;
}
