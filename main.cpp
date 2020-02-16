#include <iostream>
#include "ingredients_list.h"
#include "recipe_collection.h"

using namespace std;

int main(){
	vector<string> s1 = {"banana", "apple", "strawberry"},
		s2 = {"kiwi", "cucumber", "papaya", "blueberries"},
		s3 = {"watermelon", "winkleberry", "tomato", "grape"},
		s4 = {"banana", "soy", "chemicals", "apple", "peach"},
		s5 = {"pear", "grapefruit", "hibiscus", "spinach", "cocoa", "water"},
		s6 = {"poison"},
		sTarget = {"banana", "apple", "strawberry", "grape", "peach", "soy", "chemicals"};
	ingredients_list i1("1", s1, 3);
	ingredients_list i2("2", s2, 4);
	ingredients_list i3("3", s3, 4);
	ingredients_list i4("4", s4, 5);
	ingredients_list i5("5", s5, 6);
	ingredients_list i6("6", s6, 1);
	ingredients_list iTarget("Target", sTarget, 7);
	vector<ingredients_list> r1 = {i1, i2, i3, i4, i5, i6};
	recipe_collection c1(r1, 6);
	c1.print(cout);
	cout << endl << endl;
	recipe_collection c2 = c1.doAbleRecipes(iTarget);
	c2.print(cout);
	cout << endl << endl << endl << endl;
	
	vector<string> s2_1 = {"2", "3", "9"},
		s2_2 = {"1", "0", "2", "3"},
		s2_3 = {"9", "8", "7", "6"},
		s2_4 = {"5", "3", "7", "6", "2"},
		s2_5 = {"1", "2", "3", "4", "5", "6"},
		s2_6 = {"7"},
		s2_Target = {"7", "1", "2", "0", "3", "9", "999"};
	ingredients_list i2_1("1", s2_1, 3);
	ingredients_list i2_2("2", s2_2, 4);
	ingredients_list i2_3("3", s2_3, 4);
	ingredients_list i2_4("4", s2_4, 5);
	ingredients_list i2_5("5", s2_5, 6);
	ingredients_list i2_6("6", s2_6, 1);
	ingredients_list i2_Target("Target", s2_Target, 7);
	vector<ingredients_list> r2_1 = {i2_1, i2_2, i2_3, i2_4, i2_5, i2_6};
	recipe_collection c2_1(r2_1, 6);
	c2_1.print(cout);
	cout << endl << endl;
	recipe_collection c2_2 = c2_1.doAbleRecipes(i2_Target);
	c2_2.print(cout);
	cout << endl << endl;
	
	return 0;
}
