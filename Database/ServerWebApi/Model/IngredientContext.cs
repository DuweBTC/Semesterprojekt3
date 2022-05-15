using Microsoft.EntityFrameworkCore;

namespace IngredientApi.Models;
using Ingredient.Model;

public class IngredientContext : DbContext
{
    public IngredientContext(DbContextOptions<IngredientContext> options)
    : base(options)
    {

    }

    public DbSet<IngredientItem> IngredientItems { get; set; } = null!;

}