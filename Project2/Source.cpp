#include <iostream>

//конструктор копирования
//класс набор методов и полей который создается для работы над данными
class Vericle {
public:
	//конструктор(параметризованный)
	Vericle(int newMaxSpeed,const std::string& newColor, const std::string& newType):
		maxSpeed(newMaxSpeed),
		color(newColor),
		type(newType){}
	
	//конструктор с одним аргументом
	Vericle(int newMaxSpeed) :
		maxSpeed(newMaxSpeed),
		color("yellow"),
		type("bicycle") {}
	
	//Vericle() = delete;//показывают что нужно внести аргументы без них нельзя
	//Конструктор копирования копирует данные из другого класса
	Vericle(Vericle& obj) {
		maxSpeed = obj.getMaxSpeed();
		color = obj.getColor();
		type = obj.getType();
		
	}
	//деконструктор разрушает класс
	~Vericle() {
		std::cout << "Destruction Vericle()" << std::endl;
	}
	std::string getColor() {
		return color;
	}
	void setColor(const std::string& newColor) {
	color = newColor;
	}
	std::string& getType() {
		return type;
	}
	void setType(const std::string& newType) {
		type = newType;
	}
	//геттер возвращает поле класса
	int getMaxSpeed() {
		counter++;
		return maxSpeed;
	}

	//сеттер устанавливет новое значение
	void setMaxSpeed(int newSpeed) {
		maxSpeed = newSpeed;
	}
	bool operator==(Vericle& other) {
		if (maxSpeed == other.maxSpeed &&
			color == other.color &&
			type == other.type) {
			return true;
		}
		return false;
	}
	bool operator!() {
		if (maxSpeed < 0) {
			return true;
		}
		return false;
	}
private:
	int counter;
	int maxSpeed;
	std::string color;
	std::string type;
};
struct Point {
	int x;
	int y;
};


int main() {

	
	//std::cout << "Start of main()" << std::endl;

	/*Vericle car(20, "black", "van");
	car.setMaxSpeed(50);
	std::cout << "Max speed is: " << car.getMaxSpeed() << std::endl;
	
	std::string carColor = car.getColor();
	std::cout << "carColor: " << carColor << " car.getColor()" << car.getColor() << std::endl;
	carColor = "green";
	std::cout << "carColor: " << carColor << " car.getColor()" << car.getColor() << std::endl;
	std::string& carType = car.getType();
	carType = "randomType";
	std::cout << carType << " " << car.getType() << std::endl;*/

	Vericle originalCar(15, "white", "bus");
	Vericle newCar(originalCar);
	Vericle foreignlCar(15, "white", "abc");


	std::cout << (originalCar == newCar) << std::endl;
	std::cout << "====================\n";
	std::cout << (originalCar == foreignlCar) << std::endl;


	//std::cout << "End of main()" << std::endl;





	return 0;
}