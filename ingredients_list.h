#ifndef INGREDIENTS_LIST
#define INGREDIENTS_LIST

#include <vector>

using namespace std;

class ingredients_list{
	private:
		string name;
		vector<string> ingredients;
		int size;
	
	public:
		ingredients_list();
		ingredients_list(string, vector<string>, int);
		ingredients_list operator=(ingredients_list const & other);
		bool operator==(ingredients_list const & other) const;
		string getAt(int index) const;
		void addIngredient(string newIngredient);
	friend class recipe_collection;
};

#endif

