namespace DrinkApi.Models;
using System.Collections.Generic;
using RecipeApi.Models;
using Ingredient.Model;
//[Keyless]
public class DrinkItem
{
    public Guid titel { get; set; }

    public int Id { get; set; }

    public string? description { get; set; }

    public double price { get; set; }

    // Initialize to prevent NullReferenceException
    public List<RecipeItem> ingredients { get; set; } = new List<RecipeItem>();
    //public List<Tuple<string, double>>[] ingredientss { get; set; } = null!;
    //public List<(string, double)> ingredients { get; set; } = null!;
}