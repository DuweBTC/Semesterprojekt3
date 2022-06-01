namespace DrinkApi.Models;
using System.Collections.Generic;
using RecipeApi.Models;
using Ingredient.Model;
//[Keyless]
public class DrinkItem
{
    /*
    *@brief This function creates the get and set functions for Titel
    */
    public string Titel { get; set; } = default!;
    
    /*
    *@brief This function creates the get and set functions for DrinkItemId
    */
    public int DrinkItemId { get; set; }
    
    /*
    *@brief This function creates the get and set functions for Description
    */
    public string? Description { get; set; }
    
    /*
    *@brief This function creates the get and set functions for Price
    */
    public double Price { get; set; }

    /*
    *@brief This function creates the get and set functions for Ingredients list 
    */
    // Initialize to prevent NullReferenceException
    public List<RecipeItem> ingredients { get; set; } = new List<RecipeItem>();
    //public List<Tuple<string, double>>[] ingredientss { get; set; } = null!;
    //public List<(string, double)> ingredients { get; set; } = null!;
}