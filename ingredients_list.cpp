#include <iostream>
#include <vector>
#include <algorithm>
#include "ingredients_list.h"

using namespace std;

ingredients_list::ingredients_list(){
	name = "";
	size = 0;
}
ingredients_list::ingredients_list(string _name, vector<string> _ingredients, int _size){
	name = _name;
	std::sort(_ingredients.begin(), _ingredients.end());
	ingredients = _ingredients;
	size = _size;
}
ingredients_list ingredients_list::operator=(ingredients_list const & other){
	name = other.name;
	ingredients = other.ingredients;
	size = other.size;
	return *this;
}
bool ingredients_list::operator==(ingredients_list const & other) const{
	return size == other.size && ingredients == other.ingredients;
}
string ingredients_list::getAt(int index) const{
	return ingredients[index];
}
void ingredients_list::addIngredient(string newIngredient){
	ingredients.push_back(newIngredient);
	size++;
}

