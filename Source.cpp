#include <iostream>

class A{
public:
	int x;
	A(){
		std::cout << "konstruktor przypisuje x-owi wartosc 5" << std::endl;
		x = 5;
	}
	~A(){
		std::cout << "destruktor zostaje uruchomiony" << std::endl;
	}
	A(const A& a){
		std::cout << "konstruktor kopiujacy przypisuje x-owi wartosc 5" << std::endl;
		x = a.x;
	}
};

class B{
public:
	int size;
	double* tab;

	B(){
		size = 5;
		tab = new double[5];
		for (int i = 0; i < size; i++){
			tab[i]=i*i*i-2*i*i+i;
		}
	}
	B(int n){
		size = n;
		tab = new double[n];
		for (int i = 0; i < size; i++){
			tab[i] = i*i*i - 2 * i*i + i;
		}
	}
	B& operator=(const B& a){

		size = a.size;
		tab = new double[size];
		for (int i = 0; i < size; i++)
		{
			tab[i] = a.tab[i];
		}



		return *this;
	}
	~B(){
		delete tab;
	}
	void Drukuj(){
		for (int i = 0; i < size; i++){
			std::cout << "tab["<<i+1<<"]="<<tab[i] << std::endl;
		}

		
		
	}
};

void fun(A a){
	std::cout << "x=" << a.x << std::endl;
}


/*
Jezeli klasa ma w sobie alokacje to powinna miec:
1. Destruktor
2. Kontruktor kopiujacy
3. Operator=

Jednakze jezeli nie potrzeba powyzszego to lepiej nie pisac
*/

int main(){

	std::cout << "hey!" << std::endl;

	A* ptr = new A;

	A w;
	std::cout << "zostaje utworzony obiekt w" << std::endl;
	w.x = 13;
	std::cout << "zmienna x w obiekcie w zmienia wartosc na 13" << std::endl;
	fun(w); // tu jest tworzony nowy obiekt poprzez defaultowy konstruktor kopiuj¹cy, zas na koniec funkcji skopiowany obiekt zostaje usuniety

	std::cout << "zostaje uruchomiona funkcja fun" << std::endl;
	delete ptr;
	std::cout << "obiekt ptr zostaje usuniety" << std::endl;

	B wb;
	B v(10);
	


	wb.tab[0] = 7;
	wb.Drukuj();

	v.tab[1] = 3;
	v.Drukuj();

	wb = v;
	wb.Drukuj();
	wb.tab[2] = 4;

	v.Drukuj();
	wb.Drukuj();

	return 0;
}