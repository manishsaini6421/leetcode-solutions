class FoodRatings {
public:
    map<string, int> FoodRating;
    map<string, string> FoodCuisines;
    map<string,set<pair<int,string>>> maxRating;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            FoodRating[foods[i]] = ratings[i];
            FoodCuisines[foods[i]] = cuisines[i];
            maxRating[cuisines[i]].insert({-ratings[i],foods[i]});
        }
    }

    void changeRating(string food, int newRating) { 
         int oldRating=FoodRating[food];
        FoodRating[food] = newRating; 
       
        maxRating[FoodCuisines[food]].erase({-oldRating,food});
        maxRating[FoodCuisines[food]].insert({-newRating,food});
    }

    string highestRated(string cuisine) {
       return maxRating[cuisine].begin()->second;

    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */