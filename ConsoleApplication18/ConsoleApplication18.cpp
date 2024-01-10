#include <iostream>
#include <cstdlib>
#include <ctime>

enum class Player {
	Bot,
	User
};

int diceRoll() {
	return std::rand() % 6 + 1;
}

int main() {
	// Инициализация генератора случайных чисел
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	int botDice[5];
	int userDice[5];

	// Бросок костей для бота
	for (int i = 0; i < 5; ++i) {
		botDice[i] = diceRoll();
		std::cout << "Бот: Кость " << i + 1 << " = " << botDice[i] << std::endl;
	}

	// Бросок костей для игрока
	for (int i = 0; i < 5; ++i) {
		userDice[i] = diceRoll();
		std::cout << "Игрок: Кость " << i + 1 << " = " << userDice[i] << std::endl;
	}

	int botSum = 0;
	int userSum = 0;
	int maxBotValue = 0;
	int maxUserValue = 0;
	bool botSame = true;
	bool userSame = true;

	// Проверка на наличие всех пяти одинаковых значений для бота
	for (int i = 0; i < 5; ++i) {
		botSum += botDice[i];
		maxBotValue = std::max(maxBotValue, botDice[i]);
		if (botDice[i] != botDice[0]) {
			botSame = false;
		}
	}

	// Проверка на наличие всех пяти одинаковых значений для игрока
	for (int i = 0; i < 5; ++i) {
		userSum += userDice[i];
		maxUserValue = std::max(maxUserValue, userDice[i]);
		if (userDice[i] != userDice[0]) {
			userSame = false;
		}
	}

	// Определение победителя
	if (botSame && !userSame) {
		std::cout << "Бот победил!" << std::endl;
	}
	else if (!botSame && userSame) {
		std::cout << "Игрок победил!" << std::endl;
	}
	else if (!botSame && !userSame) {
		if (botSum > userSum) {
			std::cout << "Бот победил!" << std::endl;
		}
		else if (botSum < userSum) {
			std::cout << "Игрок победил!" << std::endl;
		}
		else {
			std::cout << "Ничья!" << std::endl;
		}
	}
	else {
		std::cout << "Ничья!" << std::endl;
	}

	return 0;
}