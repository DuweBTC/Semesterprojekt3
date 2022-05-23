namespace ContainerApi.Models;

using Ingredient.Model;
public class ContainerItem
{
    public int ContainerItemId { get; set; }

    public int Place { get; set; }

    public IngredientItem Ingredient { get; set; } = default!;


    //public List<Ingredient>[] ingredient { get; set; } = default!;

}
