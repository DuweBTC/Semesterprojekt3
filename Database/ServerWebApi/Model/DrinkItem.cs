namespace DrinkApi.Models;
using System.Collections.Generic;
using RecipeApi.Models;
using Ingredient.Model;
//[Keyless]
public class DrinkItem
{
    public string Titel { get; set; } = default!;

    public int DrinkItemId { get; set; }

    public string? Description { get; set; }

    public double Price { get; set; }

    public List<RecipeItem> ingredients { get; set; } = new List<RecipeItem>();

}
