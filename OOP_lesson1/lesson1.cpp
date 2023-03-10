#include <iostream>
#include <string>
#include "tyger.h"
class Vehicle {
public:
	//??????????? (??????????????????)
	Vehicle(int newMaxSpeed, const std::string& newColor, const std::string& newType):maxSpeed(newMaxSpeed),color(newColor),type(newType) {
		std::cout << "Constructor \n";
		/*maxSpeed = newMaxSpeed;    ?????????? ????????? ????? ??????????? ????? :(6 rows)
		color = newColor;
		type = newType;*/
		s = new char[50];
	}
	Vehicle() = delete;//?????? ??????????? ????????? ?????? ??? ????? ???????
	Vehicle(int newMaxSpeed) {	//??????????(? ????? ??????????)	
		maxSpeed = newMaxSpeed;
		color = "newColor";
		type = "bus";
	}

	Vehicle(Vehicle& obj) {//??????????? ???????????
		maxSpeed = obj.getMaxSpeed();
		color = obj.getColor();
		type = obj.getType();
	}
	//??????????
	~Vehicle() {
		std::cout << "Destruction\n";
		delete[] s;
	}
	bool operator == (Vehicle& other) {// ?????????? ????????? ?????????
		if (maxSpeed == other.maxSpeed &&
			color == other.color &&
			type == other.type) {
			return true;
		}
		return false;
	}
	int getMaxSpeed() {
		return maxSpeed;
	}
	void setMaxSpeed(int newspeed) {
		maxSpeed = newspeed;
	}
	const std::string& getColor() {
		return color;
	}
	void setColor(const std::string& newColor) {
		color = newColor;
	}
	const std::string& getType() {
		return type;
	}
	void setType(const std::string& newType) {
		type = newType;
	}
private:
	int maxSpeed;
	std::string color;
	std::string type;
	char* s;
};
int main() {
	Vehicle originalCar(45, "white", "plane");
	Vehicle twoCar(5, "white", "bus");
	Vehicle newCar(originalCar);
	std::cout << (originalCar == newCar) << "\n";
	setlocale(LC_ALL, "Russian");
	std::cout << "Start of main\n";
	Vehicle car(60,"silver", "comercail");
	std::cout << "Max speed is: " << car.getMaxSpeed() << '\n';
	car.setMaxSpeed(50);
	std::cout << "Max speed is: " << car.getMaxSpeed() << '\n';
	std::cout << "??????? ????? ????-> ";
	std::string str;
	getline(std::cin,str);
	car.setColor(str);
	std::cout << "Color is " << car.getColor() << std::endl;
	std::cout << "End of main\n";

	std::string  carColor = car.getColor();
	carColor = "red";
	std::cout << carColor << " " << car.getColor() << "\n";
	originalCar.setColor("blue");
	std::cout << "original " << originalCar.getColor() << " " << originalCar.getMaxSpeed() << '\n';
	std::cout << "newCar " << newCar.getColor() << " " << newCar.getMaxSpeed() << '\n';
	std::cout << (originalCar == newCar) << "\n";
	std::cout << (originalCar == twoCar) << "\n";

	return 0;
}