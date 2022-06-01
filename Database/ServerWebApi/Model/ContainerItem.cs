namespace ContainerApi.Models;

using Ingredient.Model;
public class ContainerItem
{
    /*
    *@brief This function creates the get and set functions for ContainerItemId
    */
    public int ContainerItemId { get; set; }

    /*
    *@brief This function creates the get and set functions for Place
    */
    public int Place { get; set; }


    /*
    *@brief This function creates the get and set functions for Ingredient
    */
    public IngredientItem Ingredient { get; set; } = default!;


    //public List<Ingredient>[] ingredient { get; set; } = default!;

}
