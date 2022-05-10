namespace ContainerApi.Models;

using Ingredient.Model;
public class ContainerItem
{
    public Guid ContainerId { get; set; }

    public int Place { get; set; }

    public Ingredient Ingredient { get; set; } = default!;


    //public List<Ingredient>[] ingredient { get; set; } = default!;

}