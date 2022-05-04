namespace DrinkApi.Models;
using System.Collections.Generic;

using Ingredient.Model;
public class DrinkItem
{
    public int Id { get; set; }

    public string? titel { get; set; }

    public string? description { get; set; }


    public List<Tuple<Ingredient, double>>[] ingredients { get; set; } = default!;

}