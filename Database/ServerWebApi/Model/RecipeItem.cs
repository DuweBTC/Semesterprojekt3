namespace RecipeApi.Models;
using Ingredient.Model;

public class RecipeItem
{

    public int RecipeItemId { get; set; }
    public IngredientItem? IngredientItem { get; set; }
    public double Amount { get; set; }

};
