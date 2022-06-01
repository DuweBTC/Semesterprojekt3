namespace RecipeApi.Models;
using Ingredient.Model;

public class RecipeItem
{

    /*
    *@brief This function creates the get and set functions for RecipeItemId
    */
    public int RecipeItemId { get; set; }

    /*
    *@brief This function creates the get and set functions for Ingredient
    */
    public IngredientItem? Ingredient { get; set; }

    /*
    *@brief This function creates the get and set functions for Amount
    */
    public double Amount { get; set; }


    // public RecipeItem(Ingredient ingredient, double amount)
    // {
    //     Ingredient = ingredient;
    //     Amount = amount;
    // }
};