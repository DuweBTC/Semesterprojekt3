namespace ContainerApi.Models;

using Ingredient.Model;
public class ContainerItem
{
    public Guid Id { get; set; }

    public int place { get; set; }

    public Ingredient ingredient { get; set; } = default!;


    //public List<Ingredient>[] ingredient { get; set; } = default!;

}