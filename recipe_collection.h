#ifndef RECIPE_COLLECTION
#define RECIPE_COLLECTION
#include "ingredients_list.h"

using namespace std;

class recipe_collection{
	private:
		vector<ingredients_list> recipes;
		int size;
	public:
		recipe_collection();
		recipe_collection(vector<ingredients_list> _recipes, int _size);
		int getSize() const;
		ingredients_list getRecipeAt(int index) const;
		void addRecipe(ingredients_list const & ingredients);
		bool removeRecipe(int index);
		void print(ostream & fout);
		recipe_collection doAbleRecipes(ingredients_list const & ingredients) const;
		recipe_collection operator=(recipe_collection const & other);
};

#endif
