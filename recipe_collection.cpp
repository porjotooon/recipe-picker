#include <iostream>
#include <vector>
#include <iomanip>
#include "recipe_collection.h"
#include "ingredients_list.h"

using namespace std;

recipe_collection::recipe_collection(){
	size = 0;
}
recipe_collection::recipe_collection(vector<ingredients_list> _recipes, int _size){
	recipes = _recipes;
	size = _size;
}
int recipe_collection::getSize() const{
	return size;
}
ingredients_list recipe_collection::getRecipeAt(int index) const{
	return recipes[index];
}
void recipe_collection::addRecipe(ingredients_list const & newRecipe){
	recipes.push_back(newRecipe);
	size++;
}
bool recipe_collection::removeRecipe(int index){
	bool isValid = index >= 0 && index < size;
	if (isValid)
		recipes.erase(recipes.begin() + index);
	return isValid;
}
void recipe_collection::print(ostream & out){
	for (int i = 0; i < size; i++){
		cout << i << endl;
		for (int j = 0; j < recipes[i].size; j++){
			cout << recipes[i].getAt(j) << endl;
		}
		cout << "----------------------------------" << endl;
	}
}
recipe_collection recipe_collection::operator=(recipe_collection const & other){
	recipes = other.recipes;
	size = other.size;
	return *this;
}
//assume arrays are sorted, all unique ingredients in an array of ingredients (unique strings)
recipe_collection recipe_collection::doAbleRecipes(ingredients_list const & ingredients) const{
	recipe_collection doAble;
	//only one recipe to check
	if (size == 1){
		int i = 0, j = 0;
		while (i < recipes[0].size && j < ingredients.size){
            if(recipes[0].getAt(i) == ingredients.getAt(j)){
                if (i == 0|| (i > 0 && recipes[0].getAt(i) != ingredients.getAt(i - 1)))
                    doAble.addRecipe(recipes[0]);
                i++;
                j++;
            }
            else if (recipes[0].getAt(i) > ingredients.getAt(j))
                j++;
            else
                i++;
        }
        return doAble;
	}
	//more than one recipe to check
	else{
		//compare the first in target array to first in each recipe, discard recipes that dont match
		for(int count = 0; count < size; count++){
			if (ingredients.getAt(0) <= recipes[count].getAt(0)){
				int i = 0, j = 0;
				//flip the comparison and now analyze target array against each valid recipe
				ingredients_list intersection;
				while (i < recipes[count].size && j < ingredients.size){
	                if(recipes[count].getAt(i) == ingredients.getAt(j)){
	                    intersection.addIngredient(recipes[count].getAt(i));
	                    i++;
	                    j++;
	                }
	                else if (recipes[count].getAt(i) > ingredients.getAt(j))
	                    j++;
	                else
	                    i++;
	    		}
	    		if(intersection == recipes[count])
	    			doAble.addRecipe(intersection);
			}
		}
		return doAble;
	}
}
