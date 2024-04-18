#include <string>
#include <iostream>

bool isValidNumber(std::string cardNumber) {
	for (auto num : cardNumber) {
		if (!isdigit(num)) {
			return false;
			break;
		}
	}

	return true;
}

int charToInt(char digit) {
	return int(digit - '0');
}

bool ValidateCard(std::string cardNumber) {
	int oddDigits, evenDigits, numsGreaterThan4, total;
	oddDigits = evenDigits = numsGreaterThan4 = total = 0;

	for (int i = 0; i < cardNumber.length() - 1; i++) {
		if (i % 2 == 0) {
			if (charToInt(cardNumber[i]) > 4) {
				numsGreaterThan4++;
			}
			evenDigits += charToInt(cardNumber[i]);
		}
		else { 
			oddDigits += charToInt(cardNumber[i]);
		}
	}
	total = (evenDigits * 2) + oddDigits + numsGreaterThan4;

	if ((charToInt(cardNumber.back()) + total) % 10 == 0) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	std::string creditCard;
	
	std::cout << "Input your credit card number: ";
	getline(std::cin, creditCard);

	// Remove whitespace
	creditCard.erase(std::remove(creditCard.begin(), creditCard.end(), ' '), creditCard.end());

	// Make sure the credit card is the right length
	if (creditCard.length() != 16) {
		std::cout << "Credit card does not have a valid amount of digits." << std::endl;
		return -1;
	}

	if (!isValidNumber(creditCard)) {
		std::cout << "Credit card can only have digits.";
		return -1;
	}

	bool result = ValidateCard(creditCard);
	if (result) {
		std::cout << "Valid credit card number.";
	}
	else {
		std::cout << "Invalid credit card number.";
	}

	return 0;
}