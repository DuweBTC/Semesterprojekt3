namespace RecipeApi.Models;
using Ingredient.Model;

public class RecipeItem
{
    public int id { get; set; }
    public List<Ingredient> Ingredients { get; set; } = new();
    public double Amount { get; set; }

    /*
    public RecipeItem(Ingredient ingredient, double amount)
    {
        Ingredient = ingredient;
        Amount = amount;
    }*/
};