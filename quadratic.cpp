/*
Arely Aguirre
UID: 605505030
Disc: 1C
*/

#include <iostream>

using namespace std;

class QuadraticEquation
{
	public:
		QuadraticEquation(double inp_a, double inp_b, double inp_c);
		void computation();
	private:
		double a, b, c;
		double discriminant;
		bool has_solutions();
		bool solutions;
		double x1, x2;
		double solution1, solution2;
		void get_solution1();
		void get_solution2();
		void no_solutions();

};

QuadraticEquation::QuadraticEquation(double inp_a,double inp_b,double inp_c)
{
	a = inp_a;
	b = inp_b;
	c = inp_c;
	//user inputs are stored as a,b, and c
	discriminant = (b * b) - (4 * a * c);
	//discriminant equation
	x1 = 0;
	x2 = 0;
	solutions = true;
	solution1 = 0;
	solution2 = 0;
}

bool QuadraticEquation::has_solutions() 
{
	if (discriminant < 0)
	//bool changed from true to false if discriminant is negative
	{
		solutions = false;
	}
	return solutions;
}

void QuadraticEquation::computation()
{
	if (has_solutions() == true)
	{
		x1 = (-b + sqrt(discriminant)) / (2 * a);
		x2 = (-b - sqrt(discriminant)) / (2 * a);
		//finds solutions to quadratic equation
		if (x2 < x1)
		//sets solutions as x1 or x2 depending on which is bigger
		{
			solution1 = x2;
			solution2 = x1;
		}
		else
		{
			solution1 = x1;
			solution2 = x2;
		}
		//calls functions to print out the solutions in the correct order
		get_solution1();
		get_solution2();
	}
	else
	{
		no_solutions();
		//calls on function that states there are no solutions
	}
}

void QuadraticEquation::get_solution1()
{
	cout << "Solution 1: " << solution1 << endl;
}

void QuadraticEquation::get_solution2()
{
	cout << "Solution 2: " << solution2 << endl;
}

void QuadraticEquation::no_solutions()
{
	cout << "This has: No real solutions" << endl;
}




int main()
{
	double a, b, c;
	cout << "Enter a coefficient: ";
	cin >> a;
	cout << "Enter b coefficient: ";
	cin >> b;
	cout << "Enter c coefficient: ";
	cin >> c;
	QuadraticEquation values(a,b,c);
	values.computation();

	return 0;
}

