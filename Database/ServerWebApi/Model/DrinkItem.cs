namespace DrinkApi.Models;
using System.Collections.Generic;
using RecipeApi.Models;
using Ingredient.Model;
//[Keyless]
public class DrinkItem
{
    public string Titel { get; set; } = default!;

    public int DrinkId { get; set; }

    public string? Description { get; set; }

    public double Price { get; set; }

    // Initialize to prevent NullReferenceException
    public List<RecipeItem> ingredients { get; set; } = new List<RecipeItem>();
    //public List<Tuple<string, double>>[] ingredientss { get; set; } = null!;
    //public List<(string, double)> ingredients { get; set; } = null!;
}